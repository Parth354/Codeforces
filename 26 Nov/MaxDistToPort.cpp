#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int main() {
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<int> types (n);
    for(int i = 0 ; i < n ; i ++){
        cin>>types[i];
    }
    vector<vector<int>> ports(n);
    for(int i  = 0 ; i <  m ; i++) {
        int a , b;
        cin>> a>>b;
        ports[a-1].push_back(b-1);
        ports[b-1].push_back(a-1);
    }

    vector<int> ans(k,INT_MAX);
    queue<pair<int,int>> q;
    q.push({0,0});
    ans[types[0]-1] = 0;
    vector<bool> visited(n,false);
    visited[0] = true;
    while(!q.empty()) {
        auto t =  q.front();
        int curr = t.first;
        int dist = t.second;
        q.pop();
        for(int i = 0 ; i< ports[curr].size() ; i++) {
            int j = ports[curr][i];
            if( !visited[j]) {
                q.push({j, dist + 1});
                visited[j] = true;
                if(ans[types[j]-1 ] == INT_MAX || ans[types[j]-1] < dist + 1 ) {
                    ans[types[j]-1] = dist + 1;
                }
            }
        }
    }
    for(int i = 0 ; i < k ; i++) {
        if(ans[i] == INT_MAX) {
            cout<< -1 << " ";
        } else {
            cout<< ans[i] << " ";
        }
    }
    return 0;
}