//
// Created by word on 2017/12/9.
//

#ifndef EASYINCREMENTALUPDATE_LOG_H
#define EASYINCREMENTALUPDATE_LOG_H

#include <android/log.h>

#define LOGI_(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO, "EasyIncrementalUpdate",FORMAT,__VA_ARGS__)
#define LOGD_(FORMAT, ...) __android_log_print(ANDROID_LOG_DEBUG,"EasyIncrementalUpdate",FORMAT,__VA_ARGS__)
#define LOGE_(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"EasyIncrementalUpdate",FORMAT,__VA_ARGS__)


#define LOGI(VALUE) __android_log_print(ANDROID_LOG_INFO, "EasyIncrementalUpdate",VALUE)
#define LOGD(VALUE) __android_log_print(ANDROID_LOG_DEBUG,"EasyIncrementalUpdate",VALUE)
#define LOGE(VALUE) __android_log_print(ANDROID_LOG_ERROR,"EasyIncrementalUpdate",VALUE)


#endif //EASYINCREMENTALUPDATE_LOG_H
