
#include <string>

#include <jni.h>
#include <android/asset_manager_jni.h>

#include "File.hpp"
#include "Paths.hpp"
#include "Screen.hpp"
#include "System.hpp"
#include "AndroidSystem.hpp"
#include "ExceptionCatch.hpp"

using namespace cu;
using namespace gm;
using namespace te;


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_test_1engine_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject) {
    std::string hello = "Hello from C++\n";

    Vector3 vec3 = { 1, 2, 3 };

    __android_log_print(ANDROID_LOG_DEBUG, "TestEngine", "LALALALALLAA");

    hello += Paths::Shaders::ui() + "\n";
    hello += Paths::Shaders::ui() / "ko" / "sopok" / "\n";

   // auto file = File("ic_launcher_background.xml");

  //  hello += file.size();

    hello += System::user_name();
    hello += vec3.to_string();
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MainActivity_setAssetManager(
        JNIEnv* env,
        jobject,
        jobject asset_manager) {

    AAssetManager* manager = nullptr;
    std::string error;

    try {
        manager = AAssetManager_fromJava(env, asset_manager);
    }
    catch (...) {
        error = what();
    }

    if (manager == nullptr) {
        throw std::runtime_error("Failed to set asset manager.");
    }

    AndroidSystem::set_asset_manager(manager);
}
