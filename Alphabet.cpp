#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;

    vector<int> dp(input.length() + 1, 1);
    vector<int> par(input.length() + 1, -1);
    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] < input[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
    }

    int best = 0;
    for (int i = 1; i < input.length(); i++)
    {
        if (dp[i] > dp[best])
            best = i;
    }
    
    
    vector<int> res;
    for (int i = best; i != -1; i = par[i])
    {
        res.push_back(i);
    }
    cout << (26 - res.size()) << '\n';

    return EXIT_SUCCESS;
}