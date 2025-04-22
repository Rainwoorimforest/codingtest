#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int, vector<int>, less<int>> pq1; //�ִ� ��
    priority_queue<int, vector<int>, greater<int>> pq2; // �ּ� ��
    int v_size = operations.size();
    int cnt = v_size;
    vector<int> result_v;

    //���ڿ� ������� �ݺ��� ����
    for (int i = 0; i < v_size; i++)
    {
        string st = operations[i];
        string word;
        istringstream steam(st);

        steam >> word;
        if (word == "I")
        {
            steam >> word;
            pq1.push(stoi(word));
            pq2.push(stoi(word));

        }
        else if (word == "D")
        {
            steam >> word;
            if (word == "-1") // �ִ� ����
            {
                pq2.pop();
                cnt--;
            }
            else if (word == "1") //�ּڰ� ����
            {
                pq1.pop();
                cnt--;
            }
        }
    }
        //��� ���Ϳ� �ֱ�
        if (cnt = 0 || pq1.empty() || pq2.empty())
        {
            result_v.push_back(0);
            result_v.push_back(0);
          
        }
        else
        {
            result_v.push_back(pq1.top());
            result_v.push_back(pq2.top());

        }

        //ť�� ���� �� ����

        return result_v;
        
}


int main() {
    vector<string> inputs;
    string line;
 
    //�Է� �ޱ�
    while (true) {
        getline(cin, line);

        if (line.empty()) {
            break;
        }

        // ���� ���� ������� �ʴٸ� ���Ϳ� �߰�
         inputs.push_back(line);
        

    }

    solution(inputs);



    return 0;
}