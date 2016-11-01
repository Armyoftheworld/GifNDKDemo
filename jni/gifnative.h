#include <jni.h>
jlong openFile(JNIEnv *env,jstring jfname, jboolean justDecodeMetaData);

jint getHeight(jlong gifInfo);

jint getWidth(jlong gifInfo);

jlong renderFrame (JNIEnv *env,jlong gifInfo, jobject jbitmap);
