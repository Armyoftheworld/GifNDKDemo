#include "com_army_gifdemo_GifHandler.h"
#include "gifnative.h"

JNIEXPORT jlong JNICALL Java_com_army_gifdemo_GifHandler_openGif(JNIEnv *env,
		jobject obj, jstring path) {
	jlong infos = openFile(env, path, JNI_FALSE);
	return infos;
}

JNIEXPORT jint JNICALL Java_com_army_gifdemo_GifHandler_getWidth(JNIEnv *env,
		jobject obj, jlong gifInfoPro) {
	return getWidth(gifInfoPro);
}

JNIEXPORT jint JNICALL Java_com_army_gifdemo_GifHandler_getHeight(JNIEnv *env,
		jobject obj, jlong gifInfoPro) {
	return getHeight(gifInfoPro);
}

JNIEXPORT jlong JNICALL Java_com_army_gifdemo_GifHandler_renderFrame(
		JNIEnv *env, jobject obj, jlong gifInfoPro, jobject frameBuffer) {
	return renderFrame(env,gifInfoPro,frameBuffer);
}
