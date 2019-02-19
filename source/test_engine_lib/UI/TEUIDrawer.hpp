//
//  TEUIDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UIDrawer.hpp"

namespace ui {
class UIImage;
}

class TEUIDrawer : public ui::UIDrawer {

public:

    TEUIDrawer();

private:

    void _fill_rect(const Rect& rect, const Color& color) override;
    const Rect _convert_rect(const Rect& rect) override;

public:

    ui::UIImage::Drawer* init_image_drawer(ui::UIImage* image) override;

#ifdef UI_DESKTOP
    void set_cursor_mode(ui::Mouse::CursorMode cursor_mode) override;
#endif

};
