#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9;
int snowman[601];

int twoPoint(int k, int st, int en) {
    int ret = 1e9;

    while (st < en) {
        int sum = snowman[st] + snowman[en];

        ret = min(ret, abs(k - sum));

        if (sum > k) en--;
        else if(sum <= k) st++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> snowman[i];

    sort(snowman, snowman + n);

    // 바깥 2개를 조합으로 뽑는다.
    int outSnowMan, inSnowMan;
    for(int i = 0; i < n - 3; i++) {
        for (int j = i + 3; j < n; j++) {
            outSnowMan = snowman[i] + snowman[j];

            inSnowMan = twoPoint(outSnowMan, i + 1, j - 1);
            ans = min(ans, inSnowMan);
        }
    }

    cout << ans;

    return 0;
} 