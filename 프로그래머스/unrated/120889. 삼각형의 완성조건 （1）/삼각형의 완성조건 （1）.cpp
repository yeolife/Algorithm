#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sides) {
    int answer = 2;
    
    int a = sides[0];
    int b = sides[1];
    int c = sides[2];
    
    if(a < b) swap(a, b);
    if(a < c) swap(a, c);
    
    if(b + c > a) return 1; 
    
    return answer;
}