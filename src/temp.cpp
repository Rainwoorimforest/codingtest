#include <iostream>

#include <algorithm>
#include <vector>
using namespace std; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0); 
	int t; cin >> t; 
	while (t--) {	
		int n, m;
		cin >> n;
		vector <int> v1(n, 0);		
		for (int i = 0; i < n; i++) cin >> v1[i];
		sort(v1.begin(), v1.end());
		cin >> m; int temp; 
		for (int i = 0; i < m; i++) {
			cin >> temp; 
			int l = 0; int h = v1.size() - 1;
			int mid = 0;
			while (l <= h) {
				mid = (l+h) /2;
				if (v1[mid] == temp) {
					cout << 1 << "\n";
					break;
				}
				else if (v1[mid] < temp)l = mid + 1;
				else h = mid - 1;
			}
			if (v1[mid] != temp)cout << 0 << "\n";		
		}		
	}
}