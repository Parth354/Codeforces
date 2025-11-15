#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> houses;
    for(int i =0 ; i < n ; i++){
        int temp;
        cin>> temp;
        houses.push_back(temp);
    }
    int ans =0;
    for(int i = 1 ; i<houses.size()-1;i++){
        if(houses[i-1]&& houses[i+1] && !houses[i]){
            ans++;
            houses[i+1]=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}