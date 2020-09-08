#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    for (decltype(phone_number.size()) i = phone_number.size() - 1; i != -1; i--) {
        if (i < phone_number.size() - 4) {
            phone_number[i] = '*';
        }
    }
    
    return phone_number;
}
