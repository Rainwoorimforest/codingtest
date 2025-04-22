#include<iostream>
#include<string>
#include<vector>

using namespace std;

int match(string a, string b)
{
	int count = 0;
	for (int i = a.size() - 1, j = b.size() - 1; j >= 0; i--, j--)
	{
		if (a[i] == b[j]) count++;
	}

	return count;
}

int main() {
	string s;
	string bomb;
	string result;


	cin >> s;
	cin >> bomb;

	int s_size = s.size();
	int bomb_size = bomb.size();



	for (int i = 0; i < s_size; i++)
	{
		char temp_s;
		temp_s = s.at(i);


		if (s.at(i) == bomb.at(bomb_size - 1)) // 마지막 문자 발견
		{

			result.push_back(temp_s);

			if (bomb_size = match(result, bomb)) // 길이도 같다면
			{
				for (int i = 0; i < bomb_size; i++)
				{
					result.pop_back();
				}

			}

		}
		else
		{
			result.push_back(temp_s);
		}

	}

	//출력하기
	if (result.empty()) cout << "FRULA" << endl;
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result.at(i);
		}
	}


	return 0;
}