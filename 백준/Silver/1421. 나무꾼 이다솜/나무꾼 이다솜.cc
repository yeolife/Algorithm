#include <bits/stdc++.h>
using namespace std;

long long n, c, w;
long long trees[51];

long long dfs(long long tree) {
    long long cnt = 0, cut = 0, ret = 0;

    for (int i = 0; i < n; i++) {
        if (trees[i] % tree > 0)
                cut = trees[i] / tree;
            else 
                cut = trees[i] / tree - 1;

        cnt = trees[i] / tree;

        long long good = (tree * cnt * w) - (cut * c);

        if(good > 0)
            ret += good;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> c >> w;

    for (int i = 0; i < n; i++)
        cin >> trees[i];

    sort(trees, trees + n);

    long long ans = trees[n - 1] * w;

    for (int i = 1; i <= 10000; i++)
        ans = max(ans, dfs(i));

    cout << ans;

    return 0;
}