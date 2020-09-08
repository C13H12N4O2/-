#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool flag = false;
    
    for (auto c : s) {
        answer *= 10;
        if (c == '-') {
            flag = true;
        } else if (c == '+') {
            continue;
        } else {
            answer += (c - 48);
        }
    }
    
    if (flag) {
        answer = -answer;
    }
    
    return answer;
}
