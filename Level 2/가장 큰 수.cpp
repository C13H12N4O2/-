#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> vs;
    string answer = "";
    
    for (const auto &i : numbers)
        vs.push_back(to_string(i));
    
    sort(vs.begin(), vs.end(), cmp);
         
    int cnt = 0;
    for (const auto &s : vs)
        if (s == "0")
            ++cnt;
    
    if (cnt == vs.size())
        return answer += *vs.begin();
    
    for (const auto &s : vs)
        answer += s;
    
    return answer;
}
