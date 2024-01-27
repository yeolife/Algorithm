#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

bool check[1001];
vector<vector<int>> vec;

void bfs(int x, int n) {
    queue<int> q;
    check[x] = true;
    cout << x << " ";
    q.push(x);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=1; i<=n; i++) {
            if(vec[x][i] == true && check[i] == false) {
                check[i] = true;
                q.push(i);
                cout << i << " ";
            }
        }
    }
    cout <<'\n';
}

void dfs(int x, int n) {
    cout << x << " ";
    check[x]=true;
    for(int i=1; i<=n; i++) {
        //x, i가 연결되어있고 i를 가보지 않았던 경우
        if(vec[x][i] == 1 && check[i] == false)
            dfs(i, n);
    }
}

int main() {
    int n,m,start;
    cin >> n >> m >> start;
    vec.assign(n+1, vector<int>(n+1,0));

    for(int i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        vec[a][b]=1;
        vec[b][a]=1;
    }
    memset(check, 0, sizeof(check));
    dfs(start,n);
    cout << endl;
    memset(check, 0, sizeof(check));
    bfs(start,n);
}