
#include <android/log.h>
#include <jni.h>

#include <memory>

#include "vr/gvr/capi/include/gvr.h"
#include "vr/gvr/jni/prisma_cam_renderer.h"

#define JNI_METHOD(return_type, method_name) \
  JNIEXPORT return_type JNICALL              \
      Java_com_google_vr_ndk_samples_prisma_1cam_MainActivity_##method_name

namespace {

inline jlong jptr(PrismaCamRenderer *native_prisma_cam) {
  return reinterpret_cast<intptr_t>(native_prisma_cam);
}

inline PrismaCamRenderer *native(jlong ptr) {
  return reinterpret_cast<PrismaCamRenderer *>(ptr);
}
}  // anonymous namespace

extern "C" {

JNI_METHOD(jlong, nativeCreateRenderer)(JNIEnv *env, jclass clazz,
                                        jobject class_loader,
                                        jobject android_context,
                                        jlong native_gvr_api) {

  return jptr(
      new PrismaCamRenderer(reinterpret_cast<gvr_context *>(native_gvr_api)));
}

JNI_METHOD(void, nativeDestroyRenderer)
(JNIEnv *env, jclass clazz, jlong native_treasure_hunt) {
  delete native(native_treasure_hunt);
}

JNI_METHOD(void, nativeInitializeGl)(JNIEnv *env, jobject obj,
                                     jlong native_prisma_cam) {
  native(native_prisma_cam)->InitializeGl();
}

JNI_METHOD(void, nativeDrawFrame)(JNIEnv *env, jobject obj,
                                  jlong native_prisma_cam) {
  native(native_prisma_cam)->DrawFrame();
}

JNI_METHOD(void, nativeOnTriggerEvent)(JNIEnv *env, jobject obj,
                                       jlong native_prisma_cam) {
  native(native_prisma_cam)->OnTriggerEvent();
}

JNI_METHOD(void, nativeOnPause)(JNIEnv *env, jobject obj,
                                jlong native_prisma_cam) {
  native(native_prisma_cam)->OnPause();
}

JNI_METHOD(void, nativeOnResume)(JNIEnv *env, jobject obj,
                                 jlong native_prisma_cam) {
  native(native_prisma_cam)->OnResume();
}

}  // extern "C"
