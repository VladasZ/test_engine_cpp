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


void te::PathView::set_path(const cu::Path& path) {
    _label->set_text(path.file_name());
    _image->set_image(FileManagerView::image_for_extension(path.extension()));
}

const cu::Path& te::PathView::path() const {
    return _path;
}

void te::PathView::setup() {
    Logvar(_frame);
    init_view(_label);
    init_view(_image);
}

void te::PathView::layout_subviews() {

    static const float margin = 5;

    auto image_size = _frame.size.height - margin * 2;

    Logvar(_frame);


    _image->edit_frame() =
            { margin,
              margin,
              image_size,
              image_size
            };

    _label->edit_frame() =
            { _image->frame().max_x() + margin,
              margin,
              _frame.size.width - _image->frame().max_x() + margin,
              image_size
            };

}

gm::Rect& te::PathView::edit_frame() {
    return View::edit_frame();
}
