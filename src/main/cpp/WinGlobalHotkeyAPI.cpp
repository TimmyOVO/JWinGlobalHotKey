#include "jni/com_github_timmyovo_winglobalhotkey_WinGlobalHotkeyAPI.h"
#include "include/WinGlobalHotkeyAPI.h"
#include <future>

JNIEXPORT void JNICALL Java_com_github_timmyovo_winglobalhotkey_WinGlobalHotkeyAPI_registerHotkey
(JNIEnv* env, jclass, jint vk, jobject jobj) {
	cout << vk << endl << fflush;
	thread wait_thread([&]() {
		RegisterHotKey(NULL, vk, 0, (UINT)vk);
		MSG msg = { 0 };

		while (GetMessage(&msg, NULL, 0, 0) != FALSE) {
			if (msg.message == WM_HOTKEY) {
				
				
				if (vk == msg.wParam) {
					jvm->AttachCurrentThread((void**)& globalEnv, nullptr);
					jclass runnableClass = globalEnv->FindClass("java/lang/Runnable");
					jmethodID runMethod = globalEnv->GetMethodID(runnableClass, "run", "()V");
					globalEnv->CallObjectMethod(jobj, runMethod);
					jvm->DetachCurrentThread();
					break;
				}
				
			}
		}

		UnregisterHotKey(NULL, vk);
		});
	wait_thread.join();
}

//override onload method
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM* vm, void* reserved) {

	auto env = getJNIEnvFromVM(vm);
	jvm = vm;
	globalEnv = env;
	java_println(env, "WinGlobalHotKey native library loaded.");
	
	return JNI_VERSION_1_6;
}

void callback(int vk) {

}