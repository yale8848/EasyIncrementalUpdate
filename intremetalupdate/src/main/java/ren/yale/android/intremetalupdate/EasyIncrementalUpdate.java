package ren.yale.android.intremetalupdate;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;

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



    public static String getApkSourceDir(Context context){
        try {
            ApplicationInfo appInfo = context.getApplicationContext().getPackageManager()
                    .getApplicationInfo(context.getApplicationContext().getPackageName(), 0);
            return appInfo.sourceDir;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return "";
    }

    /**
     * @param context
     * @param newApkPath
     * @param patchApkPath
     * @return
     */
    public synchronized static  boolean patch(Context context,String newApkPath, String patchApkPath){
        return patch(getApkSourceDir(context),newApkPath,patchApkPath);
    }
}
