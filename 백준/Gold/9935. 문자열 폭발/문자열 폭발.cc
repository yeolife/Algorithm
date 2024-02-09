#include <bits/stdc++.h>

using namespace std;

string solve(string str, string boom) {
    stack<char> st;

    int idx = boom.length()-1;
    for(int i = 0; i < str.length(); i++) {
        st.push(str[i]);

        if(st.top() == boom[idx] && st.size() >= boom.length()) {
            bool flag = false;
            string target = "";
            while(!st.empty() && st.top() == boom[idx]) {
                target += st.top();
                st.pop();

                if(idx == 0) {
                    flag = true;
                    break;
                }
                
                idx--;
            }

            if(!flag) {
                for(int i = target.length() - 1; i >= 0; i--)
                    st.push(target[i]);
            }

            idx = boom.length()-1;
        }
    }

    string ret = "";
    while(!st.empty()) {
        ret += st.top();
        st.pop();
    }

    reverse(ret.begin(), ret.end());

    if(ret.empty())
        ret = "FRULA";

    return ret;
}

int main() {
    string str, boom;
    cin >> str >> boom;
    
    string ans = solve(str, boom);

    cout << ans;
}