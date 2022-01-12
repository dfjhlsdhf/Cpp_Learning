#include <iostream>
#include <string>
using namespace std;
/*
设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
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
        {"A",23,"男"},
		{"B",22,"男"},
		{"C",20,"男"},
		{"D",21,"男"},
		{"E",19,"女"}
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