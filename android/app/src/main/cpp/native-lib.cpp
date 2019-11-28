#include <jni.h>
#include <string>

#include "Screen.hpp"
#include "System.hpp"
#include "Vector3.hpp"

using namespace cu;
using namespace gm;


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    Vector3 vec3 = { 1, 2, 3 };

    auto _screen = new te::Screen({ 100, 100 });

    hello += System::user_name();
    hello += vec3.to_string();
    return env->NewStringUTF(hello.c_str());
}
