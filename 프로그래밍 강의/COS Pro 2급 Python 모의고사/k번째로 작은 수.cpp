#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> arr, int k) {
    vector<int> list;
    
    for (auto vi : arr)
        for (auto i : vi)
                list.push_back(i);
    sort(list.begin(), list.end());
    return list[k - 1];
}
