//
//  Physics3D.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"
#include "RigidBody.hpp"


namespace scene {

    class Physics3D {

    public:

        Physics3D();
        ~Physics3D();

        static inline gm::Vector3 ground_position;
        static inline gm::Vector3 box_position;

        void update(float interval);

        void update_rigid_body(RigidBody*);

        void add_rigid_body(RigidBody*);

        void dump_all_objects() const;

    private:

#ifdef USING_BULLET3D
        btDefaultCollisionConfiguration* collisionConfiguration;
        btCollisionDispatcher* dispatcher;
        btBroadphaseInterface* overlappingPairCache;
        btSequentialImpulseConstraintSolver* solver;
        btDiscreteDynamicsWorld* dynamicsWorld;
#endif

    };

}
