#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n,m;
char alpha[15];
bool visited[15];
string ans;
string mo="aeiou";

void bt(int idx, int cnt) {
    if(cnt==0) {
        if(ans.find_first_of(mo)==-1) return;
        if(ans.find_first_not_of(mo)==ans.find_last_not_of(mo)) return;
        for(int i=0; i<n; i++)
            cout << ans[i];
        cout << '\n';
        return;
    }
    for(int i=idx; i<m; i++) {
        if(visited[i]) continue;
        visited[i]=true;
        ans.push_back(alpha[i]);
        bt(i,cnt-1);
        visited[i]=false;
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++)
        cin >> alpha[i];
    sort(alpha,alpha+m);
    bt(0,n);
}