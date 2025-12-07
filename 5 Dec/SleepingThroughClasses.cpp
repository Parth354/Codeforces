#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n , k;
        cin>>n>>k;
        string s;
        cin>>s;
        int sleepCount = 0;
        int awake = -1;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '0') {
                if(awake < i-k || awake == -1 ){
                sleepCount++;
                }
            }else{
                awake = i;
            }
        }
        cout<<sleepCount<<endl;
    }
    return 0;
}