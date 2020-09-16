#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    for (decltype(people.size()) i = 0, j = people.size() - 1; i <= j && answer != people.size(); --j) {
        if (people[i] + people[j] <= limit) {
           ++i;
        } ++answer;
    } return answer;
}
