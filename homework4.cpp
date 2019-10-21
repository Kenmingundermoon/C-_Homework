/*����һ���࣬���ڶ�10���ַ������й���Ҫ��
��1���ڶ������ʱ���ܹ�Ϊ�ַ�����գ�
��2������任���캯�����ܹ�Ϊ�ַ������Ը������ַ�����
��3�����帴�ƹ��캯����
��4�������Ա�������ܹ�Ϊ�ַ����������ݣ�
��5�������Ա�������ܹ����ַ�����ʾ������
��6�������Ա�����������ҳ�ÿ���ַ����е���Сֵ��ASCII����С���ַ��������������Сֵ�ɺ���ֵ���أ������ɲ������أ�
��7�������Ա����������Ϊ�ַ�������С����˳������
��8������main����������ص�������ÿ��������*/


#include<iostream>
#include<cstring>

using namespace std;

const int maxn=11;//�ַ������ȿ��Ե���

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


Strings::Strings(){//���캯�������ַ������

	for (int i=0;i<10;i++)
	{
		for(int j=0;j<maxn;j++){
            str[i][j]='\0';
		}
	}
}


Strings::Strings(char s[10][maxn]){//�任���캯��

	for (int i=0;i<10;i++)
	{
		strcpy(str[i],s[i]);
	}

}


Strings::Strings(const Strings &a){//���ƹ��캯��

    for(int i=0;i<10;i++){
        strcpy(str[i],a.str[i]);
    }
}

void Strings::input(){//�ַ������뺯��
    cout<<"����������10�����ȷ���Ҫ����ַ�����ÿ��һ���ַ�����"<<endl;
    for(int i=0;i<10;i++){
        cin>>str[i];
    }
}

void Strings::disp(){//�ַ�����ʾ����
    cout<<"10���ַ����ֱ�Ϊ��"<<endl;
    for(int i=0;i<10;i++){
        cout<<str[i]<<endl;
    }
}

char Strings::find(int i,int &num){//���Һ������ҵ���i���ַ�����ASCII����С���ַ�������������ɵ������׵�ַ
    char temp=str[i][0];
    for(int j=0;str[i][j]!='\0';j++){//��һ�α������ҵ���Сֵ�ַ�
        if(temp>str[i][j]){
            temp=str[i][j];
        }
    }
    for(int j=0;str[i][j]!='\0';j++){//�ڶ��α�����ͳ����Сֵ�ַ�����
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
	cout<<"�ַ����������;"<<endl;
}

int main(){

    char S[10][maxn],ch[10];
    Strings A;


    cout<<"�ַ���A����(���Թ��캯��):"<<endl;//���Թ��캯��
    A.disp();//���Թ��캯��

    cout<<"������10�����ȷ���Ҫ����ַ�����ÿ��һ�������洢�ڶ����Ķ�ά������(���Ա任���캯��):"<<endl;
    for(int i=0;i<10;i++){
        cin>>S[i];
    }


    Strings B(S);//���Ա任���캯��

    cout<<"�ַ���B����:"<<endl;
    B.disp();//���Թ��캯��

    Strings C(B);//���Ը��ƹ��캯��

    cout<<"�ַ���C����(���Ը��ƹ��캯��):"<<endl;
    C.disp();//���Թ��캯��

    C.input();//����input����
    C.disp();



    cout<<"10���ַ�������С�ַ��Լ���������£�"<<endl;
    for(int i=0;i<10;i++){
        int num=0;
        cout<<C.find(i,num);
        cout<<"  "<<num<<endl;
    }

    C.strings_sort();//����������
    cout<<"������ַ���C����:"<<endl;
    C.disp();



    return 0;

}














