#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones) {
    int cnt = 0;
    int current = 0;
    int n = stones.size();
    while (n > current) {
        current += stones[current];
        cnt++;
    }
    return cnt;
}
