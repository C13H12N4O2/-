#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<double> rate(N, 0.0);
    vector<int> answer;
    double cnt = 0.0, den = stages.size();
    double max = -99.99;
    decltype(rate.size()) index = 0;
    
    for (auto i = 0; i != N; i++) {
        for (decltype(stages.size()) j = 0; j != stages.size(); j++) {
            if (stages[j] == i + 1) {
                cnt++;
            }
        }
        cnt ? rate[i] = cnt / den : 0.0;
        den -= cnt;
        cnt = 0.0;
    }
    
    for (decltype(rate.size()) i = 0; i != rate.size(); i++) {
        for (decltype(rate.size()) j = 0; j != rate.size(); j++) {
            if (max < rate[j]) {
                max = rate[j];
                index = j;
            }
        } answer.push_back(index + 1);
        rate[index] = -99.99;
        max = -99.99;
    } return answer;
}
