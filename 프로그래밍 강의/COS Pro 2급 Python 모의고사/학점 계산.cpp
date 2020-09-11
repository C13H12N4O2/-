#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> scores) {
    vector<int> grade_counter = {0,0,0,0,0};
    for(int i = 0; i < scores.size(); ++i)
    {
        if(scores[i] >= 85 && scores[i] <= 100)
            grade_counter[0] += 1;
        else if(scores[i] >= 70 && scores[i] <= 84)
            grade_counter[1] += 1;
        else if(scores[i] >= 55 && scores[i] <= 69)
            grade_counter[2] += 1;
        else if(scores[i] >= 40 && scores[i] <= 54)
            grade_counter[3] += 1;
        else
            grade_counter[4] += 1;
    }
    return grade_counter;
}
