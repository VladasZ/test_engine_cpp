//
//  DrawingView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 4/28/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "PathData.hpp"


namespace ui {

class DrawingView : public View {

public:

    using Paths = std::vector<PathData*>;

private:

    Paths _paths;

public:

    using View::View;

    ~DrawingView() override;

    const Paths& paths() const;
    void add_path(gm::PointsPath*, const gm::Color&, PathData::DrawMode draw_mode = PathData::DrawMode::Fill);

    void remove_all_paths();

protected:

    void _draw() override;

};

}
