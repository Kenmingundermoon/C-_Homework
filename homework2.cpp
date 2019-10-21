/*

根据下列要求，编写完整程序。
设计一个类，用于对10元整型数组进行管理。要求：
（1）在定义对象时，能够为数组元素清0.
（2）定义成员函数input, 用于为数组元素输入数据。
（3）定义成员函数disp，用于显示数组的每个元素值。
（4）定义成员函数max，用于找出数组元素的最大值及其个数，其中最大值由函数值返回，个数由参数带回。
（5）定义成员函数find，用于找出数组中重复次数最多的数及其个数（可能存在多个），并显示出来。
（6）定义main函数，合理地调用上述每个函数
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
    //n为输入的值，j为此值要传入数组的位置,从0开始

    void disp(){
        for(int i=0;i<10;i++){printf("%d ",a[i]);}//各元素间以1个空格隔开
    }
    int max(int &num);

    void find();
};



int Array::max(int &num){

    for(int i=0;i<10;i++){
    //对数组进行由大到小的冒泡排序
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
    //通过遍历，找到最多的次数
        if(temp<b[i][1]){temp=b[i][1];}
    }

    for(i=0;i<=j;i++){
    //再次遍历，如果某个数的出现次数等于最大出现次数，则输出其值与出现次数
        if(b[i][1]==temp){
            printf("数字:%d 个数:%d\n",b[i][0],b[i][1]);
        }
    }
}


int main(){


    int i,c;
    Array a1;


    cout<<"测试input函数，请依次输入十个数字，中间用空格隔开:"<<endl;
    for(i=0;i<10;i++){
        cin>>c;
        a1.input(c,i);
    }
    cout<<endl<<"测试disp函数，屏幕将打印10个之前输入的数字元素:"<<endl;
    a1.disp();

    cout<<endl<<"测试max函数，屏幕将打印数组的最大值及其个数："<<endl;

    int max_arg,num=0;//初始设置个数为0

    max_arg=a1.max(num);

    cout<<"最大值："<<max_arg<<"  个数："<<num<<endl;
    cout<<"测试find函数"<<endl;

    a1.find();


    return 0;

}








