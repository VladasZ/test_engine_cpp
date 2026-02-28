//
//  RigidBody.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 02/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Physics3D.hpp"
#include "RigidBody.hpp"
#include "ForceConvert.hpp"

using namespace gm;
using namespace scene;


RigidBody::RigidBody(Vector3 pos, float size, float mass, RigidBody::Shape shape_type) {
#ifdef USING_BULLET3D

    if (physics == nullptr) {
        Fatal("Physics is not set for rigid body");
    }
    //create a dynamic rigidbody

    if (shape_type == RigidBody::Shape::Box) {
        shape = new btBoxShape(btVector3(size / 2, size / 2, size / 2));
    }
    else {
        shape = new btSphereShape(size / 2);
    }

    /// Create Dynamic Objects
    btTransform startTransform;
    startTransform.setIdentity();
    pos.flip_height();
    startTransform.setOrigin({ pos.x, pos.y, pos.z });

    //rigidbody is dynamic if and only if mass is non zero, otherwise static
    _is_dynamic = (mass != 0.f);

    btVector3 localInertia(0, 0, 0);
    if (_is_dynamic) {
        shape->calculateLocalInertia(mass, localInertia);
    }

    //using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
    motion_state = new btDefaultMotionState(startTransform);
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motion_state, shape, localInertia);
    body = new btRigidBody(rbInfo);
   // body->setRestitution(0.5);

    physics->add_rigid_body(this);

#endif
}

RigidBody::~RigidBody() {
#ifdef USING_BULLET3D
    delete shape;
    delete body;
    delete motion_state;
#endif
}

void RigidBody::update() {
    physics->update_rigid_body(this);
}

void RigidBody::set_position(const Vector3& position) {
#ifdef USING_BULLET3D
    btTransform transform;
    body->getMotionState()->getWorldTransform(transform);
    _position = position;
    _position.flip_height();
    transform.setOrigin(cu::force_cast<btVector3>(_position));
    body->setWorldTransform(transform);
    motion_state->setWorldTransform(transform);
#endif
}
