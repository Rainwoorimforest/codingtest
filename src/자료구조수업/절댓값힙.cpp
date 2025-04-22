#include <iostream>
#include <queue>
#include <vector>


using namespace std;


struct compare
{
	bool operator()(int a,int b) //false일 때 해당 요소 우선순위를 가짐
	{
		if (abs(a) == abs(b)) return a > b; //두 수의 절댓값이 같을 때, a가 크면 true반환
		else return abs(a) > abs(b); //두 수의 절댓값을 비교하여 a가 크면 true을 반환
	}
};

int main() {
	int N;

	//cin >> N;

	priority_queue<int, vector<int>, compare> pd;

	pd.push(2);
	pd.push(-2);
	pd.push(3);
	pd.push(4);
	pd.push(3);
	pd.push(5);

	pd.pop();

	cout << pd.top();

}

/*
코드를 분석해보겠습니다.

우선, 이 코드는 절대값을 기준으로 하는 우선순위 큐를 구현하였습니다. compare 구조체는 두 정수의 절대값을 비교하여 우선순위를 결정하도록 설계되었습니다.

우선순위 큐의 기본 동작 원리는 가장 우선순위가 높은 요소가 항상 큐의 맨 앞에 위치하게 됩니다. compare 구조체에 따르면 절대값이 작은 수가 더 우선순위가 높으며, 절대값이 같은 경우 원래의 값이 더 작은 것이 우선순위가 높습니다.

다음은 주어진 코드에 따라 push와 pop 연산이 어떻게 진행되는지 단계별로 설명하겠습니다:

우선순위 큐 pd 생성.

pd.push(2); : 2를 큐에 삽입. 현재 큐의 상태: 2

pd.push(-2); : -2를 큐에 삽입. -2와 2의 절대값이 동일하므로 원래 값이 더 작은 -2가 우선순위가 높습니다. 현재 큐의 상태: -2, 2

pd.push(3); : 3을 큐에 삽입. 현재 큐의 상태: -2, 2, 3 (3의 절대값은 -2보다 크기 때문에 뒤에 위치합니다.)

pd.push(4); : 4를 큐에 삽입. 현재 큐의 상태: -2, 2, 3, 4

pd.push(3); : 3을 다시 큐에 삽입. 현재 큐의 상태: -2, 2, 3, 3, 4

pd.push(5); : 5를 큐에 삽입. 현재 큐의 상태: -2, 2, 3, 3, 4, 5

pd.pop(); : 큐에서 가장 우선순위가 높은 요소를 제거. 현재 큐의 상태: 2, 3, 3, 4, 5

cout << pd.top(); : 큐의 맨 앞 요소를 출력. 출력값: 2

결론적으로, 출력값은 2입니다. 이유는 push와 pop 연산을 수행한 후에 큐의 맨 앞에 위치하는 요소가 2이기 때문입니다.





*/
