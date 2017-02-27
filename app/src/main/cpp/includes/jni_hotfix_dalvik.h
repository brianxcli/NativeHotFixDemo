#include <jni.h>

#ifndef _Included_brian_com_hotfixdemo_hotfix_HotfixManager
#define _Included_brian_com_hotfixdemo_hotfix_HotfixManager
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     brian_com_hotfixdemo_hotfix_HotfixManager
 * Method:    fixDalvik
 * Signature: (LJava/lang/reflect/Method;LJava/lang/reflect/Method;)V
 */
JNIEXPORT void JNICALL Java_brian_com_nativehotfixdemo_hotfix_HotfixManager_fixDalvik
        (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     brian_com_hotfixdemo_hotfix_HotfixManager
 * Method:    setSingleFlagArt
 * Signature: (LJava/lang/reflect/Field;)V
 */
JNIEXPORT void JNICALL Java_brian_com_nativehotfixdemo_hotfix_HotfixManager_setSingleFlagArt
        (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif