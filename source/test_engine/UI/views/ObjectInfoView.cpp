//
//  ObjectInfoView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "MetaHelpers.hpp"
#include "ObjectInfoView.hpp"

using namespace cu;
using namespace ui;


void ObjectInfoView::set_object(scene::Model* model) {

    if (model == nullptr) {
        _id_label->set_text("");
        _position_label->set_text("");
        _bounding_box_label->set_text("");
        return;
    }

    _id_label->set_text(cu::log::to_string(model));
    _position_label->set_text(model->absolute_position().to_string());
    _bounding_box_label->set_text(model->bounding_box.to_string());
}

void ObjectInfoView::clear() {
    set_object(nullptr);
}

void ObjectInfoView::setup() {
    add_subview(_id_label = new CaptionLabel());
    _id_label->set_caption("Model: ");

    add_subview(_position_label = new CaptionLabel());
    _position_label->set_caption("Position: ");

    add_subview(_bounding_box_label = new CaptionLabel());
    _bounding_box_label->set_caption("Bounding: ");
}
