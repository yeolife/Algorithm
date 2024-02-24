#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

bool cmp(pair<int, int>& a, pair<int ,int>& b) {
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    int n, ans = 0;
    priority_queue<int> pq;
    vector<pair<int ,int> > vec;

    cin >> n;

    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;

        vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end(), cmp);

    int cnt = 10001;
    for(int i = 0; i < n; i++) {
        int p, d;
        tie(p, d) = vec[i];
        pq.push(p);

        if(cnt == d) continue;

        while(!pq.empty() && cnt > d) {
            ans += pq.top();
            pq.pop();
            cnt--;
        }
        
        cnt = d;
    }

    while(!pq.empty() && cnt > 1) {
        ans += pq.top();
        pq.pop();
        cnt--;
    }

    cout << ans;

    return 0;
}