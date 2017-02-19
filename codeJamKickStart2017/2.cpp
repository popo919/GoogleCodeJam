#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		int m, n;
		cin >> m >> n;
		float prob = (m - n) * 1.0f / (m + n);
		printf("Case #%d: %.8f\n", i+1, prob);
	}

	return 0;
}