#include <jni.h>

#ifndef _Included_brian_com_hotfixdemo_hotfix_HotfixManager
#define _Included_brian_com_hotfixdemo_hotfix_HotfixManager
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     brian_com_hotfixdemo_hotfix_HotfixManager
 * Method:    fixArt
 * Signature: (LLJava/lang/reflect/Method;LJava/lang/reflect/Method;)V
 */
JNIEXPORT void JNICALL Java_brian_com_nativehotfixdemo_hotfix_HotfixManager_fixArt
        (JNIEnv *, jobject, jobject, jobject, jint);

/*
 * Class:     brian_com_hotfixdemo_hotfix_HotfixManager
 * Method:    setSingleFlagDalvik
 * Signature: (LLJava/lang/reflect/Field;Z)V
 */
JNIEXPORT void JNICALL Java_brian_com_nativehotfixdemo_hotfix_HotfixManager_setSingleFlagDalvik
        (JNIEnv *, jobject, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif
