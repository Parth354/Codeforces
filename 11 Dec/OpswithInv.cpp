#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin>>nums[i];
        }
        int count = 0;
        for(int i = 0 ; i < n ; ) {
            int last = -1;
            int lastDiff = INT_MAX;
            for(int j = i+1 ; j< n ; j ++) {
                if(nums[j] == 0) continue;
                if(nums[i] > nums[j] && nums[i] - nums[j] < lastDiff) {
                    last = j;
                    lastDiff = nums[i] - nums[j];
                }
            }
            if(last != -1) {
                nums[last] = 0;
                count++;
            }else{
                i++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}