#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (decltype(s.size()) i = 0; i != s.size(); i++) {
        if (s[i] >= 97 && s[i] <= 122) {
            if (s[i] + n > 122) {
                s[i] = (s[i] + n) % 122 + 96;
            } else {
                s[i] += n;
            }
        } else if (s[i] >= 65 && s[i] <= 90) {
            if (s[i] + n > 90) {
                s[i] = (s[i] + n) % 90 + 64;
            } else {
                s[i] += n;
            }
        }
    }
    
    return s;
}
