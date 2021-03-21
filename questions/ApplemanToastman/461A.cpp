#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int numbers_amount;
    cin >> numbers_amount;
    
    vector<int> numbers(numbers_amount);
    
    long long total_sum = 0;
    for (auto & element : numbers) {
        cin >> element;
        total_sum += element;
    }
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    numbers.push_back(0);

    long long answer = - numbers.front();
    while (not numbers.empty()) {
        answer += total_sum;
        total_sum -= numbers.back();
        numbers.pop_back();
    }

    cout << answer << endl;

    return 0;
}