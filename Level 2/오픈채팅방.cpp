#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> names;
    vector<pair<string, string>> conditions;
    vector<string> answer;
    
    for (const auto &str : record) {
        vector<string> elem;
        string temp;
        for (const auto &c : str) {
            if (c != ' ') {
                temp.push_back(c);
            } else {
                elem.push_back(temp);
                temp.clear();
            }
        } elem.push_back(temp);
        
        if (elem.size() == 3) {
            const auto key = names.find(elem[1]);
            if (elem[0] != "Change") {
                conditions.push_back(make_pair(elem[0], elem[1]));
                if (key != names.end()) {
                    key->second = elem[2];
                } else {
                    names.emplace(make_pair(elem[1], elem[2]));
                }
            } else {
                key->second = elem[2];
            }
        } else {
            conditions.push_back(make_pair(elem[0], elem[1]));
        }
    }
    
    for (const auto &iter : conditions) {
        const auto key = names.find(iter.second);
        const string line = iter.first == "Enter" ? key->second + "님이 들어왔습니다." : key->second + "님이 나갔습니다.";
        answer.push_back(line);
    } return answer;
}
