//
// Created by optio32 on 13.04.18.
//
#include <cstdio>
#include <cmath>
#include "png2stl.h"
#include "utils.h"
#include <fstream>
#include "boost/program_options.hpp"
#include "boost/filesystem.hpp"
#include <iostream>
#include "MeshLoader.h"

namespace po = boost::program_options;
using namespace std;

int main(int argc, char** argv)
{
    /*std::string appName = boost::filesystem::basename(argv[0]);
    std::string input, output;
    float z;

    try {

        po::options_description desc("Allowed options");
        desc.add_options()
                ("input,I", po::value<std::string>(&input), "Input file")
                ("output,O", po::value<std::string>(&output), "Output file")
                ("compression", po::value<float>(&z), "Z scale")
                ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("input")) {
            printf("%s", vm["input"].as<std::string>().c_str());
        } else {
            cout << "input not set.\n";
        }
    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    } */

    /*char* szFileName = argv[1];
    char* szFileOutputName = argv[2];
    float zScale = atof(argv[3]);
    printf("input:= %s, output:= %s, z:= %f\n", szFileName, szFileOutputName, zScale);
    STL_CONFIG cfg;
    cfg.szOutputFileName = szFileOutputName;
    cfg.zScale = zScale;
    PNG2STL::Png2Stl(szFileName, &cfg);*/

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);

    Mesh* mesh = new Mesh(argv[1]);
    while (!glfwWindowShouldClose(window)) {
        mesh->render();
    }
    delete mesh;

    return 0;
}
