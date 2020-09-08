#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> vi(n + 1, 0);
    int answer = 0;
    
    for (auto i = 2; i != n; i++) {
        if (!vi[i]) {
            for (auto j = i * 2; j <= n; j += i) {
                vi[j] = 1;
            }
        }
    }
    
    for (auto i = 2; i != n + 1; i++) {
        if (!vi[i]) {
            answer++;
        }
    }
    
    return answer;
}
