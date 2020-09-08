#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int tmp;
    
    for (auto i : arr)
        if (i % divisor == 0)
            answer.push_back(i);
    
    if (answer.empty()) {
        answer.push_back(-1);
        return answer;
    }
    
    for (decltype(answer.size()) i = 0; i != answer.size(); i++)
        for (decltype(answer.size()) j = 0; j != answer.size(); j++)
            if (answer[i] < answer[j]) {
                tmp = answer[i];
                answer[i] = answer[j];
                answer[j] = tmp;
            }
    
    return answer;
}
