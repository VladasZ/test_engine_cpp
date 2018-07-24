//
//  ThreadPool.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/20/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <thread>
#include <memory>

#include "Macro.hpp"
#include "Array.hpp"

class ThreadPool {

public:

    using Thread = std::thread;
    using ThreadPtr = std::shared_ptr<Thread>;
    using ThreadArray = Array<ThreadPtr>;


    ThreadArray threads;


    ThreadPool(int numberOfThreads) {

        FOR(numberOfThreads) {

        }
    }
};
