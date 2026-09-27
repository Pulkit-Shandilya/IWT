#include <iostream>

#include <string>



void push(char c, char stack[], int *top) {
    stack[++(*top)] = c;
}
int pop(char stack[], int *top) {
    if (*top == -1) {
        return -1; // Error: stack is empty
    }
    return stack[(*top)--];
}

bool isValid(std::string s){
    int len = s.length();
    char *stack = new char[len];
    
    int top = -1;
    for (int i = 0; i < len; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i], stack, &top);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (top==-1)
            {
                return 0;
            }
            char c = pop(stack, &top);
            if ((s[i] == ')' && c != '(') ||
                (s[i] == ']' && c != '[') ||
                (s[i] == '}' && c != '{')) {
                return 0;
            }
        }
    }
    return (top == -1) ? 1 : 0;
}

int main(int argc, char const *argv[])
{
    std::string x = "hello{whats up{haha(ok[ok whwaf(okwa{lkasjd})] so [wha])}}";
    std::cout << isValid(x) << std::endl;
    return 0;
}
    // std::string x = "for (int i = 0; i < len; i++){if (s[i] == '(' || s[i] == '[' || s[i] == '{') {push(s[i], stack, &top);}else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {if (top==-1){return 0;}char c = pop(stack, &top);if ((s[i] == ')' && c != '(') ||(s[i] == ']' && c != '[') ||(s[i] == '}' && c != '{')) {return 0;}}}";
