using namespace std;

int solution(int n) {
    int answer = 1, nums = 2, sum = 0;
    while (true) {
        sum = (nums + 1) * (nums) / 2;
        
        if (sum > n)
            break;
        if ((n - sum) % nums++ == 0)
            answer++;
    }
    return answer;
}
