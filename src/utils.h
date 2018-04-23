//
// Created by optio32 on 13.04.18.
//

#ifndef PNG2DAE_UTILS_H
#define PNG2DAE_UTILS_H

#include <fstream>
#include <cstring>
#include <iostream>
#include "types.h"
#include <cstdlib>

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

namespace File
{
    long GetFileSize(IN std::ifstream& file);
    long GetFileSize(IN char* szFileName);

    void ReadFile(IN char* szFileName, OUT char* szBuffer, IN ulong size);
}

namespace Path
{
    const char* ExtractFilePath(IN char* szPath);
    const char* ExtractFileName(IN char* szPath);
}

namespace Parse
{
    size_t StrToInt(char* szNumber);
    float StrToFloat(char* szNumber);
}

namespace IMG
{
    bool CheckPngHeader(char* fileHeader);
}

#endif //PNG2DAE_UTILS_H
