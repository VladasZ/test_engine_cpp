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
    static const GLint scale = 2;
    glViewport(static_cast<GLint>  (rect.origin.x) * scale,
               static_cast<GLint>  (Screen::size.height - rect.origin.y - rect.size.height) * scale,
               static_cast<GLsizei>(rect.size.width) * scale,
               static_cast<GLsizei>(rect.size.height) * scale);
}

void GL::set_clear_color(const Color& color) {
    glClearColor(color.r, color.g, color.b, color.a);
}



