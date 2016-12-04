

#ifndef TREASUREHUNT_APP_SRC_MAIN_JNI_TREASUREHUNTRENDERER_H_  // NOLINT
#define TREASUREHUNT_APP_SRC_MAIN_JNI_TREASUREHUNTRENDERER_H_  // NOLINT

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <jni.h>

#include <memory>
#include <string>
#include <thread>  // NOLINT
#include <vector>

#include "vr/gvr/capi/include/gvr.h"
#include "vr/gvr/capi/include/gvr_types.h"

class PrismaCamRenderer {
 public:

  PrismaCamRenderer(gvr_context* gvr_context);
  ~PrismaCamRenderer();

  void InitializeGl();

  void DrawFrame();
  void OnTriggerEvent();
  void OnPause();
  void OnResume();

private:

  std::unique_ptr<gvr::GvrApi> gvr_api_;

};

#endif  // TREASUREHUNT_APP_SRC_MAIN_JNI_TREASUREHUNTRENDERER_H_  // NOLINT
