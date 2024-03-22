#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;

    set<int> nums;

    for (int i = 0; i < N; i++) {
        int currentNum;
        cin >> currentNum;
        nums.insert(currentNum);
    }

    int counter = 0;
    for (auto setNum : nums) counter++;

    cout << counter;
}