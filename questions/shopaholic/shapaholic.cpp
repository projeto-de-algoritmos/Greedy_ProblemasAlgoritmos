#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    int nonDiscountItems, discount;
    int n;
    while(t--){

        cin >> n;

        vector<int> items(n);

        for(auto &item : items)
            cin >> item;

        sort(items.begin(), items.end());
        
        nonDiscountItems = n%3;
        discount = 0;

        for(int i = nonDiscountItems; i < items.size(); i+=3){
            discount += items[i];
        }

        cout << discount << endl;

    }


    return 0;
}
