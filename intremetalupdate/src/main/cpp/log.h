//
// Created by yale on 2017/12/9.
//

#ifndef EASYINCREMENTALUPDATE_LOG_H
#define EASYINCREMENTALUPDATE_LOG_H

#include <android/log.h>

#define TAG "EasyIncrementalUpdate"

#define LOGI_F(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO, TAG,FORMAT,__VA_ARGS__)
#define LOGD_F(FORMAT, ...) __android_log_print(ANDROID_LOG_DEBUG,TAG,FORMAT,__VA_ARGS__)
#define LOGE_F(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,TAG,FORMAT,__VA_ARGS__)

#define LOGI(VALUE) __android_log_print(ANDROID_LOG_INFO, TAG,"%s",VALUE)
#define LOGD(VALUE) __android_log_print(ANDROID_LOG_DEBUG,TAG,"%s",VALUE)
#define LOGE(VALUE) __android_log_print(ANDROID_LOG_ERROR,TAG,"%s",VALUE)

#endif //EASYINCREMENTALUPDATE_LOG_H
