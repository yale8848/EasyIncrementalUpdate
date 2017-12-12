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

    /**
     * @param oldApkPath old apk path
     * @param newApkPath  new created apk path
     * @param patchApkPath patch apk path
     * @return
     */
    public synchronized static native boolean patch(String oldApkPath, String newApkPath, String patchApkPath);

    /**
     * @param context
     * @param newApkPath
     * @param patchApkPath
     * @return
     */
    public synchronized static  boolean patch(Context context,String newApkPath, String patchApkPath){
        try {
            ApplicationInfo appInfo = context.getApplicationContext().getPackageManager()
                    .getApplicationInfo(context.getApplicationContext().getPackageName(), 0);
            return patch(appInfo.sourceDir,newApkPath,patchApkPath);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
}
