#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(n, vector<int>(m, 1));
    
    for (decltype(puddles.size()) i = 0; i != puddles.size(); i++)
        map[puddles[i][1] - 1][puddles[i][0] - 1] = 0;
    
    for (decltype(map.size()) i = 0; i != map.size(); i++) {
        for (decltype(map[0].size()) j = 0; j != map[0].size(); j++) {
            if (!map[i][j])
                continue;
            if (!i) {
                if (j) {
                    map[i][j] = map[i][j - 1];
                    map[i][j] %= 1000000007;
                }
            } else {
                if (j) {
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
                    map[i][j] %= 1000000007;
                } else {
                    map[i][j] = map[i - 1][j];
                    map[i][j] %= 1000000007;
                }
            }
        }
    } return map[map.size() - 1][map[0].size() - 1];
}
