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

enum class Alignment {
	Left,
	Center,
	Right
};

class Layout {

    enum class _LayoutType {
        Top,
        Bottom,
        Left,
        Right,
        CenterH,
        CenterV,
        Base
    };

public:

    struct Base {

        friend View;
        friend Layout;

        void _layout(View* view) const;
        void _layoutWithoutAnchor(View* view) const;
        void _layoutWithAnchor(View* view) const;

        float value = 0;
        View* anchor = nullptr;

        bool isTop()     const { return type() == _LayoutType::Top;     }
        bool isBottom()  const { return type() == _LayoutType::Bottom;  }
        bool isLeft()    const { return type() == _LayoutType::Left;    }
        bool isRight()   const { return type() == _LayoutType::Right;   }
        bool isCenterH() const { return type() == _LayoutType::CenterH; }
        bool isCenterV() const { return type() == _LayoutType::CenterV; }

    protected:

        virtual _LayoutType type() const = 0;

    public:

        Base(float value, View* anchor) : value(value), anchor(anchor) { }
    };

#define _DEFINE_LAYOUT_TYPE(_type) \
private:\
    struct L##_type : public Base { \
        _LayoutType type() const override { return _LayoutType::_type; } \
        public: using Base::Base; };\
public:\
    static Base* _type()                        { return new L##_type(0, nullptr);     }\
    static Base* _type(float value)             { return new L##_type(value, nullptr); }\
    static Base* _type(View* view)              { return new L##_type(0, view);        }\
    static Base* _type(float value, View* view) { return new L##_type(value, view);    }\
private:

    _DEFINE_LAYOUT_TYPE(Top);
    _DEFINE_LAYOUT_TYPE(Bottom);
    _DEFINE_LAYOUT_TYPE(Left);
    _DEFINE_LAYOUT_TYPE(Right);
    _DEFINE_LAYOUT_TYPE(CenterH);
    _DEFINE_LAYOUT_TYPE(CenterV);

public:

    using Arr = Array<Base*>;

	static Base* fromAlignment(Alignment alignment);
};

using L = Layout;
