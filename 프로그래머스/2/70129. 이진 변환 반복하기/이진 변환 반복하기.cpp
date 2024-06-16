#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s != "1") {
        int one = count(s.begin(), s.end(), '1');
        int zero = s.length() - one;
        
        answer[0]++;
        answer[1] += zero;
        
	    s = bitset<150000>(one).to_string();
        s = s.substr(s.find('1'));
    }
    
    return answer;
}