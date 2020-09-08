#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0, total = 0;
    
    sort(d.begin(), d.end());
    
    for (auto i : d) {
        total += i;
        if (total > budget) {
            return answer;
        } else if (total == budget) {
            return answer + 1;
        }
        answer++;
    }
    
    return answer;
}
