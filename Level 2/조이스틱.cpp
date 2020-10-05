#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0, n = name.size(), temp = n - 1, next;
    
    for (int i = 0; i != n; ++i) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        next = i + 1;
        while (next != n && name[next] == 'A')
            ++next;
        
        temp = min(temp, i + n - next + min(i, n - next));
    } return answer + temp;
}
