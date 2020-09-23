#include <string>
#include <vector>

using namespace std;

inline void fibo(const int &n, vector<int> &vi) {
    if (n == 0)
        vi[n] = 1;
    else if (n == 1)
        vi[n] = 1;
    else
        vi[n] = (vi[n - 1] + vi[n - 2]) % 1234567;
}

int solution(int n) {
    vector<int> vi(n, -1);
    
    for (decltype(vi.size()) i = 0; i != n; ++i)
        fibo(i, vi);
    
    return vi[n - 1];
}
