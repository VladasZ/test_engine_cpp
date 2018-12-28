//
//  GL.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/28/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "GL.hpp"
#include "Screen.hpp"

void GL::set_viewport(const ui::Rect& rect) {
    glViewport(static_cast<GLint>  (rect.origin.x),
               static_cast<GLint>  (Screen::size.height - rect.origin.y - rect.size.height),
               static_cast<GLsizei>(rect.size.width),
               static_cast<GLsizei>(rect.size.height));
}

void GL::unbind_image() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void GL::set_clear_color(const ui::Color& color) {
    glClearColor(color.r, color.g, color.b, color.a);
}



