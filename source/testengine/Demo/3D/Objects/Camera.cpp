
//  Camera.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Camera.hpp"
#include "Size.hpp"
#include "GlobalEvents.hpp"
#include "RootView.hpp"

Camera::Camera() {

	Events::onScreenSizeChange.subscribe([&](ui::Size size) {
		this->_ratio = size.ratio();
	});

	settingsView->onFov.subscribe([&](float fov) {
		this->_fov = fov * 2;
	});
    
    settingsView->onNear.subscribe([&](float near) {
        this->_near = -1 + near * 2;
    });
    
    settingsView->onFar.subscribe([&](float far) {
        this->_far = far * 100;
    });

}

const Matrix4& Camera::mvp() {

	_mvp = Matrix4::perspective(_fov, _ratio, _near, _far);

	return _mvp;
}
