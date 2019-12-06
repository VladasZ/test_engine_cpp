#include <jni.h>
#include <string>

#include "Screen.hpp"
#include "System.hpp"
#include "Vector3.hpp"
#include "File.hpp"
#include "Paths.hpp"

using namespace cu;
using namespace gm;
using namespace te;


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_test_1engine_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++\n";

    Vector3 vec3 = { 1, 2, 3 };

    hello += Paths::Shaders::ui() + "\n";
    hello += Paths::Shaders::ui() / "ko" / "sopok" / "\n";

    auto file = File("ic_launcher_background.xml");

    hello += file.size();

    hello += System::user_name();
    hello += vec3.to_string();
    return env->NewStringUTF(hello.c_str());
}
