#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        long long currInversionCount =0;
        long long zeroCount =0;
        long long oneCount = 0;
       for(int i = 0 ; i < n ; i++) {
            if(arr[i]) {
                oneCount++;
            }else{
                currInversionCount += oneCount;
            }
        }
        long long maxInversionCount = currInversionCount;
        zeroCount = n - oneCount;
        oneCount = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]) {
                long long updatedInversionCount = currInversionCount - zeroCount + oneCount ;
                maxInversionCount = max(maxInversionCount,updatedInversionCount);
                oneCount++;
            }else {
                zeroCount--;
                long long updatedInversionCount = currInversionCount + zeroCount - oneCount ;
                maxInversionCount = max(maxInversionCount,updatedInversionCount);
            }
        }
        cout << maxInversionCount << endl;
    }
    return 0 ;
}