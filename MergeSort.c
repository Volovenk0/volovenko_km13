#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge_sort(int* array, int left, int right)
{
	if (left == right) return;
	int middle = (left + right) / 2;
	merge_sort(array, left, middle);
	merge_sort(array, middle + 1, right);
	int i = left;
	int j = middle + 1;
	int* temp_array = (int*)malloc(right * sizeof(int));
	for (int step = 0; step < right - left + 1; step++)
	{
		if ((j > right) || ((i <= middle) && (array[i] < array[j])))
		{
			temp_array[step] = array[i];
			i++;
		}
		else
		{
			temp_array[step] = array[j];
			j++;
		}
	}
	for (int step = 0; step < right - left + 1; step++)
	{
		array[left + step] = temp_array[step];
	}
}

int main()
{
	srand(time(NULL));

	int* array = (int*)malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
		printf("%d ", array[i]);
	}

	printf("\n\n");
	merge_sort(array, 0, 10-1);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n\n");

}