#include <iostream>

struct type {
	char* arr;
	unsigned int length;
	unsigned short sign; // 1 - liczba ujemna, 0 - liczba dodatnia
};

unsigned int find_min(type* &array, unsigned int size)
{
	unsigned int current = 1;
	unsigned int min_index = 0;
	short int min_sign = array[min_index].sign;
	while (current < size)
	{
		if (array[current].sign != min_sign && min_sign == 0) //minimalna liczba na ta chwile jest ujemna, a sprawdzana dodatnia
		{ 
			min_index = current;
			min_sign = array[current].sign;
			break;
		}
		else if (array[current].sign == min_sign && min_sign == 1) //maja ten sam znak czyli minus, wiec trzeba porownywac dlugosc cyfr
		{
			if (array[current].length > array[min_index].length)
			{
				min_index = current;
				break;
			}
			else if (array[current].length == array[min_index].length)
			{
				unsigned int i = 1; //zaczynam od 1, poniewaz pierwszy znak mowi o znaku liczby
				while (array[current].arr[i] != '\0')
				{
					if (array[current].arr[i] > array[min_index].arr[i])
					{
						min_index = current;
						break;
					}
					++i;
				}
			}
		}
		else if (array[current].sign == min_sign && min_sign == 0)
		{
			if (array[current].length < array[min_index].length)
			{
				min_index = current;
				break;
			}
			else if (array[current].length == array[min_index].length)
			{
				unsigned int i = 1; //zaczynam od 1, poniewaz pierwszy znak mowi o znaku liczby
				while (array[current].arr[i] != '\0')
				{
					if (array[current].arr[i] < array[min_index].arr[i])
					{
						min_index = current;
						break;
					}
					++i;
				}
			}
		}
		++current;
	}
	return min_index;
}

unsigned int find_max(type*& array, unsigned int size)
{
	unsigned int current = 1;
	unsigned int max_index = 0;
	short int max_sign = array[max_index].sign;
	while (current < size)
	{
		if (array[current].sign != max_sign && max_sign == 1) //maksymalna liczba na ta chwile jest ujemna, a sprawdzana dodatnia
		{
			max_index = current;
			max_sign = array[current].sign;
			break;
		}
		else if (array[current].sign == max_sign && max_sign == 0) //maja ten sam znak czyli plus, wiec trzeba porownywac dlugosc cyfr
		{
			if (array[current].length > array[max_index].length)
			{
				max_index = current;
				break;
			}
			else if (array[current].length == array[max_index].length)
			{
				unsigned int i = 0; //zaczynam od 0, poniewaz tutaj nie ma informacji o znaku
				while (array[current].arr[i] != '\0')
				{
					if (array[current].arr[i] > array[max_index].arr[i])
					{
						max_index = current;
						break;
					}
					++i;
				}
			}
		}
		else if (array[current].sign == max_sign && max_sign == 1)
		{
			if (array[current].length < array[max_index].length)
			{
				max_index = current;
				break;
			}
			else if (array[current].length == array[max_index].length)
			{
				unsigned int i = 0; //zaczynam od 0, poniewaz tutaj nie ma informacji o znaku
				while (array[current].arr[i] != '\0')
				{
					if (array[current].arr[i] < array[max_index].arr[i])
					{
						max_index = current;
						break;
					}
					++i;
				}
			}
		}
		++current;
	}
	return max_index;
}

int main(int argc, char* argv[])
{
	int n = 0;
	scanf_s("%d", &n);
	type* array= (type*)malloc(n * sizeof(type));
	unsigned int size = n;
	unsigned int count = 0;
	char blank = getchar();
	do
	{
		int arr_size = 1;
		array[count].arr = (char*)malloc(sizeof(char));

		if (array[count].arr != NULL != NULL)
		{
			char q;
			unsigned int i = 0;
			while ((q = getchar()) != '\n')
			{
				array[count].arr[i++] = q;
				if (i == arr_size)
				{
					arr_size = i + 10;
					if (char* tmp = (char*)realloc(array[count].arr, arr_size))
					{
						array[count].arr = tmp;
					}
				}
			}
			array[count].sign = (array[count].arr[0] == '-') ? 1 : 0;
			array[count].length = (array[count].sign) ? i + 1 : i; //okreslenie dlugosci ciagu znakow
			array[count].arr[i] = '\0';
			count++;
		}
	} while (count < n);

	while (true)
	{
		char* sentence;
		char input = getchar();
		if(input == '?')
		{
			for (int i = 0; i < size; i++)
			{
				printf("%d %s\n",array[i].sign, array[i].arr);
			}
		}
		else if (input == 'q')
		{
			break;
		}
		else if (input == 'm')
		{
			char second;
			if ((second = getchar() ) == 'i')
			{
				printf("%s\n", array[find_min(array, size)].arr);
			}
		}
		else if (input == 'm')
		{
			char second;
			if ((second = getchar()) == 'a')
			{
				printf("%s\n", array[find_max(array, size)].arr);
			}
		}
	}

	/*char a = '4';
	char b = '3';
	std::cout << (char)(a - b  + 48);*/

	return 0;
}