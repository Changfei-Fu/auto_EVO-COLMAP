#include<iostream>
#include "util/option_manager.h"
#include "base/reconstruction_manager.h"

using namespace colmap;
using namespace std;
void ModelConverter(int argc, char** argv)
{
    std::string input_path;
    std::string output_path;
    std::string output_type;
    OptionManager options;
    options.AddRequiredOption("input_path", &input_path);
    options.AddRequiredOption("output_path", &output_path);
    options.AddRequiredOption("output_type", &output_type, "{BIN, TXT, NVM, Bundler, VRML, PLY}");
    options.Parse(argc, argv);
    Reconstruction reconstruction;
    reconstruction.Read(input_path);

    StringToLower(&output_type);
    reconstruction.changfei_WriteKeyFrameTrajectory(output_path);
}


void run_model_converter(char const* char_sparsebin,char const* char_sparsetxtdata)
{
    char const* converter_string[] = {"model_converter","--input_path",char_sparsebin,"--output_path",char_sparsetxtdata,"--output_type","TXT"};
    const std::string converter_command = converter_string[0];
    char ** argv_converter = const_cast<char**>(converter_string);
    ModelConverter(7, argv_converter);

}



int main(int argc, char** argv)
{
    string workspace_path = "./colmap_ws";

    std::string DATASET_PATH_BIN_IN = workspace_path + "/sparse/0";
    std::string DATASET_PATH_TEXT = "./KeyFrameTrajectory.txt";
    char const* char_sparsebin = DATASET_PATH_BIN_IN.c_str();
    char const* char_sparsetxtdata = DATASET_PATH_TEXT.c_str();
    /*if(access(char_sparsebin, F_OK)==-1)
        return orbMap;*/

    run_model_converter(char_sparsebin,char_sparsetxtdata);
}
