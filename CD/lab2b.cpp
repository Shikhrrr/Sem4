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

    map<char, int> prec = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'(', 0},
        {')', 0},
        {'^', 3}
    };

    for (int i = 0; i < n; i++) {
        if (isalpha(a[i]) || isdigit(a[i])) {
            op.pb(a[i]);
        }
        else if (a[i] == '(') {
            s.push(a[i]);
        }
        else if (a[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                op.pb(s.top());
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && prec[a[i]] <= prec[s.top()]) {
                op.pb(s.top());
                s.pop();
            }
            s.push(a[i]);
        }
    }

    while (!s.empty()) {
        op.pb(s.top());
        s.pop();
    }

    cout << op << endl;
}
