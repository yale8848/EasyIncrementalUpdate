package ren.yale.android.intremetalupdate;

import android.content.Context;
import android.content.pm.ApplicationInfo;

/**
 * Created by yale on 2017/12/3.
 */

public class EasyIncrementalUpdate {

    static {
        System.loadLibrary("eiu-bspatch");
    }
    public synchronized static native boolean patch(String oldApkPath, String newApkPath, String patchApkPath);

    public synchronized static  boolean patch(Context context,String newApkPath, String patchApkPath){
        try {
            ApplicationInfo appInfo = context.getPackageManager()
                    .getApplicationInfo(context.getPackageName(), 0);
            return patch(appInfo.sourceDir,newApkPath,patchApkPath);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
}
