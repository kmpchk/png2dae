#include <iostream>
#include "png2dae.h"
#include "stl2dae.h"
#include "png2stl.h"
#include "utils.h"

#include <boost/program_options.hpp>
using namespace boost::program_options;

int main(int argc, char** argv)
{
    //int mode = 0;
    float f = 0;
    std::string inputFile;
    std::string outputFile;
    ConvertMode mode;
    try
    {
        options_description desc{"Options"};
        desc.add_options()
                ("help,h", "Help screen")
                ("input,i", value<std::string>(&inputFile), "Input Filename")
                ("output,o", value<std::string>(&outputFile), "Output Filename")
                ("pstl,p", "Convert to Stl from Png")
                ("pdae,k", "Convert to Dae from Png")
                ("sdae,s", "Convert to Dae from Stl")
                ("zscale,z", value<float>(&f), "Z scale");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help"))
            std::cout << desc << '\n';
        else if (vm.count("input"))
            std::cout << "Input: " << inputFile << '\n';
        if (vm.count("output"))
            std::cout << "Output: " << outputFile << '\n';
        if (vm.count("pstl")) {
            //std::cout << "PS: " << f << '\n';
            mode = MPNG2STL;
        }
        if (vm.count("pdae")) {
            //std::cout << "PD: " << f << '\n';
            mode = MPNG2DAE;
        }
        if (vm.count("sdae")) {
            //std::cout << "PD mode" << '\n';
            mode = MSTL2DAE;
        }
        if (vm.count("z")) {
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    //printf("input:= %s, output:= %s, f:= %f, mode:= %d", inputFile.c_str(), outputFile.c_str(), f, mode);

    PNG2DAE_CONFIG cfg;
    cfg.zScale = f;
    cfg.szInputFilename = (char*)inputFile.c_str();
    cfg.szOutputFilename = (char*)outputFile.c_str();

    if(mode == MPNG2STL)
    {
        PNG2STL::Convert(&cfg);
    }
    else if(mode == MPNG2DAE)
    {
        Png2Dae dae(&cfg);
        dae.Convert();
    }
    else if(mode == MSTL2DAE)
    {
        STL2DAE::Convert(&cfg);
    }
    return 0;
}