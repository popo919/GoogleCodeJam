#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int L, R;
		cin >> L >> R;
		int min = L < R ? L : R;
		int res = 0;
		for (int j = 0; j < min; ++j)
		{
			res += (j + 1);
		}
		printf("Case #%d: %d\n", i + 1, res);
	}

	return 0;
}