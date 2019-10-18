#pragma once

#include <iostream>
#include "../jni/com_github_timmyovo_winglobalhotkey_WinGlobalHotkeyAPI.h"
#include <thread>
#include <Windows.h>
#include <map>

using namespace std;

JavaVM* jvm;
JNIEnv* globalEnv;

void java_println(JNIEnv* env,const char* c) {
	jclass syscls = env->FindClass("java/lang/System");
	jfieldID fid = env->GetStaticFieldID(syscls, "out", "Ljava/io/PrintStream;");
	jobject out = env->GetStaticObjectField(syscls, fid);
	jclass pscls = env->FindClass("java/io/PrintStream");
	jmethodID mid = env->GetMethodID(pscls, "println", "(Ljava/lang/String;)V");
	jstring str = env->NewStringUTF(c);
	env->CallVoidMethod(out, mid, str);
}

JNIEnv* getJNIEnvFromVM(JavaVM* vm) {
	JNIEnv* env = NULL;
	jint ret = vm->GetEnv((void**)&env, JNI_VERSION_1_6);
	if (env == nullptr) {
		cout << "Get JNIEnv* Failed." << endl << fflush;
	}
	return env;
}

void callback();