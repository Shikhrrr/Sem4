//Shikhar Kanaujia 12311005 CSE-A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter string: ";
    string input;
    getline(cin, input); 

    if (input.back() != ';' and input.back() != '}') {
        cout << "No" << endl;
        return 0;
    }

    vector<string> v = {"int", "bool", "void", "string", "char"};
    string ans;

    int c = 0;
    for (char e : input) {
        if (e == ' ') {
            c = 1;
            break;
        } else {
            ans.push_back(e);
        }
    }
    if (c == 0 or find(v.begin(), v.end(), ans) == v.end()) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes\n";
    }
}