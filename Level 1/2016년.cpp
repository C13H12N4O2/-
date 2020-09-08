#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> vs{"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> vi{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n = 0;

    for (decltype(a) i = 0; i != a - 1; i++)
        n += vi[i];
    n += b - 1;

    return vs[n % 7];
}
