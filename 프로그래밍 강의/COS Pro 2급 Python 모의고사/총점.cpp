#include <string>
#include <vector>

using namespace std;

int func_a(vector<int> s) {
    int ret = 0;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] > ret)
            ret = s[i];
    return ret;
}

int func_b(vector<int> s) {
    int ret = 0;
    for(int i = 0; i < s.size(); ++i)
        ret += s[i];
    return ret;
}

int func_c(vector<int> s){
    int ret = 101;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] < ret)
            ret = s[i];
    return ret;
}

int solution(vector<int> scores) {
    int sum = func_b(scores);
    int max_score = func_a(scores);
    int min_score = func_c(scores);
    return sum - max_score - min_score;
}
