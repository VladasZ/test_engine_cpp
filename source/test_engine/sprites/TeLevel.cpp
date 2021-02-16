//
//  TeLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Input.hpp"
#include "Touch.hpp"
#include "Player.hpp"
#include "Screen.hpp"
#include "Assets.hpp"
#include "TeLevel.hpp"
#include "Keyboard.hpp"

using namespace te;
using namespace ui;
using namespace gm;
using namespace sprite;


static Point _mouse_position;


TeLevel::TeLevel(ui::ControlPad* pad, ui::AnalogStickView* stick) : control_pad(pad), stick(stick) {

}

void TeLevel::setup() {
    setup_controls();
}

void TeLevel::setup_controls() {

    control_pad->on_up = [this] {
        _player->jump();
    };

    control_pad->on_left = [this] {
        _player->go_left();
    };

    control_pad->on_right = [this] {
        _player->go_right();
    };

    stick->on_direction_change = [this](Point point) {
        point.invert_y();
        _player->add_impulse(point * (_player->mass() * 10));
    };

    Keyboard::on_key_pressed = [this](Key key) {

        if (key == 'A') {
            _player->go_left();
        }
        else if (key == 'D') {
            _player->go_right();
        }
        else if (key == ' ') {
            _player->jump();
        }

    };

#ifdef MOUSE
    Input::on_hover_moved = [this](const gm::Point& position) {
        _mouse_position = convert_touch(position);
    };
#endif

    Input::on_ui_free_touch = [this](Touch* touch) {
        auto sprite_touch = touch->clone();
        sprite_touch->position = _mouse_position;
        on_touch(sprite_touch);
        delete sprite_touch;
    };

    on_touch = [this](Touch* touch) {

        if (!touch->is_began()) return;

        add_box(touch->position);

        if (selected_sprite) {
            selected_sprite->is_selected = false;
            selected_sprite = nullptr;
        }

        for (auto sprite : _sprites) {
            if (!sprite->contains(touch->position)) continue;
            sprite->is_selected = true;
            selected_sprite = sprite;
            break;
        }

    };

}

gm::Point TeLevel::convert_touch(const gm::Point& touch) {
    Point pos = touch;
    auto size = Screen::size / Screen::render_scale();
    pos.x -= size.width / 2;
    pos.y -= size.height / 2;
    pos.y = -pos.y;
    pos /= 10;
    pos += _player->position();
    return pos;
}

#ifdef DESKTOP_BUILD
gm::Point TeLevel::mouse_position() {
    return _mouse_position;
}
#endif
