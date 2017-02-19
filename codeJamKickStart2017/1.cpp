#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Man
{
	string name;
	string trimName;
	int num;
};

string trim(string name)
{
	string res = "";
	int pre = 0, cur = 0;
	while (cur < name.length())
	{
		while (cur < name.length() && name[cur] != ' ')
			++cur;
		res += name.substr(pre, cur - pre);
		cur++;
		pre = cur;
	}

	return res;
}

int GetNum(string name)
{
	bool namehash[26];
	fill(namehash, namehash + 26, 0);
	for (int i = 0; i < name.length(); ++i)
		namehash[name[i] - 'A'] = true;
	int num = 0;
	for (int i = 0; i < 26; ++i)
		if (namehash[i]) ++num;

	return num;
}

bool cmp(Man man1, Man man2)
{
	if (man1.num != man2.num)
		return man1.num < man2.num;
	else
		return man1.trimName > man2.trimName;
}

int main()
{
	int T, N;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		vector<Man> men;
		string name;
		getline(cin, name);
		for (int j = 0; j < N; ++j)
		{
			getline(cin, name);
			Man man;
			man.name = name;
			man.trimName = trim(name);
			man.num = GetNum(name);
			men.push_back(man);
		}
		sort(men.begin(), men.end(), cmp);
		printf("Case #%d: %s\n", i + 1, men[N-1].name.c_str());
	}
}