#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> vs{"수", "수박"};
    
    for (decltype(n) i = 0; i != n / 2; i++)
        answer += vs[1];
    if (n % 2)
        answer += vs[0];
    
    return answer;
}
