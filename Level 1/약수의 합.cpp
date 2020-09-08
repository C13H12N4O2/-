#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (auto i = 1; i != n + 1; i++) {
        if (!(n % i)) {
            answer += i;
        }
    } return answer;
}
