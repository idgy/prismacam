/* Copyright 2016 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "vr/gvr/demos/treasure_hunt/jni/prisma_cam_renderer.h"

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







