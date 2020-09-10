#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> hash;
    string temp;
    int min = 20;
    string index = "";
    auto key = hash.end();
    
    for (auto s : phone_book) {
        if (s.size() < min) {
            min = s.size();
            index = s;
        }
    }
    
    for (auto s : phone_book) {
        if (s == index) {
            key = hash.find(s);
            if (key == hash.end())
                hash.insert(make_pair(s, 1));
            else
                key->second++;
        } else {
            temp = s.substr(0, min);
            if (temp == index) {
                key = hash.find(temp);
                if (key == hash.end())
                    hash.insert(make_pair(temp, 1));
                else
                    key->second++;
            }
        }
    }
    for (auto h : hash)
        if (h.second > 1)
            return false;
    
    return true;
}
