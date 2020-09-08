#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    vector<int> vi(3, 0);
    int n = 0, cnt = 0;
    
    for (decltype(dartResult.size()) i = 0; i != dartResult.size(); i++) {
        if (dartResult[i] >= 48 && dartResult[i] <= 57) {
            n += dartResult[i] - 48;
            if (dartResult[i + 1] >= 48 && dartResult[i + 1] <= 57) {
                n = n * 10 + dartResult[i++ + 1] - 48;
            } vi[cnt] = n;
            n = 0;
        } else if (dartResult[i] == '*') {
            vi[cnt - 1] *= 2;
            if (!cnt - 2) {
                vi[cnt - 2] *= 2;
            }
        } else if (dartResult[i] == '#') {
            vi[cnt - 1] *= -1;
        } else {
            if (dartResult[i] == 'D') {
                vi[cnt] *= vi[cnt];
            } else if (dartResult[i] == 'T') {
                vi[cnt] *= vi[cnt] * vi[cnt];
            } cnt++;
        }
    }
    
    for (auto i : vi) {
        n += i;
    } return n;
}
