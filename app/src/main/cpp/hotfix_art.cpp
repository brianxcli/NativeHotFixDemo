#include "includes/jni_hotfix_art.h"
#include "includes/art.h"

JNIEXPORT void JNICALL Java_brian_com_nativehotfixdemo_hotfix_HotfixManager_fixArt
        (JNIEnv* env, jobject obj, jobject src, jobject des, jint version) {
    int versionCode = (int)version;
    if (versionCode > 23) {
        // replace_7_0(env, src, des);
    } else if (versionCode > 22) {
        replace_6_0(env, src, des);
    } else if (versionCode > 21) {
        replace_5_1(env, src, des);
    } else if (versionCode > 19) {
        replace_5_0(env, src, des);
    } else {
        replace_4_4(env, src, des);
    }
}

JNIEXPORT void JNICALL Java_brian_com_nativehotfixdemo_hotfix_HotfixManager_setSingleFlagDalvik
        (JNIEnv* env, jobject obj, jobject field, jint version) {
    int versionCode = (int)version;
    if (versionCode > 23) {
        // setFieldFlag_7_0(env, field);
    } else if (versionCode > 22) {
        setFieldFlag_6_0(env, field);
    } else if (versionCode > 21) {
        setFieldFlag_5_1(env, field);
    } else if (versionCode > 19) {
        setFieldFlag_5_0(env, field);
    } else {
        setFieldFlag_4_4(env, field);
    }
}
