#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    for (decltype(arr1.size()) i = 0; i != arr1.size(); i++) {
        for (decltype(arr1[0].size()) j = 0; j != arr1[0].size(); j++) {
            arr1[i][j] += arr2[i][j];
        }
    }
    return arr1;
}
