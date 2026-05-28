#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dp;
bool solve(vector<int>& rotations, int idx , int angle){
    if(idx == rotations.size()){
        if(!angle) return true;
        return false;
    }
    if(dp[idx][angle] != -1) return dp[idx][angle];
    int ans = false;
    int clockwiseAngle = (((angle + rotations[idx])%360)+360)%360;
    int anticlockwiseAngle = (((angle - rotations[idx])%360)+360)%360;
    ans = ans || solve(rotations, idx+1 , clockwiseAngle);
    ans = ans || solve(rotations, idx+1 ,anticlockwiseAngle);
    return dp[idx][angle]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> rotations;
    dp.assign(n, vector<int>(361,-1));
    for(int i =0 ; i < n ; i++){
        int temp;
        cin>> temp;
        rotations.push_back(temp);
    }
    if(solve(rotations,0, 0)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;    
}