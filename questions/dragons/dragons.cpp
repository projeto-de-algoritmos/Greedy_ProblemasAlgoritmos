#include <bits/stdc++.h>

using namespace std;

int main(){

    int s, n;
    cin >> s >> n;

    vector<pair<int,int>> dragons(n);

    for(auto &[force, bonus] : dragons)
        cin >> force >> bonus;

    // order dragons in the increase order 
    sort(vet.begin(), vet.end());

    // before the fight we assume that the hero 
    // will win
    bool win = true;

    for(auto [force, bonus] : dragons){
        
        if(s > force){
            // if the hero can beat the dragon
            // add the bonus in his stregth
            s+=bonus;
        }else{
            // if the force of the dragon is greater or equal
            // the hero can't win
            win = false;
        }

    }

    if(win){
        cout << "YES";
    }else{
        cout << "NO";
    }

    cout << endl;


    return 0;
}
