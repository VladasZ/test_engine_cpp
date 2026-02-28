//
//  Mouse.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Target.hpp"

#ifdef DESKTOP_BUILD

#define MOUSE

#include "Point.hpp"
#include "Event.hpp"


namespace ui {

class Mouse final {

public:

    enum class Button {
        Left,
        Right,
        Middle
    };

    enum class ButtonState {
        Up,
        Down
    };

    enum class CursorMode {
        Arrow,
        Text,
        Drag,
        HResize,
        VResize
    };

	static inline gm::Point position;
	static inline Button button = Button::Left;
	static inline ButtonState button_state = ButtonState::Up;

	static inline gm::Point frame_shift;

	static inline cu::Event<gm::Point> on_moved;

    void set_position(const gm::Point&);
    void set_button_state(Button, ButtonState);

    std::string to_string() const;
};

}

#endif
