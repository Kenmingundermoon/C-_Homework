/*��������ҵ
��1���ڶ������ʱ���ܹ�ȷ���ַ�������󳤶Ȳ�����ַ�����

��2�������Ա����input, ���ڴӼ���Ϊ�ַ����������ݡ�

��3��������������غ����������ж����������е��ַ����Ƿ���ͬ��

��4�������Ա����exchange�����ڻ����ַ�����ASCII��������С���ַ����迼���ַ����д��ڶ��������С�ַ����������

��5�������Ա����disp��������ʾ�ַ�����

��6������main����������ص�������ÿ��������

*/
#include<iostream>
#include<cstring>

using namespace std;



class String{
    int len;//��¼�ַ�������
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
    cout<<"�����벻����"<<len<<"���ַ���:"<<endl;
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
    cout<<"�ַ���ת�����"<<endl;
}

void String::disp(){
    cout<<"�ַ���Ϊ��"<<endl;
    cout<<str<<endl;
}

int main(){
    int n;
	cout<<"������һ���ַ���,�������һ���ַ�������󳤶ȣ�";
	cin>>n;
	String str1(n);//��ʼ���ַ���
	str1.input();//�����һ���ַ���
	str1.disp();//��ʾ��һ���ַ���

	cout<<"�����ڶ����ַ���,������ڶ����ַ�������󳤶ȣ�";
	cin>>n;
	String str2(n);//��ʼ���ַ���
	str2.input();//����ڶ����ַ���
	str2.disp();//��ʾ�ڶ����ַ���

	if(str1==str2){
        cout<<"�����ַ������"<<endl;
	}
	else{
        cout<<"�����ַ��������"<<endl;
	}

	str1.exchange();//����exchange()�����������ַ���str1��ASCII��������С���ַ�
	str1.disp();//��ʾ�������str1�ַ���

	str2.exchange();//����exchange()�����������ַ���str2��ASCII��������С���ַ�
	str2.disp();//��ʾ�������str2�ַ���

    return 0;

}



