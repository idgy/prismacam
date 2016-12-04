

#ifndef PRISMA_CAM_RENDERER_H__  // NOLINT
#define PRISMA_CAM_RENDERER_H__  // NOLINT

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <jni.h>

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

#endif  // PRISMA_CAM_RENDERER_H__  // NOLINT
