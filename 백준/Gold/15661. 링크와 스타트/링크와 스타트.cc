#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9;
int board[21][21];
bool visited[21];

void dfs(int depth, int idx) {
	if(depth <= (n+1) / 2) {
		int a = 0, b = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if(visited[i] && visited[j])
					a += board[i][j];
				if(!visited[i] && !visited[j])
					b += board[i][j];
			}
        }

        ans = min(ans, abs(a - b));
	}
	
    for(int i = idx; i < n; i++) {
     
	    if(visited[i]) continue;

        visited[i] = true;
        dfs(depth + 1, i);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            cin >> board[i][j];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++)
        	board[i][j] += board[j][i];
    }

    dfs(0, 0);

    cout << ans << '\n';

    return 0;
}