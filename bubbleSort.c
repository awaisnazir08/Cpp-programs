#include <stdio.h>
#include <stdbool.h>
#define n 30
int main()
{
	int i = 0, j = 0, check = 0, x = 0;
	int a[n];
	bool flag = false;
	printf("\nEnter the amount of numbers in your sequence: ");
	scanf("%d", &x);
	printf("\nPlease enter the numbers by spaces: ");
	for (i = 0; i < x; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < x - 1; i++)
	{
		for (j = 0; j < (x - i) - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				check = a[j + 1];
				a[j + 1] = a[j];
				a[j] = check;
				flag = true;
			}
		}
		if (!flag)
			break;
	}
	for (j = 0; j < x; j++)
	{
		printf("%d	", a[j]);
	}
	return 0;
}