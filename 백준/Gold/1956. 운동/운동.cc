#include <bits/stdc++.h>
using namespace std;

int dp[401][401];

int main() {
    fill(&dp[0][0], &dp[400][401], 1e9);

    int v, e;
    cin >> v >> e;

    int x, y, d;
    for(int i = 0; i < e; i++) {
        cin >> x >> y >> d;
        dp[--x][--y] = d;
    }

    for(int k = 0; k < v; k++) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(i == j) dp[i][j] = 0;

                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 1e9;
    for(int i = 0; i < v; i++) {
        for(int j = i; j < v; j++) {
            if(i == j) continue;

            ans = min(ans, dp[i][j] + dp[j][i]);
        }
    }

    if(ans == 1e9) ans = -1;

    cout << ans;

    return 0;
}