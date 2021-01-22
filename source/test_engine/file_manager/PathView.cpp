//
//  PathView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 13/03/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "PathView.hpp"
#include "FileManagerView.hpp"

using namespace cu;
using namespace te;


void PathView::set_path(const Path& path) {
    _label->set_text(path.file_name());
    _image->set_image(FileManagerView::icon_for_path(path));
}

const Path& PathView::path() const {
    return _path;
}

void PathView::setup() {
    init_view(_label, { _frame.size });
    init_view(_button);
    init_view(_image);
    _button->on_press = [this] { on_press(); };
}

void PathView::layout() {

    static const float margin = 5;

    auto image_size = _frame.size.height - margin * 2;

    _button->place.as_background();

    _image->edit_frame() =
            { margin,
              margin,
              image_size,
              image_size
            };

    _label->edit_frame().origin.x = _image->frame().max_x() + margin;

}
