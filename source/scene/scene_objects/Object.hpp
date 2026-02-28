//
//  Object.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Event.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"


namespace scene {

    class Scene;

    class Object {

        friend Scene;

    protected:

        bool _need_matrices_update = true;

        gm::Vector3 _position;

    public:

        Scene* _scene = nullptr;

    public:

        Object() = default;
        explicit Object(const gm::Vector3&);
        virtual ~Object();

    protected:

        virtual void update_matrices();

    public:

        void set_needs_matrices_update();
        virtual void update();

    public:

        cu::Event<> on_moved;

        const gm::Vector3& position() const;
        virtual gm::Vector3& edit_position();

    };

}
