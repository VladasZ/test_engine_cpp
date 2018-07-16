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

    protected:

        virtual _LayoutType type() const { return _LayoutType::Base; };

    public:
        float value = 0;
        View *anchor = nullptr;

        Base(float value = 0, View *anchor = nullptr) : value(value), anchor(anchor) { }

        bool isTop()    const { return type() == _LayoutType::Top;    }
        bool isBottom() const { return type() == _LayoutType::Bottom; }
        bool isLeft()   const { return type() == _LayoutType::Left;   }
        bool isRight()  const { return type() == _LayoutType::Right;  }
        bool isCenter() const { return type() == _LayoutType::Center; }
    };

#define _DEFINE_LAYOUT_TYPE(_type) \
    struct _type : public Base { \
        _LayoutType type() const override { return _LayoutType::_type; } \
        public: \
        using Base::Base;\
        _type() : Base() {}\
    };

    _DEFINE_LAYOUT_TYPE(Top);
    _DEFINE_LAYOUT_TYPE(Bottom);
    _DEFINE_LAYOUT_TYPE(Left);
    _DEFINE_LAYOUT_TYPE(Right);
    _DEFINE_LAYOUT_TYPE(Center);

    static Base * top(float value = 0) { return new Top(value); }
    static Base * bottom(float value = 0) { return new Bottom(value); }
    static Base * left(float value = 0) { return new Left(value); }
    static Base * right(float value = 0) { return new Right(value); }
    static Base * center(float value = 0) { return new Center(value); }

    using Array = Array<Base *>;

};
