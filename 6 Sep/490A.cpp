#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int,vector<int>> mapIdx;
    for(int i = 0 ; i< n ; i++){
        int temp;
        cin>> temp;
        mapIdx[temp].push_back(i+1);
    }
    int teams = min(mapIdx[1].size(),min(mapIdx[2].size(),mapIdx[3].size()));
    cout<<teams<<endl;

    for(int i = 0 ;i < teams ; i++){
        cout<<mapIdx[1][i]<<" "<<mapIdx[2][i]<<" "<<mapIdx[3][i]<<endl;
    }
    return 0;
}