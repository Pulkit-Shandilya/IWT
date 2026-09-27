
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
        if (s[i] == '(') {
            push(')', stack, &top);
        }
        else if (s[i] == '[') {
            push(']', stack, &top);
        }
        else if (s[i] == '{') {
            push('}', stack, &top);
        }
        else if (top == -1 || s[i] != pop(stack, &top)) {
            return 0;
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