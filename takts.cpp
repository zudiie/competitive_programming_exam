#include <bits/stdc++.h>

using namespace std;
// the second testcase dos not make sense, by their rules the answer should
// be 7930 which i get but they get much lower
int cM = 1, cS = 0;

void checkMultiplier(){
    if (cS < 2 && cM == 1) cM = 1;
    else if (cS >= 2 && cM == 1) cM = 2;
    else if (cS >= 4 && cM == 2) cM = 4;
    else if (cS >= 8 && cM == 4)cM = 8;
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
            cout << "score: " << score << " cS: " << cS << " cM: " << cM << " sum: " << sum << '\n';
        } else {
            reduceMultiplier();
            cS = 0;
        }
    }

    cout << sum;


    return EXIT_SUCCESS;
}