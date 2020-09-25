#include <string>
#include <vector>

using namespace std;

inline vector<pair<string, int>>::iterator find(vector<pair<string, int>> &map, const string &str) {
    for (auto beg = map.begin(); beg != map.end(); ++beg) {
        if (beg->first == str) {
            return beg;
        }
    } return map.end();
}

int solution(vector<vector<string>> clothes) {
    vector<pair<string, int>> map;
    int answer = 1;
    
    for (const auto &vec : clothes) {
        auto key = find(map, vec[1]);
        if (key != map.end()) {
            ++key->second;
        } else {
            map.push_back(pair(vec[1], 2));
        }
    }
    
    for (const auto &iter : map) {
        answer *= iter.second;
    }
    
    return --answer;
}
