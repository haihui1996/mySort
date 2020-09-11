/////////////////////////////////////////////////////////////////////////////
//@FileName:  bubble_sort.h
//@Path:      H:\Sort\bubble
//@Description: Ã°ÅİÅÅĞòËã·¨
//@Copyright (c) 2020 Haihui Deng
//@Author     haihui_deng@163.com 2020/09/08
/////////////////////////////////////////////////////////////////////////////
#include "../../common/common.h"
static void bubble_sort(const uint n, uint array[])
{
    int flag;
    for (uint i = n - 1; i > 0; i--)
    {
        flag = 0;
        for (uint j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                flag = 1;
            }
        }

        if (!flag)
        {
            return;
        }
    }
}