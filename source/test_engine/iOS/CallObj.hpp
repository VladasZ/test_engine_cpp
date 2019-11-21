//
//  CallObj.h
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/19/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>
#include <vector>

namespace obj_c {
    
    using strings = std::vector<std::string>;
    
    extern const std::string work_directory_path;
    
    void show_alert(const std::string& message);
    strings ls(const std::string& path);
}
