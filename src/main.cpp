#include <iostream>
#include "cstdio"
#include "cstring"
#include "png2stl.h"

using namespace std;

int main(int argc, char** argv)
{
    char szFileName[80] = {0};

    strcpy(szFileName, argv[1]);
    printf("Filename:= %s\n", szFileName);
    //printf("Width:= %d, Height:= %d, Size:= %d, Depth:= %d/n", hm->width, hm->height, hm->size, hm->depth);
    Png2Stl(szFileName, 0.25);
    return 0;
}

