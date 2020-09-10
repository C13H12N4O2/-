#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> list;
    int n = 0;
    bool flag = false;
    
    for (auto c : s) {
        if (c == '-') {
            n *= -1;
            flag = true;
        } else if (c >= 48 && c <= 57) {
            n += (c - 48);
            n *= 10;
        } else if (c == ' ') {
            n /= 10;
            if (flag)
                n *= -1;
            list.push_back(n);
            n = 0;
            flag = false;
        }
    } n /= 10;
    if (flag)
        n *= -1;
    list.push_back(n);
    
    sort(list.begin(), list.end());
    answer += to_string(*list.begin()) + ' ';
    sort(list.begin(), list.end(), greater<int>());
    answer += to_string(*list.begin());
    
    return answer;
}
