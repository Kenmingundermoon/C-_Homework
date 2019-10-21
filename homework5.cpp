
/*
题目：基于链表的学生信息管理系统

要求：

    （1）插入节点：输入学生信息后，生成节点并插入链表中；//尾插法实现

    （2）删除节点：根据给定的学生姓名或学号删除该学生节点；

    （3）查找节点：根据给定的学生姓名或学号查找学生信息，并显示出来；

  （4）查找并显示总成绩最高和最低的学生信息；

     （5）统计链表中的学生人数；

  （6）（时间允许时选做）对链表节点按总成绩从高到低排序。

   注：

   （1）每个学生信息包括：姓名、学号、性别、出生年月日和3门课的成绩；

   （2）系统运行后，首先显示一个简易的菜单，基于菜单操作来完成上述功能；

   （3）链表的功能需要编程实现。
*/


#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=20;

class clink{
    char id[maxn];
    char stu_num[maxn];
    char gender;
    int score[3];//三科成绩
    int year;
    int month;
    int day;
    int sum_score;//总成绩
    clink *next;
    friend class clist;
public:
    clink(){
        ;
    }
    clink(char* a_id,char* a_stu_num,char a_gender,
          int a_year,int a_month,int a_day,
          int sc0,int sc1,int sc2){

        strcpy(id,a_id);
        strcpy(stu_num,a_stu_num);
        gender=a_gender;
        year=a_year;
        month=a_month;
        day=a_day;
        score[0]=sc0;
        score[1]=sc1;
        score[2]=sc2;
    }

    void disp(){//显示学生所有信息
        printf("%10s   ",id);
        printf("%10s ",stu_num);
        printf("  %c  ",gender);
        printf("%4d-%2d-%2d",year,month,day);
        printf("  %3d  %3d  %3d   %3d\n",score[0],score[1],score[2],sum_score);
    }
    void sum(){//求学生的总成绩
        sum_score=0;
        for(int i=0;i<3;i++){
            sum_score+=score[i];
        }
    }
    clink &operator =(const clink &a){//排序时使用的运算符重载
        strcpy(id,a.id);
        strcpy(stu_num,a.stu_num);
        gender=a.gender;
        for(int i=0;i<3;i++){
            score[i]=a.score[i];
        }
        year=a.year;
        month=a.month;
        day=a.day;
        sum_score=a.sum_score;
        return (*this);
    }
};


class clist{
protected:
    clink* first;
    clink* last;
    int number;

public:
    clist(){
        first=last=new clink;
        number=0;
    }
    ~clist(){
        clink* head=first;
        while(first!=last){
            head=first->next;
            delete first;
            first=head;
        }
    }

    clist &Append(const clink &a);
    clink* Find_by_name(char a[maxn]);
    clink* Find_by_number(char a[maxn]);
    clink* Find_the_max();
    clink* Find_the_min();
    clist &Delete(clink* a);
    void Print_number(){
        cout<<"当前数据库学生数量为："<<number<<endl;
    }

    void Print();
    clist &Sort();

};


clist &clist::Append(const clink &a){//尾插法
    clink* ptr=last;
    *ptr=a;
    last=new clink;
    ptr->next=last;
    number++;
    return (*this);
}


clink* clist::Find_by_name(char a[maxn]){
    clink* ptr=first;
    while(ptr!=last){
        if(strcmp(ptr->id,a)==0){
            cout<<"学生已找到！"<<endl;
            ptr->disp();
            return ptr;
        }
        else{
            ptr=ptr->next;
        }
    }
    cout<<"未找到符合要求的学生！"<<endl;
    return NULL;
}


clink* clist::Find_by_number(char a[maxn]){
    clink* ptr=first;
    while(ptr!=last){
        if(strcmp(ptr->stu_num,a)==0){
            cout<<"学生已找到！"<<endl;
            ptr->disp();
            return ptr;
        }
        else{
            ptr=ptr->next;
        }
    }
    cout<<"未找到符合要求的学生！"<<endl;
    return NULL;
}


clist &clist::Delete(clink* a){//confirm
    clink* ptr=first;
    clink* pre;
    if(first==last){//数据库没有学生的时候，判定没有对应学生
        cout<<"没有对应学生！"<<endl;
        return (*this);
    }
    else{
        if(first==a){
            clink* temp=first;
            delete first;
            first=temp->next;
            cout<<"删除成功！"<<endl;
            number--;
            return (*this);
        }
        else{
            while(ptr!=last){
                if(ptr!=a){
                    pre=ptr;
                    ptr=ptr->next;
                }
                else{
                    pre->next=ptr->next;
                    delete ptr;
                    cout<<"删除成功！"<<endl;
                    number--;
                    return (*this);
                }
            }
            cout<<"没有对应学生！"<<endl;
            return (*this);
        }

    }
}


