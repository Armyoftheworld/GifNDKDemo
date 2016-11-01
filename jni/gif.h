#ifndef _GIF
#define _GIF

#define _GNU_SOURCE 1
#ifdef __clang__
#pragma clang system_header
#pragma clang diagnostic ignored "-Wgnu"
#elif __GNUC__
#pragma GCC system_header
#pragma GCC diagnostic ignored "-Wgnu"
#endif

#include <unistd.h>
#include <jni.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <sys/cdefs.h>
#include <sys/stat.h>
#include <pthread.h>
#include <poll.h>
#include <errno.h>
#include <sys/eventfd.h>
#include <android/log.h>
#ifdef DEBUG
#define  LOG_TAG  "tuch"
#endif
#define  INFO(FORMAT,...)  __android_log_print(ANDROID_LOG_INFO,"tuch",FORMAT,##__VA_ARGS__);

#define TEMP_FAILURE_RETRY(exp) ({         \
    __typeof__(exp) _rc;                   \
    do {                                   \
        _rc = (exp);                       \
    } while (_rc == -1 && errno == EINTR); \
    _rc; })
#define THROW_ON_NONZERO_RESULT(fun, message) if (fun !=0) throwException(env, RUNTIME_EXCEPTION_ERRNO, message)
#define GET_ADDR(bm, width, left, top) bm + top * width + left
#define OOME_MESSAGE "Failed to allocate native memory"
#define DEFAULT_FRAME_DURATION_MS 100

/**
 * Some gif files are not strictly follow 89a.
 * DGifSlurp will return read head error or get record type error.
 * but the image still can display. so here should ignore the error.
 */
//#define STRICT_FORMAT_89A

/**
 * Decoding error - no frames
 */
#define D_GIF_ERR_NO_FRAMES        1000
/**
* Decoding error - invalid GIF screen size
*/
#define D_GIF_ERR_INVALID_SCR_DIMS    1001
/**
* Decoding error - invalid frame size
*/
#define D_GIF_ERR_INVALID_IMG_DIMS    1002
/**
* Decoding error - frame size is greater that screen size
*/
#define D_GIF_ERR_IMG_NOT_CONFINED    1003
/**
* Decoding error - input source rewind failed
*/
#define D_GIF_ERR_REWIND_FAILED    1004
/**
* Decoding error - invalid and/or indirect byte buffer specified
*/
#define D_GIF_ERR_INVALID_BYTE_BUFFER    1005

enum Exception {
	RUNTIME_EXCEPTION_ERRNO, RUNTIME_EXCEPTION_BARE, OUT_OF_MEMORY_ERROR, NULL_POINTER_EXCEPTION
};



#endif
jlong openFile(JNIEnv *env,jstring jfname, jboolean justDecodeMetaData);

jint getHeight(jlong gifInfo);

jint getWidth(jlong gifInfo);

jint renderFrame (jlong gifInfo, jobject jbitmap);
