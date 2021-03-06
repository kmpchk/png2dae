//
// Created by optio32 on 23.04.18.
//

#ifndef STL2DAE_H
#define STL2DAE_H

#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "png2dae.h"

namespace STL2DAE
{
    void Convert(char* szStlFilename);
    void Convert(PPNG2DAE_CONFIG cfg);
}

#endif //PNG2DAE_STL2DAE_H
