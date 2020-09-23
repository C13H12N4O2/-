#include <string>

using namespace std;

inline int count(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2)
            ++cnt;
        n /= 2;
    } return cnt;
}

int solution(int n) {
    int target = count(n);
    int next = n;
    
    while (true) {
        int cnt = count(++next);
        
        if (target == cnt)
            return next;
    }
}
