#include <string>
#include <vector>

using namespace std;

int solution(vector<int> price, int money) {
    int answer = 0;
    
    for (auto i : price)
        answer += i;
    
    return money - answer >= 0 ? money - answer : -1;
}
