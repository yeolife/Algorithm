#include <bits/stdc++.h>

using namespace std;

int n;
int ans_min = 1e9, ans_max = -1e9;
vector<int> vec;
int oper[4];

void dfs(int depth, int ret) {
    if(depth == n) {
        ans_max = max(ans_max, ret);
        ans_min = min(ans_min, ret);

        return;
    }
    
    // +-*/
    for(int i = 0; i < 4; i++) {
        if(!oper[i]) continue;
        
        oper[i]--;

        switch(i) {
            case 0:
                dfs(depth + 1, ret + vec[depth]);
                break;
            case 1:
                dfs(depth + 1, ret - vec[depth]);
                break;
            case 2:
                dfs(depth + 1, ret * vec[depth]);
                break;
            case 3:
                if(ret < 0 && vec[depth] >= 0) {
                    ret = abs(ret) / vec[depth];
                    ret *= -1;

                    dfs(depth + 1, ret);
                }
                else 
                    dfs(depth + 1, ret / vec[depth]);
                break;
        }
        
        oper[i]++;
    }
}

int main() {
    cin >> n;

    int num = 0;
    for(int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }

    for(int i = 0; i < 4; i++)
        cin >> oper[i];

    dfs(1, vec[0]);

    cout << ans_max << '\n' << ans_min;
}