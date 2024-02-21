#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int dp[1001][1001][2];

int dfs(int idx, int prev, bool state) {
    if(idx == n) return 0;

    if(dp[idx][prev][state]) return dp[idx][prev][state];

    int ret = dfs(idx + 1, prev, state);

    if(!state) {
        if(arr[idx] > prev)
            ret = max(ret, dfs(idx + 1, arr[idx], state) + 1);
        else if(arr[idx] < prev)
            ret = max(ret, dfs(idx + 1, arr[idx], !state) + 1);
    }
    else {
        if(arr[idx] < prev)
            ret = max(ret, dfs(idx + 1, arr[idx], state) + 1);
    }

    return dp[idx][prev][state] = ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = dfs(0, 0, 0);

    cout << ans;

    return 0;
}