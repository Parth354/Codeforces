#include<iostream>
#include<vector>
using namespace std;

int main(){
    string exp;
    cin>>exp;
    vector<int> count(3,0);
    for(int i = 0 ; i < exp.size() ; i++){
        if(exp[i] == '+') continue;
        int digit = exp[i]-'0';
        count[digit-1]++;
    }
    int digit = 0;
    for(int i = 0; i < exp.size();i++){
        while(count[digit] == 0) digit++;
        if(exp[i] =='+') continue;
        char d= (digit+1)+'0';
        exp[i]=d;
        count[digit]--;
    }
    cout<<exp<<endl;
    return 0;
}