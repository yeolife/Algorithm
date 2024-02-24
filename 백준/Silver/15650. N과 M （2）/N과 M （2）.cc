#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n,m;
bool visited[9];

void bt(int idx,int cnt) {
    if(cnt==m) {
        for(int i=1; i<=n; i++) {
            if(visited[i])
                cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=idx; i<=n; i++) {
        if(visited[i]) continue;
        visited[i]=true;
        bt(i+1,cnt+1);
        visited[i]=false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    bt(1,0);
}