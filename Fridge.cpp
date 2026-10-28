#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    string input;
    cin >> input;
    int temp;
    map<int, int> nums;
    for (int i = 0; i < input.length(); i++){
        temp = (input[i] - '0');
        nums[temp]++;
    }
    int min = 1001;
    int index = 11;
    for (int i = nums.size(); i >= 0; i--){
        if (min > nums[i]){
            min = nums[i];
            index = i;
        }
    }
    int numFOUND;
    bool found = false;
    cout << min << " " << index;
    for (int i = 1; i < 10; i++){
        if (nums[i] == 0){
            found = true;
            numFOUND = i;
            break;
        }
    }
    if (found){
        cout << numFOUND << '\n';
    } else if (!found && nums[0] == 0){
        cout << 10 << '\n';
    } else if (nums[0] != 0){
        for (int i = 0; i <= min; i++){
            cout << index;
        }
        cout << '\n';
    } else {
        cout << 1;
        for (int i = 0; i <= min; i++){
            cout << index;
        }
    }
    


    return EXIT_SUCCESS;
}