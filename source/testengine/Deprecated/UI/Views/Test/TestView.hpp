//
//  TestView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/04/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"

class TestView : public OldView {
    
public:

	using OldView::OldView;

	void setup() override;
};
