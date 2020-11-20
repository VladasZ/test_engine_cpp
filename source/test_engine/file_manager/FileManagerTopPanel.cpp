//
//  FileManagerTopPanel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 29/04/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Assets.hpp"
#include "FileManagerTopPanel.hpp"

using namespace cu;
using namespace ui;
using namespace te;


void FileManagerTopPanel::set_path(const Path& path) {
    _path_label->set_text(path);
}

void FileManagerTopPanel::setup() {
    init_view(_up_button);
    init_view(_path_label);

    _up_button->set_image(Assets::images->up);
    _up_button->on_press = [this] { on_press_up_button(); };

}

void FileManagerTopPanel::layout() {

    static Float margin = 5;

    auto button_size = _frame.size.height - margin * 2;

    _up_button->edit_frame() =
            { margin,
              margin,
              button_size,
              button_size
            };

    _path_label->edit_frame() =
            { _up_button->frame().max_x() + margin,
              0,
              _frame.size.width - button_size - margin,
              _frame.size.height
            };

}
