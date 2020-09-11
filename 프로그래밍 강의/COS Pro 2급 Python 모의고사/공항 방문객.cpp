#include <string>
#include <vector>

using namespace std;

vector<int> func_a(vector<int> arr, int n){
    vector<int> ret;
    for(int i = 0; i < arr.size(); ++i)
        if(arr[i] != n)
            ret.push_back(arr[i]);
    return ret;
}

int func_b(int a, int b){
    if (a >= b)
        return a - b;
    else
        return b - a;
}

int func_c(vector<int> arr){
    int ret = -1;
    for (int i = 0; i < arr.size(); ++i){
        if(ret < arr[i] )
            ret = arr[i];
    }
    return ret;
}

int solution(vector<int> visitor) {
    int max_first = func_c(visitor);
    vector<int> visitor_removed = func_a(visitor, max_first);
    int max_second = func_c(visitor_removed);
    int answer = func_b(max_first, max_second);
    return answer;
}
