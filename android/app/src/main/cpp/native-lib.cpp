
#include <string>
#include <thread>

#include <jni.h>
#include <android/asset_manager_jni.h>

#include "File.hpp"
#include "Paths.hpp"
#include "Assets.hpp"
#include "Screen.hpp"
#include "System.hpp"
#include "GLDebug.hpp"
#include "Dispatch.hpp"
#include "AndroidSystem.hpp"
#include "OpenGLHeaders.hpp"
#include "ExceptionCatch.hpp"

#import "Input.hpp"
#import "Screen.hpp"
#import "GLWrapper.hpp"
#import "TestScene.hpp"
#import "TestLevel.hpp"
#import "SelectionView.hpp"

te::Screen* _screen;

using namespace cu;
using namespace gm;
using namespace te;


extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MyGLRenderer_setup(JNIEnv* env, jobject) {

    static bool not_first_call = false;

    if (not_first_call) {
        return;
    }

    not_first_call = true;

    GL::on_window_size_change({ 1000,
                                1000 });

    _screen = new te::Screen({ 1000,
                               1000 });

   // _screen->set_scene(new TestScene());
#ifndef NO_BOX2D
   // _screen->set_level(new TestLevel());
#endif
    _screen->set_view(new SelectionView());

}

extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MyGLRenderer_update(JNIEnv* env, jobject) {
      _screen->update();
    //GL::set_clear_color(gm::Color::turquoise);
   // GL::clear();
    //GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
//    glBegin();
//    glEnd();
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MyGLRenderer_setScreenSize(JNIEnv* env, jobject, jint width, jint height) {
    _screen->set_size({ width, height });
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MainActivity_setAssetManager(JNIEnv* env, jobject, jobject asset_manager) {

    AAssetManager* manager = nullptr;
    std::string error;

    try {
        manager = AAssetManager_fromJava(env, asset_manager);
    }
    catch (...) {
        error = what();
        Fatal(error);
    }

    if (manager == nullptr) {
        Fatal("Failed to get asset manager.");
    }

    AndroidSystem::set_asset_manager(manager);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MainActivity_touchBegan(JNIEnv *env, jobject, jfloat x, jfloat y, jint id) {
    cu::Dispatch::on_main([=]{
        ui::Input::process_touch_event(new ui::Touch(id, {x, y}, ui::Touch::Began));
    });
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MainActivity_touchMoved(JNIEnv *env, jobject, jfloat x, jfloat y, jint id) {
    cu::Dispatch::on_main([=]{
        ui::Input::process_touch_event(new ui::Touch(id, {x, y}, ui::Touch::Moved));
    });
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_test_1engine_MainActivity_touchEnded(JNIEnv *env, jobject, jfloat x, jfloat y, jint id) {
    cu::Dispatch::on_main([=]{
        ui::Input::process_touch_event(new ui::Touch(id, {x, y}, ui::Touch::Ended));
    });
}