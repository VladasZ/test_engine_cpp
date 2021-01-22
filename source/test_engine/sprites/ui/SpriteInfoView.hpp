//
//  SpriteInfoView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 09/01/21.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "SpritesInclude.hpp"

#ifdef USING_SPRITES

#include "Sprite.hpp"
#include "CaptionLabel.hpp"


namespace te {

    class SpriteInfoView : public ui::View {

    public:

        using View::View;

        virtual ~SpriteInfoView();

        void set_sprite(sprite::Sprite*);

    protected:

        void setup() override;
        void layout() override;

    private:

        sprite::Sprite* sprite = nullptr;

        ui::CaptionLabel* id_label = nullptr;
        ui::CaptionLabel* position_label = nullptr;
        ui::CaptionLabel* size_label = nullptr;

    };

}

#endif
