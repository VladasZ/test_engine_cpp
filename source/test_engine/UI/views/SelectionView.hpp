//
//  TestView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Button.hpp"
#include "Switch.hpp"
#include "ImageView.hpp"
#include "DrawingView.hpp"
#include "ObjectInfoView.hpp"
#include "SelectionScene.hpp"


class SelectionView : public ui::View {

public:

    using ui::View::View;

    ObjectInfoView* object_info_view = nullptr;

    ui::View* revolving_view;

    ui::Button* button;
    ui::Switch* switcher;
    ui::ImageView* image;

    ~SelectionView();

protected:

    void setup() override;
    void layout() override;

};
