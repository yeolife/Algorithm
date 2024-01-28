#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,dp[100001]; cin >> n >> k;
    for(int i=0; i<=n; i++)
        dp[i]=n-i;
    for(int i=n+1; i<=k; i++) {
        if(i%2==0) dp[i]=min(dp[i/2],dp[i-1]+1);
        else dp[i]=min(dp[i-1]+1,min(dp[(i+1)/2],dp[(i-1)/2])+1);
    }
    cout << dp[k];
}