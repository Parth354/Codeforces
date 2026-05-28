#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> dp;

int solve(int n, int a, int b, int c) {
    if (n == 0) return 0;           // base: perfect cut
    if (n < 0) return INT_MIN;      // invalid cut
    if (dp[n] != -1) return dp[n];  // memoized

    int ca = solve(n - a, a, b, c);
    int cb = solve(n - b, a, b, c);
    int cc = solve(n - c, a, b, c);

    int ans = max(ca, max(cb, cc));

    if (ans == INT_MIN) return dp[n] = INT_MIN; // no valid cut
    return dp[n] = ans + 1; // valid cut, add this piece
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    dp.assign(n + 1, -1);

    int ans = solve(n, a, b, c);
    cout << ans << endl;
    return 0;
}
