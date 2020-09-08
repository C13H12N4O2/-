#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;
    
    for (auto i : numbers) {
        if (i == 2 || i == 5 || i == 8 || i == 0) {
            if (!i)
                i = 11;
            if (abs((left - 1) / 3 - (i - 1) / 3) + abs((left - 1) % 3 - (i - 1) % 3) == (abs((right - 1) / 3 - (i - 1) / 3) + abs((right - 1) % 3 - (i - 1) % 3))) {
                if (hand == "right") {
                    answer += 'R';
                    right = i;
                } else {
                    answer += 'L';
                    left = i;
                }
            } else if (abs((left - 1) / 3 - (i - 1) / 3) + abs((left - 1) % 3 - (i - 1) % 3) > (abs((right - 1) / 3 - (i - 1) / 3) + abs((right - 1) % 3 - (i - 1) % 3))) {
                answer += 'R';
                right = i;
            } else {
                answer += 'L';
                left = i;
            }
        } else if (i == 1 || i == 4 || i == 7) {
            answer += 'L';
            left = i;
        } else if (i == 3 || i == 6 || i == 9) {
            answer += 'R';
            right = i;
        }
    } return answer;
}
