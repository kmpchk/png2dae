//
// Created by optio32 on 13.04.18.
//

#ifndef PNG2DAE_PNG_H
#define PNG2DAE_PNG_H

#include <tiff.h>
#include "png2dae.h"

typedef struct _STL_CONFIG
{
  float zScale = 1;
  char* szOutputFileName;
} STL_CONFIG, *PSTL_CONFIG;

namespace PNG2STL
{
    void Convert(PPNG2DAE_CONFIG Config);
    bool CheckPngHeader(char* szFile);

}

#endif //PNG2DAE_PNG_H
