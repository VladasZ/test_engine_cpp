//
//  TEDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "../ui/source/ui_lib/Drawer.hpp"

namespace ui {
class Image;
}

namespace te {

class Drawer : public ui::Drawer {

public:

    Drawer();

private:

    void _draw_rect(const Rect& rect) override;
    void _fill_rect(const Rect& rect, const Color& color) override;
    const Rect _convert_rect(const Rect& rect) override;

public:

    ui::Image::Drawer* init_image_drawer(ui::Image* image) override;

#ifdef UI_DESKTOP
    void set_cursor_mode(ui::Mouse::CursorMode cursor_mode) override;
#endif

};

}
