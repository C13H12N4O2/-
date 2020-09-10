#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    for (decltype(arr.size()) i = 0; i != arr.size(); i++)
        if (arr[i] != i + 1)
            return false;

    return true;
}
