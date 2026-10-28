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
        vector<int> heights;
        int min = INT_MAX;
        for (int i = 0; i < num; i++){
            cin >> phot;
            heights.push_back(phot);
            if (min > phot){
                min = phot;
            }
        }

        //cout << min << " ";
        auto pointer = find(heights.begin(), heights.end(), min);
        vector<int> alice;
        vector<int> bob;
        auto it = heights.begin();
        int j = 0;
        if (it != pointer){
             while (it != pointer) {
            //cout << heights[i] << " \n";
            alice.push_back(heights[j++]);
            it++;
        }
        }
       

        int aliceHeight, bobHeight;
        //cout << min << " ";
        it = heights.begin();
        if (alice.size() == 0) continue;
        else if (alice.size() == 1) aliceHeight = alice[0];
        else {
            auto pointerAlice = upper_bound(alice.begin(), alice.end(), min);
            if (alice.at(*pointerAlice) == min) continue;
            std::advance(it, *pointerAlice);
            aliceHeight = *it;
        }
        
        //cout << aliceHeight << " ";
        auto pointer2 = pointer + 1;
        auto it2 = heights.end();

        for (int i = heights.size() - 1; pointer2 != it2; i--){
            bob.push_back(heights[i]);
            pointer2++;
        }
        if (bob.size() == 0) continue;
        else if (bob.size() == 1) bobHeight = bob[0];
        else {
            auto pointerBob = upper_bound(bob.begin(), bob.end(), aliceHeight);
            if (bob[*pointerBob] == aliceHeight) continue;
            std::advance(it, *pointerBob);
            bobHeight = *it;
        }
        if (bobHeight == 0 || aliceHeight == 0) continue;
        count++;
        res.push_back(m);
    }
    // cout << count << '\n';
    // for (int i = 0; i < res.size(); i++){
    //     cout << res[i] << "\n";
    // }
    return EXIT_SUCCESS;
}