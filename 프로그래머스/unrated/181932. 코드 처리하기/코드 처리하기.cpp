#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    
    bool mode = false;
    for(int i = 0; i < code.length(); i++) {
        if(!mode) {
            if(code[i] == '1') mode = 1;
            if(i % 2 == 0 && code[i] != '1') answer += code[i];
        }
        else {
            if(code[i] == '1') mode = 0;
            if(i % 2 != 0 && code[i] != '1') answer += code[i];
        }
    }
    
    return answer != "" ? answer : "EMPTY";
}