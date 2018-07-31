//
//  String.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "String.hpp"

String operator "" _s(const char *in, size_t size) { return String(in); }
String operator "" _s(unsigned long long in) { return String(in); }
