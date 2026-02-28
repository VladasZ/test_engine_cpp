//
//  ViewPlacer.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 22/01/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#pragma once

#include "ui.hpp"
#include "MetaHelpers.hpp"


namespace ui {

	class View;

	class ViewPlacer {
	public:

		explicit ViewPlacer(View*);

	public:

		void set_center(const Point&) const;
		void as(View*) const;

		void as_background() const;

		void at_center() const;
		void center_ver() const;
		void center_hor() const;

		void at_bottom(float margin = 0) const;

		void l(float margin = 0) const;
		void r(float margin = 0) const;

		void br(float margin = 0) const;
		void bl(float margin = 0) const;
		void tr(float margin = 0) const;

		void place_at_left_half(bool preserve_height = false) const;
		void place_at_right_half(bool preserve_height = false) const;
		void place_at_top_half() const;
		void place_at_bottom_half() const;

		void same_height(View*) const;

		void to(View* view, Edge edge, float margin = 0, Edge alignment = Edge::Center) const;

		template <class Container>
		void array_hor(const Container& container) {
			auto width = _frame.size.width / container.size();
			for (int i = 0; i < container.size(); i++)
				container[i]->edit_frame() = { i * width, 0, width, _frame.size.height };
		}

		template <bool save_y = false, class ...Views, size_t size = sizeof...(Views)>
		void hor(Views& ... views) {
			auto width = _frame.size.width / size;
			auto tuple = std::forward_as_tuple(views...);
			cu::static_for<size>([&](auto i) {
				auto& frame = std::get<i>(tuple)->edit_frame();
				if constexpr (save_y) {
					frame = { i * width, frame.origin.y, width, frame.size.height };
				}
				else {
					frame = { i * width, 0, width, _frame.size.height };
				}
			});
		}

		template <bool save_y = false, class ...Views, size_t size = sizeof...(Views)>
		void hor(const std::array<float, size>& ratio, Views& ... views) {
			auto tuple = std::forward_as_tuple(views...);
			auto total_ratio = 1.0f / cu::container::summ(ratio);
			cu::static_for<size>([&](auto i) {
				constexpr bool is_first = i == 0;
				auto x_pos = is_first ? 0 : std::get<is_first ? 0 : i - 1>(tuple)->max_x();
				auto& frame = std::get<i>(tuple)->edit_frame();
				if constexpr (save_y) {
					frame = { x_pos, frame.origin.y, ratio[i] * _frame.size.width * total_ratio, frame.size.height };
				}
				else {
					frame = { x_pos, 0, ratio[i] * _frame.size.width * total_ratio, _frame.size.height };
				}
			});
		}

		template <class ...Views, size_t size = sizeof...(Views)>
		void ver(Views&... views) {
			auto height = _frame.size.height / size;
			auto tuple = std::forward_as_tuple(views...);
			cu::static_for<size>([&](auto i) {
				std::get<i>(tuple)->edit_frame() =
				{ 0, i * height, _frame.size.width, height, };
			});
		}

		template <class ...Views, size_t size = sizeof...(Views)>
		void ver(const std::array<float, size>& ratio, Views& ... views) {
			auto tuple = std::forward_as_tuple(views...);
			auto total_ratio = 1.0f / cu::container::summ(ratio);
			cu::static_for<size>([&](auto i) {
				constexpr bool is_first = i == 0;
				auto y_pos = is_first ? 0 : std::get<is_first ? 0 : i - 1>(tuple)->max_y();
				std::get<i>(tuple)->edit_frame() =
				{ 0, y_pos, _frame.size.width, ratio[i] * _frame.size.height * total_ratio, };
			});
		}

	private:

		Rect& _frame;
		View* _view = nullptr;

	};

}