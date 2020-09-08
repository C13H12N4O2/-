#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    unsigned cnt = 0;
    unsigned min = s.size();
    string word;
    string num;
    vector<char> vc;
    vector<string> vs;
   
    for (unsigned i = 0; i != s.size() / 2; i++) {
        for (auto c : s) {
            word += c;
            
            if (cnt == i) {
                vs.push_back(word);
                cnt = 0;
                word.clear();
            } else {
                cnt++;
            }
        } cnt = 1;
        
        if (!word.empty()) {
            vs.push_back(word);
            word.clear();
        }
        
        for (decltype(vs.size()) j = 0; j != vs.size() - 1; j++) {
            if (vs[j] == vs[j + 1]) {
                cnt++;
            } else {
                if (cnt != 1) {
                    if (cnt >= 10) {
                        num = to_string(cnt);
                        
                        for (auto c : num)
                            vc.push_back(c);
                    } else
                        vc.push_back('0' + cnt);
                    
            }
                for (auto c : vs[j])
                    vc.push_back(c);
                cnt = 1;
            }
        }
        if (cnt != 1) {
            if (cnt >= 10) {
                num = to_string(cnt);
                        
                for (auto c : num)
                    vc.push_back(c);
            } else
                vc.push_back('0' + cnt);
        }
        
        for (auto c : vs[vs.size() - 1])
            vc.push_back(c);
        
        if (min > vc.size())
            min = vc.size();
        
        vs.clear();
        vc.clear();
        cnt = 0;
    }
    
    return answer = min;
}
