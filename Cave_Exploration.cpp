#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    string input;
    cin >> input;
    int temp;
    //map<int, int> nums(10, 0);
    for (int i = 0; i < input.length(); i++){
        temp = (input[i] - '0');
        cout << temp << '\n';
        //nums[atoi(input[i])]++;
    }

    return EXIT_SUCCESS;
}