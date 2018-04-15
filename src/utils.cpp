//
// Created by optio32 on 13.04.18.
//

#include "utils.h"

long File::GetFileSize(IN std::ifstream &file)
{
    file.seekg(0, std::ios_base::end);
    return file.tellg();
}

long File::GetFileSize(IN char* szFileName)
{
    std::ifstream in(szFileName, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

char* File::ReadFile(IN char* szFileName, OUT char* szBuffer, IN ulong fileSize)
{
    std::ifstream inputFile(szFileName, std::ios::in | std::ios::binary);
    //fileSize = GetFileSize(inputFile);
    inputFile.read(szBuffer, fileSize);
    return szBuffer;
}

const char* Path::ExtractFileName(IN char* szPath)
{
    PCHAR start, end;

    start = szPath;
    end = start + strlen(start) - 1;
    while(*end != '/')
        end--;
    end++;
    return end;
}

const char* Path::ExtractFilePath(IN char* szPath)
{
    std::string str(szPath);
    return str.substr(0, str.find_last_of("\\/")).c_str();
}

size_t Parse::StrToInt(char* szNumber)
{
    return atoi(szNumber);
}

float Parse::StrToFloat(char* szNumber)
{
    return atof(szNumber);
}

