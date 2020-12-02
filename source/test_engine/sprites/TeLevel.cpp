//
//  TeLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//


#include "Input.hpp"
#include "Screen.hpp"
#include "Assets.hpp"
#include "TeLevel.hpp"
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

    Input::on_tap = [this](const Point& pos) {

        static Point converted_pos;
        converted_pos = pos;
        converted_pos.x -= Screen::size.width / 2;
        converted_pos.y -= Screen::size.height / 2;
        converted_pos.y = -converted_pos.y;
        converted_pos /= 10;
        converted_pos += _player->position();

        on_tap(converted_pos);

    };

    on_tap = [this](const Point& pos) {
        add_box(pos, { 1, 1 });
    };

}