#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    constexpr size_t size = 500;
    
    for (auto i = 0; i != size; i++) {
        if (num == 1) {
            return i;
        } else {
            if (num % 2 == 1) {
                num = num * 3 + 1;
            } else {
                num /= 2;
            }
        }
    }
    
    return -1;
}
