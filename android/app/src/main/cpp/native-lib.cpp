
#include <string>
#include <thread>

#include <jni.h>
#include <android/asset_manager_jni.h>

#include "File.hpp"
#include "Paths.hpp"
#include "Assets.hpp"
#include "Screen.hpp"
#include "System.hpp"
#include "AndroidSystem.hpp"
#include "ExceptionCatch.hpp"

#import "Input.hpp"
#import "Screen.hpp"
#import "TestView.hpp"
#import "GLWrapper.hpp"
#import "TestScene.hpp"
#import "TestLevel.hpp"

te::Screen* _screen;

using namespace cu;
using namespace gm;
using namespace te;


std::thread gl_thread;

void start() {

    Log("Hello");


    GL::on_window_size_change({ 500,
                                500 });

    _screen = new te::Screen({ 500,
                               500 });

    _screen->set_scene(new TestScene());
#ifndef NO_BOX2D
    _screen->set_level(new TestLevel());
#endif
    _screen->set_view(new TestView());

    while(true) {
        _screen->update();
    }
}


extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MainActivity_test(
        JNIEnv* env,
        jobject) {
    std::string hello;

    gl_thread = std::thread(start);

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
