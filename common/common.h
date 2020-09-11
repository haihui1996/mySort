/////////////////////////////////////////////////////////////////////////////
//@FileName:  common.h
//@Path:      H:\Sort\common
//@Description: 
//@Copyright (c) 2020 Haihui Deng
//@Author     haihui_deng@163.com 2020/09/08
/////////////////////////////////////////////////////////////////////////////
#ifndef __COMMON_H__
#define __COMMON_H__
#include "type.h"
#include "config.h"
#include <malloc.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ALG_BUBBLE      (1) /* √∞≈›≈≈–Ú */
#define ALG_INSERTION   (2) /* ≤Â»Î≈≈–Ú */


#define SORT_MODE (2)   



/////////////////////////////////////////////////////////////////////////////////////////////////////
// common functions
/////////////////////////////////////////////////////////////////////////////////////////////////////
void swap( uint *a, uint *b);
void sort_alg(const uint n, uint array[]);
void sort_creat_random_data(const uint count, uint array[]);


#endif // !__COMMON_H__