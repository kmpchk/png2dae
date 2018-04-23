//
// Created by optio32 on 13.04.18.
//

#ifndef PNG2DAE_HEIGHTMAP_H
#define PNG2DAE_HEIGHTMAP_H

#include <tiff.h>
#include <fstream>
#include "png2stl.h"
#include "png2dae.h"

typedef struct _HEIGHTMAP{

    // xy dimensions (size = width * height)
    unsigned int width, height;
    unsigned long size;

    unsigned int depth;

    // z dimensions (range = max - min = relief)
    unsigned char min, max, range;

    // raster with size pixels ranging in value from min to max
    unsigned char* data;

} HEIGHTMAP, *PHEIGHTMAP;

HEIGHTMAP* PngToHeightmap(char *szFileName);
int HeightmapToSTL(HEIGHTMAP *hm, PPNG2DAE_CONFIG cfg);
void FreeHeightmap(HEIGHTMAP **hm);

#endif //PNG2DAE_HEIGHTMAP_H
