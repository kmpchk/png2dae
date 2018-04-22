//
// Created by optio32 on 23.04.18.
//

#ifndef PNG2DAE_H
#define PNG2DAE_H

typedef struct _PNG2DAE_CONFIG
{
    float zScale = 1;
    char* szOutputFilename;
}PNG2DAE_CONFIG, *PPNG2DAE_CONFIG;


class Png2Dae {
public:
    Png2Dae(PNG2DAE_CONFIG cfg);
};


#endif //PNG2DAE_PNG2DAE_H
