#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    long long s1, s2, s3 , s4;
    cin>>s1>>s2>>s3>>s4;
    unordered_set<long long> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    s.insert(s4);
    cout<<4- s.size()<<endl;
    return 0;
}