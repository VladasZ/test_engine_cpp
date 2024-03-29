//
//  TEUIDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UIDrawer.hpp"

class TEUIDrawer : public ui::UIDrawer {

public:

    TEUIDrawer() = default;

private:

    void fill_rect(const gm::Rect&, const gm::Color&) override;
    void draw_rect(const gm::Rect&, const gm::Color&) override;
    void draw_image_in_rect(Image*, const gm::Rect&, const gm::Color& color = gm::Color::white) override;
    void draw_path_in_rect(ui::PathData*, const gm::Rect&) override;

    ui::PathData* initialize_path_data(gm::PointsPath*, const gm::Color&, ui::PathData::DrawMode draw_mode) override;
    void free_path_data(ui::PathData*) override;

public:

#ifdef DESKTOP_BUILD
    void set_cursor_mode(ui::Mouse::CursorMode cursor_mode) override;
#endif

};
