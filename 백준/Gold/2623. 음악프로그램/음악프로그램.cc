#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;
vector<int> singer[1001];
int degrees[1001];

int main() {
    cin >> n >> m;

    int k, x, y;
    for(int i = 0; i < m; i++) {
        cin >> k >> x;

        for(int j = 1; j < k; j++) {
            cin >> y;

            degrees[y]++;
            singer[x].push_back(y);
            x = y;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!degrees[i]) {
            q.push(i);
            ans.push_back(i);
        }
    }


    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < singer[cur].size(); i++) {
            int next = singer[cur][i];

            if(!--degrees[next]) {
                q.push(next);
                ans.push_back(next);
            }
        }
    }

    if(ans.size() != n) cout << 0;
    else {
        for(auto& it: ans)
            cout << it << '\n';
    }

    cout << '\n';

    return 0;
}