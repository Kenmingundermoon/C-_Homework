/*
�Ӽ�������R��C�ж�ά�������飬�ҳ�ÿһ�еĴ����ֵ����ʾ������Ҫ��
��1��R��CΪ���ų�����
��2����ά�����Ƕ�̬�������ɵģ�
��3��ÿһ�еĴ����ֵ�����õ����ĺ������û�õģ�
��4��������Ԫ�صķ����Լ��������������ȶ�������ָ��ʵ�ֵġ�
*/




#include<iostream>

using namespace std;

const int R=3;
const int C=4;
const int ERROR=-666;

void Sort_Array(int (*p)[C]){
    //�����������ڽ���������
    int temp,temp1;
    for(int x=0;x<R;x++){
        for(int y=0;y<C;y++){
            temp=p[x][y];
            for(int k=y;k<C;k++){
                if(temp<p[x][k]){
                    temp1=p[x][k];
                    p[x][k]=temp;
                    temp=temp1;
                }
            }
            p[x][y]=temp;
        }
    }
}


int Search_Second(int (*p)[C],int n){
    //Ѱ�ҵڶ����Ԫ�أ������ڣ�����Ԫ�ص�ֵ�����򷵻ش�����ϢERROR
    //����n��ʾѰ�ҵ�n�еĴ����ֵ

    int i=1;
    while(i!=C){
        if((*(*(p+n)+i))!=*(*(p+n)+i-1)){
            return *(*(p+n)+i);
        }
        i++;
    }
    return ERROR;

}


int main(){

    int i,j,x,y,temp;
    int (*a)[C];
    a=new int[R][C];//��̬����ռ�

    cout<<"Please enter the number:"<<endl;

    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            cin>>*(*(a+i)+j);
        }
    }

    Sort_Array(a);
    for(i=0;i<R;i++){
        int ans=Search_Second(a,i);

        if(ans!=ERROR){
            cout<<ans<<endl;
        }
        else{
            cout<<"No The 2nd biggest number found."<<endl;
        }

    }

    return 0;
}

