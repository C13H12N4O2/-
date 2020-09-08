#include <string>

using namespace std;

bool solution(string s) {
    unsigned p = 0, y = 0;
    
    for (auto c : s)
        if (c == 'p')
            p++;
        else if (c == 'P')
            p++;
        else if (c == 'y')
            y++;
        else if (c == 'Y')
            y++;
    
    return p == y ? true : false;
}
