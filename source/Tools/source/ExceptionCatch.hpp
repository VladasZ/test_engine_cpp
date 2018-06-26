//
//  ExceptionCatch.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 6/26/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "String.hpp"

String what(const std::exception_ptr &eptr = std::current_exception());
