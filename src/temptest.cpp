#include <iostream>
#include <queue>

using namespace std;

vector<int> parent;
vector<int> D;


// 초기화
void init(int n) {

    parent.resize(n);
    D.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        
    }
}

// find
int findSet(int a) {
    if (a == parent[a]) return a;
    return parent[a] = findSet(parent[a]);
}

// union
void unionSet(int a, int b) {
    int a = findSet(a);
    int b = findSet(b);
    if (a == b) return;
    parent[b] = a;
    D[a] += D[b];
}


vector<int> calculateS(vector<int> serverProp){

    int n = serverProp.size();
    init(n);
    vector<int> result(n);

    //r


    //각 서버가 속한 클러스터 크기 구하기
    for(int i =0; i<n; i++)
    {
        int temp = findSet(i);
        result[i] = D[temp];
    }
     
     return result

}

