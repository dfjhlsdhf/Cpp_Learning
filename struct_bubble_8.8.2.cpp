#include <iostream>
#include <string>
using namespace std;
/*
���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�;�����ṹ�����飬�����д��5��Ӣ�ۡ�

ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����
*/
struct people
{
    string name;
    int age;
    string sex;
};
void Bubble(struct people p[],int len);
void printdata(struct people *p,int len);
int main(){
    struct people peo[5]{
        {"A",23,"��"},
		{"B",22,"��"},
		{"C",20,"��"},
		{"D",21,"��"},
		{"E",19,"Ů"}
    };
    int len=sizeof(peo)/sizeof(struct people);
    Bubble(peo,len);
    printdata(peo,len);
    return 0;
}

void Bubble(struct people p[],int len)
{
    int i,j;
    struct people tmp;
    for (i = 0; i <len-1; i++)
    {
        for ( j = 0; j < len-i-1; j++)
        {
            if(p[j].age>p[j+1].age)
            {
                tmp=p[j];
                p[j]=p[j+1];
                p[j+1]=tmp;
            }
        }
        
    }
    
}

void printdata(struct people *p,int len)
{
    int i;
    for(i=0;i<len;i++){
        cout<<"name: "<<p[i].name<<" age: "<<p[i].age<<" sex: "<<p[i].sex<<endl;
    }
}