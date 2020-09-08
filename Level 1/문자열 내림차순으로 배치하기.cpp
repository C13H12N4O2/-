#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char tmp;
    
    for (decltype(s.size()) i = 0; i != s.size(); i++)
        for (decltype(s.size()) j = 0; j != s.size(); j++)
            if (s[i] > s[j]) {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
    answer = s;
    
    return answer;
}
