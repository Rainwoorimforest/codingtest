/*
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);       //�޴����
void MakeAccount(void);     //���°����� ���� �Լ�
void DepositMoney(void);     //�Ա�
void WithdrawMoney(void);      //���
void ShowAllAccInfo(void);     //�ܾ� ��ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int accID;      //���¹�ȣ
	int balance;	//�ܾ�
	char cusName[NAME_LEN];   //���̸�
} Account;

Account accArr[100];   //Account ������ ���� �迭
int accNum = 0;        //����� Account ��

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�̸�: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName, strlen(name)+1,name);
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�Աݾ� ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "�Ա� �Ϸ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��ݾ� ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "����ID: " << accArr[i].accID << endl;
		cout << "��  ��: " << accArr[i].cusName << endl;
		cout << "��  ��: " << accArr[i].balance << endl << endl;
	}
}
*/

#include <iostream>
#include <cstring>

//���� �Ϻ� ����鿡 ���� �̼��ϰ� �Ⱥ��� ���α׷��� ¥�ڴ� �� �� ���� ������ ��� ���� ���縦 ���� �����Ͽ����ϴ�.
//��� �ּ����� �������� ������ �Ĳ��ϰ� ������ ����Ͽ����ϴ�.

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);       //�޴����
void MakeAccount(void);     //���°����� ���� �Լ�
void DepositMoney(void);     //�Ա�
void WithdrawMoney(void);      //���
void ShowAllAccInfo(void);     //�ܾ� ��ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
	private:
		int accID;      //���¹�ȣ
		int balance;	//�ܾ�
		char* cusName[NAME_LEN];//���̸�

	public:
		Account(int _accID, int _balance, char* _name) :accID(_accID), balance(_balance)
		//Account �Լ��� ���ؼ� ���°���,�ܾ�,�̸��� �Ű������� ������ �� ����.
		//�̶� private�ؼ� ���е� �������� �Ű������� ��Ī����. this�� ���� ����.
		{
			cusName = new char[strlen(_name) + 1]; //�߸𸣴� �κ��Դϴ�. new �����ڸ� �̿��Ͽ� cusName�� ������ ������ �Ͽ� ���̸����� �޴�
											  //���ڿ��� �ּҸ� ����ŵ�ϴ�. �׷��� cusName�� �迭�̶��ص� ������ �� �����ϴ�. �̶� 1�� ���ϴ� ���� ���ڿ� \0�����Դϴ�.
			strcpy(cusName, _name); //cusName�� ���̸��ִ� �迭�� ����.
		}
	//���������.
		Account(const Account& ref) :accID(_accID), balance(_balance)
		{

			cusName = new char[strlen(ref.cusName) + 1];
			strcpy(cusName, ref.cusName);
		}

	//�Ҹ���
		~Account()
		{
			delete[] cusName; //������ �ʴ� �޸𸮸� �����մϴ�.
		}

	//Ŭ������ ����ü�� �ٸ��� ��� ����� �⺻������ public���� �����Ǿ�
	//�����ϰ� ���� ����� private�� ���������ڷ� �����ϰ� �� ���Ŀ� main�Լ����� ȣ���Ҷ���
	//get�Լ��� set�Լ��� �̿��� ȣ���Ѵ�.

		int GetAccID()
		{
			return accID;
		}

		void Deposit(int money)
		{
			balance += money;
		}

		int WithDraw(int money)
		{
			if (balance < money)
			{
				return 0;
			}
			balance -= money;
			return money;   
		}

		void ShowAccInfo()
		{
			cout << "����ID: " << accID << endl;
			cout << "�̸�: " << cusName << endl;
			cout << "�ܾ�: " << balance << endl;


		}//Ŭ���� ������ �Լ��� ����

};




Account accArr[100];   //Account ������ ���� �迭
int accNum = 0;        //����� Account ��

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�̸�: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�Աݾ� ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i] -> GetAccID() == id) //this�� '�ƴ� �迭 ->�Լ�'���´� �������� �𸣰���.
		{
			accArr[i]->Desposit( money); //this�� '�ƴ� �迭 ->�Լ�'���´� �������� �𸣰���.
			cout << "�Ա� �Ϸ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��ݾ� ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID == id) //this�� '�ƴ� �迭 ->�Լ�'���´� �������� �𸣰���.
		{
			if (accArr[i]->WithDraw( money) ==0) //this�� '�ƴ� �迭 ->�Լ�'���´� �������� �𸣰���.
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		/*cout << "����ID: " << accArr[i].accID << endl;
		cout << "��  ��: " << accArr[i].cusName << endl;
		cout << "��  ��: " << accArr[i].balance << endl << endl;
	
		*/ 

		accArr[i]->ShowAccInfo();
}
