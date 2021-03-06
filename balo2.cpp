// Knapsack_problem.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <stack>

using namespace std;

struct Thing
{
	int v;	// Value
	int w;	// Weight
};

stack<int> Knapsack(Thing *things, int **values, int n, int w);

int main()
{
	int num, capacity;
	Thing *t;
	int **values;
	stack<int> result;

	cout << "Please Enter the number of thing: ";
	cin >> num;

	t = new Thing[num];

	cout << "Enter the value and weight of things: " << endl;
	for (int i = 0; i < num; ++i)
	{
		cin >> t[i].v >> t[i].w;
	}
	cout << "Enter the capacity of the Knapsack: ";
	cin >> capacity;

	// Allocate memory for values
	values = new int*[num + 1];
	for (int i = 0; i <= num; ++i)
		values[i] = new int[capacity + 1];

	result = Knapsack(t, values, num + 1, capacity + 1);

	cout << "The solution is: " << endl;
	while (!result.empty())
	{
		cout << result.top() << " ";
		result.pop();
	}
		
	cout << endl;

    return 0;
}

stack<int> Knapsack(Thing * things, int ** values, int n, int w)
{
	int r = n - 1, c = w - 1;
	stack<int> result;
	
	// Initialize the array values
	for (int i = 0; i < w; ++i)
		values[0][i] = 0;
	for (int i = 0; i < n; i++)
		values[i][0] = 0;

	// Fill in the array values
	for (int j = 1; j < w; ++j)
	{
		for (int i = 1; i < n; ++i)
		{
			if ((j - things[i - 1].w) < 0)
				values[i][j] = values[i - 1][j];
			else
				values[i][j] = (values[i - 1][j] > 
							   (things[i - 1].v + values[i - 1][j - things[i - 1].w]) ? 
								values[i - 1][j] : 
							   (things[i - 1].v + values[i - 1][j - things[i - 1].w]));
		}
	}
	
	// Backtrack the values
	while (r != 0 && c != 0)
	{
		if (values[r][c] != values[r - 1][c])
		{
			result.push(r);
			c -= things[r - 1].w;
		}
		r--;
	}
	return result;
}