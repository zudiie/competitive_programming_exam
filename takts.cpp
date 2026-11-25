#include <bits/stdc++.h>

using namespace std;

int cM = 1, cS = 0;

void checkMultiplier(){
    if (cS < 2 && cM == 1){
        cM = 1; cS = 1;
    } 
    else if (cS >= 2 && cM == 1){
    
      cM = 2; cS = 0;
    }
    else if (cS >= 4 && cM == 2) {
        cM = 4; cS = 0;
    }
    else if (cS >= 8 && cM == 4){
        cM = 8; cS = 0;
    }
}

void reduceMultiplier(){
    if (cM > 1) cM /= 2;
    else cM = 1;
}

int main(){
    int num, score, sum = 0;
    cin >> num;
    vector<int> scores;
    for (int i = 0; i < num; i++){
        cin >> score;
        if (score > 0) {
            cS++;
            checkMultiplier();
            sum += score * cM;

        } else {
            reduceMultiplier();
            cS = 0;
        }
    }

    cout << sum;


    return EXIT_SUCCESS;
}