#include <bits/stdc++.h>

using namespace std;


int main(){
    stack<char> st;
      char input;
    while (cin >> input && input != '\n'){
        if (input == '<'){
            st.pop();
        } else {
            st.push(input);
        }
    }
    string ans;
    while (!st.empty()){
        ans += st.top(); st.pop();
    }
    std::reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    


    return EXIT_SUCCESS;
}