#include <bits/stdc++.h>

using namespace std;

//for map sorting
bool cmp(pair<string, int>& a, pair<string, int>& b) 
{ 
    return a.second < b.second; 
} 

void sort(map<string, int>& map_, int num) 
{ 
    vector<pair<string, int>> test; 
    for (auto& it : map_) { 
        test.push_back(it); 
    } 

    sort(test.begin(), test.end(), cmp); 

    for (auto& it : test) { 

        cout << it.first << ' '
            << it.second << endl; 
    } 
} 

int main(){

    string junk, str;
    while(cin >> junk){
        map<string, int> dict;
        string text, ctext, word;
        int times;
        getline(cin, text);
        while(cin >> word && word != "</text>"){
            dict[word]++;
            cout << word << '\n';
        }
        scanf("%c");
        cin >> str;
        if (str == "<top"){
            scanf("%c");
            cin >> times;
            cin >> junk;
            sort(dict, times);
        } else {
            cin >> junk;
        }
    }

    //cout << str;



    return EXIT_SUCCESS;
}