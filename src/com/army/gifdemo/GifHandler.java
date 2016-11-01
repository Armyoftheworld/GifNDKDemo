package com.army.gifdemo;

import android.graphics.Bitmap;

public class GifHandler {
	public long gifInfoPro;
	static {
		System.loadLibrary("GIFEngine");
		System.loadLibrary("gifmain");
	}

	public GifHandler(String path) {
		gifInfoPro = openGif(path);
	}

	public native long openGif(String path);

	public native int getWidth(long gifInfoPro);

	public native int getHeight(long gifInfoPro);
	
	public native long renderFrame(long gifInfoPro, Bitmap frameBuffer);
}
