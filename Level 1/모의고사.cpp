#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> ms1{1, 2, 3, 4, 5};
    vector<int> ms2{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> ms3{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> score(3, 0);
    vector<int> answer;
    int max = 0;
    
    for (decltype(answers.size()) i = 0; i != answers.size(); i++) {
        if (answers[i] == ms1[i % ms1.size()]) {
            score[0]++;
        }
        if (answers[i] == ms2[i % ms2.size()]) {
            score[1]++;
        }
        if (answers[i] == ms3[i % ms3.size()]) {
            score[2]++;
        }
    }

    for (decltype(score.size()) i = 0; i != score.size(); i++) {
        if (score[i] > max) {
            max = score[i];
        }
    }
    
    for (decltype(score.size()) i = 0; i != score.size(); i++) {
        if (max == score[i]) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
