#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int n; 
    cin>> n;
    vector<int>b(n);
    for(int i = 0 ; i < n ; i++ ) {
        cin>>b[i];
    }
    unordered_map<int,int> votes;
    vector<int> a;
    for(int i = 0 ; i< n ; i++) {
        a.push_back(min(i, n-i-1));
    }
    int m = 0;
    for(int i = 0 ; i < n ; i++) {
        int x = b[i]-a[i];
        votes[x]++;
        m = max(m, votes[x]);
    }
    cout<<n-m<<endl;
    return 0;
}