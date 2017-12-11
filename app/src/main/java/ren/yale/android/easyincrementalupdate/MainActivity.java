package ren.yale.android.easyincrementalupdate;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import com.daoxuehao.android.commondir.CommonDir;

public class MainActivity extends Activity {

    static final String TAG="easyincrementalupdate";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        CommonDir.getInstance().init(this);
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);


        startService(new Intent(this,TestService.class));

    }

}
