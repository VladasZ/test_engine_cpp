package com.example.test_engine;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.Window;
import android.view.WindowManager;
import android.widget.TextView;
import android.view.MotionEvent;


import android.content.res.AssetManager;

public class MainActivity extends Activity {

    private MyGLSurfaceView gLView;

    static { System.loadLibrary("native-lib"); }

    private AssetManager asset_manager = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        gLView = new MyGLSurfaceView(this);
        setContentView(gLView);

        asset_manager = getResources().getAssets();
        setAssetManager(asset_manager);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        return super.onTouchEvent(event);
    }


    public native void setAssetManager(AssetManager assManager);

}
