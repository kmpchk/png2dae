//
// Created by optio32 on 13.04.18.
//

#include "png2stl.h"
#include "utils.h"
#include "stb_image.h"
#include "heightmap.h"
#include "png2dae.h"

/*void PNG2STL::Png2Stl(char* szPngFileName, PSTL_CONFIG stlConfig)
{
    HEIGHTMAP* hm = NULL;
    hm = PngToHeightmap(szPngFileName);
    printf("Width:= %d, Height:= %d, Size:= %d, Depth:= %d/n", hm->width, hm->height, hm->size, hm->depth);
    if(HeightmapToSTL(hm, stlConfig) != 0)
    {
        printf("[ERROR]HeightmapToSTL");
        return;
    }

    FreeHeightmap(&hm);

}*/

bool PNG2STL::CheckPngHeader(char* fileHeader)
{
    uint8_t png_signature[8] = { 137,80,78,71,13,10,26,10 };
    bool fOk = false;
    for(int i = 0; i < 8; i++)
    {
        if((uint8_t)fileHeader[i] != png_signature[i])
            return fOk;
    }
    return !fOk;
}
