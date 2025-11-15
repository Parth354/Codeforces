#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> children;
    int maxCandies = 0;
    int maxTimes=0;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin>> temp;
        children.push_back(temp);
        double modu = (double)temp / m;
        int curr = ceil(modu);
        if(curr >= maxTimes){
            maxCandies = i;
            maxTimes = curr;
        }
    }
    cout<<maxCandies+1<<endl;
    return 0;
}