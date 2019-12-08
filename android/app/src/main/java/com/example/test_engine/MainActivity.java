package com.example.test_engine;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import android.view.MotionEvent;


import android.content.res.AssetManager;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private AssetManager asset_manager = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String dataPath = getFilesDir().getPath() + "/";
        asset_manager = getResources().getAssets();

        Log.d("TestEngine", "lalalal");
        Log.d("TestEngine", asset_manager.toString());


        setAssetManager(asset_manager);

        Log.d("TestEngine", dataPath);
        Log.d("TestEngine", "lalalal");

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        return super.onTouchEvent(event);
    }


    public native String stringFromJNI();
    public native void setAssetManager(AssetManager assManager);

}
