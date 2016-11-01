package com.army.gifdemo;

import java.io.File;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.support.v4.app.ActivityCompat;
import android.widget.ImageView;

public class MainActivity extends Activity implements ActivityCompat.OnRequestPermissionsResultCallback {
	private ImageView gif;
	private GifHandler gifHandler;
	private Bitmap bitmap;
	private Handler handler = new Handler() {
		public void handleMessage(android.os.Message msg) {
			long nextTime = gifHandler.renderFrame(gifHandler.gifInfoPro, bitmap);
			gif.setImageBitmap(bitmap);
			sendEmptyMessageDelayed(0, nextTime);
		};
	};

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		gif = (ImageView) findViewById(R.id.gif);
		if (ActivityCompat.checkSelfPermission(this,
				Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
			ActivityCompat.requestPermissions(this, new String[] { Manifest.permission.READ_EXTERNAL_STORAGE }, 20);
			return;
		}
		gifHandler = new GifHandler(new File(Environment.getExternalStorageDirectory(), "image.gif").getAbsolutePath());
		int width = gifHandler.getWidth(gifHandler.gifInfoPro);
		int height = gifHandler.getHeight(gifHandler.gifInfoPro);
		bitmap = Bitmap.createBitmap(width, height, Config.ARGB_8888);
		long nextTime = gifHandler.renderFrame(gifHandler.gifInfoPro, bitmap);
		gif.setImageBitmap(bitmap);
		handler.sendEmptyMessageDelayed(0, nextTime);
	}

	@Override
	public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
		if (requestCode == 20 && grantResults != null && grantResults.length > 0) {
			if (grantResults[0] == PackageManager.PERMISSION_GRANTED) {
				gifHandler = new GifHandler(
						new File(Environment.getExternalStorageDirectory(), "image.gif").getAbsolutePath());
				int width = gifHandler.getWidth(gifHandler.gifInfoPro);
				int height = gifHandler.getHeight(gifHandler.gifInfoPro);
				bitmap = Bitmap.createBitmap(width, height, Config.ARGB_8888);
				long nextTime = gifHandler.renderFrame(gifHandler.gifInfoPro, bitmap);
				gif.setImageBitmap(bitmap);
				handler.sendEmptyMessageDelayed(0, nextTime);
			}
		}
	}
}
