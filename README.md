# auto_EVO-colmap
This project use evo to evaluate colmap on several datasets such as EuRoc, TUM, ICL-NUIM and Kitti. Default settings allow this program to automatically run ORBSLAM3 on every sequence for 10 times and give out the results consisting of files named KeyFrameTrajectory.txt, figures of trajectories, mean time used to run on this sequence, mean tracking rate and mean ape.
# Usage
## 1. modify the directory paths of evo in evo_EuRoc.py evo_ICL-NUIM.py and evo_Tum.py.

## 2. build colmap modified.

cd colmap

mkdir build

cd build

cmake ..

make -j

sudo make install
  
# Examples
python3 evo_Tum.py ~/dataset/Tum/folders

python3 evo_EuRoc.py ~/dataset/EuRoc/folders

python3 evo_ICL-NUIM.py ~/dataset/ICL-NUIM/folders
