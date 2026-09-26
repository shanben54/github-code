//表达式求值
//新的知识点：try,catch,exception,size_t,substr,stod
#include<iostream>
#include<string>
#include<stack>
#include<exception>//异常类的头文件，exception是其他异常类的基类，所以可以接受其他的异常类
using namespace std;

//判断符号优先级的函数
int Level(char c){
    switch(c){
        case '+': case '-': return 2;
        case '*': case '/': return 3;
        default: return 0;//"#"优先级最低
    }
}

//用于比较两个符号的优先级高低
char Precede(char top,char cur){
    if(top=='('&&cur==')') return '=';//两个括号相互抵消
    if(top=='#'&&cur=='#') return '=';//两个起始符也相互抵消
    if(top=='('||cur=='(') return '<';//左括号给其他符号让路
    if(cur=='#'||cur==')') return '>';//准备收尾，清算括号里的数据
    return Level(top)<Level(cur)?'<':'>';
}

//用于运算的函数
double Apply(double left,char op,double right){
    switch(op){
        case '+':return left+right;
        case '-':return left-right;
        case '*':return left*right;
        case '/':return left/right;
        default: return 0;
    }
}

//判断表达式的括号是否平衡
bool Balance(const string &s){
    int cnt=0;
    for(char c:s){
        if(c=='('){
            cnt++;
        }else if(c==')'){
            if(cnt--<0) return false;//cnt小于0说明有右括号先出现，如果没有这个判断，)(的情况也会算正常
        }
    }
    return cnt==0;//判断最后括号有没有都消掉
}

int main(){
    string s;
    cout<<"输入表达式"<<endl;
    cin>>s;
    
    //判断表达式平衡性，如果不平衡不用计算直接退出
    if(!Balance(s)){
        cout<<"表达式不合规"<<endl;
        system("pause");
        return 0;
    }
    
    stack<char> Operator;//用于储存运算符的栈
    stack<double> Number;//用于储存运算数据的栈
    Operator.push('#');//先填入一个#
    s+='#';//在表达式尾也加上一个#，和运算符栈进行匹配

    size_t i=0;//循环下标
    string err;//错误类型的字符串
    bool ok=true;//程序是否出错

    while(true){
        char c=s[i];//取出表达式的元素
        //如果是数字
        if((c>='0'&&c<='9')||c=='.'){
            size_t j=i;
            while(j<s.size()&&((s[j]>='0'&&s[j]<='9')||s[j]=='.')){
                j++;
            }//把i后面的数字和.都记录下来
            string tok=s.substr(i,j-i);//把整个数字完整的取出来
            size_t pos=0;
            double val=0;
            
            //try如果顺利就继续执行try的语句，如果出问题就直接抛出异常，由catch接收
            try{
                val=stod(tok,&pos);//将字符串转换成double，pos接受转换的长度
            }catch(const exception &){//接收exception的异常，不添加变量名表示不在于异常的具体内容
                ok=false;
                err="输入数字格式不对";
                break;
            }
            //pos不等于要转化的字符串长度，说明数字格式不对，出现1.2.3这样的情况
            if(pos!=tok.size()){
                ok=false;
                err="输入数字格式不对";
                break;
            }
            Number.push(val);//将这个数字放入运算数据栈
            i=j;//更新i的位置，直接跳过这个数字
        }else{//如果是运算符
            char top=Operator.top();//取出运算符栈顶的符号
            char rel=Precede(top,c);//和当前运算符进行优先级对比
            
            //如果当前运算符优先级更高
            if(rel=='<'){
                Operator.push(c);//直接把当前运算符放入栈，进行下一个数据判断
                i++;

            }else if(rel=='>'){//如果栈顶运算符优先级更高，则对栈顶运算符进行运算
                //这里i没有增加，i仍然指向当前运算符，先把当前运算符之前的更高运算符计算完然后再把当前运算符入栈

                if(Number.size()<2){
                    ok=false;
                    err="可操作数不足";
                    break;
                }//运算数据不足2个无法进行运算

                Operator.pop();
                double right=Number.top();//先取出来的数据是右数据
                Number.pop();
                double left=Number.top();//后取出来的数据是左数据
                Number.pop();
                
                //除数不能为0
                if(top=='/'&&right==0){
                    ok=false;
                    err="除数不能为0";
                    break;
                }

                //进行运算，然后把运算结果放入运算数据栈
                Number.push(Apply(left,top,right));

            }else{//如果两个优先级一样，两个是括号或者#，直接两两抵消
                Operator.pop();//取出栈顶运算符
                i++;//跳过这个运算符
                if(top=='#'&&c=='#') break;//如果是#，直接收尾结束
            }
        }
    }
    
    if(ok&&Number.size()==1){//如果表达式计算过程中没出错
        double ans=Number.top();//取出最终运算结果
        cout<<s.substr(0,s.size()-1)<<" = ";//这里s是size-1，因为最后还添加了一个#，不用打印出来
        cout<<ans<<endl;
    }else{
        cout<<(err.empty()?"表达式不合规":err)<<endl;//输出错误，表达式为空就说明虽然过程中没有问题，但是这个表达式计算不出来值
    }
    system("pause");
    return 0;
}