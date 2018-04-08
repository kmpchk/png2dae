#include <iostream>
#include "heightmap.h"
#include "cstdio"
#include "cstring"
#include "libtrix.h"

using namespace std;

int main(int argc, char** argv)
{
    Heightmap* hm = NULL;
    char szFileName[80] = {0};

    strcpy(szFileName, argv[1]);
    printf("Filename:= %s\n", szFileName);
    hm = ReadHeightmap(szFileName);
    printf("Width:= %d, Height:= %d, Size:= %d, Depth:= %d/n", hm->width, hm->height, hm->size, hm->depth);

    if(HeightmapToSTL(hm) != TRIX_OK)
    {
        printf("Conversion error!");
    }

    FreeHeightmap(&hm);


    return 0;
}

