#ifndef __HEAD_H__
#define __HEAD_H__

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_ERR(errmsg)                                   \
    do {                                                    \
        printf("%s:%s:%d\n", __FILE__, __func__, __LINE__); \
        perror(errmsg);                                     \
        return -1;                                          \
    } while (0)

#endif