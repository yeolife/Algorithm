#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int coin[n];
    int dp[k+1];
    
    for(int i=0; i<n; i++)
        cin>> coin[i];
    fill(dp, dp+(k+1), 100001);
    dp[0]=0;
    for(int i=0; i<n; i++) {
        for(int j=coin[i]; j<=k; j++) {
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }
    if(dp[k]==100001) {
        cout << -1 << endl;
    }
    else
        cout << dp[k] << endl;
}