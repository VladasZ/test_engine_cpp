//
//  ResearchScreen.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 05/02/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#include "ResearchView.hpp"
#include "ResearchScene.hpp"
#include "ResearchScreen.hpp"

using namespace te;
using namespace gm;


ResearchScreen::ResearchScreen(const Size& size) : Screen(size){
    clear_color = gm::Color::gray;
    set_view(new ResearchView);
    set_scene(new ResearchScene);
}

