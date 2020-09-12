#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    constexpr size_t high_limit = 15;
    constexpr size_t low_limit = 3;
    string answer = "";
    
    for (decltype(new_id.size()) i = 0; i != new_id.size(); i++) {
        new_id[i] = tolower(new_id[i]);
        
        if (answer.empty()) {
            if (new_id[i] != '.') {
                if ((new_id[i] >= 48 && new_id[i] <= 57) || (new_id[i] >= 97 && new_id[i] <= 122) || new_id[i] == '-' || new_id[i] == '_') {
                    answer += new_id[i];
                }
            }
        } else {
            if (*(answer.end() - 1) == '.' && new_id[i] == '.') {
                continue;
            } else {
                if ((new_id[i] >= 48 && new_id[i] <= 57) || (new_id[i] >= 97 && new_id[i] <= 122) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
                    answer += new_id[i];
                }
            }
        }
    }
    if (*(answer.end() - 1) == '.') {
        answer.pop_back();
    }
    
    while (answer.size() > high_limit) {
        answer.pop_back();
    }
    
    if (!answer.empty()) {
        if (*(answer.end() - 1) == '.') {
            answer.pop_back();
        }
    }
    
    while (answer.size() < low_limit) {
        if (answer.empty()) {
            answer.push_back('a');
        } else {
            answer.push_back(*(answer.end() - 1));
        }
    } return answer;
}

