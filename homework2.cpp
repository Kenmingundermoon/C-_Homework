/*

��������Ҫ�󣬱�д��������
���һ���࣬���ڶ�10Ԫ����������й���Ҫ��
��1���ڶ������ʱ���ܹ�Ϊ����Ԫ����0.
��2�������Ա����input, ����Ϊ����Ԫ���������ݡ�
��3�������Ա����disp��������ʾ�����ÿ��Ԫ��ֵ��
��4�������Ա����max�������ҳ�����Ԫ�ص����ֵ����������������ֵ�ɺ���ֵ���أ������ɲ������ء�
��5�������Ա����find�������ҳ��������ظ�����������������������ܴ��ڶ����������ʾ������
��6������main����������ص�������ÿ������
*/





#include<iostream>

using namespace std;

class Array{

private:
    int a[10];

public:
    Array(){
        for(int i=0;i<10;i++){a[i]=0;}
    }
    void input(int n,int j){a[j]=n;}
    //nΪ�����ֵ��jΪ��ֵҪ���������λ��,��0��ʼ

    void disp(){
        for(int i=0;i<10;i++){printf("%d ",a[i]);}//��Ԫ�ؼ���1���ո����
    }
    int max(int &num);

    void find();
};



int Array::max(int &num){

    for(int i=0;i<10;i++){
    //����������ɴ�С��ð������
        for(int j=0;j<10-i-1;j++){
            if(a[j]<a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    int i=0;
    while(a[i++]==a[0]){num++;}
    return a[0];

}

void Array::find(){
    int i,j=0;
    int b[10][2]={0};
    b[0][1]++;
    for(i=1;i<10;i++){
        if(a[i]==a[i-1]){
            b[j][0]=a[i-1];
            b[j][1]++;
        }
        else{
            j++;
            b[j][0]=a[i];
            b[j][1]++;
        }
    }

    int loc,temp;
    temp=b[0][1];
    loc=0;
    for(i=1;i<=j;i++){
    //ͨ���������ҵ����Ĵ���
        if(temp<b[i][1]){temp=b[i][1];}
    }

    for(i=0;i<=j;i++){
    //�ٴα��������ĳ�����ĳ��ִ������������ִ������������ֵ����ִ���
        if(b[i][1]==temp){
            printf("����:%d ����:%d\n",b[i][0],b[i][1]);
        }
    }
}


int main(){


    int i,c;
    Array a1;


    cout<<"����input����������������ʮ�����֣��м��ÿո����:"<<endl;
    for(i=0;i<10;i++){
        cin>>c;
        a1.input(c,i);
    }
    cout<<endl<<"����disp��������Ļ����ӡ10��֮ǰ���������Ԫ��:"<<endl;
    a1.disp();

    cout<<endl<<"����max��������Ļ����ӡ��������ֵ���������"<<endl;

    int max_arg,num=0;//��ʼ���ø���Ϊ0

    max_arg=a1.max(num);

    cout<<"���ֵ��"<<max_arg<<"  ������"<<num<<endl;
    cout<<"����find����"<<endl;

    a1.find();


    return 0;

}








