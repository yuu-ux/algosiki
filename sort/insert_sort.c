#include <stdio.h>

void print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

void	insert_sort(int *array, int total)
{
	int i;
	int j;
	int insert;
	i = 1;
	while (i < total)
	{
		insert = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > insert)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = insert;
		i++;
		print_array(array, total);
	}
}

int main(void) {
	int total;
	scanf("%d", &total);
	int array[total];
	int i;

	i = 0;
	while (i < total)
	{
		scanf("%d", &array[i]);
		i++;
	}
	insert_sort(array, total);
	return 0;
}
