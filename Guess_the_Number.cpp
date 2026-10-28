#include <iostream>

using namespace std;

int main()
{
    int guessCount = 1;
    int guess = 500;
    int l = 1;
    int r = 1001;

    cout << guess << '\n';
    string input;
    while (cin >> input){
        if (guessCount == 10){
            return EXIT_SUCCESS;
        }
        if (input == "correct"){
            return EXIT_SUCCESS;
        } else if (input == "higher"){
            l = guess;            
        } else {
            r = guess;
        }
        guess = (l + r) / 2;
        guessCount++;
        cout << guess << '\n';
    }

    return EXIT_SUCCESS;
}