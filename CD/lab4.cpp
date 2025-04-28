//Shikhar Kanaujia   12311005    CSE-A
#include <bits/stdc++.h>

using namespace std;

class SymbolTableEntry {
public:
    string name;
    string type;
    string scope;

    SymbolTableEntry(string name, string type, string scope) {
        this->name = name;
        this->type = type;
        this->scope = scope;
    }
};

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;
    cin.ignore(); 

    vector<SymbolTableEntry> table;

    for (int i = 0; i < n; i++) {
        string name, type, scope;

        cout << "Enter details for variable " << (i + 1) << endl;
        cout << "Name: ";
        getline(cin, name);

        cout << "Type: ";
        getline(cin, type);

        cout << "Scope (e.g., global, local): ";
        getline(cin, scope);

        table.emplace_back(name, type, scope);
    }

    cout << "\n+------------+------------+------------+" << endl;
    cout << "| " << setw(10) << left << "Name"
         << " | " << setw(10) << left << "Type"
         << " | " << setw(10) << left << "Scope" << " |" << endl;
    cout << "+------------+------------+------------+" << endl;

    for (const auto& entry : table) {
        cout << "| " << setw(10) << left << entry.name
             << " | " << setw(10) << left << entry.type
             << " | " << setw(10) << left << entry.scope << " |" << endl;
        cout << "+------------+------------+------------+" << endl;
    }

    return 0;
}
