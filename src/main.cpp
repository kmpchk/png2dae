#include <iostream>
#include "png2dae.h"
#include "stl2dae.h"
#include "png2stl.h"
#include "utils.h"

int main(int argc, char** argv) {


    /*STL_CONFIG cfg;
    cfg.zScale = 0.25;
    cfg.szOutputFileName = argv[2];
    PNG2STL::Png2Stl(argv[1], &cfg);
    STL2DAE::Convert(argv[2]);*/


    /*PNG2DAE_CONFIG cfg;
    cfg.szInputFilename = argv[1];
    cfg.szOutputFilename = argv[2];
    cfg.zScale = Parse::StrToFloat(argv[3]);*/
    printf("%s", argv[1]);
    STL2DAE::Convert(argv[1]);
    /*Png2Dae dae(&cfg);
    if(dae.IsPng())
    {
        printf("PNG\n");
        if(cfg.zScale == -1)
        {
            dae.Stl2Dae();
        }
        dae.Png2Stl();
        dae.Stl2Dae();
    }*/



    return 0;
}