#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   ios::sync_with_stdio(0); cin.tie(NULL);

    int n;
    ll ret = 1e18;
    ll ans[3] = {0, }, liquid[5001] = {0,};

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> liquid[i];

    sort(liquid, liquid + n);

    for(int i = 0; i < n - 2; i++) {
        ll target = liquid[i];

        int st = i + 1, en = n - 1;

        while (st < en) {
            ll mix = target + liquid[st] + liquid[en];
            if(ret > abs(mix)) {
                ans[0] = target;
                ans[1] = liquid[st];
                ans[2] = liquid[en];

                ret = abs(mix);
            }

            if (0 > mix) st++;
            else  en--;
        }
    }

    sort(ans, ans + 3);

    for(auto& it: ans)
        cout << it << ' ';

   return 0;
}