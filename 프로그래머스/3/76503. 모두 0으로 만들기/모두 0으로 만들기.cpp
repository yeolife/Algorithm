#include <bits/stdc++.h>
using namespace std;

int degree[300001];
vector<int> nodes[300001];

long long solution(vector<int> A, vector<vector<int>> edges) {
    long long ans = 0;
    vector<long long> a;
    
    for(int i = 0; i < A.size(); i++)
        a.push_back(A[i]);
    
    if(accumulate(a.begin(), a.end(), 0ll)) return -1;

    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        degree[a]++;
        degree[b]++;

        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    queue<int> q;
    
    for(int i = 0; i < a.size(); i++) {        
        if(degree[i] == 1)
            q.push(i);
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        degree[cur]--;
        
        for(int i = 0; i < nodes[cur].size(); i++) {
            int next = nodes[cur][i];

            if(!degree[next]) continue;
            
            degree[next]--;
            a[next] += a[cur];
            ans += abs(a[cur]);

            if(degree[next] == 1)
                q.push(next);
            
            break;
        }
    }

    return ans;
}