/*
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);       //메뉴출력
void MakeAccount(void);     //계좌개설을 위한 함수
void DepositMoney(void);     //입금
void WithdrawMoney(void);      //출금
void ShowAllAccInfo(void);     //잔액 조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int accID;      //계좌번호
	int balance;	//잔액
	char cusName[NAME_LEN];   //고객이름
} Account;

Account accArr[100];   //Account 저장을 위한 배열
int accNum = 0;        //저장된 Account 수

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
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
	cout << "[입 금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액 ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "입금 완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액 ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이  름: " << accArr[i].cusName << endl;
		cout << "잔  액: " << accArr[i].balance << endl << endl;
	}
}
*/

#include <iostream>
#include <cstring>

//아직 일부 개념들에 대해 미숙하고 안보고 프로그램을 짜자니 알 수 없는 오류가 계속 나서 교재를 조금 참고하였습니다.
//대신 주석으로 차이점과 설명을 꼼꼼하게 적으려 노력하였습니다.

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);       //메뉴출력
void MakeAccount(void);     //계좌개설을 위한 함수
void DepositMoney(void);     //입금
void WithdrawMoney(void);      //출금
void ShowAllAccInfo(void);     //잔액 조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
	private:
		int accID;      //계좌번호
		int balance;	//잔액
		char* cusName[NAME_LEN];//고객이름

	public:
		Account(int _accID, int _balance, char* _name) :accID(_accID), balance(_balance)
		//Account 함수를 통해서 계좌개설,잔액,이름을 매개변수로 가져올 수 있음.
		//이때 private해서 은닉된 변수들을 매개변수와 매칭해줌. this와 같은 역할.
		{
			cusName = new char[strlen(_name) + 1]; //잘모르는 부분입니다. new 생성자를 이용하여 cusName이 포인터 역할을 하여 고객이름으로 받는
											  //문자열의 주소를 가리킵니다. 그래서 cusName을 배열이라해도 무방한 것 같습니다. 이때 1을 더하는 것은 문자열 \0때문입니다.
			strcpy(cusName, _name); //cusName에 고객이름있는 배열을 복사.
		}
	//복사생성자.
		Account(const Account& ref) :accID(_accID), balance(_balance)
		{

			cusName = new char[strlen(ref.cusName) + 1];
			strcpy(cusName, ref.cusName);
		}

	//소멸자
		~Account()
		{
			delete[] cusName; //사용되지 않는 메모리를 삭제합니다.
		}

	//클래스는 구조체와 다르게 모든 멤버가 기본적으로 public으로 설정되어
	//은닉하고 싶은 멤버는 private로 접근지정자로 설정하고 그 이후에 main함수에서 호출할때는
	//get함수와 set함수를 이용해 호출한다.

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
			cout << "계죄ID: " << accID << endl;
			cout << "이름: " << cusName << endl;
			cout << "잔액: " << balance << endl;


		}//클래스 내에서 함수를 정의

};




Account accArr[100];   //Account 저장을 위한 배열
int accNum = 0;        //저장된 Account 수

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액 ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i] -> GetAccID() == id) //this도 '아닌 배열 ->함수'형태는 무엇인지 모르겠음.
		{
			accArr[i]->Desposit( money); //this도 '아닌 배열 ->함수'형태는 무엇인지 모르겠음.
			cout << "입금 완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액 ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID == id) //this도 '아닌 배열 ->함수'형태는 무엇인지 모르겠음.
		{
			if (accArr[i]->WithDraw( money) ==0) //this도 '아닌 배열 ->함수'형태는 무엇인지 모르겠음.
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		/*cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이  름: " << accArr[i].cusName << endl;
		cout << "잔  액: " << accArr[i].balance << endl << endl;
	
		*/ 

		accArr[i]->ShowAccInfo();
}
