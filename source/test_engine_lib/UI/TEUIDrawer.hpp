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

    TEUIDrawer();

private:

    void fill_rect(const gm::Rect&, const gm::Color&) override;
    void draw_image_in_rect(Image*, const gm::Rect&) override;
    void draw_path_in_rect(ui::PathData*, const gm::Rect&) override;

    virtual ui::PathData* initialize_path_data(gm::Path*, const gm::Color&) override;

public:

#if DESKTOP_BUILD
    void set_cursor_mode(ui::Mouse::CursorMode cursor_mode) override;
#endif

};
