/*
 * Copyright 2014 Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.projecttango.examples.cpp.hellovideo;

import android.app.Activity;
import android.content.ComponentName;
import android.content.ServiceConnection;
import android.hardware.Camera;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.os.IBinder;
import android.view.Display;
import android.util.DisplayMetrics;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.WindowManager;
import android.widget.ToggleButton;

import com.projecttango.examples.cpp.util.TangoInitializationHelper;

/**
 * Main activity shows video overlay scene.
 */
public class HelloVideoActivity extends Activity {
    private static final int CAMERA_ID = 0;

    private GLSurfaceView mSurfaceView;
    private ToggleButton mFilterOn;

    private ServiceConnection mTangoServiceCoonnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder binder) {
            TangoJniNative.onTangoServiceConnected(binder);
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {
            // Handle this if you need to gracefully shutdown/retry
            // in the event that Tango itself crashes/gets upgraded while running.
        }
    };

    private static final int MY_CAMERA_REQUEST_CODE = 100;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);


        if (checkSelfPermission(android.Manifest.permission.CAMERA) != android.content.pm.PackageManager.PERMISSION_GRANTED)
        {
            requestPermissions(new String[]{android.Manifest.permission.CAMERA}, MY_CAMERA_REQUEST_CODE);
        }

        /* Check the current screen rotation and set it to the renderer. */
        WindowManager windowManager = (WindowManager) getSystemService(WINDOW_SERVICE);
        Display display = windowManager.getDefaultDisplay();

        //todo: use Camera2 + CameraCharacteristics + CameraManager
        Camera.CameraInfo info = new Camera.CameraInfo();
        Camera.getCameraInfo(CAMERA_ID, info);

        TangoJniNative.onCreate(this, display.getRotation(), info.orientation);

        // Configure OpenGL renderer
        mSurfaceView = (GLSurfaceView) findViewById(R.id.surfaceview);
        mSurfaceView.setEGLContextClientVersion(2);
        mSurfaceView.setRenderer(new HelloVideoRenderer(true));

        mFilterOn = (ToggleButton) findViewById(R.id.filter_on);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if(item.isCheckable()){

            item.setChecked(!item.isChecked());
            TangoJniNative.SetDoubling(item.isChecked());
        }

        return true;
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    protected void onResume() {
        super.onResume();
        mSurfaceView.onResume();
        TangoInitializationHelper.bindTangoService(this, mTangoServiceCoonnection);
        TangoJniNative.setYuvMethod(mFilterOn.isChecked());
    }

    @Override
    protected void onPause() {
        super.onPause();
        mSurfaceView.onPause();
       TangoJniNative.onPause();
        unbindService(mTangoServiceCoonnection);
    }

    /**
     * The render mode toggle button was pressed.
     */
    public void renderModeClicked(View view) {
        TangoJniNative.setYuvMethod(mFilterOn.isChecked());
    }

    public void toRightClicked(View view) {
        TangoJniNative.AdjustMiddleStart(false);
    }

    public void toLeftClicked(View view) {
        TangoJniNative.AdjustMiddleStart(true);
    }
}
