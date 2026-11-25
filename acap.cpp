#include <bits/stdc++.h>

using namespace std;

int main(){

    int numnotes, dif;
    cin >> numnotes >> dif;

    int note, ans = 0;

    // vector<int> notes;
    // vector<int> differences(numnotes);

    // cin >> note;
    // notes.push_back(note);
    // differences[0] = 0;
    // int current = 0;

    // for (int i = 1; i < numnotes; i++){
    //     cin >> note;
    //     notes.push_back(note);
    //     differences[i] = abs(note - notes[current]);
    //     if (differences[i] > dif){
    //         ans++; current = i;
    //     } 
    // }

    // for (int n: differences) cout << n << " ";
    // cout << endl;

    set<int> notes;
    for (int i = 0; i < numnotes; i++){
        cin >> note;
        notes.insert(note);
    }

    auto it = notes.begin();
    auto current = it;
    while (it != notes.end()){
        cout << *it << '\n';
        if (abs (*it++ - *current) <= dif){
            continue;
        } else {
            ans++;
            current = it;
        }
    }

    cout << ans << '\n';
    return EXIT_SUCCESS;
}