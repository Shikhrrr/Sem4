#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void)
{
    cout << "Enter string: ";
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
        {'/', 1}
    };

    for (int i = 0; i < n; i++) {
        if (isalpha(a[i]) or isdigit(a[i])) {
            op.pb(a[i]);
        }
        else {
            if (a[i] == '(') {
                s.push(a[i]);
            }
            else if (a[i] == ')') {
                while (!s.empty() and s.top() != '(') {
                    op.pb(s.top());
                    s.pop();
                }
                s.pop();
            }
            else {
                while (!s.empty() and prec[s.top()] >= prec[a[i]]) {
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