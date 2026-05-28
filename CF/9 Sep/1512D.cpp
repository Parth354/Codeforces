#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
     while (t--) {
        int n; cin >> n;
        vector<long long> b(n + 2);
        long long total = 0;
        for (int i = 0; i < n + 2; ++i) { cin >> b[i]; total += b[i]; }
        sort(b.begin(), b.end());

        bool ok = false;

        for (int j = n + 1; j >= n && !ok; --j) {
            long long S = b[j];
            long long x = total - 2LL * S;
            if (x < 0) continue;

            int idx = -1;
            for (int i = 0; i < n + 2; ++i) {
                if (i == j) continue; 
                if (b[i] == x) { idx = i; break; }
            }

            if (idx != -1) {
                for (int i = 0; i < n + 2; ++i) {
                    if (i == j || i == idx) continue;
                    cout << b[i] << " ";
                }
                cout << "\n";
                ok = true;
            }
        }

        if (!ok) cout << -1 << "\n";
    }
    return 0;
}