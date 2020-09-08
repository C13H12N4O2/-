#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> vi1;
    vector<vector<int>> board1, board2;
    string line;
    int temp;

    for (decltype(arr1.size()) i = 0; i != arr1.size(); i++) {
        for (decltype(arr1.size()) j = 0; j != arr1.size(); j++) {
            arr1[i] % 2 ? vi1.push_back(1) : vi1.push_back(0);
            arr1[i] /= 2;
        }
        for (decltype(vi1.size()) j = 0; j != vi1.size() / 2; j++) {
            temp = vi1[j];
            vi1[j] = vi1[vi1.size() - j - 1];
            vi1[vi1.size() - j - 1] = temp;
        } board1.push_back(vi1);
        vi1.clear();
    }
    
    for (decltype(arr2.size()) i = 0; i != arr2.size(); i++) {
        for (decltype(arr2.size()) j = 0; j != arr2.size(); j++) {
            arr2[i] % 2 ? vi1.push_back(1) : vi1.push_back(0);
            arr2[i] /= 2;
        }
        for (decltype(vi1.size()) j = 0; j != vi1.size() / 2; j++) {
            temp = vi1[j];
            vi1[j] = vi1[vi1.size() - j - 1];
            vi1[vi1.size() - j - 1] = temp;
        } board2.push_back(vi1);
    }
    
    for (decltype(board1.size()) i = 0; i != board1.size(); i++) {
        for (decltype(board1.size()) j = 0; j != board1.size(); j++) {
            board1[i][j] |= board2[i][j];
        }
    }
    
    for (auto v : board1) {
        for (auto i : v) {
            i ? line += '#' : line += ' ';
        } answer.push_back(line);
        line.clear();
    } return answer;
}
