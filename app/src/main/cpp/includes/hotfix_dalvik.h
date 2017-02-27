#include <jni.h>
#include "dalvik.h"

#ifdef __cplusplus
extern "C" {
#endif

void replace_dalvik(Method* before, Method* after);

#ifdef __cplusplus
}
#endif
