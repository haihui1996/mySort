/////////////////////////////////////////////////////////////////////////////
//@FileName:  insertion.h
//@Path:      H:\Sort\alg\insertion
//@Description: ≤Â»Î≈≈–Ú
//@Copyright (c) 2020 Haihui Deng
//@Author     haihui_deng@163.com 2020/09/10
/////////////////////////////////////////////////////////////////////////////
#include "../../common/common.h"


static void insertion_sort(const uint n, uint *array)
{
    uint temp;
    int i, j;

    for (i = 1; i < n; i++)
    {
        temp = array[i];
        j = i-1;
        while(j >= 0 && temp < array[j])
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

