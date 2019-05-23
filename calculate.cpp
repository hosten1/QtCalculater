#include "calculate.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<string, int>> word;
//string expr = "(1.5+5.789)*82-10/2";
int idx = 0;
int sym = 0;
int err = 0; // 错误

void T();
void F();
/*--------------------------------词法分析----------------------------*/
int word_analysis(vector<pair<string, int>>& word, const string expr)
{
    for(int i=0; i<expr.length(); ++i)
    {
        // 如果是 + - * / ( )
        if(expr[i] == '(' || expr[i] == ')' || expr[i] == '+'
           || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            string tmp;
            tmp.push_back(expr[i]);
            switch (expr[i])
            {
                case '+':
                    word.push_back(make_pair(tmp, 1));
                    break;
                case '-':
                    word.push_back(make_pair(tmp, 2));
                    break;
                case '*':
                    word.push_back(make_pair(tmp, 3));
                    break;
                case '/':
                    word.push_back(make_pair(tmp, 4));
                    break;
                case '(':
                    word.push_back(make_pair(tmp, 6));
                    break;
                case ')':
                    word.push_back(make_pair(tmp, 7));
                    break;
            }
        }
        // 如果是数字开头
        else if(expr[i]>='0' && expr[i]<='9')
        {
            string tmp;
            while(expr[i]>='0' && expr[i]<='9')
            {
                tmp.push_back(expr[i]);
                ++i;
            }
            if(expr[i] == '.')
            {
                ++i;
                if(expr[i]>='0' && expr[i]<='9')
                {
                    tmp.push_back('.');
                    while(expr[i]>='0' && expr[i]<='9')
                    {
                        tmp.push_back(expr[i]);
                        ++i;
                    }
                }
                else
                {
                    return -1;  // .后面不是数字，词法错误
                }
            }
            word.push_back(make_pair(tmp, 5));
            --i;
        }
        // 如果以.开头
        else
        {
            return -1;  // 以.开头，词法错误
        }
    }

    return 0;
}
/*--------------------------------语法分析----------------------------*/
// 读下一单词的种别编码
void Next()
{
    if(idx < word.size())
        sym = word[idx++].second;
    else
        sym = 0;
}

// E → T { +T | -T }
void E()
{
    T();
    while(sym == 1 || sym == 2)
    {
        Next();
        T();
    }
}

// T → F { *F | /F }
void T()
{
    F();
    while(sym == 3 || sym == 4)
    {
        Next();
        F();
    }
}

// F → (E) | d
void F()
{
    if (sym == 5)
    {
        Next();
    }
    else if(sym == 6)
    {
        Next();
        E();
        if (sym == 7)
        {
            Next();
        }
        else
        {
            err = -1;
        }
    }
    else
    {
        err = -1;
    }
}
bool isDig(char c){
    switch (c) {
        case '0':
            return true;
            break;
        case '1':
            return true;
            break;
        case '2':
            return true;
            break;
        case '3':
            return true;
            break;
        case '4':
            return true;
            break;
        case '5':
            return true;
            break;
        case '6':
            return true;
            break;
        case '7':
            return true;
            break;
        case '8':
            return true;
            break;
        case '9':
            return true;
            break;
        default:
            return false;
            break;
    }
}
///////////////////////////////////////////////////////////////////////中缀转后缀
#define Max 100
#define Maxop 7
struct
{//设定运算符优先级
    char ch;//运算符
    int pri;//优先级
}lpri[]={{'=',0}, {'(',1}, {'*',5}, {'/',5}, {'+',3} ,{'-',3}, {')', 6} },
rpri[]={{'=',0},{'(',6}, {'*',4}, {'/',4},{'+',2},{'-',2}, {')',1} };
Calculate::Calculate()
{

}
float Calculate::stringCalculate(std::string expression){
    bool isPreChar = false;
//    char c;
    string str;//这里先去除掉+、-号，方便验证
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '+' || expression[i] == '-') {
            if (i+1 >= expression.length()) {
                continue;
            }
            if (expression[i+1] == '+' || expression[i+1] == '-') {
                isPreChar = true;
                str = str + expression[i];
                i++;
                continue;
            }
            if (isDig(expression[i+1])) {
                if(i-1 >= 0 && isDig(expression[i-1])){//前一个是数字，后一个是数字
                    isPreChar = true;
                    str = str + expression[i];
                }else{
                    isPreChar = true;
                    str = str + expression[i+1];
                    i++;
                }
               
                continue;
            }
            
        }
        str = str+expression[i];
    }
    cout <<"str="<< str << endl;
//    return 2.1;
    word.clear();
    int idx = 0;
    int sym = 0;
    int err = 0;
    int err_num = word_analysis(word, str);
    cout << expression << endl << "Word Analysis:" << endl;
    float pos = 0.0;
    if (-1 == err_num)
    {
        cout << "Word Error!" << endl;
    }
    else
    {
        // 测试输出
        vector<pair<string, int>>::iterator beg = word.begin();
        for(;beg!=word.end(); ++beg)
            cout << "   (" << beg->first << ", " << beg->second << ")" << endl;
        
        // 词法正确，进行语法分析
        Next();
        E();
        if (sym == 0 && err == 0) { // 注意要判断两个条件
            cout << "Right Expression." << endl;
            cout<<"本例可算负数，小数:"<<expression<<endl;
            string str = expression;
            char exp[str.length()+1];
            int i;
            for( i=0;i<str.length();i++){
                exp[i] = str[i];
            }
            exp[i] = '\0';
            
            char postexp[str.length()+1];
            Trans(exp,postexp);
            pos = Compvalue(postexp);
            cout<<"中缀表达式"<<exp<<endl;
            cout<<"后缀表达式"<<postexp<<endl;
            cout<<"值"<<pos<<endl;
        
        }else{
            cout << "Wrong Expression." << endl;
        }
    }
    return pos;
}
int  Calculate::leftpri(char op)
{//求左运算符的优先级
    int i;
    for(i=0;i<Maxop;i++){
        if(lpri[i].ch==op){
           return lpri[i].pri;
        }

    }
    return 0;
}
int  Calculate::rightpri(char op)
{//求右运算符优先级
    int i;
    for(i=0;i<Maxop;i++){
        if(rpri[i].ch==op){
           return rpri[i].pri;
        }

    }

    return 1;
}

