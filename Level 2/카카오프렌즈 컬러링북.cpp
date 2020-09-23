#include <vector>

using namespace std;

int bfs(const int &color, const int &m, const int &n, const int &row, const int &col, vector<vector<int>> &picture, vector<vector<bool>> &visited) {
    vector<pair<int, int>> queue;
    int area = 0;
    
    queue.push_back(pair(row, col));
    while (!queue.empty()) {
        const int i = queue.front().first;
        const int j = queue.front().second;
        queue.erase(queue.begin());
        
        if (visited[i][j])
            continue;
        visited[i][j] = true;
        ++area;
        
        if (i > 0 && picture[i - 1][j] == color)
            queue.push_back(pair(i - 1, j));
        if (i < m - 1 && picture[i + 1][j] == color)
            queue.push_back(pair(i + 1, j));
        if (j > 0 && picture[i][j - 1] == color)
            queue.push_back(pair(i, j - 1));
        if (j < n - 1 && picture[i][j + 1] == color)
            queue.push_back(pair(i, j + 1));
    } return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (decltype(picture.size()) i = 0; i != picture.size(); ++i) {
        for (decltype(picture[0].size()) j = 0; j != picture[0].size(); ++j) {
            if (picture[i][j] && !visited[i][j]) {
                max_size_of_one_area
                    = max(max_size_of_one_area,
                          bfs(picture[i][j], m, n, i, j, picture, visited));
                ++number_of_area;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
