package ren.yale.android.easyincrementalupdate;

import android.app.Service;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.net.Uri;
import android.os.IBinder;

import com.daoxuehao.android.commondir.CommonDir;

import java.io.File;

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

            File file = CommonDir.getInstance().getExternalStorageDirectoryWrite("111");

            final String path = file.getAbsolutePath()+File.separator;
            ApplicationInfo appInfo = getPackageManager()
                    .getApplicationInfo(getPackageName(), 0);

            if ( EasyIncrementalUpdate.patch(appInfo.sourceDir,path+"aaa.apk",path+"p.apk")){
                Intent intent1 = new Intent(Intent.ACTION_VIEW);
                intent1.setDataAndType(Uri.parse("file://" + path+"aaa.apk"),
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
