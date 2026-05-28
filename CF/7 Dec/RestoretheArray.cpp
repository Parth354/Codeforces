#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n-1);
        for(int i = 0 ; i < n-1 ; i++) {
            cin>>arr[i];
        }
        int  j=0;
        vector<int> result(n,0);
        for(int i = 0 ; i < n-2 ; i++ ) {
            if(arr[i] < arr[i+1]) {
                result[j] = arr[i];
                
            }else{
                result[j] = arr[i];
                j++;
            }
        }
        for(int i = 0 ; i < n-1 ; i++ ) {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}