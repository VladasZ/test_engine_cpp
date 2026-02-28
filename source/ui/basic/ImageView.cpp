//
//  ImageView.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/11/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "ui.hpp"

#include "UIDrawer.hpp"
#include "ImageView.hpp"

using namespace ui;
using namespace gm;

ImageView::ImageView() : ImageView({ }, nullptr) { }

ImageView::ImageView(Image* image) : ImageView({ }, image) { }

ImageView::ImageView(const gm::Rect& rect) : ImageView(rect, nullptr) { }

ImageView::ImageView(const Rect& rect, Image* image) : View(rect), _image(image) {
    _content_view = new View();
    _content_view->draw_debug_frame = false;
    add_subview(_content_view);
}

const Image* ImageView::image() const {
    return _image;
}

void ImageView::set_image(Image* image) {
    _image = image;
}

void ImageView::set_content_mode(ContentMode mode) {
    _content_mode = mode;
}

void ImageView::_draw() {
    View::_draw();
    if (_image) {
        ui::config::drawer()->
                draw_image_in_rect(_image,
                                   _content_view->absolute_frame(),
                                   tint_color
        );
    }
}

void ImageView::layout() {

    switch (_content_mode) {
        case ContentMode::Fill:
            _content_view->edit_frame() = {_frame.size };
            break;
        case ContentMode::AspectFit:
            _content_view->edit_frame() = _frame.fit_size({ _image->width(), _image->height() });
            _content_view->place.set_center(_frame.center());
            break;
    }

}
