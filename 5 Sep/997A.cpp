#include<iostream>
using namespace std;

int main(){
    long long n ;
    int k;
    cin >> n >> k;
    while(k){
        int lastDigit = n % 10;
        if(lastDigit < k){
            k-= (lastDigit+1);
            n = n/10;
        }
        else if(lastDigit && lastDigit >= k){
            n-= k;
            k=0;
        }else{
            n/=10;
            k--;
        }
    }
    cout<<n<<endl;
    return 0;
}