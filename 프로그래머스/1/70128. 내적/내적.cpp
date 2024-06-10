#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<int> b) {    
    for(int i = 0; i < a.size(); i++) a[i] *= b[i];
    
    return accumulate(a.begin(), a.end(), 0);
}