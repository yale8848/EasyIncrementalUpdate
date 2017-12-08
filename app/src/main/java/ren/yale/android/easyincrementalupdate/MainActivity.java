package ren.yale.android.easyincrementalupdate;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.net.Uri;
import android.os.Bundle;
import android.widget.TextView;

import com.daoxuehao.android.commondir.CommonDir;

import java.io.File;

import ren.yale.android.intremetalupdate.EasyIncrementalUpdate;

public class MainActivity extends Activity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        CommonDir.getInstance().init(this);
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);

        File file = CommonDir.getInstance().getExternalStorageDirectoryWrite("111");

        final String path = file.getAbsolutePath()+File.separator;
        new Thread(new Runnable() {
            @Override
            public void run() {

                try {
                    ApplicationInfo appInfo = MainActivity.this.getPackageManager()
                            .getApplicationInfo(MainActivity.this.getPackageName(), 0);

                   if ( EasyIncrementalUpdate.patch(appInfo.sourceDir,path+"aaa.apk",path+"p.apk")){
                       Intent intent = new Intent(Intent.ACTION_VIEW);
                       intent.setDataAndType(Uri.parse("file://" + path+"aaa.apk"),
                               "application/vnd.android.package-archive");
                       MainActivity.this.startActivity(intent);
                   }

                } catch (Exception e) {
                    e.printStackTrace();
                }



            }
        }).start();
    }

}
