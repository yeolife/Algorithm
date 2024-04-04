#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int degrees[32001];
vector<int> nodes[32001];

struct cmp {
    bool operator()(int& a, int& b) {
        return a > b;
    }
};

int main() {
   ios::sync_with_stdio(0); cin.tie(NULL);

    int n, m;
    priority_queue<int, vector<int>, cmp> pq;

    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;

        degrees[b]++;
        nodes[a].push_back(b);
    }

    for(int i = 1; i <= n; i++) {
        if(!degrees[i])
            pq.push(i);
    }

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        ans.push_back(cur);

        for(int i = 0; i < nodes[cur].size(); i++) {
            int next = nodes[cur][i];

            if(--degrees[next] == 0)
                pq.push(next);
        }
    }

    for(auto& it: ans)
        cout << it << ' ';

   return 0;
}