//
// Created by optio32 on 23.04.18.
//

#include <cstdint>
#include "png2dae.h"
#include "utils.h"
#include "stb_image.h"
#include "heightmap.h"
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

bool Png2Dae::IsPng()
{
    uint8_t png_signature[8] = { 137,80,78,71,13,10,26,10 };
    bool fOk = false;
    for(int i = 0; i < 8; i++)
    {
        if((uint8_t)_data[i] != png_signature[i])
            return fOk;
    }
    return !fOk;
}

void Png2Dae::Png2Stl()
{
        HEIGHTMAP* hm = NULL;
        hm = PngToHeightmap(_cfg->szInputFilename);
        printf("Width:= %d, Height:= %d, Size:= %d, Depth:= %d/n", hm->width, hm->height, hm->size, hm->depth);
        if(HeightmapToSTL(hm, _cfg) != 0)
        {
            printf("[ERROR]HeightmapToSTL");
            return;
        }

        FreeHeightmap(&hm);
}

void Png2Dae::Stl2Dae()
{
    std::string dae_file(_cfg->szOutputFilename);
    dae_file += ".dae";
    std::string stl_file(_cfg->szOutputFilename);
    stl_file += ".stl";
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(stl_file.c_str(), 0);

    Assimp::Exporter exporter;
    aiReturn result = exporter.Export(scene, "collada", dae_file.c_str(), 0);
}

Png2Dae::Png2Dae(PPNG2DAE_CONFIG cfg)
{
    _data = new char[8];
    _cfg = cfg;
    File::ReadFile(cfg->szInputFilename, _data, 8);
}

Png2Dae::~Png2Dae()
{
    delete [] _data;
    printf("Erase\n");
}
