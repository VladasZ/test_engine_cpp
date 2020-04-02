//
//  FileManagerView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 27/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Image.hpp"
#include "StackView.hpp"
#include "ScrollView.hpp"


namespace te {

    class FileManagerView : public ui::ScrollView {

    private:

        cu::Path _path;
        ui::StackView* _stack_view;

    public:

        using ScrollView::ScrollView;

        float cell_height = 50.0f;

    protected:

        void set_path(const cu::Path& path);

        void  _setup() override;
        void _layout() override;

    public:

        static Image* image_for_extension(const std::string& extension);

    };

}
