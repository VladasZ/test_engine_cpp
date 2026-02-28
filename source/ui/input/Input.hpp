//
//  Input.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 18/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <list>
#include <stdint.h>

#include "Point.hpp"
#include "Event.hpp"
#include "Mouse.hpp"
#include "Target.hpp"


namespace ui {

class View;
class Touch;

class Input final {

private:

    static inline View* _resizing_view = nullptr;

    static inline std::vector<View*> _subscribed_views;
    static inline std::vector<View*> _resizables;

    static inline std::vector<View*> _views_to_subscribe;
    static inline std::vector<View*> _resizable_to_subscribe;

    static inline std::vector<View*> _views_to_unsubscribe;
    static inline std::vector<View*> _resizable_to_unsubscribe;

public:

    static void process_touch_event(Touch*);

    static inline cu::Event<Touch*> on_touch;
    static inline cu::Event<Touch*> on_ui_free_touch;

    static void subscribe_view(View*);
    static void subscribe_resizable(View*);

    static void unsubscribe_view(View*);
    static void unsubscribe_resizable(View*);

#ifdef MOUSE
    static inline cu::Event<const gm::Point&> on_hover_moved;
#endif

#ifdef DESKTOP_BUILD
    static void hover_moved(const gm::Point& position);
#endif

};

}
