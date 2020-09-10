#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    vector<string> queue;
    string str;
    int answer = 0;
    
    for (auto vs : skill_trees) {
        for (auto c : vs) {
            for (auto s : skill) {
                if (s == c)
                    str.push_back(s);
            }
        } queue.push_back(str);
        str.clear();
    }
    
    for (auto vs : queue) {
        str = skill;
        if (str.size() != vs.size()) {
            while (str.size() != vs.size()) {
                str.pop_back();
            }
        }
        if (str == vs)
                answer++;
    }
    
    return answer;
}
