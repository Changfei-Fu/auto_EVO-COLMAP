#include "controllers/automatic_reconstruction.h"
#include "base/reconstruction_manager.h"
#include "util/option_manager.h"
#include "util/threading.h"
#include "controllers/incremental_mapper.h"
#include "feature/extraction.h"
#include "feature/matching.h"
#include "mvs/fusion.h"
#include "mvs/meshing.h"
#include "mvs/patch_match.h"
#include "/usr/local/include/colmap/exe/mvs.h"
using namespace std;
using namespace colmap;

AutomaticReconstructionController::Options reconstruction_options;

int main(int argc, char** argv)
{
    reconstruction_options.workspace_path=argv[1];
    reconstruction_options.image_path=argv[2];
    reconstruction_options.gpu_index="-1";
    reconstruction_options.use_gpu=true;
//    reconstruction_options.num_threads=15;
    reconstruction_options.sparse=true;
    reconstruction_options.dense=false;
    reconstruction_options.single_camera=true;
    reconstruction_options.camera_model="PINHOLE";
    reconstruction_options.data_type = AutomaticReconstructionController::DataType::INDIVIDUAL;//INDIVIDUAL
    reconstruction_options.quality = AutomaticReconstructionController::Quality::LOW;//MEDIUM, HIGH, EXTREME
    reconstruction_options.mesher = AutomaticReconstructionController::Mesher::POISSON;


    ReconstructionManager reconstruction_manager;
    AutomaticReconstructionController controller(reconstruction_options, &reconstruction_manager);
    controller.SFM_Run();

    return 0;
}



