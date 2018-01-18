//
//  View.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "View.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"
#include "Window.hpp"
#include "Tools.hpp"

View::View(float x, float y, float width, float height) : frame(Rect(x, y, width, height)) { }
View::View(float width, float height) : View(0, 0, width, height) { }

BufferData * View::getBufferData() {
    return frame.getData();
    
}

void View::setupBuffer() {
    delete buffer;
    buffer = new Buffer(getBufferData(), BufferConfiguration(2));
}

void View::drawSubviews() const {
    for (int i = (int)subviews.size() - 1; i >= 0; i--)
        subviews[i]->draw();
}

void View::draw() {
    
    layout();
    
    drawSubviews();
        
    Shader::ui.use();
    Shader::ui.setUniformColor(color);
    buffer->draw();
}

void View::layout() {
    
    if (autolayoutMask == Autolayout::None) {
        setupBuffer();
        return;
    }
    
    Rect parentFrame;
    Rect layoutFrame = frame;
    
    if (superview == nullptr) parentFrame = Rect(Window::size.width, Window::size.height);
    else parentFrame = superview->frame;
    
    if (autolayoutMask & Autolayout::StickToLeft)
        layoutFrame.origin.x = 0;
    
    if (autolayoutMask & Autolayout::StickToRight)
        layoutFrame.origin.x = parentFrame.size.width - frame.size.width;
    
    if (autolayoutMask & Autolayout::StickToTop)
        layoutFrame.origin.y = 0;
    
    if (autolayoutMask & Autolayout::StickToBottom)
        layoutFrame.origin.y = parentFrame.size.height - frame.size.height;

    if (autolayoutMask & Autolayout::Center) {
        layoutFrame.origin.x = parentFrame.size.width / 2 - frame.size.width / 2;
        layoutFrame.origin.y = parentFrame.size.height / 2 - frame.size.height / 2;
    }
    
    if (autolayoutMask & Autolayout::CenterHorizontally)
        layoutFrame.origin.x = parentFrame.size.width / 2 - frame.size.width / 2;

    if (autolayoutMask & Autolayout::CenterVertically)
        layoutFrame.origin.y = parentFrame.size.height / 2 - frame.size.height / 2;

    this->frame = layoutFrame;
    
    setupBuffer();    
}

void View::setFrame(const Rect &frame) {
    
    this->frame = frame;
    buffer->setData(getBufferData());
    layout();
}

void View::addSubview(View *view) {
    
    subviews.push_back(view);
}
