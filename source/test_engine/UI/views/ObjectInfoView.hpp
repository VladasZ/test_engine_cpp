//
//  ObjectInfoView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"
#include "CaptionLabel.hpp"
#include "ViewResizer.hpp"

class ObjectInfoView : public ui::View {

protected:

    ui::CaptionLabel* _id_label;

public:

    using View::View;

    void set_object(scene::Model*);

    void clear();

protected:

    void _setup() override;
    void _layout() override;

};

