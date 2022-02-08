#include <iostream>
#include <string>
using namespace std;
#define MAX 1000l

struct Person
{
	string m_Name; //姓名
	int m_Sex; //性别：1男 2女
	int m_Age; //年龄
	string m_Phone; //电话
	string m_Addr; //住址
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};
void showMenu();
void addPerson(struct Addressbooks *abs);
void showPerson(struct Addressbooks *abs);
void deletePerson(struct Addressbooks *abs);
void findPerson(struct Addressbooks *abs);
void modifyPerson(struct Addressbooks * abs);
void cleanPerson(struct Addressbooks * abs);

int main()
{
	struct Addressbooks abs;
	abs.m_Size=0;
    int select =0;
	while(true){
		showMenu();
		cin>>select;
		switch (select)
		{
		case 1:
			/* 添加联系人 */
			addPerson(&abs);
			break;
		case 2:
			/* 显示联系人 */
			showPerson(&abs);
			break;
		case 3:
			/* 删除联系人 */
			deletePerson(&abs);
			break;
		case 4:
			/* 查找联系人 */
			findPerson(&abs);
			break;
		case 5:
			/* 修改联系人 */
			modifyPerson(&abs);
			break;
		case 6:
			/* 清空联系人 */
			cleanPerson(&abs);
			break;
		case 0:
			/* 退出通讯录 */
			cout<<"退出通讯录"<<endl;
			return 0;
			break;
		default:
			break;
		}
	}
}

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(struct Addressbooks *abs)
{
	if(abs->m_Size>=MAX)
	{		
		cout<<"Full"<<endl;
		return;
	}
	else
	{
		string Name;
		int sex;
		cout<<"Input Name"<<endl;
		cin>>Name;
		abs->personArray[abs->m_Size].m_Name=Name;

		cout<<"Input Sex"<<endl;
		cout<<"1---Male"<<endl;
		cout<<"2---Female"<<endl;
		while(true)
		{		
			cin>>sex;
			if(sex==1||sex==2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout<<"error!input again"<<endl;

		}

		int age;
		cout<<"Input Age"<<endl;
		cin>>age;
		abs->personArray[abs->m_Size].m_Age=age;

		string phone;
		cout<<"Input phone number"<<endl;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone=phone;

		string address;
		cout<<"Input address"<<endl;
		cin>>address;
		abs->personArray[abs->m_Size].m_Addr=address;		

		//update people number

		cout<<"add success"<<endl;
		abs->m_Size++;
		system("pause");
		system("cls");

	}
	
}

void showPerson(struct Addressbooks *abs)
{
	if(abs->m_Size==0)
	{
		cout<<"the book is empty"<<endl;
		return;
	}
	else
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			cout << "NAME：" << abs->personArray[i].m_Name << "\t";
			cout << "SEX：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "AGE：" << abs->personArray[i].m_Age << "\t";
			cout << "TELEPHONE：" << abs->personArray[i].m_Phone << "\t";
			cout << "ADD：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(struct Addressbooks *abs,string name)
{
	for (int i=0;i<abs->m_Size;i++)
	{
		if(abs->personArray[i].m_Name==name)
			return i;
	}
	return -1;
}
void deletePerson(struct Addressbooks *abs)
{
	string name;
	cout<<"input the person u want to delete"<<endl;
	cin>>name;
	int result=isExist(abs,name);
	if(result!=-1)
	{
		for (int i=result;i<abs->m_Size;i++)
		{
			abs->personArray[i]=abs->personArray[i+1];
		}
		abs->m_Size--;
		cout<<"success"<<endl;
		
	}
	else
	{
		cout<<"error"<<endl;

	}
	system("pause");
	system("cls");
	
}

void findPerson(struct Addressbooks *abs)
{
	string name;
	cout<<"input the person u want to find"<<endl;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
		
	}
	else
	{
		cout<<"error"<<endl;

	}
	system("pause");
	system("cls");

}

void modifyPerson(struct Addressbooks * abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

//6、清空所有联系人
void cleanPerson(struct Addressbooks * abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}