#include <cstdio>
#include "png2stl.h"
#include "heightmap.h"
#include "libtrix.h"


void Png2Stl(char* szFileName, float zScale)
{
    Heightmap* hm = NULL;
    hm = ReadHeightmap(szFileName);
    printf("Width:= %d, Height:= %d, Size:= %d, Depth:= %d/n", hm->width, hm->height, hm->size, hm->depth);
    if(HeightmapToSTL(hm, zScale) != TRIX_OK)
    {
        printf("[ERROR]HeightmapToSTL");
        return;
    }

    FreeHeightmap(&hm);
}

