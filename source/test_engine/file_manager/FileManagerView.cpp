//
//  FileManagerView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 27/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Label.hpp"
#include "Assets.hpp"
#include "Button.hpp"
#include "PathView.hpp"
#include "FileManagerView.hpp"

using namespace cu;
using namespace te;
using namespace gm;
using namespace ui;


void FileManagerView::set_path(const Path& path) {

    if (!path.is_directory()) {
        Log("Not a dir");
        return;
    }

    _stack_view->remove_all_subviews();

    _path = path;
    _path.trim_relative();

    auto ls = _path.ls();

    Size size = { _frame.size.width, cell_height };

    Logvar(size);

    for (auto file : ls) {
        auto view = new PathView(size);
        _stack_view->add_subview(view);
        view->set_path(file);
    }

    _stack_view->edit_frame().size.height = cell_height * ls.size();
}

void FileManagerView::_setup() {
    ScrollView::_setup();
    init_view(_stack_view);
    set_path(System::pwd());
}

void FileManagerView::_layout() {
    _calculate_absolute_frame();
    content_size.height = _stack_view->frame().size.height;
    ScrollView::_layout();
}

Image* FileManagerView::image_for_extension(const std::string& extension) {
    if (extension.empty())  return Assets::images->folder;
    if (extension == "png") return Assets::images->image;
                            return Assets::images->file;
}
