#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    auto task = progresses.begin();
    auto prog = speeds.begin();
    bool flag = true;
    
    while (!progresses.empty()) {
        if (*task >= 100) {
            progresses.erase(task);
            speeds.erase(prog);
            task = progresses.begin();
            prog = speeds.begin();
            if (flag) {
                answer.push_back(1);
                flag = false;
            } else {
                answer[answer.size() - 1]++;
            }
        } else {
            while (task != progresses.end()) {
                *(task++) += *(prog++);
            }
            task = progresses.begin();
            prog = speeds.begin();
            flag = true;
        }
    } return answer;
}
