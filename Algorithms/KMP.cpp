#include<bits/stdc++.h>
using namespace std;

int main() {

    string text = "abababbbaababaca";
    string pattern = "ababaca";

    auto build_lps = [&]( const string &p ) {
        int m = p.size();
        vector<int> lps(m,0);
        int i = 1 , len =0 ;
        while(i< m) {
            if(p[i] == p[len]){
                lps[i++] = ++len;
            }else {
                if(len != 0 ) {
                    len = lps[len-1];
                }else{                   
                    lps[i++] =0;  
                }
            }
        }
        return lps;
    };

    auto kmp = [&] (const string &s , const string &p) {
        int n = s.size() , m = p.size();
        vector<int> lps = build_lps(p);

        int j =0 , i =0;
        while(i < n  ) {
            if(p[j] == s[i]){
                i++;
                j++;
            }
            if(j==m){
                cout<<"Pattern found at index "<<i-j<<endl;
                j=lps[j-1];
            }
            if(i < n && p[j] != s[i]) {
                if(j!=0){
                    j = lps[j-1];
                }else {
                    i++;
                }
            }
        }
    };

    kmp(text,pattern);
    return 0;
}