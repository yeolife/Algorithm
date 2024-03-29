#include <bits/stdc++.h>
using namespace std;

struct thing {
    int w;
    int p;
};

int main() {
    int n, k;
    thing things[101];
    int dp[100001] = {0,};

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> things[i].w >> things[i].p;

    for(int i = 0; i < n; i++) {
        for(int j = k; j >= things[i].w; j--) {
            dp[j] = max(dp[j], dp[j - things[i].w] + things[i].p);
        }
    }

    cout << dp[k];

    return 0;
}