#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(int type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(std::cin, text);
    int last_unmatched = -1;

    stack <Bracket> opening_brackets_stack;
    if (text.length() < 2) {
        cout << 1;
        return 0;
    }

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            if (!opening_brackets_stack.empty() && opening_brackets_stack.top().Matchc(next)) {
                opening_brackets_stack.pop();
            } else { 
                cout << position + 1;
                return 0;
            }
        }
    }

    if (opening_brackets_stack.empty() && last_unmatched == -1) {
        cout << "Success";
    } else if (last_unmatched == -1) {
        cout << opening_brackets_stack.top().position + 1;
    } else {
        cout << last_unmatched + 1;
    } 

    return 0;
}
