#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

int read_TimeStamps(vector<string> &lines, vector<long double> &vTimeStamps, string KeyFrameTrajectory_Path){
    int size=0;
    fstream KeyFrameTrajectory;
    KeyFrameTrajectory.open(KeyFrameTrajectory_Path);
    long double timeStamp;
    while(!KeyFrameTrajectory.eof()) {
        string s;
        stringstream ss;
        getline(KeyFrameTrajectory, s);//此函数每次读一行,存在S中
        if (!s.empty()) {
            if (s[0] == '#')
                continue;
            lines.push_back(s);
            ss << s;
            ss >> timeStamp;
            
            vTimeStamps.push_back(timeStamp);
            ss.clear();
            ss.str("");
            size++;
        }
    }
    KeyFrameTrajectory.close();
    return size;
}



void sort_KeyFrameTrajectory(int size, vector<string> &lines, vector<long double> &vTimeStamps){
    string temp_string;
    long double temp_double;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size ;j++){
            if(vTimeStamps[j]<vTimeStamps[i]){
                temp_double=vTimeStamps[i];
                vTimeStamps[i]=vTimeStamps[j];
                vTimeStamps[j]=temp_double;

                temp_string=lines[i];
                lines[i]=lines[j];
                lines[j]=temp_string;
            }
        }
    }
    // for(int i=0; i<size; i++){
    //     cout<<std::fixed<<vTimeStamps[i]<<endl;
        
    // }
}



int main()
{

    vector<long double> vTimeStamps;
    vector<string>  lines;
    int size = read_TimeStamps(lines, vTimeStamps, "./KeyFrameTrajectory.txt");
    sort_KeyFrameTrajectory(size, lines, vTimeStamps);

    fstream KeyFrameTrajectory;
    KeyFrameTrajectory.open("./KeyFrameTrajectory.txt",ios::out);
    for(int i=0; i<size; i++){
        //cout<<lines[i]<<endl;
        KeyFrameTrajectory<<lines[i]<<endl;
    }
    KeyFrameTrajectory.close();
    return 0;
}



