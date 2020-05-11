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
#include "StringUtils.hpp"
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

    Size size = { _frame.size.width, cell_height };

    for (const auto& file : _path.ls()) {
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

    _top_panel->on_press_up_button = [&] {
        set_path(_path.parent());
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

Image* FileManagerView::icon_for_path(const cu::Path& path) {

    if (path.is_directory()) return Assets::images->folder;

    if (String::contains(path.file_name(), "cmake")) {
        return Assets::images->cmake;
    }

    if (path.extension() == "png") return Assets::images->image;
    if (path.extension() == "txt") return Assets::images->text;

    return Assets::images->file;

}
