#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> rates;
    vector<int> answer;
    int num = 0, den = stages.size();
    
    for (int i = 1; i != N + 1; ++i) {
        num = count_if(stages.begin(), stages.end(), [i](int N){return N <= i;});
        rates.push_back(make_pair(static_cast<double>(stages.size() - num) / den, i));
        den = stages.size() - num;
    }
    
    sort(rates.begin(), rates.end());
    
    for (const auto &iter : rates)
        answer.push_back(iter.second);
    
    return answer;
}
