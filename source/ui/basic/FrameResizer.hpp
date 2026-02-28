//
//  FrameResizer.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Rect.hpp"
#include "Touch.hpp"


namespace ui {

    class FrameResizer {

    public:

        struct EdgeInfo {

            inline static constexpr float width = 16;

            float left_min = 0;
            float left_max = 0;

            float right_min = 0;
            float right_max = 0;

            float top_min = 0;
            float top_max = 0;

            float bottom_min = 0;
            float bottom_max = 0;

        };

    public:

        FrameResizer(gm::Rect& frame, gm::Rect& absolute_frame, bool& needs_layout);

    public:

        gm::Edge get_edge(const gm::Point& point);

        void on_touch(ui::Touch*);

        void update_edge_info();

    private:

        gm::Rect& _frame;
        gm::Rect& _absolute_frame;
        bool& _needs_layout;

        gm::Point _initial_touch;

        EdgeInfo _edge_info;
        gm::Edge _current_edge;

    };

}
