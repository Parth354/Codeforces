#include<iostream>
#include<vector>
using ll = long long;
using namespace std;

int main(){
    int n ;
    cin>>n;
    vector<ll> l(n);
    for(int i =0 ; i < n ; i++) {
        cin>>l[i];
    }
    ll maxReduction = 0;
    for(int i = 0 ; i <  n-1 ; i ++) {
        if(l[i] <= l[i+1]) {
        ll need = l[i+1] - ( l[i]  -1 );
        maxReduction = max(maxReduction , need); 
        l[i+1]  = l[i] - 1 ;
        }
    }
    if(maxReduction <= 0 ) {
        cout<<0<<endl;
        return 0;
    }

    int days = 0;
    while( ( (1ll << days ) -1) < maxReduction && days < 61) {
        days++;
    }
    cout<<days<<endl;
    return 0;
}