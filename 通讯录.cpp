#include <iostream>
#include <string>
using namespace std;
#define MAX 1000l

struct Person
{
	string m_Name; //����
	int m_Sex; //�Ա�1�� 2Ů
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //סַ
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
			/* �����ϵ�� */
			addPerson(&abs);
			break;
		case 2:
			/* ��ʾ��ϵ�� */
			showPerson(&abs);
			break;
		case 3:
			/* ɾ����ϵ�� */
			deletePerson(&abs);
			break;
		case 4:
			/* ������ϵ�� */
			findPerson(&abs);
			break;
		case 5:
			/* �޸���ϵ�� */
			modifyPerson(&abs);
			break;
		case 6:
			/* �����ϵ�� */
			cleanPerson(&abs);
			break;
		case 0:
			/* �˳�ͨѶ¼ */
			cout<<"�˳�ͨѶ¼"<<endl;
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
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
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
			cout << "NAME��" << abs->personArray[i].m_Name << "\t";
			cout << "SEX��" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "AGE��" << abs->personArray[i].m_Age << "\t";
			cout << "TELEPHONE��" << abs->personArray[i].m_Phone << "\t";
			cout << "ADD��" << abs->personArray[i].m_Addr << endl;
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
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
		
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
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;

		//�Ա�
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}

//6�����������ϵ��
void cleanPerson(struct Addressbooks * abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}