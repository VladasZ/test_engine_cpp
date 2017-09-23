//
//  Color.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Color.hpp"
#include "GL.hpp"
#include "System.hpp"

Color::Color(Color const &obj) : Color() {
    
    this->data = obj.data;
}

Color& Color::operator=(Color const &obj) {
    
    data = obj.data;
    r = data.r;
    g = data.g;
    b = data.b;
    a = data.a;
    
    return *this;
}

Color::Color() : r(data.r), g(data.g), b(data.b), a(data.a), dataBuffer(&data[0]) {
    
    data = vec4(1, 1, 1, 1);
}

Color::Color(Float r, Float g, Float b, Float a) : Color() {
    
    data = vec4(r, g, b, a);
}

void Color::setToUniform(UInt uniform) const {
    
    glUniform4fv(uniform, 1, &data.r);
}

Color Color::random() {
    
    static vector<Color> colors = {
        
        Color::red,
        Color::green,
        Color::blue,
        Color::yellow,
        Color::orange,
        Color::purple,
        Color::turquoise
    };
    
    return colors[System::random((int)colors.size())];
}

string Color::toString() const {
    
    return "r: " + to_string(r) + " g: " + to_string(g) + " b: " + to_string(b) + " a: " + to_string(a);
}

const Color Color::black     = Color();
const Color Color::white     = Color(1, 1, 1);
const Color Color::red       = Color(1, 0, 0);
const Color Color::green     = Color(0, 1, 0);
const Color Color::blue      = Color(0, 0, 1);
const Color Color::yellow    = Color(1, 1, 0);
const Color Color::orange    = Color(1, 0.5, 0);
const Color Color::purple    = Color(1, 0, 1);
const Color Color::turquoise = Color(0, 1, 1);
const Color Color::gray      = Color(0.5, 0.5, 0.5);
