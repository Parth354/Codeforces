#include<iostream>
using namespace std;

int main(){
    int n=25;
    int index =0;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin>>temp;
        if(temp) index =i;
    }
    int i = (index /5) +1;
    int j = (index%5) + 1;
    int ans= abs(i-3) + abs(j-3);
    cout<<ans<<endl;
    return 0;
}