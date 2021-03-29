//
//  Window.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Scene.hpp"
#include "Target.hpp"
#include "RootView.hpp"
#include "DebugInfoView.hpp"
#include "SpritesInclude.hpp"


namespace te {

	class Screen {

		void _initialize_ui();

		scene::Scene* _scene = nullptr;

		ui::View* _view  = nullptr;

#ifdef USING_SPRITES
		sprite::Level* _level = nullptr;
#endif

		RootView* _root_view = nullptr;

	public:

		static inline int FPS = 0;
		static inline float frame_time = 0;
		static inline int frames_drawn = 0;

		static inline gm::Size size;

		static inline gm::Color clear_color;

		static inline Screen* current = nullptr;

		static float render_scale();

	public:

		static inline DebugInfoView* debug_view = nullptr;

	public:

		Screen(const gm::Size&);
		~Screen();
		
#ifdef DESKTOP_BUILD
		void start_main_loop();
#endif

		void update() const;

		void setup_input();

		void set_size(const gm::Size&) const;

	public:

		void set_scene(scene::Scene*);
		scene::Scene* scene() const;

		void set_view(ui::View*);
		ui::View* view() const;

#ifdef USING_SPRITES
		void set_level(sprite::Level*);
		sprite::Level* level() const;
#endif

		te::RootView* root_view() const;

	};

}
