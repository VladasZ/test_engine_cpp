//
//  ChartView.сpp
//  ui
//
//  Created by Vladas Zakrevskis on 4/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ChartView.hpp"

using namespace ui;

size_t ChartView::graph_size() const {
    return _graphs.size();
}

void ChartView::set_size(size_t size) {
    remove_all_subviews();
    _graphs.clear();
    for (size_t i = 0; i < size; i++) {
        auto graph = new GraphView();
        _graphs.push_back(graph);
        add_subview(graph);
    }
}

void ChartView::add_values(const std::initializer_list<float>& values) {
    size_t i = 0;
    for (auto value : values) {
        _graphs[i++]->add_point(value);
        if (i == _graphs.size()) {
            return;
        }
    }
}

void ChartView::set_colors(const std::initializer_list<gm::Color>& colors) {
    size_t i = 0;
    for (auto color : colors) {
        _graphs[i++]->graph_color = color;
        if (i == _graphs.size()) {
            return;
        }
    }
}

void ChartView::set_points_size(size_t size) {
    for (auto graph : _graphs) {
        graph->set_points_size(size);
    }
}

void ChartView::reset() {
    for (auto graph : _graphs) {
        graph->reset();
    }
}

void ChartView::setup() {
    set_size(1);
}

void ChartView::layout() {
    for (auto graph : _graphs) {
        graph->edit_frame() = _frame.with_zero_origin();
    }
}
