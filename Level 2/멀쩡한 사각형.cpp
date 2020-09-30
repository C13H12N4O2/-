#include <algorithm>

using namespace std;

long long solution(int w, int h) {
    long long square = static_cast<long long>(w) * h;
    long long diagonal = w + h - __gcd(w, h);
    return square - diagonal;
}
