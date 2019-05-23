#ifndef CALCULATE_H
#define CALCULATE_H
#include <string>

class Calculate
{
public:
    Calculate();
    float stringCalculate(std::string expression);
    ~Calculate();
private:
    int leftpri(char op);
    int rightpri(char op);
    bool Inop(char ch);
    int Precede(char op1,char op2);
    void Trans(char * exp,char postexp[]);
    float Compvalue(char *postexp);
};

#endif // CALCULATE_H
