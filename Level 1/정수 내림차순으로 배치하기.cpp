#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    vector<int> vi;
    long long answer = 0;
    int max = -99;
    int cur;
    
    if (!n % 10) {
        return n;
    }
    
    vi.push_back(n % 10);
    while (n /= 10) {
        vi.push_back(n % 10);
    }
    
    for (decltype(vi.size()) i = 0; i != vi.size(); i++) {
        answer *= 10;
        
        for (decltype(vi.size()) j = 0; j != vi.size(); j++) {
            if (max < vi[j]) {
                max = vi[j];
                cur = j;
            }
        } answer += max;
        vi[cur] = - 99;
        max = -99;
    }
    
    return answer;
}
