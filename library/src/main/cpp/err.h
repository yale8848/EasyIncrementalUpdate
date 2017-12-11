//
// Created by word on 2017/12/9.
//

#ifndef EASYINCREMENTALUPDATE_ERR_H
#define EASYINCREMENTALUPDATE_ERR_H

#include "log.h"

/*
#define err(n,format,...) {\
        if (format == NULL) return n;\
        LOGE_(format,__VA_ARGS__);       \
        return n;                      \
}                                       \

#define err(n,format) {\
        if (format == NULL) return n;\
        LOGE_(format,__VA_ARGS__);       \
        return n;                      \
}                                       \

#define errx(n,format,...) {\
        if (format == NULL) return n;\
        LOGE_(format,__VA_ARGS__);       \
        return n;                      \
}                                      \


#define errx(n,format) {\
        if (format == NULL) return n;\
        LOGE_(format,__VA_ARGS__);       \
        return n;                      \
}                                      \

*/

#include<stdarg.h>
#include <stdio.h>
#include <sys/cdefs.h>






__BEGIN_DECLS

 int err(int __status, const char* __fmt, ...) __printflike(2, 3);
 int  errx(int __status, const char* __fmt, ...) __printflike(2, 3);

__END_DECLS
int err(int __status, const char* __fmt, ...){
        char printf_buf[1024];
        va_list args;
        va_start(args, __fmt);
        printf(printf_buf, __fmt, args);
        va_end(args);
        return  __status;
}

int errx(int __status, const char* __fmt, ...){

        char printf_buf[1024];
        va_list args;
        va_start(args, __fmt);
        printf(printf_buf, __fmt, args);
        va_end(args);
        return  __status;
}


#endif //EASYINCREMENTALUPDATE_ERR_H
