#include <string>
#include <vector>

using namespace std;

void pop(vector<int> &stack, unsigned &answer) {
    if (stack.size() != 1) {
        if (stack[stack.size() - 1] == stack[stack.size() - 2]) {
            stack.pop_back();
            stack.pop_back();
            answer += 2;
            pop(stack, answer);
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> stack;
    unsigned answer = 0;

    for (auto i : moves) {
        for (decltype(board.size()) j = 0; j != board.size(); j++) {
            if (board[j][i - 1]) {
                stack.push_back(board[j][i - 1]);
                board[j][i - 1] = 0;
                pop(stack, answer);
                break;
            }
        }
    }

    return answer;
}
