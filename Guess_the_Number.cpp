#include <bits/stdc++.h>

using namespace std;

int main()
{
    int guessCount = 1;
    int guess = 500;
    int l = 1;
    int r = 1000;

    cout << guess << endl;
    while (true){
        string input;
        cin >> input;
        if (input == "correct"){
            return EXIT_SUCCESS;
        } else if (input == "higher"){
            l = guess;            
        } else {
            r = guess;
        }
        guess = (l + r) / 2;
        guessCount++;
        cout << guess << endl;
    }

    return EXIT_SUCCESS;
}