#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG(__message) __android_log_write(ANDROID_LOG_INFO, "", __message);

#define FUN(__returnType, name___) extern "C" JNIEXPORT __returnType JNICALL Java_com_example_uzakreuskis_testengine_MainActivity_##name___ (JNIEnv *env, jobject /* this */)

FUN(jstring, getHello) {
    std::string hello = "Hello from C++ 22234";
    return env->NewStringUTF(hello.c_str());
}

FUN(void, sayHello) {

    __android_log_write(ANDROID_LOG_DEBUG, "", "spes");

    LOG("Hellloooww heeeloooyyww");
}