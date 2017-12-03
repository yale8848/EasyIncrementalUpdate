package ren.yale.android.intremetalupdate;

/**
 * Created by yale on 2017/12/3.
 */

public class EasyIncrementalUpdate {

    static {
        System.loadLibrary("native-lib");
    }
    public synchronized static native boolean patch(String oldFilePath, String newFilePath, String patchPath);
}
