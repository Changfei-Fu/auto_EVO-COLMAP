# auto_EVO-colmap
This project use evo to evaluate COLMAP-SFM on several datasets such as EuRoc, TUM, ICL-NUIM and Kitti. Default settings allow this program to automatically run COLMAP-SFM on every sequence for 10 times and give out the results consisting of files named KeyFrameTrajectory.txt, figures of trajectories, mean time used to run on this sequence, mean tracking rate and mean ape.
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
#### 1). ICL-NUIM dataset
cd ./auto_EVO-COLMAP/ICL-NUIM

python3 evo_ICL-NUIM.py ~/dataset/ICL-NUIM/folders

#### 2). Tum dataset
cd ./auto_EVO-COLMAP/Tum

python3 evo_Tum.py ~/dataset/Tum/folders

#### 3). EuRoc dataset
cd ./auto_EVO-COLMAP/EuRoc

python3 evo_EuRoc.py ~/dataset/EuRoc/folders

# Specialty
## 1. Resume after interrupted
  If this project is stoped before it finishes 10 times evoluation, the process can be continued next time you want to run it. But you'd better delete the colmap_ws directory, because the function to count the time consuming will resume.
## 2. Automatically evoluate new sequences
  This project automatically run COLMAP-SFM on all sequneces in the folder "~/dataset/<dataset_name>/folders", and after the process is interrupted you can resume it without rerun the finished sequences and finished times in 10 times. In addition, if you add new sequences into the folder, it will automatically proceed the new sequnces without waste time on the finished sequences or finished times.
