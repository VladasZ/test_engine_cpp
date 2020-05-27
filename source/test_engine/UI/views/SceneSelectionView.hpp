//
//  SceneSelectionView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 19/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Screen.hpp"
#include "PopupView.hpp"


namespace te {

    class SceneSelectionView : public ui::PopupView {

    public:

        using PopupView::PopupView;

        template <class Scene>
        void add_scene() {
            add_action(cu::class_name<Scene>, [&] {
                Screen::current->set_scene(new Scene());
            });
        }

    };

}
