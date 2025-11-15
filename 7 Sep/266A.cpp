#include<iostream>
using namespace std;

int main(){
    int n;
    int ans =0;
    char prev = ' ';
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        char temp ;
        cin>> temp;
        if(temp== prev){
            ans++;
        }
        else prev = temp;
    }
    cout<<ans<<endl;
    return 0;
}