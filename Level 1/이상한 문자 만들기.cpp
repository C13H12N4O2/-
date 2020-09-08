#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int cnt = 0;
    for (decltype(s.size()) i = 0; i != s.size(); i++) {
        if (s[i] != ' ') {
            if (cnt++ % 2 != 0)
                s[i] = tolower(s[i]);
            else
                s[i] = toupper(s[i]);
        } else {
            cnt = 0;
        }
    } return s;
}
