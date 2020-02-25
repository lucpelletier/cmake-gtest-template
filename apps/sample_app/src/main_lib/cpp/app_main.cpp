#include "sample_app/app_main.h"

#include <stdio.h>
#include <stdlib.h>

#include "sample_lib/sample.h"

int SampleApp_Main(int argc, const char** argv)
{
    if(argc != 3)
    {
        printf("Usage: %s number number\n", argv[0]);
        return -1;
    }
    printf("Total is %d\n", SampleFunction(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10)));
    return 0;
}
