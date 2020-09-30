#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> C = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int a = 0, b = 0, c = 0;
    
    int i = 0, j = 0, k = 0;
    for (const auto &n : answers) {
        if (i == A.size())
            i = 0;
        if (j == B.size())
            j = 0;
        if (k == C.size())
            k = 0;
        
        if (n == A[i])
            ++a;
        if (n == B[j])
            ++b;
        if (n == C[k])
            ++c;
        ++i; ++j; ++k;
    }
    
    int high = max(a, max(b, c));
    if (a == high)
        answer.push_back(1);
    if (b == high)
        answer.push_back(2);
    if (c == high)
        answer.push_back(3);
    return answer;
}
