#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> cnt;
    unordered_map<string, queue<pair<int, size_t>>> list;
    vector<int> answer;
    
    for (decltype(genres.size()) i = 0; i != genres.size(); ++i) {
        cnt[genres[i]] += plays[i];
        list[genres[i]].push(make_pair(plays[i], i));
    }
    
    map<int, string, greater<int>> temp;
    for (const auto &itr : cnt) {
        temp[itr.second] = itr.first;
    }
    
    int n = 0;
    vector<pair<int, size_t>> vec;
    
    for (auto &itr : list) {
        n = itr.second.size();
        for (int i = 0; i != n; ++i) {
            vec.push_back(make_pair(itr.second.front().first, itr.second.front().second));
            itr.second.pop();
        }
        sort(vec.begin(), vec.end(), [](const pair<int, size_t> &a, const pair<int, size_t> &b){return a.first > b.first;});
        
        n = vec.size();
        for (int i = 0; i != n; ++i) {
            itr.second.push(make_pair(vec.front().first, vec.front().second));
            vec.erase(vec.begin());
        }
    }
    
    unordered_map<string, queue<pair<int, size_t>>>::iterator key;
    for (auto beg = temp.begin(); beg != temp.end(); ++beg) {
        key = list.find(beg->second);
        n = key->second.size();
        for (int i = 0 ; i != 2 && !key->second.empty(); ++i) {
            answer.push_back(key->second.front().second);
            key->second.pop();
        }
    } return answer;
}
