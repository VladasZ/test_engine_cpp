//
//  Scene.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "View.hpp"
#include "Model.hpp"
#include "Camera.hpp"
#include "PointLight.hpp"
#include "BulletInclude.hpp"
#include "PositionManipulator.hpp"


namespace scene {

    class Scene {

        friend Model;

    protected:

        Physics3D* _physics = nullptr;

    public:

        Model* selected_model = nullptr;

        PositionManipulator* position_manipulator;

        std::vector<PointLight*> _light_sources;

        Camera* const camera;

        std::vector<Model*> _models;
        std::vector<Object*> _objects;

        cu::Event<Model*> on_model_selected;
        cu::Event<Model*> on_model_moved;

        Scene();
        virtual ~Scene();

        void add_object(Object*);
        void add_light(PointLight*);

        void remove_object(Object*);

        void add_box(const gm::Vector3&, const gm::Box&, const gm::Color& color = gm::Color::green);

        virtual void update(float frame_time);
        void draw();

        gm::Axis select_axis(const gm::Ray&);
        gm::Axis select_plane(const gm::Ray&) const;
        Model* select_model(const gm::Ray&);

        void add_ray(const gm::Ray&);

        void setup_selection();

        virtual void setup() { }

    private:

        gm::Axis selected_axis       = gm::Axis::None;
        gm::Axis selected_plane_axis = gm::Axis::None;

    };

}
