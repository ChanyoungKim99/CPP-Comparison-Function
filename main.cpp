#include <iostream>

void Sort(int numbers[], int count);

// Comparison Function (비교 함수)
// -> Predicate (서술어) : 크다? 작다? 같다?

using Comparison = bool (*)(int, int);

bool Greater(int x, int y)
{
	return x > y;
};

bool Lesser(int x, int y)
{
	return x < y;
}

void Sort(int numbers[], int count, Comparison f)
{
	int temp{};

	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if ( f(numbers[i], numbers[j]) )
			{
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

int main()
{
	const int ARRAY_COUNT = 10;
	int scores[ARRAY_COUNT]{ 20, 10, 40, 15, 30, 50, 100, 90, 70, 60 };

	Sort(scores, ARRAY_COUNT, Greater);
	
	for (int i = 0; i < ARRAY_COUNT; i++)
	{
		std::cout << scores[i] << ", ";
	}

	std::cout << std::endl;
}