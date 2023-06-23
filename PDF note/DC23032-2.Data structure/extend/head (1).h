#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define PRINT_ERR(errmsg) \
    do {                  \
        perror(errmsg);   \
        return -1;        \
    } while (0)

#endif