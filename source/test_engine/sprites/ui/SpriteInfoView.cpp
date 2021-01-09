//
//  SpriteInfoView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 09/01/21.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "GlobalEvents.hpp"
#include "SpriteInfoView.hpp"

using namespace te;
using namespace ui;
using namespace sprite;


SpriteInfoView::~SpriteInfoView() {
    Events::frame_drawn.unsubscribe(this);
}

void SpriteInfoView::set_sprite(Sprite* sprite) {
    if (sprite) {
        id_label->set_text(std::to_string((uint64_t)sprite));
        position_label->set_text(sprite->position().to_string());
        size_label->set_text(sprite->size().to_string());
    }
    else {
        id_label->set_text("");
        position_label->set_text("");
        size_label->set_text("");
    }
}

void SpriteInfoView::setup() {
    init_views(id_label, position_label, size_label);
    id_label->set_caption("Id:");
    position_label->set_caption("Position:");
    size_label->set_caption("Size:");
    Events::frame_drawn.subscribe(this) = [this] { set_sprite(sprite); };
}

void SpriteInfoView::layout() {
    place_ver(id_label, position_label, size_label);
}
