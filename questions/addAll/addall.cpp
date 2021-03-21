#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n;
    long long value;
    long long cost;

    long long a ,b;

    priority_queue<long long, vector<long long>, greater<long long>> heap;
    while(cin >> n && n!=0){

        cost = 0;
        
        for(int i = 0; i<n; ++i){
            cin >> value;

            heap.push(value);
        }

        while(heap.size() >= 2){
            a = heap.top();
            heap.pop();

            b = heap.top();
            heap.pop();

            cost += a +b;
            heap.push(a+b);
        }

        heap.pop();

        cout << cost << endl;
    }


    return 0;
}
