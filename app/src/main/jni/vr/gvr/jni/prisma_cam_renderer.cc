
#include "vr/gvr/jni/prisma_cam_renderer.h"

#include <android/log.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <random>

#define LOG_TAG "TreasureHuntCPP"
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)



PrismaCamRenderer::PrismaCamRenderer(
    gvr_context* gvr_context)
    : gvr_api_(gvr::GvrApi::WrapNonOwned(gvr_context))

{}


PrismaCamRenderer::~PrismaCamRenderer() {

}

void PrismaCamRenderer::InitializeGl() {
  gvr_api_->InitializeGl();
}

void PrismaCamRenderer::DrawFrame() {

}



void PrismaCamRenderer::OnTriggerEvent() {

}

void PrismaCamRenderer::OnPause() {
  gvr_api_->PauseTracking();
}

void PrismaCamRenderer::OnResume() {
  gvr_api_->RefreshViewerProfile();
  gvr_api_->ResumeTracking();
}







