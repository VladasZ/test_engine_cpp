//
//  TeLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//


#include "TeLevel.hpp"

#ifdef USING_SPRITES

#include "Input.hpp"
#include "Screen.hpp"
#include "Assets.hpp"
#include "Keyboard.hpp"

using namespace te;
using namespace ui;
using namespace gm;
using namespace sprite;


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

    Input::on_ui_free_touch = [this](Touch* touch) {

        Point pos = touch->position;
        pos.x -= Screen::size.width / 2;
        pos.y -= Screen::size.height / 2;
        pos.y = -pos.y;
        pos /= 10;
        pos += _player->position();

        auto sprite_touch = touch->clone();
        sprite_touch->position = pos;

        on_touch(sprite_touch);

        delete sprite_touch;

    };

    on_touch = [this](Touch* touch) {

        if (!touch->is_began()) return;

        //add_box(touch->position);

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

#endif
