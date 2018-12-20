
//  Camera.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Camera.hpp"
#include "Size.hpp"
#include "GlobalEvents.hpp"

Camera::Camera() {

	Events::on_screen_size_change.subscribe([&](ui::Size size) {
		this->_ratio = size.ratio();
	});

}

const Matrix4& Camera::mvp() {

	_mvp = Matrix4::perspective(_fov, _ratio, _near, _far);

	return _mvp;
}
