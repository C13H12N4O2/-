#include<string>
#include<vector>

using namespace std;

bool solution(string s) {
    vector<char> vc;

    for (auto c : s) {
        if (vc.empty()) {
            if (c == ')') {
                return false;
            } else {
                vc.push_back(c);
            }
        } else {
            if (c == '(') {
                vc.push_back(c);
            } else {
                if (vc.back() == '(') {
                    vc.pop_back();
                }
            }
        }
    } return vc.size() ? false : true;
}
