#include <string>
#include <vector>

using namespace std;

int solution(vector<string> name_list) {
    int answer = 0;
    for(int i = 0; i < name_list.size(); ++i)
        for(int j = 0; j < name_list[i].length(); ++j)
            if(name_list[i][j] == 'j' || name_list[i][j] == 'k'){
                answer++;
                break;
            }
    return answer;
}
