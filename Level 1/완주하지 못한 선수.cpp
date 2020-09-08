#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    
    for (auto s : completion) {
        m[s]++;
    }
    
    for (auto s : participant) {
        m[s]--;
    }
    
    for (auto s : m) {
        if (s.second) {
            return s.first;
        }
    }
}
