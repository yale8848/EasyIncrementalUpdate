//
// Created by word on 2017/12/9.
//

#ifndef EASYINCREMENTALUPDATE_ERR_H
#define EASYINCREMENTALUPDATE_ERR_H

#include "log.h"
//#include<stdarg.h>
//#include <stdio.h>

int err(int n, char * format,...)
{
    LOGE(format);
    return  n;
}

int errx(int n, char * format,...)
{
    LOGE(format);
    return  n;
}



//#define err(n, ...) _exit(n)
//#define errx(n, ...) _exit(n)

#endif //EASYINCREMENTALUPDATE_ERR_H
