//
//  PathView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 13/03/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "PathView.hpp"
#include "FileManagerView.hpp"


void te::PathView::set_path(const cu::Path& path) {
    _label->set_text(path.file_name());
    _image->set_image(FileManagerView::image_for_extension(path.extension()));
}

const cu::Path& te::PathView::path() const {
    return _path;
}

void te::PathView::_setup() {
    init_view(_label);
    init_view(_button);
    init_view(_image);
}

void te::PathView::_layout() {
    _calculate_absolute_frame();

    _button->edit_frame() = _frame.with_zero_origin();

    _layout_subviews();
}
