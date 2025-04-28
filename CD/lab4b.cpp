#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

struct Symbol {
    string name;
    string type;
    string returnType;
    string scope;
};

vector<Symbol> symbolTable;
stack<string> scopeStack;

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n");
    return str.substr(first, (last - first + 1));
}

string currentScope() {
    if (scopeStack.empty()) return "global";
    stack<string> temp = scopeStack;
    vector<string> scopes;
    while (!temp.empty()) {
        scopes.push_back(temp.top());
        temp.pop();
    }
    reverse(scopes.begin(), scopes.end());
    string scopeStr;
    for (const string& s : scopes) {
        scopeStr += s + "::";
    }
    return scopeStr.substr(0, scopeStr.length() - 2);
}

void addSymbol(const string& name, const string& type, const string& returnType) {
    Symbol sym = {name, type, returnType, currentScope()};
    symbolTable.push_back(sym);
}

bool isType(const string& word) {
    vector<string> types = {"int", "float", "double", "char", "bool", "void", "long", "short"};
    return find(types.begin(), types.end(), word) != types.end();
}

void parseFunction(string line) {
    line = trim(line);
    size_t openParen = line.find('(');
    size_t closeParen = line.find(')');
    if (openParen == string::npos || closeParen == string::npos) return;

    string header = line.substr(0, openParen);
    string params = line.substr(openParen + 1, closeParen - openParen - 1);

    stringstream headerStream(header);
    string returnType, name;
    headerStream >> returnType >> name;

    addSymbol(name, "function", returnType);
    scopeStack.push(name);

    stringstream paramStream(params);
    string param;
    while (getline(paramStream, param, ',')) {
        param = trim(param);
        if (param.empty()) continue;
        stringstream pStream(param);
        string pType, pName;
        pStream >> pType >> pName;
        if (!pType.empty() && !pName.empty())
            addSymbol(pName, "parameter", pType);
    }
}

void parseVariable(string line) {
    line = trim(line);
    if (line.back() == ';') line.pop_back();

    stringstream ss(line);
    string type, name;
    ss >> type >> name;

    if (!type.empty() && !name.empty()) {
        addSymbol(name, "variable", type);
    }
}

void parseLine(string line) {
    line = trim(line);

    if (line.empty()) return;
    if (line == "{") {
        scopeStack.push("block");
    } else if (line == "}") {
        if (!scopeStack.empty()) scopeStack.pop();
    } else {
        size_t parenPos = line.find('(');
        if (parenPos != string::npos && line.find(')') != string::npos) {
            parseFunction(line);
        } else {
            string firstWord;
            stringstream ss(line);
            ss >> firstWord;
            if (isType(firstWord)) {
                parseVariable(line);
            }
        }
    }
}

void printSymbolTable() {
    cout << "\nSymbol Table:\n";
    cout << "----------------------------------------------------------\n";
    cout << "| Name       | Type      | Return Type | Scope           |\n";
    cout << "----------------------------------------------------------\n";
    for (const auto& sym : symbolTable) {
        printf("| %-10s | %-9s | %-11s | %-15s |\n", 
               sym.name.c_str(), sym.type.c_str(), sym.returnType.c_str(), sym.scope.c_str());
    }
    cout << "----------------------------------------------------------\n";
}

int main() {
    vector<string> codeLines;
    string line;

    cout << "Enter code lines (type END to finish):" << endl;
    while (getline(cin, line)) {
        if (trim(line) == "END") break;  
        codeLines.push_back(line);
    }

    for (const string& codeLine : codeLines) {
        parseLine(codeLine);
    }

    printSymbolTable();
    return 0;
}
