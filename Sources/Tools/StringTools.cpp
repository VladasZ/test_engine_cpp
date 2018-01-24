//
//  StringTools.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//


string StringTools::fileName(string path) {
    
#ifdef WINDOWS
	auto lastSlash = path.rfind('\\');
#else
	auto lastSlash = path.rfind('/');
#endif
    
    if(string::npos != lastSlash) {
        return removeExtension(path.substr(lastSlash + 1, path.size()));
    } else {
        return path;
    }
}

string StringTools::removeExtension(string source) {
    
    auto dot = source.rfind('.');
    
    if(string::npos != dot) { return source.substr(0, dot); }
	else { return source; }
}
