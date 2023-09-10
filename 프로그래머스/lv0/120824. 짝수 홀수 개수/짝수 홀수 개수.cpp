#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num) {
    vector<int> answer;
    
    int a = 0, b = 0;
    
    for(int i = 0; i < num.size(); i++) {
        // 짝수
        if(num[i] % 2 == 0)
            a++;
        // 홀수
        else if(num[i] % 2 == 1)
            b++;
    }
    
    answer.push_back(a);
    answer.push_back(b);
    
    return answer;
}