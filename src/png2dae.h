//
// Created by optio32 on 23.04.18.
//

#ifndef PNG2DAE_H
#define PNG2DAE_H

enum ConvertMode {MPNG2DAE=0, MPNG2STL, MSTL2DAE};

typedef struct _PNG2DAE_CONFIG
{
    float zScale = 0.25;
    char* szOutputFilename;
    char* szInputFilename;
}PNG2DAE_CONFIG, *PPNG2DAE_CONFIG;


class Png2Dae {
private:
    char* _data;
    PPNG2DAE_CONFIG _cfg;

    //bool IsPng();
public:
    Png2Dae(PPNG2DAE_CONFIG cfg);
    ~Png2Dae();
    bool IsPng();
    void Png2Stl();
    void Stl2Dae();
    void Convert();
};


#endif //PNG2DAE_PNG2DAE_H
