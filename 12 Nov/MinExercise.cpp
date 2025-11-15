#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int e , n;
    cin>> e>>n;
    vector<int> ex;
    for(int i = 0 ; i < n ; i++ ) {
        int temp;
        cin>> temp;
        ex.push_back(temp);
    }
    sort(ex.begin(),ex.end(),[](int a ,int b){
        return a>b;
    });
    int curr=0;
    int moves=0;
    for(int i = 0 ; i < ex.size() ; i++){
        curr+= ex[i];
        moves++;
        if(curr < e){
            curr+= ex[i];
            moves++;
        }else break;
    }
    if(curr>= e)cout<<moves<<endl;
    else cout<<-1<<endl;
    return 0;
}