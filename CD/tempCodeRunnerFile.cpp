#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void)
{
    string a;
    cin >> a;
    int n = a.length();
    string op;

    stack<char> s;

    map<char, int> prec = 
    {
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'/', 1},
        {'(', 2},
        {')', 2}
    };

    for (int i = 0; i < n; i++) {
        if (a[i] != '+' and a[i] != '-' and a[i] != '*' and a[i] != '/' and a[i] != '(' and a[i] != ')') {
            op.pb(a[i]);
        }
        else {
            if (s.empty()) s.push(a[i]);
            else {
                while (!s.empty() && prec[s.top()] >= prec[a[i]]) {
                    if (s.top() == '(') break;
                    op.pb(s.top());
                    s.pop();
                }
                s.push(a[i]);
            }
        }
    }

    while (!s.empty()) {
        op.pb(s.top());
        s.pop();
    }

    cout << op << endl;
}