#include "includes/jni_hotfix_dalvik.h"
#include "includes/hotfix_dalvik.h"

JNIEXPORT void JNICALL Java_brian_com_nativehotfixdemo_hotfix_HotfixManager_fixDalvik
        (JNIEnv* env, jobject obj, jobject src, jobject des) {
    Method* before = (Method*)env->FromReflectedMethod(src);
    Method* after = (Method*)env->FromReflectedMethod(des);
    replace_dalvik(before, after);
}

JNIEXPORT void JNICALL Java_brian_com_nativehotfixdemo_hotfix_HotfixManager_setSingleFlagArt
        (JNIEnv* env, jobject obj, jobject field) {
    Field* dalvikField = (Field*) env->FromReflectedField(field);
    dalvikField->accessFlags = dalvikField->accessFlags & (~ACC_PRIVATE) | ACC_PUBLIC;
}

void replace_dalvik(Method* before, Method* after) {
    before->accessFlags |= ACC_PUBLIC;
    before->methodIndex = after->methodIndex;
    before->jniArgInfo = after->jniArgInfo;
    before->registersSize = after->registersSize;
    before->outsSize = after->outsSize;
    before->insSize = after->insSize;

    before->prototype = after->prototype;
    before->insns = after->insns;
    before->nativeFunc = after->nativeFunc;
}