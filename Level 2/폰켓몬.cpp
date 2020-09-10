#include <vector>

using namespace std;

int solution(vector<int> nums) {
    vector<vector<int>> hash;
    vector<int> node;
    int answer = 0, max = 0;;
    bool flag = true;
    auto cur = node.begin();
    
    for (auto i : nums) {
        if (hash.empty()) {
            node.push_back(i);
            node.push_back(1);
            hash.push_back(node);
        } else {
            for (auto &h : hash) {
                if (*h.begin() == i) {
                    *(h.begin() + 1) +=1;
                    flag = false;
                }
            }
            if (flag) {
                node.push_back(i);
                node.push_back(1);
                hash.push_back(node);
            } flag = true;
        } node.clear();
    }
    
    for (decltype(nums.size()) i = 0; i != nums.size() / 2; i++) {
        for (auto &h : hash) {
            if (*h.begin() > max) {
                max = *h.begin();
                cur = h.begin();
            }
        } *cur = -99;
        answer++;
    }
    
    return answer > hash.size() ? hash.size() : answer;
}
