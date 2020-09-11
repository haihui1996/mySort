/////////////////////////////////////////////////////////////////////////////
//@FileName:  main.c
//@Path:      H:\Sort\test
//@Description:
//@Copyright (c) 2020 Haihui Deng
//@Author     haihui_deng@163.com 2020/09/08
/////////////////////////////////////////////////////////////////////////////
#include "../common/common.h"
#include "../alg/insertion/insertion.h"
void print_data_to_file(FILE *fp, const uint *array, const uint n);

int main(void)
{
    FILE *fp = NULL;
    time_t timecut;
    uint *array = (uint *)calloc(DATA_SIZE, sizeof(uint));

    sort_creat_random_data(DATA_SIZE, array);

    timecut = time(NULL);
    sort_alg(DATA_SIZE, array);
    timecut = time(NULL) - timecut;

    printf("time = %ld\n", timecut);

#ifdef SORT_CHECK
    uint temp = array[0];
    for (uint i = 1; i < DATA_SIZE; i++)
    {
        if (array[i] < temp)
        {
            printf("\r\nsort eror");
            return;
        }
    }
#endif

#if (DEBUG_PRINT == 1)
    fp = fopen("./sort_data.txt", "w");
    print_data_to_file(fp, array, DATA_SIZE);
#endif

    free(array);
    return 0;
}

void print_data_to_file(FILE *fp, const uint *array, const uint n)
{
    for (uint i = 0; i < n; i++)
    {
        fprintf(fp, "%#10x ", array[i]);
        if (((i + 1) % 10 == 0))
        {
            fprintf(fp, "\n");
        }
    }
}
