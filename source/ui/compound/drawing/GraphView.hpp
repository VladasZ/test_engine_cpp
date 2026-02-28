//
//  GraphView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 4/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "DrawingView.hpp"
#include "RangeConversion.hpp"


namespace ui {

    class GraphView : public View {

        gm::PointsPath* _path = nullptr;

        std::vector<float> _points;

        DrawingView* _drawing_view = nullptr;

        cu::RangeConversion _range;

        size_t _points_size = 1000;

    public:

        bool auto_ranges = true;

        using View::View;

        gm::Color graph_color;

        ~GraphView() override;

        size_t points_size() const;
        void set_points_size(size_t);

        virtual void add_point(float);
        void reset();
        void reset_ranges();

        void set_range_min(float);
        void set_range_max(float);

    protected:

        void setup() override;
        void layout() override;

        float _delta() const;
        void _recalculate_graph();

    };

}
