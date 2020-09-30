#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    bitset<16> bits;
    string temp;
    
    for (decltype(arr1.size()) i = 0; i != arr1.size(); ++i) {
        bits = arr1[i] | arr2[i];
        for (decltype(bits.size()) j = n - 1; j != -1; --j)
            bits[j] == 1 ? temp += '#' : temp += ' ';
        
        answer.push_back(temp);
        temp.clear();
    } return answer;
}
