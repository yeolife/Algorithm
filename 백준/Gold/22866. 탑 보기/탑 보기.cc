#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

stack<pii> st;
int building[100001], dist[100001], ans[100001];

int main() {
    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> building[i];

    // 정방향
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().first <= building[i])
            st.pop();

        dist[i] += st.size();

        if(!st.empty() && !ans[i])
            ans[i] = st.top().second + 1;

        st.push({building[i], i});
    }

    st = stack<pii>();

    // 역방향
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top().first <= building[i])
            st.pop();

        dist[i] += st.size();

        if(!st.empty()) {
            if (ans[i] == 0)
                ans[i] = st.top().second + 1;
            else if (abs(i - (ans[i] - 1)) > abs(i - st.top().second))
                ans[i] = st.top().second + 1;
        }

        st.push({building[i], i});
    }

    for(int i = 0 ; i < n; i++) {
        if (dist[i] == 0)
            cout << 0 << '\n';
        else
            cout << dist[i] << ' ' << ans[i] << '\n';
    }

    return 0;
}