#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool find(vector<int> list, int n) {
    for (auto beg = list.begin(); beg != list.end(); ++beg) {
        if (*beg == n) {
            return true;
        }
    } return false;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (decltype(numbers.size()) i = 0; i != numbers.size(); ++i) {
        for (decltype(numbers.size()) j = i + 1; j != numbers.size(); ++j) {
            int sum = numbers[i] + numbers[j];
            if (!find(answer, sum)) {
                answer.push_back(sum);
            }
        }
    } sort(answer.begin(), answer.end());
    return answer;
}
