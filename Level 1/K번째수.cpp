#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    for (const auto &vec : commands) {
        for (decltype(array.size()) i = vec[0] - 1; i != vec[1]; ++i)
            temp.push_back(array[i]);
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[vec[2] - 1]);
        temp.clear();
    } return answer;
}
