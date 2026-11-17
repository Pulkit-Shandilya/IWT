
    #include <iostream>
#include <string>

    int longestValidParentheses(std::string s){
        int len = s.length();
        char *stack = new char[len];
        int max = 0;
        int count = 0;
        if (s.length()<2){return 0;}
        for (int i = 0; i < len; i++){
            
            if (s[i] == '(' && s[i+1] == ')') {
                count++;
                i++;
            }
            else{
                (count>max) ? max = count : 0;
                count = 0;
            }
        }
        (max==0) ? max=count:0;
        return max*2;

    }


int main(int argc, char const *argv[])
{
    std::string x = "()(())";
    std::cout << longestValidParentheses(x) << std::endl;
    return 0;
}
// (()()())()()((())()((()()((()()()((()()()))(()()(()(()))(()(())()))((())(()))(())(()()()())))(()((()))))))))
