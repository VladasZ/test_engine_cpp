//
//  TestScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "math.h"

#ifdef USING_CONAN
#include <glm/gtx/quaternion.hpp>
#endif

#include "Grid.hpp"
#include "Mesh.hpp"
#include "Image.hpp"
#include "Plane.hpp"
#include "Paths.hpp"
#include "Screen.hpp"
#include "GLWrapper.hpp"
#include "EffectsScene.hpp"
#include "VectorModel.hpp"
#include "GlobalEvents.hpp"
#include "ModelImporter.hpp"
#include "TestView.hpp"

using namespace gm;
using namespace te;

void EffectsScene::_setup() {
    
    Screen::clear_color = Color::light_gray;
    
    position_manipulator->is_hidden = false;
    
    camera->set_target({ 0, 0, 0 });
    camera->edit_position() = {1, 1, 1 };
    camera->flying_speed = 0.2f;
    
#ifdef USING_CONAN
    
    floor = new scene::Grid();
    add_object(floor);
    
    //    floor = new scene::Plane(Size { 200, 200 });
    //    floor->color = Color::light_gray;
    //    add_object(floor);
    
    cube = new scene::BoxModel(Box { 0.1f });
    cube->set_position({ 3, 3, 1 });
    add_object(cube);
    
    
    vector_model = new scene::VectorModel();
    vector_model->set_scale({ 10, 1, 1 });
    add_object(vector_model);
    
    TestView::sliders->on_change.subscribe([&](const Vector4& vector) {
        auto vec = vector;
        
        cube->set_position(vector.vector3());
        vector_model->look_at(vector.vector3());
        
        vec.normalize();
        
        vec *= sin(vector.w / 2);
        
        auto myQuat = glm::quat(cos(vector.w / 2), vec.x, vec.y, vec.z);
        
        Log(cos(vector.w / 2) * cos(vector.w / 2) + vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
        
        glm::mat4 rot_mat = glm::toMat4(myQuat);
        
#ifdef USING_ASSIMP
        monkey->set_rotation_matrix(gm::Matrix4(rot_mat));
#endif
    });
    
#endif
    
#ifdef USING_ASSIMP
    add_object(monkey = ModelImporter::import("Monkey.blend"));
    //  monkey->set_scale(0.1f);
#endif
    
    
}
