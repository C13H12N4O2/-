#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &key) {
    vector<vector<int>> temp(key);
    
    for (decltype(key.size()) i = 0; i != key.size(); i++)
        for (decltype(key.size()) j = 0; j != key.size(); j++)
            key[i][key.size() - j - 1] = temp[key.size() - j - 1][key.size() - i - 1];
    return key;
}

bool insertKey(vector<vector<int>> &key, vector<vector<int>> &lock, vector<vector<int>> board, decltype(board.size()) a, decltype(board.size()) b) {
    for (decltype(key.size()) i = 0, n = a; i != key.size(); i++, n++) {
        for (decltype(key.size()) j = 0, m = b; j != key.size(); j++, m++) {
            board[n][m] ^= key[i][j];
            if (!board[n][m] && key[i][j]) {
                return false;
            }
        }
    }

    for (decltype(lock.size()) i = 0; i != lock.size(); i++) {
        for (decltype(lock.size()) j = 0; j != lock.size(); j++) {
            if (!board[key.size() + i - 1][key.size() + j - 1]) {
                return false;
            }
        }
    } return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<int>> board(lock.size() * 3, vector<int>(lock.size() * 3));
    const unsigned size = 4;
    unsigned flag = 0;
    
    for (decltype(lock.size()) i = 0; i != lock.size(); i++) {
        for (decltype(lock.size()) j = 0; j != lock.size(); j++) {
            if (!lock[i][j]) {
                flag++;
            } board[key.size() + i - 1][key.size() + j - 1] = lock[i][j];
        }
    } if (!flag)
        return true;

    for (decltype(board.size()) i = 0; i != key.size() + lock.size() - 1; i++) {
        for (decltype(board.size()) j = 0; j != key.size() + lock.size() - 1; j++) {
            for (unsigned n = 0; n != size; n++) {
                if (insertKey(key, lock, board, i, j)) {
                    return true;
                } rotate(key);
            }
        }
    } return false;
}
