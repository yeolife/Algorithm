#include <bits/stdc++.h>
using namespace std;

int n, ans;
int alpha_cnt;
int mp[27];
vector<int> vec(10);
string strs[10];
char ch[10];
bool visited[10];

void dfs(int depth) {
    if(depth == alpha_cnt) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int mul = 1;
            for(int j = strs[i].length()-1; j >= 0; j--) {
                sum += mp[strs[i][j] - 'A'] * mul;
                mul *= 10;
            }
        }

        ans = max(ans ,sum);
        return;
    }

    for(int i = 0; i < 10; i++) {
        if(visited[i] == true) continue;

        visited[i] = true;
        mp[ch[depth] - 'A'] = i;

        dfs(depth + 1);

        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> strs[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < strs[i].length(); j++) {
            bool flag = false;
            for (int k = 0; k < alpha_cnt; k++) {
                if (ch[k] == strs[i][j]) {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;

            ch[alpha_cnt++] = strs[i][j];
        }
    }

    dfs(0);

    cout << ans;

    return 0;
}