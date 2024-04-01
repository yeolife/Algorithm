#include <bits/stdc++.h>
using namespace std;

struct coin {
    int p;
    int k;
};

int dp[10001];
coin coins[101];

int main() {

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; i++)
        cin >> coins[i].p >> coins[i].k;

    dp[0] = 1;

    for(int i = 0; i < k; i++) {
        for(int j = n; j >= coins[i].p; j--) {
            for(int z = 1; z <= coins[i].k; z++) {
                if(j - coins[i].p * z >= 0)
                    dp[j] += dp[j - coins[i].p * z];
            }
        }
    }

    cout << dp[n];

    return 0;
}