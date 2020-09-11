#include <vector>

using namespace std;

int solution(vector<int> sticker) {
    if (sticker.size() == 1)
        return *sticker.begin();
    vector<int> temp1(sticker.size()), temp2(sticker.size());
    
    temp1[0] = sticker[0];
    temp1[1] = temp1[0];
    
    temp2[0] = 0;
    temp2[1] = sticker[1];
    
    for (decltype(sticker.size()) i = 2; i != sticker.size(); i++)
        temp1[i] = max(temp1[i - 1], temp1[i - 2] + sticker[i]);
    
    for (decltype(sticker.size()) i = 2; i != sticker.size(); i++)
        temp2[i] = max(temp2[i - 1], temp2[i - 2] + sticker[i]);
    return max(temp1[temp1.size() - 2], temp2[temp2.size() - 1]);
}
