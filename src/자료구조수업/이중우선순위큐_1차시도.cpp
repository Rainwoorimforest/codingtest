#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int, vector<int>, less<int>> pq1; //최대 힙
    priority_queue<int, vector<int>, greater<int>> pq2; // 최소 힙
    int v_size = operations.size();
    int cnt = v_size;
    vector<int> result_v;

    //문자열 받은대로 반복문 돌기
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
            if (word == "-1") // 최댓값 삭제
            {
                pq2.pop();
                cnt--;
            }
            else if (word == "1") //최솟값 삭제
            {
                pq1.pop();
                cnt--;
            }
        }
    }
        //출력 벡터에 넣기
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

        //큐랑 벡터 다 비우기

        return result_v;
        
}


int main() {
    vector<string> inputs;
    string line;
 
    //입력 받기
    while (true) {
        getline(cin, line);

        if (line.empty()) {
            break;
        }

        // 현재 줄이 비어있지 않다면 벡터에 추가
         inputs.push_back(line);
        

    }

    solution(inputs);



    return 0;
}