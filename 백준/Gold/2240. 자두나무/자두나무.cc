#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    int t,w;
    int dp[1001][31]={0,};

    cin >> t >> w;

    int n;
    for(int i=1; i<=t; i++) {
        cin >> n;
        for(int j=0; j<=min(i, w); j++) {
            int flag=0;
            if((!(j & 1) && n == 1) || (j & 1 && n == 2))
                flag=1;
            if(j==0)
                dp[i][j]=dp[i-1][j]+flag;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])+flag;
        }
    }

    int ans=0;
    for(int i=0; i<=w; i++)
        ans = max(ans, dp[t][i]);

    cout << ans;

    return 0;
}