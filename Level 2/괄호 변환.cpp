#include <string>
#include <vector>

using namespace std;

string function(string p) {
    vector<unsigned> vi(2, 0);
    vector<char> vc;
    auto &left = vi[0];
    auto &right = vi[1];
    string u, v, temp, temp2;
    bool flag = false;
    
    if (p.empty())
        return p;
        
    for (auto c : p) {
        if (vc.empty()) {
            if (c == '(')
                vc.push_back(c);
            else {
                vc.push_back(c);
                break;
            }
        } else {
            if (c == ')')
                vc.pop_back();
            else
                vc.push_back(c);
        }
    }
    
    if (vc.empty())
        return p;
    vc.clear();
    
    for (auto c : p) {
        if (flag) {
            v += c;
        } else {
            if (c == '(')
                left++;
            else
                right++;
            u += c;
            
            if (left == right)
                flag = true;
        }
    }
    
    for (auto c : u) {
        if (vc.empty()) {
            if (c == '(')
                vc.push_back(c);
            else {
                vc.push_back(c);
                break;
            }
        } else {
            if (c == ')')
                vc.pop_back();
            else
                vc.push_back(c);
        }
    }
    
    if (vc.empty())
        return u + function(v);
    vc.clear();
    
    temp = '(' + function(v) + ')';
    
    for (decltype(u.size()) i = 1; i != u.size() - 1; i++)
        temp2 += u[i];
    
    for (decltype(temp2.size()) i = 0; i != temp2.size(); i++) {
        if (temp2[i] == '(')
            temp2[i] = ')';
        else
            temp2[i] = '(';
    }
    
    return temp + temp2;
}

string solution(string p) {
    string answer = "";
    vector<char> vc;
    
    if (p.empty())
        return answer;
    
    for (auto c : p) {
        if (vc.empty()) {
            if (c == '(')
                vc.push_back(c);
            else {
                vc.push_back(c);
                break;
            }
        } else {
            if (c == ')')
                vc.pop_back();
            else
                vc.push_back(c);
        }
    }
    
    if (vc.empty())
        return p;
    vc.clear();
    
    answer = function(p);
    
    return answer;
}
