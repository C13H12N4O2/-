#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    vector<int> occupied, reserved;
    size_t length = truck_weights.size();
    int time = 0, curWeight = 0, cnt = 0;
    
    while (true) {
        if (*reserved.begin() == time && time != 0) {
            curWeight -= *occupied.begin();
            occupied.erase(occupied.begin());
            reserved.erase(reserved.begin());
        }
        
        if (cnt < length && curWeight + truck_weights[cnt] <= weight) {
            curWeight += truck_weights[cnt];
            occupied.push_back(truck_weights[cnt]);
            reserved.push_back(time + bridge_length);
            cnt++;
        } time++;
        
        if (reserved.empty() && cnt == length)
            return time;
    }
}
