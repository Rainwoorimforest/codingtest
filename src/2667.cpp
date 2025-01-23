#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // sort 함수 사용

using namespace std;

// 상하좌우 이동을 위한 배열
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// BFS 함수
int BFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int n) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int count = 1; // 단지 내 집의 수 (현재 시작점 포함)

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 범위 체크 및 조건 확인
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    // 지도 입력받기
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 방문 여부를 저장할 배열
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    vector<int> complex_sizes; // 각 단지의 크기를 저장할 벡터

    // 모든 칸을 순회하며 BFS 실행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                // 새로운 단지를 발견하면 BFS 실행
                int complex_size = BFS(grid, visited, i, j, n);
                complex_sizes.push_back(complex_size);
            }
        }
    }

    // 단지 크기 정렬
    sort(complex_sizes.begin(), complex_sizes.end());

    // 결과 출력
    cout << complex_sizes.size() << "\n"; // 총 단지 수
    for (int size : complex_sizes) {
        cout << size << "\n"; // 각 단지 크기
    }

    return 0;
}
