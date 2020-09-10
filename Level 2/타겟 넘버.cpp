#include <string>
#include <vector>

using namespace std;

void targetNum(vector<int> numbers, int target, int sum, int index, int &answer) {
    if (numbers.size() == index) {
        if (sum == target)
            answer++;
        return ;
    }
    
    targetNum(numbers, target, sum + numbers[index], index + 1, answer);
    targetNum(numbers, target, sum - numbers[index], index + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    targetNum(numbers, target, 0, 0, answer);
    
    return answer;
}
