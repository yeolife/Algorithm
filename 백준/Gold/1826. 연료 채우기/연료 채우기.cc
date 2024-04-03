#include <bits/stdc++.h>
using namespace std;

struct oilBank {
    int d;
    int w;
};

int n, ans;
int dest, cw;
oilBank oilBanks[10001];

bool cmp(oilBank& a, oilBank& b) {
    if(a.d == b.d)
        return a.w > b.w;
    return a.d < b.d;
};

int main() {
   ios::sync_with_stdio(0); cin.tie(NULL);

   priority_queue<int> pq;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> oilBanks[i].d >> oilBanks[i].w;

    cin >> oilBanks[n].d >> oilBanks[n].w;

    swap(cw, oilBanks[n].w);

    sort(oilBanks, oilBanks + n + 1, cmp);

    int cur = 0;
    bool flag = false;
    for(int i = 0; i <= n; i++) {
        oilBank next = oilBanks[i];

        cw -= next.d - cur;
        cur = next.d;

        while(!pq.empty() && cw < 0) {
            cw += pq.top();
            pq.pop();
            ans++;
        }

        if(cw < 0) break;

        pq.push(next.w);

        if(cw >= 0 && i == n) flag = true;
    }

    if(!flag) ans = -1;

    cout << ans;

   return 0;
}