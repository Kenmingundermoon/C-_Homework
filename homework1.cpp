/*
从键盘输入R行C列二维整型数组，找出每一行的次最大值并显示出来。要求：
（1）R和C为符号常量；
（2）二维数组是动态申请生成的；
（3）每一行的次最大值是利用单独的函数调用获得的；
（4）对数组元素的访问以及函数参数声明等都是利用指针实现的。
*/




#include<iostream>

using namespace std;

const int R=3;
const int C=4;
const int ERROR=-666;

void Sort_Array(int (*p)[C]){
    //排序函数，用于将数组排序
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
    //寻找第二大的元素，若存在，返回元素的值，否则返回错误信息ERROR
    //参数n表示寻找第n行的次最大值

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
    a=new int[R][C];//动态申请空间

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

