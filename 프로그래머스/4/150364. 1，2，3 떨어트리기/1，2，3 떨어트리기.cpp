#include <bits/stdc++.h>
using namespace std;

vector<int> cycle;
int root[101], cnt[101];
vector<int> nodes[101];

void find_seq(int n) {
    if(root[n] == -1) {
        cycle.push_back(n);
        return;
    }

    find_seq(root[n]);
}

void move(int n) {
    if(root[n] == -1) return;

    int cur = root[n];
    int nsz = nodes[n].size();
    int idx = (cnt[n] + 1) % nsz;
    cnt[n] = idx;
    root[n] = nodes[n][idx];

    move(cur);
}

void find_cycle() {
    bool flag;

    do {
        flag = true;

        find_seq(0);
        move(0);

        for(int i = 0; i < 101; i++) {
            if(cnt[i] != 0)
                flag = false;
        }
    } while(!flag);
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> ans, src(target.size(), 0);

    for(int i = 0; i < edges.size(); i++) {
        int p = edges[i][0] - 1, c = edges[i][1] - 1;

        nodes[p].push_back(c);
    }

    memset(root, -1, sizeof(root));

    for(int i = 0; i < 101; i++) {
        sort(nodes[i].begin(), nodes[i].end());

        if(!nodes[i].empty())
            root[i] = nodes[i][0];
    }

    find_cycle();

    int tc = target.size();
    for(int i = 0; i < target.size(); i++) {
        if(target[i]) tc--;
    }
    
    int sz = 0;
    bool visited[101] = {0, };
    for(int i = 0; i <= 10000; i++) {
        int cur = cycle[i % cycle.size()];
        src[cur]++;

        if(src[cur] <= target[cur] && target[cur] <= src[cur] * 3 && !visited[cur]) {
            tc++;
            visited[cur] = true;
        }

        if(src[cur] > target[cur])
            return {-1};

        sz++;

        if(tc == target.size()) break;
    }

    for(int i = 0; i < sz; i++) {
        int cur = cycle[i % cycle.size()];

        src[cur]--;
        for (int j = 1; j <= 3; j++) {
            if (src[cur] <= target[cur] - j && target[cur] - j <= 3 * src[cur]) {
                ans.push_back(j);
                target[cur] -= j;
                break;
            }
        }
    }

    return ans;
}