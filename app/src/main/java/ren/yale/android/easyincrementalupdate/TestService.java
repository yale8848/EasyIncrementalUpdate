package ren.yale.android.easyincrementalupdate;

import android.app.Service;
import android.content.Intent;
import android.net.Uri;
import android.os.Environment;
import android.os.IBinder;

import ren.yale.android.intremetalupdate.EasyIncrementalUpdate;

/**
 * Created by yale on 2017/12/11.
 */

public class TestService extends Service {
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();
    }

    private void patch(){
        try {
            String oldApk = EasyIncrementalUpdate.getApkSourceDir(this.getApplicationContext());
            String sdpath= Environment.getExternalStorageDirectory().getAbsolutePath()+"/tmp/";
            String newApk = sdpath+"new.apk";
            String patch = sdpath+"patch.patch";
            if ( EasyIncrementalUpdate.patch(oldApk,newApk,patch)){
                Intent intent1 = new Intent(Intent.ACTION_VIEW);
                intent1.setDataAndType(Uri.parse("file://"+newApk),
                        "application/vnd.android.package-archive");
                startActivity(intent1);
            }else{
                LogUtil.d(" update fail");
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                patch();
            }
        }).start();
        return super.onStartCommand(intent, flags, startId);
    }
}
