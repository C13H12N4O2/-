#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> tree;
    sort(numbers.begin(), numbers.end());
    
    for (decltype(numbers.size()) i = 0; i != numbers.size() - 1; ++i)
        for (decltype(numbers.size()) j = i; j != numbers.size(); ++j)
            if (i != j)
                tree.emplace(numbers[i] + numbers[j]);
    
    for (const auto &i : tree)
        answer.push_back(i);
    return answer;
}
