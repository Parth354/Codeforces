#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , a;
        cin>>n>>a;
        vector<int> marbles;
        int sum =0;
        for(int i = 0 ; i < n ; i ++){
            int temp;
            cin>>temp;
            marbles.push_back(temp);
            sum+= temp;
        }
        int lsum=0;
        int count=0;
        for(int i = 0 ; i < marbles.size() ; i++){
            if(marbles[i] < a){
            lsum += marbles[i];
            count++;
            }
        }
        if(n - count > count) cout<<a+1<<endl;
        else cout<<a-1<<endl;
    }
    return 0;
}