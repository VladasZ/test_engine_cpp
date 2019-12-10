
#include <string>

#include <jni.h>
#include <android/asset_manager_jni.h>

#include "File.hpp"
#include "Paths.hpp"
#include "Assets.hpp"
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
    std::string hello;

    auto file = File("Fonts/OpenSans.ttf");

    hello += file.to_string();

    hello += System::user_name();

    auto path = Paths::Shaders::ui() / "ui.vert";

    Log(path);

    Log(File::read_to_string(path));

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
