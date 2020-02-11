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

using namespace gm;
using namespace cu;
using namespace ui;

void ObjectInfoView::set_object(scene::Model* model) {

    if (model == nullptr) {
        _id_label->set_text("");
        _position_label->set_text("");
        return;
    }

    _id_label->set_text(cu::Log::to_string(model));
    _position_label->set_text(model->position().to_string());

}

void ObjectInfoView::clear() {
    set_object(nullptr);
}

void ObjectInfoView::_setup() {
    add_subview(_id_label = new CaptionLabel());
    _id_label->set_caption("Model: ");

    add_subview(_position_label = new CaptionLabel());
    _position_label->set_caption("Position: ");
}

void ObjectInfoView::_layout() {
    StackView::_layout();
    _layout_subviews();
}
