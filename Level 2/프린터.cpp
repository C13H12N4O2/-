#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<vector<int>> index, list;
    vector<int> elem;
    int max = 0;
    bool flag = true;
    
    for (decltype(priorities.size()) i = 0; i != priorities.size(); i++) {
        elem.push_back(priorities[i]);
        elem.push_back(i);
        index.push_back(elem);
        elem.clear();
    }
    
    while (!index.empty()) {
        if (flag) {
            for (decltype(index.size()) i = 0; i != index.size(); i++) {
                if (max < index[i][0]) {
                    max = index[i][0];
                }
            } flag = false;
        }

        if (max == (*index.begin())[0]) {
            list.push_back(*index.begin());
            index.erase(index.begin());
            flag = true;
            max = 0;
        } else {
            index.push_back(*index.begin());
            index.erase(index.begin());
        }
    }
    
    for (decltype(list.size()) i = 0; i != list.size(); i++) {
        if (list[i][1] == location) {
            return i + 1;
        }
    }
}
