package com.example.uzakreuskis.testengine;

import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private GLSurfaceView mGLView;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Create a GLSurfaceView instance and set it
        // as the ContentView for this Activity.
        mGLView = new MyGLSurfaceView(this);
        setContentView(mGLView);

        Log.d("", "onCreate: " + getHello());
        sayHello();
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {

        mGLView.queueEvent(new Runnable() {
            @Override
            public void run() {
                callGL();
            }
        });

        return super.onTouchEvent(event);
    }

    static {
        System.loadLibrary("native-lib");
    }

    public native String getHello();
    public native void sayHello();
    public native void callGL();

}
