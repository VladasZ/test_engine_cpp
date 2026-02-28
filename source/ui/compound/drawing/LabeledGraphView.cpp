//
//  LabeledGraphView.сpp
//  ui
//
//  Created by Vladas Zakrevskis on 29/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "StringUtils.hpp"
#include "LabeledGraphView.hpp"

using namespace ui;


void LabeledGraphView::set_caption(const std::string& caption) {
    _caption_label->set_text(caption);
}

void LabeledGraphView::add_point(float point) {
    GraphView::add_point(point);
    _caption_label->set_text(cu::String::from_float(point));
}

void LabeledGraphView::setup() {
    GraphView::setup();
    init_view(_caption_label, { 100, 25 });
}
