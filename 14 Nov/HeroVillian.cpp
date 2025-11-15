#include<iostream>
using namespace std;

int ans(int arr[],int n , int m , int h){
    int total = 0;
    for(int i = 0 ; i < n ; i++) total += arr[i];
    if(total <= m *h) return 0;
    else {
        int sumh = 0 ;
        int totalhero = m *h ;
        for(int i = n -1 ; i >0 ; i--) {
            sumh += arr[i];
            if(sumh >= totalhero) {
                return i;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int m ;
    cin>>m;
    int h;
    cin>>h;
    int* arr = new int[n];
    for(int i =0; i<n; i++){ 
        cin>>arr[i];
    }
    cout<<ans(arr,n,m,h);
    delete[] arr;
    return 0;
}