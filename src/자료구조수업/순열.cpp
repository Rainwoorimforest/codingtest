#include <iostream>
#include <queue>
#define MAX_QUEUE_SIZE 100

using namespace std;

class CircularQueue {
protected: 
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];

public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(int val) {
		if (isFull())
		{
			cout << "error: 큐 포화상태" << endl; exit(-1);
		}
		else
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE; // 6%7 = 6
			data[rear] = val;
		}
}

	int dequeue() {
		if (isEmpty())
		{
			cout << "error: 큐 공백상태" << endl; exit(-1);
		}
		else
		{
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}

	}

	int peek() {
		if (isEmpty())
		{
			cout << "error: 큐 공백상태" << endl; exit(-1);
		}
		else
		{
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
	void display() { 	// 큐의 모든 내용을 순서대로 출력
		printf("큐 내용 : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++)
			cout << data[i % MAX_QUEUE_SIZE] << " ";
		cout << endl;
	}

};



int main() {

	int N, K;
	int cnt = 1;

	queue<int> q;
	queue<int> temp;
	queue<int> result;


	CircularQueue Cir_q;

	cin >> N >> K;

	int Cir_a_size = N;

	//처음 입력 넣기
	for (int i = 1; i <= N; i++)
	{
		Cir_q.enqueue(i);
	}


	while (Cir_a_size > 1)
	{
		//if(처음은 안들어옴)
		if (cnt != 1)
		{
			int temp_size = temp.size();

			for (int i = 1; i <= temp_size; i++)
			{
				Cir_q.enqueue(temp.front());
				temp.pop();

			}
		}

		for (int i = 1; i <= Cir_a_size; i++)
		{
			if (i < K)
			{
				temp.push(Cir_q.dequeue());
			}
			else if (i == K || i == K + 1)
			{
				result.push(Cir_q.dequeue());
			}
			else
			{
				Cir_q.enqueue(Cir_q.dequeue());
			}
		}

		//사이즈 줄임.
		Cir_a_size--;
		Cir_a_size--;

		cnt++;

	}

	//결과 출력
	int result_size = result.size();
	for (int i = 0; i < result_size; i++)
	{
		cout << result.front() << " ";
		result.pop();
	}

	return 0;
}




