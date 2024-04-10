#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int building[100001], dist[100001], ans[100001];
stack<pii> st;

int main() {
    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> building[i];

    memset(ans, -1, sizeof(ans));

    // 정방향
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().first <= building[i])
            st.pop();

        if(!st.empty())
            ans[i] = st.top().second;

        dist[i] += st.size();
        st.push({building[i], i});
    }

    st = stack<pii>();

    // 역방향
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top().first <= building[i])
            st.pop();

        if(!st.empty() && ((abs(i - ans[i]) > abs(i - st.top().second)) || ans[i] == -1))
            ans[i] = st.top().second;

        dist[i] += st.size();
        st.push({building[i], i});
    }

    for(int i = 0 ; i < n; i++) {
        cout << dist[i];
        if(dist[i] > 0) cout << ' ' << ans[i] + 1;
        cout << '\n';
    }

    return 0;
}