#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        if(s[i] == 'a')
            s[i] = 'z';
        else if(s[i] == 'z')
            s[i] = 'a';
    }
    return s;
}
