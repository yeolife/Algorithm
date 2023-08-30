#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[1001] = {0};
    int MAX = -1;
    int ans = 0;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        bool visited[1001] = {0,};

        visited[i] = true;

        int cur = arr[i];
        while(1) {
            if(visited[cur]) break;

            visited[cur] = true;
            cur = arr[cur];
            cnt++;
        }

        if(cnt > MAX) {
            ans = i;
            MAX = cnt;
        }  
    }

    cout << ans;
}