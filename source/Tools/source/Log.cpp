//
//  Log.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/01/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <string>

#include "Log.hpp"

using namespace std;

static string basename(const string& filename)
{
	if (filename.empty()) return "";

	auto len = filename.length();
	auto index = filename.find_last_of("/\\");

	if (index == std::string::npos) return filename;

	if (index + 1 >= len) {
		len--;
		index = filename.substr(0, len).find_last_of("/\\");
		if (len == 0) return filename;
		if (index == 0) return filename.substr(1, len - 1);
		if (index == string::npos) return filename.substr(0, len);
		return filename.substr(index + 1, len - index - 1);
	}

	return filename.substr(index + 1, len - index);
}

string __getFileName(const char* path) {
	return basename(path);
}