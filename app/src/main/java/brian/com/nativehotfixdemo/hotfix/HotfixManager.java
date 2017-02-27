package brian.com.nativehotfixdemo.hotfix;

import android.os.Build;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

import brian.com.nativehotfixdemo.BuildConfig;

/**
 * Created by Xiaochen on 22/02/2017.
 */

public class HotfixManager {
    private static HotfixManager self;

    private boolean isArt;

    public static HotfixManager instance() {
        if (self == null) {
            self = new HotfixManager();
        }
        return self;
    }

    private HotfixManager() {
        isArt = System.getProperty("java.vm.version").startsWith("2");
        if (isArt) {
            System.loadLibrary("hotfix-art");
        } else {
            System.loadLibrary("hotfix-dalvik");
        }
    }

    public void performFix(Method src, Method tar) {
        if (isArt) {
            fixArt(src, tar, Build.VERSION.SDK_INT);
        } else {
            fixDalvik(src, tar);
        }

        setFlags(tar.getDeclaringClass());
    }

    private void setFlags(Class<?> clz) {
        Field[] srcFields = clz.getDeclaredFields();
        for (Field field : srcFields) {
            if (isArt) {
                setSingleFlagArt(field);
            } else {
                setSingleFlagDalvik(field, BuildConfig.VERSION_CODE);
            }
        }
    }

    public native void fixArt(Method src, Method tar, int code);
    public native void fixDalvik(Method src, Method tar);

    public native void setSingleFlagArt(Field field);
    public native void setSingleFlagDalvik(Field field, int code);
}
