//
//  Physics3D.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Matrix4.hpp"
#include "Physics3D.hpp"
#include "ForceConvert.hpp"

using namespace gm;
using namespace scene;


Physics3D::Physics3D() {
#ifdef USING_BULLET3D
    ///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
    collisionConfiguration = new btDefaultCollisionConfiguration;

    ///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
    dispatcher = new btCollisionDispatcher(collisionConfiguration);

    ///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
    overlappingPairCache = new btDbvtBroadphase;

    ///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
    solver = new btSequentialImpulseConstraintSolver;

    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

    dynamicsWorld->setGravity(btVector3(0, -10, 0));

#endif
}

Physics3D::~Physics3D() {
#ifdef USING_BULLET3D
    delete dynamicsWorld;
    delete solver;
    delete overlappingPairCache;
    delete dispatcher;
    delete collisionConfiguration;
#endif
}

void Physics3D::update(float interval) {
#ifdef USING_BULLET3D
    dynamicsWorld->stepSimulation(interval, 10);
//    dump_all_objects();
//    Log << "Hello";
#endif
}

void Physics3D::update_rigid_body(RigidBody* rigid_body) {
#ifdef USING_BULLET3D
    btTransform trans;
    rigid_body->body->getMotionState()->getWorldTransform(trans);
    rigid_body->_position = cu::force_cast<Vector3>(trans.getOrigin());
    rigid_body->_position.flip_height();
    rigid_body->_rotation = cu::cast<Vector4>(trans.getRotation());
#endif
}

void Physics3D::add_rigid_body(RigidBody* rigid_body) {
#ifdef USING_BULLET3D
    dynamicsWorld->addRigidBody(rigid_body->body);
#endif
}

void Physics3D::dump_all_objects() const {
#ifdef USING_BULLET3D
    for (int i = 0; i < dynamicsWorld->getNumCollisionObjects(); i++) {
        auto obj = dynamicsWorld->getCollisionObjectArray()[i];
        auto body = btRigidBody::upcast(obj);
        btTransform trans;

        body->getMotionState()->getWorldTransform(trans);
        Log << cu::force_cast<Vector3>(trans.getOrigin());

        trans = body->getWorldTransform();
        Log << cu::force_cast<Vector3>(trans.getOrigin());
    }
#endif
}
