#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    auto temp = x;
    auto den = 0;
    
    while (temp) {
        den += temp % 10;
        temp /= 10;
    }
    
    return !(x % den);
}
