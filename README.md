# auto_EVO-colmap
This project use evo to evaluate colmap on several datasets such as EuRoc, TUM, ICL-NUIM and Kitti. Default settings allow this program to automatically run COLMAP-SFM on every sequence for 10 times and give out the results consisting of files named KeyFrameTrajectory.txt, figures of trajectories, mean time used to run on this sequence, mean tracking rate and mean ape.
# Usage
## 1. build colmap modified.
### before execute below commands, it's recommended to install cuda-11.5 library.
cd colmap

mkdir build

cd build

cmake ..

make -j

sudo make install
  
## 2. At the second step you do nothing apart from running the python programs.

## Examples
#### ICL-NUIM dataset
cd ./auto_EVO-COLMAP/ICL-NUIM

python3 evo_ICL-NUIM.py ~/dataset/ICL-NUIM/folders

#### Tum dataset
cd ./auto_EVO-COLMAP/Tum

python3 evo_Tum.py ~/dataset/Tum/folders

#### EuRoc dataset
cd ./auto_EVO-COLMAP/EuRoc

python3 evo_EuRoc.py ~/dataset/EuRoc/folders

# Specialty
...

