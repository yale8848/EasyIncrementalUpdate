//
// Created by yale on 2017/12/9.
//

#ifndef EASYINCREMENTALUPDATE_ERR_H
#define EASYINCREMENTALUPDATE_ERR_H

#include "log.h"
#include<stdarg.h>
#include <stdio.h>

int err(int __status, const char* __fmt, ...) __printflike(2, 3);
int errf(int __status,u_char * old_buf,u_char *new_buf,const char* __fmt, ...) __printflike(4, 5);
int errx(int __status, const char* __fmt, ...) __printflike(2, 3);

int err(int __status, const char* __fmt, ...){

    char buf[1024]={0};
    va_list ap;
    va_start(ap, __fmt);
    vsprintf (buf, __fmt, ap);
    LOGE(buf);
    va_end(ap);
    return  __status;
}
int errf(int __status, u_char * old_buf,u_char *new_buf,const char* __fmt, ...){

    char buf[1024]={0};
    va_list ap;
    va_start(ap, __fmt);
    vsprintf (buf, __fmt, ap);
    LOGE(buf);
    va_end(ap);

    if (old_buf!=NULL) free(old_buf);
    if (new_buf!=NULL) free(new_buf);

    return  __status;
}
int errx(int __status, const char* __fmt, ...){

    char buf[2048]={0};
    va_list ap;
    va_start(ap, __fmt);
    vsprintf (buf, __fmt, ap);
    LOGE(buf);
    va_end(ap);
    return  __status;
}


#endif //EASYINCREMENTALUPDATE_ERR_H
