/*定义一个类，用于对10个字符串进行管理。要求：
（1）在定义对象时，能够为字符串清空；
（2）定义变换构造函数，能够为字符串赋以给定的字符串；
（3）定义复制构造函数；
（4）定义成员函数，能够为字符串输入数据；
（5）定义成员函数，能够将字符串显示出来；
（6）定义成员函数，用于找出每个字符串中的最小值（ASCII码最小的字符）及其个数，最小值由函数值返回，个数由参数带回；
（7）定义成员函数，用于为字符串按从小到大顺序排序。
（8）定义main函数，合理地调用上述每个函数。*/


#include<iostream>
#include<cstring>

using namespace std;

const int maxn=11;//字符串长度可以调整

class Strings{
    char str[10][maxn];

public:
    Strings();
    Strings(char s[10][maxn]);
    Strings(const Strings &a);

    void input();
    void disp();
    char find(int i,int &num);
    void strings_sort();

};


Strings::Strings(){//构造函数，将字符串清空

	for (int i=0;i<10;i++)
	{
		for(int j=0;j<maxn;j++){
            str[i][j]='\0';
		}
	}
}


Strings::Strings(char s[10][maxn]){//变换构造函数

	for (int i=0;i<10;i++)
	{
		strcpy(str[i],s[i]);
	}

}


Strings::Strings(const Strings &a){//复制构造函数

    for(int i=0;i<10;i++){
        strcpy(str[i],a.str[i]);
    }
}

void Strings::input(){//字符串输入函数
    cout<<"请依次输入10个长度符合要求的字符串，每行一个字符串："<<endl;
    for(int i=0;i<10;i++){
        cin>>str[i];
    }
}

void Strings::disp(){//字符串显示函数
    cout<<"10个字符串分别为："<<endl;
    for(int i=0;i<10;i++){
        cout<<str[i]<<endl;
    }
}

char Strings::find(int i,int &num){//查找函数，找到第i个字符串中ASCII码最小的字符，并返回其组成的数组首地址
    char temp=str[i][0];
    for(int j=0;str[i][j]!='\0';j++){//第一次遍历，找到最小值字符
        if(temp>str[i][j]){
            temp=str[i][j];
        }
    }
    for(int j=0;str[i][j]!='\0';j++){//第二次遍历，统计最小值字符个数
        if(str[i][j]==temp){
            num++;
        }
    }
    return temp;
}


void Strings::strings_sort()
{
	for(int i=0;i<10;i++)
	{
        for(int j=0;j<9-i;j++){
            if(strcmp(str[j],str[j+1])>0){
                char *temp=new char[maxn];
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);
            }
        }
	}
	cout<<"字符串排序完成;"<<endl;
}

int main(){

    char S[10][maxn],ch[10];
    Strings A;


    cout<<"字符串A如下(测试构造函数):"<<endl;//测试构造函数
    A.disp();//测试构造函数

    cout<<"请输入10个长度符合要求的字符串，每行一个，将存储于独立的二维数组中(测试变换构造函数):"<<endl;
    for(int i=0;i<10;i++){
        cin>>S[i];
    }


    Strings B(S);//测试变换构造函数

    cout<<"字符串B如下:"<<endl;
    B.disp();//测试构造函数

    Strings C(B);//测试复制构造函数

    cout<<"字符串C如下(测试复制构造函数):"<<endl;
    C.disp();//测试构造函数

    C.input();//测试input函数
    C.disp();



    cout<<"10个字符串的最小字符以及其个数如下："<<endl;
    for(int i=0;i<10;i++){
        int num=0;
        cout<<C.find(i,num);
        cout<<"  "<<num<<endl;
    }

    C.strings_sort();//测试排序函数
    cout<<"排序后字符串C如下:"<<endl;
    C.disp();



    return 0;

}














