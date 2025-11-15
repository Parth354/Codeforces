#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<long long>& a , long long targetLower , long long targetUpper , int idx ){
    int l = idx+1;
    int r = a.size()-1;
    int lower =-1;
    while(l <= r){
        int mid = l +(r-l)/2;
        if(a[mid] >= targetLower) {
            r = mid-1;
            lower=mid;
        }else if(a[mid] < targetLower ) {
            l = mid+1;
        }
    }
    l = idx+1;
    r = a.size()-1;
    int upper =-1;
    while(l <= r){
        int mid = l +(r-l)/2;
        if(a[mid] > targetUpper) {
            r = mid-1;
        }else if(a[mid] <= targetUpper ) {
            l = mid+1;
            upper=mid;
        }
    }
    if(upper!=-1 && lower!= -1){
            if(a[upper] >= targetLower && a[lower] <= targetUpper ) 
                return upper - lower +1;
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    long long n , l ,r ;
    cin>>n>>l>>r;
    vector<long long>a(n);
    for(int i =0 ;i < n ; i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long ans=0;
    for(int i = 0 ; i < n ; i++){
        long long tarl= l-a[i];
        long long tarr = r-a[i];
        long long pairs = binarySearch(a , tarl,tarr,i);
        ans+= pairs;
    }
    cout<<ans<<endl;
    }
    return 0;
}