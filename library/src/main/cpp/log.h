//
// Created by word on 2017/12/9.
//

#ifndef EASYINCREMENTALUPDATE_LOG_H
#define EASYINCREMENTALUPDATE_LOG_H

#include <android/log.h>

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO, "EasyIncrementalUpdate",FORMAT,__VA_ARGS__)
#define LOGD(FORMAT, ...) __android_log_print(ANDROID_LOG_DEBUG,"EasyIncrementalUpdate",FORMAT,__VA_ARGS__)
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"EasyIncrementalUpdate",FORMAT,__VA_ARGS__)

#endif //EASYINCREMENTALUPDATE_LOG_H
