#include <bits/stdc++.h>
using namespace std;

struct app {
    int m;
    int p;
};

app apps[101];
int dp[10001] = {0,};

int main() {
    int n, k;

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> apps[i].m;
    for(int i = 0; i < n; i++)
        cin >> apps[i].p;

    for(int i = 0; i < n; i++) {
        for(int j = 10000; j >= apps[i].p; j--)
            dp[j] = max(dp[j], dp[j - apps[i].p] + apps[i].m);
    }

    int ans = 0;
    for(int i = 0; i <= 10000; i++) {
        if(dp[i] >= k) {
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}