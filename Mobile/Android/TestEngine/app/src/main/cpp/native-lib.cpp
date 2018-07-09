#include <jni.h>
#include <string>
#include <android/log.h>
#include <GLES2/gl2.h>

#define LOG(__message) __android_log_write(ANDROID_LOG_DEBUG, "", __message);

#define FUN(__returnType, name___) extern "C" JNIEXPORT __returnType JNICALL Java_com_example_uzakreuskis_testengine_MainActivity_##name___ (JNIEnv *env, jobject /* this */)
#define FUN_RE(__returnType, name___) extern "C" JNIEXPORT __returnType JNICALL Java_com_example_uzakreuskis_testengine_MyGLRenderer_##name___ (JNIEnv *env, jobject /* this */)

FUN(jstring, getHello) {
    std::string hello = "Hello from C++ 22234";
    return env->NewStringUTF(hello.c_str());
}

FUN(void, sayHello) {
    LOG("Hellloooww heeeloooyyww");
}


FUN(void, callGL) {

    static bool shme = true;

    if (shme) {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        shme = false;
    }
    else {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        shme = true;
    }

}
