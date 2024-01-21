#include <bits/stdc++.h>
using namespace std;

int n, ans;
int alpha_cnt;
map<char, int> mp;
vector<int> vec;
string strs[10];
bool visited[10];

bool cmp(string a, string b) {
    return a.length() > b.length();
}

void dfs(int depth, int idx) {
    if(depth >= alpha_cnt) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int mul = 1;
            for(int j = strs[i].length()-1; j >= 0; j--) {
                sum += vec[mp[strs[i][j]]] * mul;

                mul *= 10;
            }
        }

        ans = max(ans ,sum);

        return;
    }

    for(int i = 9; i > 9 - alpha_cnt; i--) {
        if(visited[i]) continue;

        visited[i] = true;
        vec.push_back(i);

        dfs(depth + 1, i - 1);

        visited[i] = false;
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> strs[i];

    sort(strs, strs+n, cmp);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < strs[i].length(); j++) {
            if(mp.count(strs[i][j]) == 0) {
                mp[strs[i][j]] = alpha_cnt;
                alpha_cnt++;
            }
        }
    }

    dfs(0, 9);

    cout << ans;

    return 0;
}