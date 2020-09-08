#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int n;
    
    for (auto i : arr)
        if (n != i) {
            answer.push_back(i);
            n = i;
        }
            
    return answer;
}
