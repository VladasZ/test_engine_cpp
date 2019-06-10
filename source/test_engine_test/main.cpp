
#ifndef IOS_BUILD

#include "TestView.hpp"
#include "TestScene.hpp"
#include "TestEngine.hpp"

int main() {
    TestEngine::start_with_scene<TestScene>();
    return 0;
}

#endif
