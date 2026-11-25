#include <iostream>
#include <set>
#include <climits>
#include <map>

using namespace std;

int main()
{
    int photos;
    cin >> photos;
    int count = 0;
    vector<int> res;
    for (int m = 1; m <= photos; m++)
    {
        int num, phot;
        cin >> num;
        vector<int> heights;
        int min = INT_MAX;
        for (int i = 0; i < num; i++)
        {
            
            cin >> phot;
            heights.push_back(phot);
            if (min > phot)
            {
                min = phot;
            }
        }

        // cout << min << " ";
        auto pointer = find(heights.begin(), heights.end(), min);
        vector<int> alice;
        vector<int> bob;
        auto it = heights.begin();
        int j = 0;
        if (it != pointer)
        {
            while (it != pointer)
            {
                //cout << heights[pointer - it - 1] << " \n";
                alice.push_back(heights[pointer - it - 1]);
                it++;
            }
        }
        int aliceHeight, bobHeight;
        // cout << min << " ";
        it = heights.begin();
        if (alice.size() == 0)
            continue;
        else
        {
            auto pointerAlice = upper_bound(alice.begin(), alice.end(), min);
            if (alice[pointerAlice - alice.begin()] == min)
                continue;
            aliceHeight = alice[pointerAlice - alice.begin()];
            //cout << aliceHeight << " ";
        }

        // cout << aliceHeight << " ";
        auto pointer2 = pointer;
        auto it2 = heights.end();

        for (int i = heights.size() - 1; pointer2 != it2; i--)
        {
            bob.push_back(heights[it2 - pointer2 + i]);
            pointer2++;
        }
        if (bob.size() == 0)
            continue;
        else
        {
            auto pointerBob = upper_bound(bob.begin(), bob.end(), aliceHeight);
            if (bob[pointerBob - bob.begin()] == aliceHeight)
                continue;
            bobHeight = bob[pointerBob - bob.begin()];
            //cout << bobHeight << " ";
        }
        if (bobHeight == 0 || aliceHeight == 0)
            continue;
        count++;
        res.push_back(m);
    }
    cout << count << '\n';
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    return EXIT_SUCCESS;
}