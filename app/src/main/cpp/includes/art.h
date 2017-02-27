#include <jni.h>

#ifdef HAVE_STDINT_H
# include <stdint.h>    /* C99 */
typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;
typedef int8_t s1;
typedef int16_t s2;
typedef int32_t s4;
typedef int64_t s8;
#else
typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef unsigned long long u8;
typedef signed char s1;
typedef signed short s2;
typedef signed int s4;
typedef signed long long s8;
#endif

void replace_4_4(JNIEnv* env, jobject src, jobject dest);
void setFieldFlag_4_4(JNIEnv* env, jobject field);
void replace_5_0(JNIEnv* env, jobject src, jobject dest);
void setFieldFlag_5_0(JNIEnv* env, jobject field);
void replace_5_1(JNIEnv* env, jobject src, jobject dest);
void setFieldFlag_5_1(JNIEnv* env, jobject field);
void replace_6_0(JNIEnv* env, jobject src, jobject dest);
void setFieldFlag_6_0(JNIEnv* env, jobject field);
void replace_7_0(JNIEnv* env, jobject src, jobject dest);
void setFieldFlag_7_0(JNIEnv* env, jobject field);

