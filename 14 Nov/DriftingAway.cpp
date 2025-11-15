#include<iostream>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();

        bool hasL = false, hasR = false;
        for(char c : s) {
            if(c == '<') hasL = true;
            if(c == '>') hasR = true;
        }
        if(hasL && hasR) {
            cout << -1 << "\n";
            continue;
        }

        if(!hasL && !hasR) {
            cout << -1 << "\n";
            continue;
        }
        cout << n << "\n";
    }
    return 0;
}
