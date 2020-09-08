#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> vi(n, 1);
    int answer = 0;
    
    for (auto i : lost) {
        vi[i - 1]--;
    }
    
    for (auto i : reserve) {
        vi[i - 1]++;
    }
    
    for (decltype(vi.size()) i = 0; i != vi.size(); i++) {
        if (i) {
            if (i == vi.size() - 1) {
                if (vi[i] == 2 && vi[i - 1] == 0) {
                    vi[i]--;
                    vi[i - 1]++;
                }
            } else {
                if (vi[i] == 2 && vi[i - 1] == 0) {
                    vi[i]--;
                    vi[i - 1]++;
                }
                if (vi[i] == 2 && vi[i + 1] == 0) {
                    vi[i]--;
                    vi[i + 1]++;
                }
            }
        } else {
            if (vi[i] == 2 && vi[i + 1] == 0) {
                vi[i]--;
                vi[i + 1]++;
            }
        }
    }
    
    for (auto i : vi) {
        if (i)
            answer++;;
    }
    
    return answer > n ? n : answer;
}
