#include <string>
#include <vector>

using namespace std;

void divide(vector<string> &list, string str) {
    if (str.size() == 2) {
        bool flag = true;
        
        for (auto &c : str)
            if (!(c >= 65 && c <= 90)) {
                flag = false;
                break;
            }
        
        if (flag)
            list.push_back(str);
    } else {
        string temp1, temp2;
        for (decltype(str.size()) i = 0; i != str.size(); i++) {
            if (i < 1) {
                temp1.push_back(str[i]);
            } else if (i == 1) {
                temp1.push_back(str[i]);
                temp2.push_back(str[i]);
            } else {
                temp2.push_back(str[i]);
            }
        }
        divide(list, temp1);
        divide(list, temp2);
    }
}

void upperCase(string &str) {
    for (auto &c : str)
        c = toupper(c);
}

int solution(string str1, string str2) {
    vector<string> list1, list2, list3;
    double den, num;
    bool flag = true;
    
    upperCase(str1);
    upperCase(str2);
    divide(list1, str1);
    divide(list2, str2);
    list3 = list1;

    for (auto s1 : list2) {
        for (auto &s2 : list1) {
            if (s2 == s1) {
                s2 = "X";
                flag = false;
                break;
            } else {
                flag = true;
            }
        }
        if (flag)
            list3.push_back(s1);
    }
    
    den = list3.size() ? list3.size() : 1;
    num = den - list1.size() - list2.size();
    
    if (num < 0)
        num *= -1;
    
    return num / den * 65536;
}
