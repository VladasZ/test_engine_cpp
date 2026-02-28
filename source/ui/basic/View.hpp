//
//  View.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/5/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "ui.hpp"
#include "Rect.hpp"
#include "Event.hpp"
#include "Color.hpp"
#include "ViewPlacer.hpp"
#include "NonCopyable.hpp"


namespace ui {

    class Touch;
    class Input;
    class FrameResizer;

    class View : cu::NonCopyable {

    public:

        using Array = std::vector<View*>;

    protected:

        int _touch_id = 0;

        Rect _frame;
        View* _superview = nullptr;

        Array _subviews;

    public:

        bool clips = false;
        Point content_offset;
        Size content_size;

        bool is_hidden = false;
        bool draw_debug_frame = true;
        Color background_color;

    public:

    	View(View&&) = delete;
    	View(const View&) = delete;
    	View& operator=(const View& other) = delete;
        View& operator=(View&& other) = delete;
    	
        explicit View(const Rect& = { });
        virtual ~View();

    public:

        View* superview() const;
        const View::Array& subviews() const;

        void add_subview(View*);

        void remove_all_subviews();
        void remove_from_superview();

        void remove_last_subview();

    public:

		const  Rect& frame () const { return _frame;        }
		const Point& origin() const { return _frame.origin; }
		const  Size& size  () const { return _frame.size;   }

		float x() const { return _frame.origin.x; }
		float y() const { return _frame.origin.y; }

		float width () const { return _frame.size.width;  }
		float height() const { return _frame.size.height; }

		float max_x() const { return _frame.max_x(); }
		float max_y() const { return _frame.max_y(); }

        virtual Rect& edit_frame();

        const Rect& absolute_frame() const;

        float content_width() const;
        float content_height() const;

    public:

        friend ViewPlacer;

        ViewPlacer place;

    public:

        bool contains_global_point(const Point&) const;

        bool is_visible() const;

    public:

        virtual void _draw();

    private:

        bool _needs_layout = true;
        bool _needs_reposition = true;

    protected:

        void _set_needs_layout();
        void _set_needs_reposition();

    private:

        Rect _absolute_frame;

        void _draw_rect() const;

        void _calculate_absolute_frame();

    protected:

        virtual void setup() { }

        virtual void layout() { };

    public:

        cu::Event<> on_layout;

    protected:

        friend Input;

        FrameResizer* _resizer = nullptr;
        bool _touch_enabled = false;
        bool _resize_enabled = false;

    public:

        cu::Event<Touch*> on_touch;

        void enable_touch();
        void disable_touch();

        void enable_resize();
        void disable_resize();

    public:

        static View* dummy(const Rect& = { 28, 28 });

    public:

        template <class T>
        T* init_view(T*& view, const Rect& frame) {
            add_subview(view = new T(frame));
            return view;
        }

        template <class T, class ...Args>
        T* init_view(T*& view, Args&&... args) {
            add_subview(view = new T(std::forward<Args>(args) ...));
            return view;
        }

		template<class ...Args>
		void init_views(Args&&... args) {
			(init_view(args), ...);
		}

    };

}
