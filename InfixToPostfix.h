#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <cmath>

#include "Stack.h"

class InfixToPostfix{
    private:
        string infix;
        string postfix;

        int getPriority(char op){
            if (op == '*' || op == '/')
                return 2;
            if (op == '+' || op == '-')
                return 1;
            return 0;
        }
        bool precedence(char op1, char op2){
            return getPriority(op1) >= getPriority(op2);
        }

    public:
        InfixToPostfix(): infix(""), postfix(""){}
        ~InfixToPostfix(){}
        string getInfix(){
            return infix;
        }
        void setInfix(string i){
            infix = i;
        }
        string getPostfix(){
            return postfix;
        }
        void showInfix(){
            cout << "Infix Expression: "  << infix << ";" << endl;
        }
        void showPostfix(){
            cout << "Postfix Expression: " << postfix << endl;
        }
        int convertBinaryToInt(char binString[]){
            Stack<int> s;
            int res = 0;
            
            int weight = 0;
            for(int i = 0; binString[i] != '\0'; i++){
                s.push(binString[i] - '0');
            }

            while(!s.isEmpty()){
                res += s.top() * pow(2, weight++);
                s.pop();
            }
            return res;
        }
        void convertToPostfix(){
            postfix = "";
            Stack <char> s;

            for(int i = 0; i < infix.length(); i++){
                char cur = infix.at(i);
                if(cur == ' ' || cur == '\n')
                    continue;
                if(isalnum(cur)){
                    if(isdigit(cur)){
                        while(i < infix.length() && isdigit(infix[i])){
                            postfix += infix[i++];
                        }
                        postfix += " ";
                        i--;
                    }
                    else{
                        postfix += cur;
                        postfix += " ";
                    }
                }
                else if (cur == '(')
                    s.push(cur);
                else if (cur == ')'){
                    while(!s.isEmpty() && s.top() != '('){
                        postfix += s.top();
                        postfix += " ";
                        s.pop();
                    } 
                    if (!s.isEmpty())
                        s.pop();
                }
                else if (getPriority(cur) != 0){
                    while(!s.isEmpty() && s.top() != '(' && precedence(s.top(), cur)){
                        postfix += s.top();
                        postfix += " ";
                        s.pop();
                    }
                    s.push(cur);
                }
            }
            while(!s.isEmpty()){
                if (s.top() != '('){
                    postfix += s.top();
                    postfix += " ";
                }
                s.pop();
            }
        }

        int postfixCalculator(){
            Stack <int> s;

            for(int i = 0; i < postfix.length(); i++){
                char cur = postfix.at(i);
                if(cur == ' ' || cur == '\n')
                    continue;
                if(isdigit(cur)){
                    int num = 0;
                    while (i < postfix.length() && isdigit(postfix[i])){
                        num = num * 10 + (postfix[i] - '0');
                        i++;
                    }
                    i--;
                    s.push(num);
                }
                else if (getPriority(cur) != 0){
                    int val2 = s.top();
                    s.pop();
                    int val1 = s.top();
                    s.pop();
                    
                    if (cur == '+')
                        s.push(val1 + val2);
                    else if (cur == '-')
                        s.push(val1 - val2);
                    else if (cur == '*')
                        s.push(val1 * val2);
                    else{
                        if(val2 == 0)
                            throw out_of_range("Cannot divide by 0");
                        s.push(val1 / val2);
                    }
                    
                }
                    
            }
            return s.top();
        }
};
#endif