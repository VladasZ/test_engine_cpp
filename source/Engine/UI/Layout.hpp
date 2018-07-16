//
//  Layout.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/15/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Array.hpp"

class View;

class Layout {

    enum class _LayoutType {
        Top,
        Bottom,
        Left,
        Right,
        Center,
        Base
    };

public:

    struct Base {

        friend View;
        friend Layout;

        void _layout(View *view) const;
        void _layoutWithoutAnchor(View *view) const;
        void _layoutWithAnchor(View *view) const;

        float value = 0;
        View *anchor = nullptr;

        bool isTop()    const { return type() == _LayoutType::Top; }
        bool isBottom() const { return type() == _LayoutType::Bottom; }
        bool isLeft()   const { return type() == _LayoutType::Left; }
        bool isRight()  const { return type() == _LayoutType::Right; }
        bool isCenter() const { return type() == _LayoutType::Center; }

    protected:

        virtual _LayoutType type() const = 0;

    public:

        Base(float value = 0, View *anchor = nullptr) : value(value), anchor(anchor) { }

    };

#define _DEFINE_LAYOUT_TYPE(_type) \
private:\
    struct L##_type : public Base { \
        _LayoutType type() const override { return _LayoutType::_type; } \
        public: \
        using Base::Base;\
        L##_type() : Base() {}\
    };\
public:\
    static Base * _type(float value = 0, View *view = nullptr) { return new L##_type(value, view); }\
private:

    _DEFINE_LAYOUT_TYPE(Top);
    _DEFINE_LAYOUT_TYPE(Bottom);
    _DEFINE_LAYOUT_TYPE(Left);
    _DEFINE_LAYOUT_TYPE(Right);
    _DEFINE_LAYOUT_TYPE(Center);

public:

    using Array = Array<Base *>;

};
