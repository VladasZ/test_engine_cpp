//
//  GL.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/28/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "GL.hpp"
#include "Screen.hpp"

void GL::set_viewport(const Rect& rect) {
    glViewport(static_cast<GLint>  (rect.origin.x) * 1,
               static_cast<GLint>  (Screen::size.height - rect.origin.y - rect.size.height) * 1,
               static_cast<GLsizei>(rect.size.width) * 1,
               static_cast<GLsizei>(rect.size.height) * 1);
}

void GL::set_clear_color(const Color& color) {
    glClearColor(color.r, color.g, color.b, color.a);
}



