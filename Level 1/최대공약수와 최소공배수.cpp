#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int range;
    
    if (n > m)
        range = n;
    else
        range = m;
    
    while (range) {
        if (!(n % range) && !(m % range)) {
            answer.push_back(range);
            answer.push_back(n * m / range);
            return answer;
        } range--;
    }
}
