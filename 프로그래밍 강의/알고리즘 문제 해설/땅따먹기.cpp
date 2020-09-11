#include <vector>

using namespace std;

int solution(vector<vector<int>> land) {
    vector<vector<int>> temp(land.size(), vector<int>(land[0].size(), 0));
    int answer = 0;
    
    for (decltype(land[0].size()) i = 0; i != land[0].size(); i++)
        temp[0][i] = land[0][i];
    
    for (decltype(land.size()) i = 1; i != land.size(); i++)
        for (decltype(land[0].size()) j = 0; j != land[0].size(); j++)
            for (decltype(land[0].size()) k = 0; k != land[0].size(); k++)
                if (j != k)
                    temp[i][j] = max(temp[i][j], land[i][j] + temp[i - 1][k]);
    
    for (decltype(temp[0].size()) i = 0; i != temp[0].size(); i++)
        answer = max(answer, temp[temp.size() - 1][i]);
    return answer;
}