void clist::Print(){//显示所有学生信息
    clink* ptr=first;
    while(ptr!=last){
        ptr->disp();
        ptr=ptr->next;
    }
}


clink* clist::Find_the_max(){//显示最高总分以及学生信息
    clink* ptr=first;
    clink* target=first;
    int sum_temp=first->sum_score;
    while(ptr!=last){
        if(sum_temp<ptr->sum_score){
            sum_temp=ptr->sum_score;
            target=ptr;
        }
        ptr=ptr->next;
    }
    cout<<"最高总分为："<<sum_temp<<endl;
    cout<<"总成绩最高学生信息如下："<<endl;
    target->disp();
    return target;

}


clink* clist::Find_the_min(){//显示最低总分以及学生信息
    clink* ptr=first;
    clink* target=first;
    int sum_temp=first->sum_score;
    while(ptr!=last){
        if(sum_temp>ptr->sum_score){
            sum_temp=ptr->sum_score;
            target=ptr;
        }
        ptr=ptr->next;
    }
    cout<<"最低总分为："<<sum_temp<<endl;
    cout<<"总成绩最低学生信息如下："<<endl;
    target->disp();
    return target;

}


clist &clist::Sort(){
    clink* p;
    clink* q;
    for(p=first;p!=last;p=p->next){
        for(q=p->next;q!=last;q=q->next){
            if(p->sum_score<q->sum_score){
                clink temp=*p;
                *p=*q;
                *q=temp;
             }
         }
    }
    return (*this);

}


void menu()//功能菜单
{
    printf("    |________________________________________________|\n");
    printf("    |                                                |\n");
    printf("    |                学生信息管理系统                |\n");
    printf("    |                                                |\n");
    printf("    |               0、退出系统                      |\n");
    printf("    |               1、增加学生信息                  |\n");
    printf("    |               2、根据名字删除学生信息          |\n");
    printf("    |               3、根据学号删除学生信息          |\n");
    printf("    |               4、根据名字查找学生的信息        |\n");
    printf("    |               5、根据学号查找学生的信息        |\n");
    printf("    |               6、按照学生成绩排序              |\n");
    printf("    |               7、浏览全部学生信息              |\n");
    printf("    |               8、显示数据库学生数量            |\n");
    printf("    |                                                |\n");
    printf("    |________________________________________________|\n");
}




int main(){

    int ch;
    clist student;
    clink* m;
    char id[maxn],stu_num[maxn],gender;
    int year,month,day,sc0,sc1,sc2;
    char name1[maxn],number1[maxn];


    menu();
    cin>>ch;
    while(1){
        switch(ch){
        case 0:
            cout<<"您已退出系统"<<endl;
            return 0;
        case 1:
            int N;
            cout<<"请输入待输入信息的学生个数：";
            cin>>N;
            cout<<"请依次输入每个学生的相关信息："<<endl;
            for(int i=0;i<N;i++){
                cin>>id;
                cin>>stu_num;
                cin>>gender;
                cin>>year;
                cin>>month;
                cin>>day;
                cin>>sc0;
                cin>>sc1;
                cin>>sc2;
                clink A(id,stu_num,gender,year,month,day,sc0,sc1,sc2);
                A.sum();//求总成绩
                student.Append(A);
            }
            cout<<"信息输入完成！"<<endl;
            cin>>ch;
            break;
        case 2:
            cout<<"请输入要删除的学生姓名:"<<endl;
            cin>>name1;
            m=student.Find_by_name(name1);
            student.Delete(m);
            cin>>ch;
            break;
        case 3:
            cout<<"请输入要删除的学生学号:"<<endl;
            cin>>number1;
            m=student.Find_by_number(number1);
            student.Delete(m);
            cin>>ch;
            break;
        case 4:
            cout<<"请输入查询的学生名字:"<<endl;
            cin>>name1;
            student.Find_by_name(name1);
            cin>>ch;
            break;
        case 5:
            cout<<"请输入查询的学生学号:"<<endl;
            cin>>number1;
            student.Find_by_number(number1);
            cin>>ch;
            break;
        case 6:
            student.Sort();
            cout<<"排序完成!"<<endl;
            cin>>ch;
            break;
        case 7:
            student.Print();
            cin>>ch;
            break;
        case 8:
            student.Print_number();
            cin>>ch;
            break;

        }

    }


    return 0;

}
