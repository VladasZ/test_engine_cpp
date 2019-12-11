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

public class MainActivity extends Activity implements SurfaceHolder.Callback {


    private MyGLSurfaceView gLView;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private AssetManager asset_manager = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        gLView = new MyGLSurfaceView(this);
        setContentView(gLView);

      //  asset_manager = getResources().getAssets();
      //  setAssetManager(asset_manager);

      //  test();
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        return super.onTouchEvent(event);
    }

    @Override
    public void surfaceCreated(SurfaceHolder surfaceHolder) {
    }

    @Override
    public void surfaceChanged(SurfaceHolder surfaceHolder, int i, int w, int h) {
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder surfaceHolder) {
    }


    public native void test();
    public native void setAssetManager(AssetManager assManager);

}
