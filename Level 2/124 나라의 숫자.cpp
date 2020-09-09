#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    vector<string> stack;
    string answer = "";
    
    while (n) {
        if (n % 3) {
            stack.push_back(to_string(n % 3));
        } else {
            stack.push_back("4");
            n--;
        } n /= 3;
    }
    
    for (auto end = stack.end() - 1; end != stack.begin() - 1; end--)
        answer += *end;
    
    return answer;
}