bool  Calculate::Inop(char ch)
{//判断ch是否为运算符
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')')
        return true;
    else
        return false;
}
int  Calculate::Precede(char op1,char op2)//////////////////////////
{//运算符优先级比较结果
    if(leftpri(op1) == rightpri(op2))
        return 0;
    else if(leftpri(op1) <rightpri(op2))
        return -1;
    else
        return 1;
}

void  Calculate::Trans(char * exp,char postexp[])
{//将算术表达式装换成后缀表达式

    struct
    {
        char data[Max];
        int top;
    }op;
    //  SqStack op;

    int i=0;
    op.top=-1;
    op.top++;
    op.data[op.top]='=';

    if(*exp=='-')
    {
        postexp[i++]='0';
        postexp[i++]='#';
        exp++;
        while(*exp>='0'&&*exp<='9'||*exp=='.')
        {
            postexp[i++]=*exp;
            exp++;
        }
        postexp[i++]='#';
        postexp[i++]='-';

    }
    if(*exp=='.')
    {
        postexp[i++]='0';
        postexp[i++]='.';
        exp++;
        while(*exp>='0'&&*exp<='9')
        {
            postexp[i++]=*exp;
            exp++;
        }
        postexp[i++]='#';


    }


    while(*exp!='\0')
    {
        if(* exp=='(' )
        {exp++;
            if( * exp=='-')
            {   //cout<<*exp<<endl;
                postexp[i++]='0';

                //  cout<<"sgd"<<endl;
                postexp[i++]='#';
                op.top++;
                op.data[op.top]='(';
                op.top++;
                op.data[op.top]='-';
                exp++;
                //cout<<"asdgwerherth"<<endl;
            }
            else
                exp--;
        }
        //--exp;

        if(!Inop(*exp))//不是运算符,是数字
        {
            while(*exp >= '0' && * exp <= '9' || *exp == '.' )
            {
                postexp[i++]= * exp;
                // i++;
                exp++;
            }
            postexp[i++]='#';
        }
        else
        {
            switch(Precede(op.data[op.top],*exp))///////
            {
                case -1:
                    op.top++;///////栈顶运算符优先级低
                    op.data[op.top]= * exp;
                    exp++;
                    break;
                case 0:///只有左右括号相遇满足这种情况
                    //  postexp[i]=op.data[op.top];
                    //  i++;
                    op.top--;
                    exp++;
                    break;
                case 1:
                    postexp[i++]=op.data[op.top];
                    //  i++;
                    op.top--;
                    //  exp++;
                    break;

            }
        }
    }//while


    while(op.data[op.top]!='=')
    {
        postexp[i++]=op.data[op.top];
        op.top--;
        /// i++;
    }


    postexp[i]='\0';


}

/////////////////////////////////////////////////////////////后缀表达式求值
float  Calculate::Compvalue(char *postexp)
{
    int i;
    struct
    {
        float data[Max];
        int top;
    }st;
    float d,a;
    st.top=-1;
    while(*postexp!='\0')
    {
        switch(*postexp)
        {
            case '+':
                a=st.data[st.top];
                st.top--;
                st.data[st.top]+=a;
                break;
            case '-':   a=st.data[st.top];
                st.top--;
                st.data[st.top]-=a;
                break;
            case '*':
                a=st.data[st.top];
                st.top--;
                st.data[st.top]*=a;
                break;
            case '/':
                a=st.data[st.top];


                if(a==0)
                {   cout<<"0不能做除数"<<endl;
                    exit(0);
                }
                else
                {
                    //      a=st.data[s.top];
                    st.top--;
                    st.data[st.top]/=a;
                    break;
                }

            default:

                d=0;
                i=0;
                while(*postexp!='#')
                {
                    if(*postexp=='.')
                    {
                        postexp++;
                        i++;
                        //    while(*postexp!='#')
                        //  {
                        if(*postexp>='0'&&*postexp<='9')
                        {
                            d=10*d + *postexp-'0';/////////////////////////////////////////double(*postexp)错误
                            postexp++;
                        }
                        //  }//while
                    }
                    if(i!=0){
                        if(*postexp>='0'&&*postexp<='9')
                        {i++;
                            d=10*d + *postexp-'0';/////////////////////////////////////////double(*postexp)错误
                            postexp++;
                        }
                    }
                    else
                        if(*postexp>='0'&&*postexp<='9')
                        {
                            d=10*d + *postexp-'0';/////////////////////////////////////////double(*postexp)错误
                            postexp++;
                        }


                }

                while(i!=0)
                {
                    d=d/10;
                    i--;
                    cout<<d<<endl;

                }
                st.top++;
                st.data[st.top]=d;
                break;
        }//switch
        postexp++;
    }//while

    return st.data[st.top];

}
Calculate::~Calculate(){

}
