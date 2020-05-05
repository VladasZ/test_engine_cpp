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
#include "PathView.hpp"
#include "FileManagerView.hpp"
#include "FileManagerTopPanel.hpp"

using namespace cu;
using namespace te;
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

    for (auto file : ls) {
        auto view = new PathView(size);
        _stack_view->add_subview(view);
        view->set_path(file);
    }

    _top_panel->set_path(path);

}

void FileManagerView::setup() {
    ScrollView::setup();
    init_view(_top_panel);
    init_view(_stack_view);
    set_path(System::pwd());

    _top_panel->on_press_up_button = [] {
        Ping;
    };

}

void FileManagerView::layout_subviews() {
    ScrollView::layout_subviews();

    _top_panel->edit_frame() = { _frame.size.width, cell_height };

    auto& stack_frame = _stack_view->edit_frame();

    stack_frame.size.height = cell_height * _stack_view->subviews().size();
    stack_frame.size.width = _frame.size.width;
    stack_frame.origin.y = cell_height;

    content_size.height = _stack_view->frame().size.height;
}

Image* FileManagerView::image_for_extension(const std::string& extension) {
    if (extension.empty())  return Assets::images->folder;
    if (extension == "png") return Assets::images->image;
                            return Assets::images->file;
}
