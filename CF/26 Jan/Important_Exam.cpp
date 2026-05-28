#include<iostream>
#include<vector>
using namespace std;

int main () {
    int n , m;
    cin >> n >> m;
    vector<string> answers(n);
    for(int i = 0 ; i < n ; i ++) {
        cin >> answers[i];
    }
    vector<vector<int>> scores(m ,vector<int>(5,0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            scores[j][answers[i][j] - 'A']++;
        }
    }
    vector<int> points(m);
    for(int i = 0 ; i < m ; i++) {
        cin >> points[i];
    }
    int ans = 0;
    for(int i = 0 ; i < m ; i++) {
        int maxScore = 0;
        for(int j = 0 ; j < 5 ; j++) {
            if(scores[i][j] >= maxScore) {
                maxScore = scores[i][j];
            }
        }
        maxScore *= points[i];
        ans += maxScore;
    }
    cout << ans << endl;
    return 0;
}