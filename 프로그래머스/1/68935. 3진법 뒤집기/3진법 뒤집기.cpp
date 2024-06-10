#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int ans = 0;
    string sam = "";
    
    while(n != 0) {
        sam += (n % 3) + '0';
        n /= 3;
    }
    
    int cur = 0;
    for(int i = sam.length() - 1; i >= 0; i--) {
        ans += (sam[i] - '0') * pow(3, cur);
        cur++;
    }
    
    return ans;
}