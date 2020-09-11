/////////////////////////////////////////////////////////////////////////////
//@FileName:  common.c
//@Path:      H:\Sort\common
//@Description: 
//@Copyright (c) 2020 Haihui Deng
//@Author     haihui_deng@163.com 2020/09/11
/////////////////////////////////////////////////////////////////////////////
#include "common.h"
#include "../alg/insertion/insertion.h"
#include "../alg/bubble/bubble_sort.h"

void swap( uint *a, uint *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void sort_alg(const uint n, uint array[])
{
#if (SORT_MODE == ALG_BUBBLE)
    bubble_sort(n, array);
#elif (SORT_MODE == ALG_INSERTION)
    insertion_sort(n, array);
#endif
}

void sort_creat_random_data(const uint count, uint array[])
{
    srandom((uint)time(NULL));
    for (int i = 0; i < count; i++)
    {
        array[i] = rand() % (0xFFFFFFFF);
    }
}