
/*
��Ŀ�����������ѧ����Ϣ����ϵͳ

Ҫ��

    ��1������ڵ㣺����ѧ����Ϣ�����ɽڵ㲢���������У�//β�巨ʵ��

    ��2��ɾ���ڵ㣺���ݸ�����ѧ��������ѧ��ɾ����ѧ���ڵ㣻

    ��3�����ҽڵ㣺���ݸ�����ѧ��������ѧ�Ų���ѧ����Ϣ������ʾ������

  ��4�����Ҳ���ʾ�ܳɼ���ߺ���͵�ѧ����Ϣ��

     ��5��ͳ�������е�ѧ��������

  ��6����ʱ������ʱѡ����������ڵ㰴�ܳɼ��Ӹߵ�������

   ע��

   ��1��ÿ��ѧ����Ϣ������������ѧ�š��Ա𡢳��������պ�3�ſεĳɼ���

   ��2��ϵͳ���к�������ʾһ�����׵Ĳ˵������ڲ˵�����������������ܣ�

   ��3������Ĺ�����Ҫ���ʵ�֡�
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
    int score[3];//���Ƴɼ�
    int year;
    int month;
    int day;
    int sum_score;//�ܳɼ�
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

    void disp(){//��ʾѧ��������Ϣ
        printf("%10s   ",id);
        printf("%10s ",stu_num);
        printf("  %c  ",gender);
        printf("%4d-%2d-%2d",year,month,day);
        printf("  %3d  %3d  %3d   %3d\n",score[0],score[1],score[2],sum_score);
    }
    void sum(){//��ѧ�����ܳɼ�
        sum_score=0;
        for(int i=0;i<3;i++){
            sum_score+=score[i];
        }
    }
    clink &operator =(const clink &a){//����ʱʹ�õ����������
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
        cout<<"��ǰ���ݿ�ѧ������Ϊ��"<<number<<endl;
    }

    void Print();
    clist &Sort();

};


clist &clist::Append(const clink &a){//β�巨
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
            cout<<"ѧ�����ҵ���"<<endl;
            ptr->disp();
            return ptr;
        }
        else{
            ptr=ptr->next;
        }
    }
    cout<<"δ�ҵ�����Ҫ���ѧ����"<<endl;
    return NULL;
}


clink* clist::Find_by_number(char a[maxn]){
    clink* ptr=first;
    while(ptr!=last){
        if(strcmp(ptr->stu_num,a)==0){
            cout<<"ѧ�����ҵ���"<<endl;
            ptr->disp();
            return ptr;
        }
        else{
            ptr=ptr->next;
        }
    }
    cout<<"δ�ҵ�����Ҫ���ѧ����"<<endl;
    return NULL;
}


clist &clist::Delete(clink* a){//confirm
    clink* ptr=first;
    clink* pre;
    if(first==last){//���ݿ�û��ѧ����ʱ���ж�û�ж�Ӧѧ��
        cout<<"û�ж�Ӧѧ����"<<endl;
        return (*this);
    }
    else{
        if(first==a){
            clink* temp=first;
            delete first;
            first=temp->next;
            cout<<"ɾ���ɹ���"<<endl;
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
                    cout<<"ɾ���ɹ���"<<endl;
                    number--;
                    return (*this);
                }
            }
            cout<<"û�ж�Ӧѧ����"<<endl;
            return (*this);
        }

    }
}


void clist::Print(){//��ʾ����ѧ����Ϣ
    clink* ptr=first;
    while(ptr!=last){
        ptr->disp();
        ptr=ptr->next;
    }
}


clink* clist::Find_the_max(){//��ʾ����ܷ��Լ�ѧ����Ϣ
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
    cout<<"����ܷ�Ϊ��"<<sum_temp<<endl;
    cout<<"�ܳɼ����ѧ����Ϣ���£�"<<endl;
    target->disp();
    return target;

}


clink* clist::Find_the_min(){//��ʾ����ܷ��Լ�ѧ����Ϣ
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
    cout<<"����ܷ�Ϊ��"<<sum_temp<<endl;
    cout<<"�ܳɼ����ѧ����Ϣ���£�"<<endl;
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


void menu()//���ܲ˵�
{
    printf("    |________________________________________________|\n");
    printf("    |                                                |\n");
    printf("    |                ѧ����Ϣ����ϵͳ                |\n");
    printf("    |                                                |\n");
    printf("    |               0���˳�ϵͳ                      |\n");
    printf("    |               1������ѧ����Ϣ                  |\n");
    printf("    |               2����������ɾ��ѧ����Ϣ          |\n");
    printf("    |               3������ѧ��ɾ��ѧ����Ϣ          |\n");
    printf("    |               4���������ֲ���ѧ������Ϣ        |\n");
    printf("    |               5������ѧ�Ų���ѧ������Ϣ        |\n");
    printf("    |               6������ѧ���ɼ�����              |\n");
    printf("    |               7�����ȫ��ѧ����Ϣ              |\n");
    printf("    |               8����ʾ���ݿ�ѧ������            |\n");
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
            cout<<"�����˳�ϵͳ"<<endl;
            return 0;
        case 1:
            int N;
            cout<<"�������������Ϣ��ѧ��������";
            cin>>N;
            cout<<"����������ÿ��ѧ���������Ϣ��"<<endl;
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
                A.sum();//���ܳɼ�
                student.Append(A);
            }
            cout<<"��Ϣ������ɣ�"<<endl;
            cin>>ch;
            break;
        case 2:
            cout<<"������Ҫɾ����ѧ������:"<<endl;
            cin>>name1;
            m=student.Find_by_name(name1);
            student.Delete(m);
            cin>>ch;
            break;
        case 3:
            cout<<"������Ҫɾ����ѧ��ѧ��:"<<endl;
            cin>>number1;
            m=student.Find_by_number(number1);
            student.Delete(m);
            cin>>ch;
            break;
        case 4:
            cout<<"�������ѯ��ѧ������:"<<endl;
            cin>>name1;
            student.Find_by_name(name1);
            cin>>ch;
            break;
        case 5:
            cout<<"�������ѯ��ѧ��ѧ��:"<<endl;
            cin>>number1;
            student.Find_by_number(number1);
            cin>>ch;
            break;
        case 6:
            student.Sort();
            cout<<"�������!"<<endl;
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
