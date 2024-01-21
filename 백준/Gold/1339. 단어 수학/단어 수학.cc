#include <bits/stdc++.h>
using namespace std;

int n, ans;
int alpha_cnt;
map<char, int> mp;
vector<int> vec(10);
string strs[10];
bool visited[10];

bool cmp(string a, string b) {
    return a.length() > b.length();
}

void dfs(int depth) {
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
        if(visited[i]) continue; // 중복되는 알파벳이면 패스

        visited[i] = true;
        vec[depth] = i;

        dfs(depth + 1);

        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> strs[i];

    sort(strs, strs+n, cmp);

    // 9부터 알파벳의 개수만큼 순열을 돌림
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < strs[i].length(); j++) {
            if(mp.count(strs[i][j]) == 0) {
                mp[strs[i][j]] = alpha_cnt;
                alpha_cnt++;
            }
        }
    }

    dfs(0);

    cout << ans;

    return 0;
}

// 벡터에 알파벳의 종류를 넣는다
// 중복되지 않고, 이전것을 참조하지 않으면서 벡터에 순열을 만든다.
// 만약에 모든 순열이 완성되면, 

// 알파벳 -> 순번
// 알파벳은 크기가 되어야함. (ex A = 9, B = 7)
// 벡터에서는 순서에 따라 크기를 부여할 예정.(1번째 숫자는 9, 2번째는 8..)