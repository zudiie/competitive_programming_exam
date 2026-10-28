#include <iostream>
#include <set>
#include <climits>
#include <map>

using namespace std;

int main(){
    int photos;
    cin >> photos;
    int count = 0;
    vector<int> res;
    for (int m = 1; m <= photos; m++){
        int num, phot;
        cin >> num;
        unordered_map<int, int> heights;
        int min = INT_MAX;
        for (int i = 0; i < num; i++){
            cin >> phot;
            heights[i] = phot;
            if (min > phot){
                min = phot;
            }
        }
        //cout << min << " ";
        auto pointer = find(heights.begin(), heights.end(), min);
        set<int> alice;
        set<int> bob;
        auto it = heights.begin();
        int i = 0;
        while (it != pointer){
            cout << heights[i] << " \n";
            alice.insert(heights[i++]);
            it++;
        }
        cout << min << " ";
        auto pointerAlice = upper_bound(alice.begin(), alice.end(), min);
        if (*pointerAlice == min) continue;
        cout << *pointerAlice << "\n\n";
        int aliceHeight = heights[*pointerAlice];

        auto pointer2 = pointer;
        auto it2 = heights.end();

        for (int i = heights.size() - 1; pointer2 != it2; i--){
            bob.insert(heights[i]);
            pointer2++;
        }
        auto pointerBob = upper_bound(bob.begin(), bob.end(), aliceHeight);
        if (*pointerBob == aliceHeight) continue;
        count++;
        res.push_back(m);
    }
    // cout << count << '\n';
    // for (int i = 0; i < res.size(); i++){
    //     cout << res[i] << " ";
    // }
    return EXIT_SUCCESS;
}