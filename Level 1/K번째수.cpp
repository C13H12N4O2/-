#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, temp;
    int tmp;
    
    for (auto v : commands) {
        for (int i = v[0] - 1; i != v[1]; i++)
            temp.push_back(array[i]);
        for (decltype(temp.size()) i = 0; i != temp.size(); i++)
            for (decltype(temp.size()) j = 0; j != temp.size(); j++)
                if (temp[i] < temp[j]) {
                    tmp = temp[i];
                    temp[i] = temp[j];
                    temp[j] = tmp;
                }
        answer.push_back(temp[v[2] - 1]);
        temp.clear();
    }
    
    return answer;
}
