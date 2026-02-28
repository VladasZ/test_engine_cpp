 //
//  Scene.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Grid.hpp"
#include "Scene.hpp"
#include "Input.hpp"
#include "Touch.hpp"
#include "Camera.hpp"
#include "BoxModel.hpp"
#include "Physics3D.hpp"
#include "ArrayUtils.hpp"
#include "PointLight.hpp"
#include "VectorModel.hpp"

using namespace gm;
using namespace ui;
using namespace scene;


Scene::Scene() : camera(new Camera(this)) {

    position_manipulator = new PositionManipulator();
    position_manipulator->_scene = this;
    position_manipulator->is_hidden = true;
    position_manipulator->selectable = false;
    static_cast<Model*>(position_manipulator)->_setup();

    _physics = new Physics3D();
    RigidBody::physics = _physics;

    setup_selection();
}

Scene::~Scene() {
    for (auto obj : _objects) {
        delete obj;
    }
#ifdef USING_BULLET3D
    delete _physics;
#endif
    
    delete position_manipulator;
    Input::on_ui_free_touch.unsubscribe(this);
}

void Scene::add_object(Object* obj) {
    _objects.push_back(obj);
    obj->_scene = this;
    if (auto model = dynamic_cast<Model*>(obj)) {
        _models.push_back(model);
        model->_setup();
    }
}

void Scene::add_light(PointLight* light) {
    _light_sources.push_back(light);
}

void Scene::remove_object(Object* object) {
    cu::container::remove(_models, object);
    cu::container::remove(_objects, object);
    delete object;
}

void Scene::add_box(const gm::Vector3& position, const gm::Box& box, const gm::Color& color) {
    auto box_model = new BoxModel(box);
    box_model->color = color;
    add_object(box_model);
    box_model->edit_position() = position;
}

void Scene::update(float frame_time) {
    _physics->update(frame_time);
    camera->update_matrices();
    for (auto obj : _objects) {
        obj->update();
    }
    for (auto light : _light_sources) {
        light->update();
    }
    position_manipulator->update();
}

void Scene::draw() {
    for (auto model : _models) {
        model->draw();
    }
    position_manipulator->draw();
}

gm::Axis Scene::select_axis(const gm::Ray& ray) {
    if (position_manipulator->is_hidden) return gm::Axis::None;
    for (auto arrow : position_manipulator->arrows) {
        if (auto hit = arrow->intersecting_ray(ray)) {
            return position_manipulator->get_axis(hit);
        }
    }
    return gm::Axis::None;
}

gm::Axis Scene::select_plane(const Ray& ray) const {
    if (position_manipulator->is_hidden) return Axis::None;
    for (auto arrow : position_manipulator->planes) {
        if (auto hit = arrow->intersecting_ray(ray)) {
            return position_manipulator->get_plane(hit);
        }
    }
    return gm::Axis::None;
}

Model* Scene::select_model(const gm::Ray& ray) {

    position_manipulator->is_hidden = true;
    selected_model = nullptr;

    std::vector<Model*> hits;

    for (auto model : _models) {
        model->deselect();
        if (auto hit = model->intersecting_ray(ray)) {
            hits.push_back(hit);
        }
    }

    if (hits.empty()) return nullptr;

    Model* closest_to_camera = nullptr;
    auto min_distance = std::numeric_limits<float>::max();

    for (auto model : hits) {
        auto distance = model->position().distance_to(camera->position());
        if (distance < min_distance) {
            min_distance = distance;
            closest_to_camera = model;
        }
    }

    selected_model = closest_to_camera;
    selected_model->is_selected = true;
    position_manipulator->edit_position() = selected_model->absolute_position();
    position_manipulator->is_hidden = false;

    return selected_model;
}

void Scene::add_ray(const gm::Ray& ray) {
    auto vector = new VectorModel();
    add_object(vector);
    vector->set_scale({ ray.length(), 0.1f, 0.1f });
    vector->edit_position() = ray.begin;
    vector->look_at(ray.direction_vector());
    vector->selectable = false;
}

void Scene::setup_selection() {

    Input::on_ui_free_touch.subscribe(this) = [this](Touch* touch) {

        Vector3 model_position;

        if (touch->is_ended()) {
            selected_axis       = Axis::None;
            selected_plane_axis = Axis::None;
            return;
        }

        if (touch->is_moved() && selected_axis != Axis::None) {
            auto ray = camera->cast_ray(touch->position);
            const auto& position = selected_model->position();
            auto axis_vector = selected_model->position();
            axis_vector.set_axis(selected_axis, position.get_axis(selected_axis) + 1.0f);
            Ray axis_ray { selected_model->position(), axis_vector };
            auto point = ray.closest_points_with(axis_ray).second;
            selected_model->edit_position() = point;
            position_manipulator->edit_position() = point;
            on_model_moved(selected_model);
        }
        else if (touch->is_moved() && selected_plane_axis != Axis::None) {
            const auto ray = camera->cast_ray(touch->position);

            Vector3 normal;
            normal.set_axis(selected_plane_axis, 1.0f);
            Vector3 origin = model_position;

            LineSegment seg = { origin, normal };

            auto target = ray.plane_intersection(seg) + camera->position();

            selected_model->edit_position() = target;
            position_manipulator->edit_position() = target;

            on_model_moved(selected_model);

            return;
        }

        if (touch->is_began()
        #ifdef DESKTOP_BUILD
            && touch->is_left_click()
        #endif
                ) {

            auto ray = camera->cast_ray(touch->position);

            auto axis = select_axis(ray);

            if (axis != Axis::None) {
                selected_axis = axis;
                return;
            }

            auto plane_axis = select_plane(ray);

            if (plane_axis != Axis::None) {
                selected_plane_axis = plane_axis;
                model_position = selected_model->position();
                return;
            }

            if (selected_model) {
                selected_model->on_moved.unsubscribe(this);
            }

            selected_model = select_model(ray);

            if (selected_model) {
                selected_model->on_moved.subscribe(this) = [&] {
                    position_manipulator->edit_position() = selected_model->position();
                };
            }

            on_model_selected(selected_model);
        }
    };
}
