#include <iostream>
#include <string>
#include <stack>

bool areBracketsBalanced(const std::string& line) 
{
    std::stack<char> brackets;

    for (char ch : line) {
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (brackets.empty()) return false;

            char top = brackets.top();
            brackets.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) 
                {
                return false;
                }
        }
    }

    return brackets.empty();
}

int main()
{
    std::string line;
    std::cout << "Enter your brackets: ";
    std::getline(std::cin, line);

    if (areBracketsBalanced(line))
        std::cout << "OK\n";
    else
        std::cout << "NOT OK\n";
}
