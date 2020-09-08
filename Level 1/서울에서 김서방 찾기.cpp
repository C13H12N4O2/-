#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    string str = "에 있다";
    
    for (int i = 0; i != seoul.size(); i++)
        if (seoul[i] == "Kim") {
            answer += to_string(i) + str;
            break;
        }
    
    return answer;
}
