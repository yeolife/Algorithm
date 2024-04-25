#include <bits/stdc++.h>

using namespace std;

vector<string> binary_num;

string DtoB(long long num) {
    string ret = "";

    while(num != 0) {
        ret += (num % 2) + '0'; 

        num /= 2;
    }
    
    int i = 1;
    while(ret.length() >= i) 
        i *= 2;
            
    for(int j = ret.length(); j < i - 1; j++) 
        ret += '0';
                        
    return ret;
}

int go(string tree, int st, int en, int cur) {
	if (st == en) return tree[cur] - '0';

	int n1 = go(tree, st, cur - 1, (st + (cur - 1)) / 2);
	int n2 = go(tree, cur + 1, en, (en + (cur + 1)) / 2);
    
    if(n1 == 2 || n2 == 2) return 2;
    
    if(!(tree[cur] - '0')) {
        if(n1 || n2) 
            return 2;
    }
    	
	return tree[cur] - '0';
}

vector<int> solution(vector<long long> numbers) {
    vector<int> ans;
    
    for(int i = 0; i < numbers.size(); i++)
        binary_num.push_back(DtoB(numbers[i]));
        
    for(int i = 0; i < binary_num.size(); i++)
        ans.push_back(go(binary_num[i], 0, binary_num[i].length() - 1, binary_num[i].length() / 2));
        
    for(auto& it: ans) {
        if(it == 2) it = 0;
    }
    
    return ans;
}
