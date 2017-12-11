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

//#include<stdarg.h>
//#include <stdio.h>


int err(int n,char *format,char *value){
        if (format == NULL){
                return n;
        }
        LOGE_(format, value);
        return  n;
}

int errx(int n,char *format,char *value){
        if (format == NULL){
                return n;
        }
        LOGE_(format, value);
        return  n;
}
//#define err(n, ...) _exit(n)
//#define errx(n, ...) _exit(n)

#endif //EASYINCREMENTALUPDATE_ERR_H
