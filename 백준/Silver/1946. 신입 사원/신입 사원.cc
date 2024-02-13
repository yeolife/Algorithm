#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);


    int t;
    cin >> t;

    for(int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        vector<pair<int, int> > vec;

        int a, b;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            vec.push_back({a, b});
        }

        sort(vec.begin(), vec.end());
    
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        int ans = 1;
        pq.push(vec[0]);

        for(int i = 1; i < n; i++) {            
            if(pq.top().second > vec[i].second) ans++;

            pq.push(vec[i]);
        }
        
        cout << ans << '\n';
    }
}