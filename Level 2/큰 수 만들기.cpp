#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    char cmax;
    for (decltype(number.size()) j = 0, index = 0; j != number.size() - k; ++j) {
        cmax = 0;
        for (auto i = index; i != k + j + 1; ++i) {
            if (cmax < number[i]) {
                index = i + 1;
                cmax = number[i];
            }
        } answer += cmax;
    } return answer;
}
