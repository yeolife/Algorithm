#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    if(eq == "=") {
        if(ineq == ">") {
            if(n >= m) 
                return 1;
        }
        else {
            if(n <= m) 
                return 1;
        }
    }
    else {
        if(ineq == ">") {
            if(n > m) 
                return 1;
        }
        else {
            if(n < m) 
                return 1;
        }
    }
    
    return 0;
}