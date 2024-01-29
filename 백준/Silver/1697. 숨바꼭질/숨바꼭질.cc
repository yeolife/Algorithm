#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    io();
    int n,k;
    cin >> n >> k;
    int dp[100001];
    for(int i=0; i<=n; i++) {
        dp[i]=n-i;
    }
    for(int i=n+1; i<=k; i++) {
        // 짝수
        if(i%2==0)
            dp[i]=min(dp[i/2],dp[i-1])+1;
        // 홀수
        else
            dp[i]=min(dp[i-1],min(dp[(i+1)/2],dp[(i-1)/2])+1)+1;
    }
    cout << dp[k];
}