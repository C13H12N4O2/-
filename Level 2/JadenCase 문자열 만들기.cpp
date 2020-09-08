#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    
    for (auto c : s) {
        if (flag) {
            if (c == ' ') {
                answer += c;
            } else {
                answer += toupper(c);
                flag = false;
            }
        } else {
            if (c == ' ') {
                answer += c;
                flag = true;
            } else {
                answer += tolower(c);
            }
        }
    }
    
    return answer;
}
