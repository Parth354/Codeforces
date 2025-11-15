#include<iostream>
#include<vector>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> rotations(n);
    for(int i =0 ; i < n ; i++) cin>> rotations[i];

    bool possible = false;
    for(int mask =0 ; mask < (1 << n ) ; mask++){
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(mask & (1<<i))
                sum+= rotations[i];
            else 
                sum-=rotations[i];
        }
        if((sum%360 +360 ) %360 == 0){
            possible = true;
            break;
        }
    }

    if(possible) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}