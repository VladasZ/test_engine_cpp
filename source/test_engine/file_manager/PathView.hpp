//
//  PathView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 13/03/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"
#include "Button.hpp"
#include "ImageView.hpp"


namespace te {

    class PathView : public ui::View {

        cu::Path _path;

        ui::Label* _label;
        ui::ImageView* _image;

    public:

        using View::View;

        void set_path(const cu::Path& path);

        const cu::Path& path() const;

    protected:

        void setup() override;
        void layout_subviews() override;

        gm::Rect& edit_frame() override;


    };

}