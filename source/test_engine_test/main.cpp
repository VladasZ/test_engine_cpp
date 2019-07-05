
#ifndef IOS_BUILD

#include "Log.hpp"
#include "TestView.hpp"
#include "TestScene.hpp"
#include "TestEngine.hpp"

#include "Utils.hpp"

int main() {


    const char* spes;

    using StringLiteral = decltype ("spes");

    /*Info((cu::is_string<StringLiteral>));


    Info(cu::type_name<cu::ArrayType<StringLiteral>>);
*/
  //  return 0;

    TestEngine::start_with_scene<TestScene>();
    return 0;
}

#endif
