#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#include <stdbool.h>
#include <fcntl.h>
#include <dlfcn.h>

#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <utime.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "includes/art.h"
#include "includes/hotfix_art_7_0.h"

void replace_7_0(JNIEnv* env, jobject src, jobject dest) {
    art::mirror::ArtMethod* smeth =
            (art::mirror::ArtMethod*) env->FromReflectedMethod(src);

    art::mirror::ArtMethod* dmeth =
            (art::mirror::ArtMethod*) env->FromReflectedMethod(dest);

//	reinterpret_cast<art::mirror::Class*>(smeth->declaring_class_)->class_loader_ =
//			reinterpret_cast<art::mirror::Class*>(dmeth->declaring_class_)->class_loader_; //for plugin classloader
    reinterpret_cast<art::mirror::Class*>(dmeth->declaring_class_)->clinit_thread_id_ =
            reinterpret_cast<art::mirror::Class*>(smeth->declaring_class_)->clinit_thread_id_;
    reinterpret_cast<art::mirror::Class*>(dmeth->declaring_class_)->status_ =
            reinterpret_cast<art::mirror::Class*>(smeth->declaring_class_)->status_ -1;
    //for reflection invoke
    reinterpret_cast<art::mirror::Class*>(dmeth->declaring_class_)->super_class_ = 0;

    smeth->declaring_class_ = dmeth->declaring_class_;
    smeth->access_flags_ = dmeth->access_flags_  | 0x0001;
    smeth->dex_code_item_offset_ = dmeth->dex_code_item_offset_;
    smeth->dex_method_index_ = dmeth->dex_method_index_;
    smeth->method_index_ = dmeth->method_index_;
    smeth->hotness_count_ = dmeth->hotness_count_;

    smeth->ptr_sized_fields_.dex_cache_resolved_methods_ =
            dmeth->ptr_sized_fields_.dex_cache_resolved_methods_;
    smeth->ptr_sized_fields_.dex_cache_resolved_types_ =
            dmeth->ptr_sized_fields_.dex_cache_resolved_types_;

    smeth->ptr_sized_fields_.entry_point_from_jni_ =
            dmeth->ptr_sized_fields_.entry_point_from_jni_;
    smeth->ptr_sized_fields_.entry_point_from_quick_compiled_code_ =
            dmeth->ptr_sized_fields_.entry_point_from_quick_compiled_code_;
}

void setFieldFlag_7_0(JNIEnv* env, jobject field) {
    art::mirror::ArtField* artField =
            (art::mirror::ArtField*) env->FromReflectedField(field);
    artField->access_flags_ = artField->access_flags_ & (~0x0002) | 0x0001;
}

