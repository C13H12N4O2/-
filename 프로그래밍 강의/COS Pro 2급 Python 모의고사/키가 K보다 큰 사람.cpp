#include <string>
#include <vector>

using namespace std;

int solution(vector<int> height, int k) {
    int answer = 0;
    int n = height.size();
    for(int i = 0; i < n; ++i)
        if(height[i] > k)
            answer++;
    return answer;
}
