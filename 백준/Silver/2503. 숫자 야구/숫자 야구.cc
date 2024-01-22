#include <bits/stdc++.h>
using namespace std;

using tiii = tuple<int, int, int>;

int n, ans;
tiii quests[101];
bool visited[10];

bool check(int youngsu, tiii quest) {
    int minheock, strike, ball;
    tie(minheock, strike, ball) = quest;

    vector<int> a, b;
    while(youngsu > 0) {
        a.push_back(youngsu % 10);
        b.push_back(minheock % 10);

        youngsu /= 10;
        minheock /= 10;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(a[i] == b[j] && i == j)
                strike--;
            else if(a[i] == b[j]) ball--;
        }
    }

    if(strike == 0 && ball == 0) 
        return true;

    return false;
}

void dfs(int depth, int num) {
    if(depth == 1000) {
        for(int i = 0; i < n; i++) {
            if(!check(num, quests[i])) 
                return;
        }
        ans++;

        return;
    }

    for(int i = 1; i <= 9; i++) {
        if(visited[i]) continue;

        visited[i] = true;
        dfs(depth * 10, num + (depth * i));
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    int q, st, ba;
    for(int i = 0; i < n; i++) {
        cin >> q >> st >> ba;
        quests[i] = {q, st, ba};
    }

    dfs(1, 0);

    cout << ans;

    return 0;
}