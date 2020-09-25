#include <string>
#include <vector>
#include <queue>

using namespace std;

inline int pq_pop(priority_queue<int, vector<int>, greater<int>> &pq) {
    const int n = pq.top();
    pq.pop();
    return n;
}

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0, high = 0, low = 0;
    
    while (pq.top() < K) {
        if (pq.size() == 1)
            return -1;
        
        low = pq_pop(pq);
        
        high = pq_pop(pq);
        
        pq.push(low + high * 2);
        ++answer;
    } return answer;
}
