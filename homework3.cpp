/*第三次作业
（1）在定义对象时，能够确定字符串的最大长度并清空字符串。

（2）定义成员函数input, 用于从键盘为字符串输入数据。

（3）定义运算符重载函数，用于判断两个对象中的字符串是否相同。

（4）定义成员函数exchange，用于互换字符串中ASCII码最大和最小的字符（需考虑字符串中存在多个最大和最小字符的情况）。

（5）定义成员函数disp，用于显示字符串。

（6）定义main函数，合理地调用上述每个函数。

*/
#include<iostream>
#include<cstring>

using namespace std;



class String{
    int len;//记录字符串长度
    char *str;


public:
    String(int n);
    ~String();
    void input();
    bool operator == (const String &another);
    void exchange();
    void disp();

};

String::String(int n){
    if(n>0){
        len=n;
        str=new char [len+1];
        for(int i=0;i<len;i++)
            str[i]='\0';
    }
}

String::~String(){
    delete []str;
}


void String::input(){
    cout<<"请输入不长于"<<len<<"的字符串:"<<endl;
    cin>>str;
}

bool String::operator==(const String &another){
    int i;

    if(strcmp(str,another.str)==0){
        return true;
    }
    else{
        return false;
    }
}


void String::exchange(){
    char Max=str[0],Min=str[0];
    for(int i=0;i<len&&str[i]!='\0';i++){
        if(Max<str[i]){
            Max=str[i];
        }
        if(Min>str[i]){
            Min=str[i];
        }
    }
    for(int i=0;i<len&&str[i]!='\0';i++){
        if(str[i]==Max){
            str[i]=Min;
        }
        else if(str[i]==Min){
            str[i]=Max;
        }
    }
    cout<<"字符串转换完成"<<endl;
}

void String::disp(){
    cout<<"字符串为："<<endl;
    cout<<str<<endl;
}

int main(){
    int n;
	cout<<"创建第一个字符串,请输入第一个字符串的最大长度：";
	cin>>n;
	String str1(n);//初始化字符串
	str1.input();//输入第一个字符串
	str1.disp();//显示第一个字符串

	cout<<"创建第二个字符串,请输入第二个字符串的最大长度：";
	cin>>n;
	String str2(n);//初始化字符串
	str2.input();//输入第二个字符串
	str2.disp();//显示第二个字符串

	if(str1==str2){
        cout<<"两个字符串相等"<<endl;
	}
	else{
        cout<<"两个字符串不相等"<<endl;
	}

	str1.exchange();//调用exchange()函数，互换字符串str1中ASCII码最大和最小的字符
	str1.disp();//显示互换后的str1字符串

	str2.exchange();//调用exchange()函数，互换字符串str2中ASCII码最大和最小的字符
	str2.disp();//显示互换后的str2字符串

    return 0;

}



