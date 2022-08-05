#include"utils.h"

#include<bits/stdc++.h>

using namespace std;

void write_img(vector<vector<vector<int>>> img, std::string filename, int img_height, int img_width){
    ofstream f;
    cout<<"writing image";
    f.open(filename);
    f<< "P3\n" << img_width << " " << img_height << "\n255\n";
    for (int i =0; i<img_height; i++){
        for (int j = 0; j<img_width; j++){
            f<<img[i][j][0]<<" "<<img[i][j][1]<<" "<<img[i][j][2]<<"\n";
        }
    }   
    f.close();
}