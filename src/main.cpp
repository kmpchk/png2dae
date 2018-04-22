#include <iostream>
#include "png2dae.h"
#include "stl2dae.h"
#include "png2stl.h"

int main(int argc, char** argv) {

    STL_CONFIG cfg;
    cfg.zScale = 0.25;
    cfg.szOutputFileName = argv[2];
    PNG2STL::Png2Stl(argv[1], &cfg);
    STL2DAE::Convert(argv[2]);

    return 0;
}