#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
void change_rgbtxt(const string &srcFile,int num){
    ifstream f_i;
    ofstream f_o;
    f_i.open(srcFile.c_str());
    vector<string> s;
    int i(0);
    while(!f_i.eof())
    {
        if(i==num){
            break;
        }
        string local_s;
        getline(f_i,local_s);//此函数每次读一行,存在S中
        if(!local_s.empty())
        {
            if(local_s[0]=='#')
                continue;
            else{
                s.push_back(local_s);
                i++;
            }
        }
    }
    f_i.close();
    f_o.open(srcFile.c_str());

    for(int i=0 ; i<num-1; i++){
        f_o<<s[i]<<endl;
    }f_o<<s[num-1]<<endl;
}

void LoadImages(const string &strFile, vector<double> &vTimestamps)
{
    ifstream f;
    f.open(strFile.c_str());
    while(!f.eof())
    {
        string s;
        getline(f,s);//此函数每次读一行
        if(!s.empty())
        {
            if(s[0]=='#')
                continue;
            stringstream ss;
            ss << s;


            double t;
            ss >> t;
            //cout<<std::fixed<<t<<endl;
            vTimestamps.push_back(t);
            continue;
        }
    }

}
void WriteImages(const string &srcFile, vector<double> &vTimestamps)
{
    vector<string> string_lines;
    ifstream f_i;
    ofstream f_o;
    f_i.open(srcFile.c_str());
	int lines_N(0);
    while(!f_i.eof())
    {
        vector<string> String(8);
		string this_line;
        getline(f_i,this_line);//此函数每次读一行
        if(!this_line.empty())
        {
            if(this_line[0]=='#')
                continue;
			stringstream ss;
            ss << this_line;
			for(int i=0;i<8;i++){
				ss >> String[i];	
			}

            ss.str("");
            ss.clear();
            ss<<std::fixed<<vTimestamps[lines_N++];
			ss>>String[0];

			ss.str("");
            ss.clear();
			for(int i=0;i<7;i++){
				ss<<String[i]<<" ";
			}ss<<String[7];

            string_lines.push_back(ss.str());
        }
    }

    f_i.close();
    f_o.open(srcFile.c_str());

    for(int i=0; i<lines_N-1; i++){
        f_o<<string_lines[i]<<endl;
    }f_o<<string_lines[lines_N-1];

}

int main(int argc, char** argv)
{
    int Image_num(0),num(0);
    //cv::Mat img0=cv::imread("../rgb/0.png",cv::IMREAD_UNCHANGED);
    // while(1){
    //     num++;
    //     cv::Mat img=cv::imread("./rgb/"+to_string(num)+".png",cv::IMREAD_UNCHANGED);
    //     if(img.empty()){
    //         num--;
    //         break;zhon
    //     }
    //     //cout<<num<<endl;
    // }
    stringstream ss;
    ss<<argv[1];
    ss>>Image_num;
//    if(img0.empty()) {//从1开始
//        Image_num=num;
//    }else{
//        Image_num=num+1;
//    }

    change_rgbtxt(string(argv[2]),Image_num);//删除TUM中rgb.txt的多余部分
    vector<double> vTimestamps_rgb;
    LoadImages(string(argv[2]),vTimestamps_rgb);//取出rgb.txt时间戳

//    for(auto it: vTimestamps_rgb){
//        cout<<std::fixed<<it<<endl;
//    }

    WriteImages(string(argv[3]),vTimestamps_rgb);
//修改GT时间戳
    //remove("./ground_truth.txt");
    return 0;
}
