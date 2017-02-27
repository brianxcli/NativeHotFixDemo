package brian.com.nativehotfixdemo;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.lang.annotation.Annotation;
import java.lang.reflect.Method;

import brian.com.nativehotfixdemo.annotations.MethodHotfix;
import brian.com.nativehotfixdemo.hotfix.HotfixManager;
import brian.com.nativehotfixdemo.modules.ArrayUtils;
import dalvik.system.DexClassLoader;

public class MainActivity extends Activity implements View.OnClickListener {
    private static final int MSG_STOP_PROGRESS = 1;
    private static final int MSG_SHOW_EXCEPTION = 2;

    private TextView mText;
    private ProgressBar mProgress;
    private Button mCalculate;
    private Button mHotfix;

    private static Handler mHandler = new Handler() {
        public void handleMessage(Message msg) {
        switch (msg.what) {
            case MSG_STOP_PROGRESS:
                break;
        }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mText = (TextView) findViewById(R.id.progress_text);
        mProgress = (ProgressBar) findViewById(R.id.progress);
        mCalculate = (Button) findViewById(R.id.calculate);
        mHotfix = (Button) findViewById(R.id.fix);

        mCalculate.setOnClickListener(this);
        mHotfix.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.calculate:
                calculate();
                break;
            case R.id.fix:
                hotfix();
                break;
        }
    }

    private void calculate() {
        ArrayUtils utils = new ArrayUtils();
        try {
            int sum = utils.sum(new int[]{1, 2, 3, 4});
            mText.setText("The sum is: " + sum);
        } catch (Exception e) {
            final String message = e.getCause() + " | " + e.getMessage();
            mHandler.post(new Runnable() {
                public void run() {
                    mText.setText(message);
                }
            });
        }
    }

    private void hotfix() {
        DexClassLoader classLoader = loadDex("hotfix.dex");
        parseMethod(classLoader);
    }

    private DexClassLoader loadDex(String fileName) {
        File src = copyFromAssets(fileName);

        if (src == null) {
            return null;
        }

        File temp = getDir("opt", Context.MODE_PRIVATE);
        if (temp.exists()) {
            temp.delete();
        }

        try {
            return new DexClassLoader(src.getAbsolutePath(), getDir("opt", Context.MODE_PRIVATE).getAbsolutePath(), null, getClassLoader());
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }

    private File copyFromAssets(String fileName) {
            File des = getDir(fileName, Context.MODE_PRIVATE);
        if (des.exists()) {
            des.delete();
        }

        BufferedInputStream input = null;
        BufferedOutputStream output = null;

        try {
            if (!des.createNewFile()) {
                return null;
            }

            input = new BufferedInputStream(getAssets().open(fileName));
            output = new BufferedOutputStream(new FileOutputStream(des));

            byte[] buf = new byte[128];
            int res;
            while ((res = input.read(buf, 0, 128)) != -1) {
                output.write(buf, 0, res);
            }
        } catch(IOException e) {
            e.printStackTrace();
        } finally {
            if (input != null) {
                try {
                    input.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            if (output != null) {
                try {
                    output.flush();
                    output.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        return des;
    }

    private void parseMethod(ClassLoader classLoader) {
        HotfixManager manager = HotfixManager.instance();
        try {
            Class<?> clz = classLoader.loadClass("brian.com.nativehotfixdemo.hotfix.ArrayUtils");
            Method[] methods = clz.getDeclaredMethods();
            for (Method method : methods) {
                Annotation[] annotations = method.getDeclaredAnnotations();
                for (Annotation annotation : annotations) {
                    if (annotation instanceof MethodHotfix) {
                        MethodHotfix fix = (MethodHotfix)annotation;
                        String clazz = fix.className();
                        String methodName = fix.methodName();
                        Class<?> tar = Class.forName(clazz);
                        int[] arr = new int[1];
                        Method fixMethod = tar.getDeclaredMethod(methodName, arr.getClass());
                        manager.performFix(fixMethod, method);
                    }
                }
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
    }
}
