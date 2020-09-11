#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    vector<vector<int>> temp(board.size() + 1, vector<int>(board[0].size() + 1, 0));
    auto answer = 0;
    
    for (decltype(board.size()) i = 1; i != board.size() + 1; i++) {
        for (decltype(board[0].size()) j = 1; j != board[0].size() + 1; j++) {
            if (board[i - 1][j - 1]) {
                temp[i][j] = min(temp[i][j - 1], min(temp[i - 1][j], temp[i - 1][j - 1])) + 1;
                answer = max(answer, temp[i][j]);
            }
        }
    } return answer * answer;
}
