#include <iostream>

#define MAX 100
struct stack{
    int data[MAX];
    int top;

    public:
        stack(): top(-1){}

        int PopEle(){
            if (top==-1){
                std::cout<<"Queue is empty"<<std::endl;
                return -1;
            }
            return data[top--];
        }
        
        void Push(int element){
            if (top ==MAX-1){
                std::cout<<"Stack is full"<<std::endl;
            }
            else{
                data[++top] = element;
            }
        }
};

int NextEle(struct stack *s1 , struct stack *s2){
    if (s2->top == -1){
        if(s1->top != -1){
            while (s1->top != 0){
                s2->Push(s1->PopEle());
            }
            return s1->PopEle();
        }
        else{
            std::cout<<"Queue is empty"<<std:: endl;
        }
    }else{
        return s2->PopEle();
    }
}

void EnterEle(struct stack *s1, struct stack *s2, int element){
    if (s2->top==-1){
        s1->Push(element);
    }
    else{
        while (s2->top !=-1)
        {
            s1->Push(s2->PopEle());
        }
        s1->Push(element);
    }
    
}
int main(int argc, char const *argv[]){
    stack s1 , s2;

    EnterEle(&s1, &s2, 10);
    EnterEle(&s1, &s2, 5);
    EnterEle(&s1, &s2, 213);
    EnterEle(&s1, &s2, 3);
    EnterEle(&s1, &s2, 2);
    std::cout<<NextEle(&s1, &s2)<<std::endl;
    std::cout<<NextEle(&s1, &s2)<<std::endl;
    std::cout<<NextEle(&s1, &s2)<<std::endl;
    EnterEle(&s1, &s2, 6);
    EnterEle(&s1, &s2, 4);
    std::cout<<NextEle(&s1, &s2)<<std::endl;
    std::cout<<NextEle(&s1, &s2)<<std::endl;
    std::cout<<NextEle(&s1, &s2)<<std::endl;
    std::cout<<NextEle(&s1, &s2)<<std::endl;
    std::cout<<NextEle(&s1, &s2)<<std::endl;
 
}
