#define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h>
#include <stdio.h>

struct type {
	char* arr;
	unsigned int length;
	unsigned short sign; // 1 - liczba ujemna, 0 - liczba dodatnia
};

//unsigned int count_char(char* arr)
//{
//	unsigned i = 0;
//	while (arr[i] != NULL)
//	{
//		++i;
//	}
//	return i;
//}

//jesli wieksza jest pierwsza liczba, to zwroci 1, jak wieksza jest druga to 2, a jesli sa rowne to 0
unsigned short which_bigger(type arr1, type arr2)
{
	if (arr1.sign != arr2.sign)
	{
		if (arr1.sign == 0) //to znaczy, ze arr2 jest ujemne i mozna zamienic to na odejmowanie bez znaku
		{
			return 1;
		}
		else //to znaczy, ze arr1 jest ujemne i znowu mozna to zamienic na odejmowanie 
		{
			return 2;
		}
	}
	else if (arr1.sign == 0) //obydwie sa dodatnie i trzeba sprawdzic, ktora jest wieksza
	{
		if (arr1.length > arr2.length)
		{
			return 1;
		}
		else if (arr1.length < arr2.length)
		{
			return 2;
		}
		else
		{
			unsigned int i = 0;
			while (arr1.arr[i] != '\0' && arr2.arr[i] != '\0')
			{
				if (arr1.arr[i] > arr2.arr[i])
				{
					return 1;
				}
				else if (arr1.arr[i] < arr2.arr[i])
				{
					return 2;
				}
				++i;
			}
		}
	}
	else if (arr1.sign == 1)
	{
		if (arr1.length < arr2.length)
		{
			return 1;
		}
		else if (arr1.length > arr2.length)
		{
			return 2;
		}
		else
		{
			unsigned int i = 0;
			while (arr1.arr[i] != '\0' && arr2.arr[i] != '\0')
			{
				if (arr1.arr[i] < arr2.arr[i])
				{
					return 1;
				}
				else if (arr1.arr[i] > arr2.arr[i])
				{
					return 2;
				}
				++i;
			}
		}
	}
	return -1;
}

unsigned int find_min(type* array, unsigned int size)
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
		}
		else if (array[current].sign == min_sign && min_sign == 1) //maja ten sam znak czyli minus, wiec trzeba porownywac dlugosc cyfr
		{
			if (array[current].length > array[min_index].length)
			{
				min_index = current;
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
					else if (array[current].arr[i] < array[min_index].arr[i])
					{
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
			}
			else if (array[current].length == array[min_index].length)
			{
				unsigned int i = 0; //zaczynam od 1, poniewaz pierwszy znak mowi o znaku liczby
				while (array[current].arr[i] != '\0')
				{
					if (array[current].arr[i] < array[min_index].arr[i])
					{
						min_index = current;
						break;
					}
					else if (array[current].arr[i] > array[min_index].arr[i])
					{
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

unsigned int find_max(type* array, unsigned int size)
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
		}
		else if (array[current].sign == max_sign && max_sign == 0) //maja ten sam znak czyli plus, wiec trzeba porownywac dlugosc cyfr
		{
			if (array[current].length > array[max_index].length)
			{
				max_index = current;
			}
			else if (array[current].length == array[max_index].length)
			{
				unsigned int i = 0; //zaczynam od 0, poniewaz tutaj nie ma informacji o znaku
				while (array[current].arr[i] != '\0' && array[max_index].arr[i] != '\0')
				{
					if (array[current].arr[i] > array[max_index].arr[i])
					{
						max_index = current;
						break;
					}
					else if (array[current].arr[i] < array[max_index].arr[i])
					{
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
			}
			else if (array[current].length == array[max_index].length)
			{
				unsigned int i = 1; //zaczynam od 0, poniewaz tutaj jest informacja o znaku
				while (array[current].arr[i] != '\0')
				{
					if (array[current].arr[i] < array[max_index].arr[i])
					{
						max_index = current;
						break;
					}
					else if (array[current].arr[i] > array[max_index].arr[i])
					{
						break;
					}
					++i;
				}
			}
		}
		current++;
	}
	return max_index;
}

void addition(type* arr_i, type* arr_j, type* arr_k)
{
	unsigned short sign1 = arr_j->sign;
	unsigned short sign2 = arr_k->sign;
	unsigned short bigger = which_bigger(*arr_j, *arr_k);
	if (sign1 == sign2 && sign1 == 0)
	{
		if (bigger == 1) //arr_j jest wieksza, wiec petla bedzie iterowala do konca arr_k
		{
			char* tmp_main = (char*)malloc(arr_j->length * sizeof(char));
			for (int i = 0; i < arr_j->length; ++i)
			{
				tmp_main[i] = arr_j->arr[i];
			}
			tmp_main[arr_j->length] = '\0';
			/*printf("%s chuj\n", tmp_main);*/
			int h_id = arr_j->length - 1;
			int l_id = arr_k->length - 1;
			arr_i->length = arr_j->length;
			while (h_id >= 0)
			{				
				if (l_id >= 0)
				{
					/*printf("%s %d\n", tmp_main, h_id);*/
					tmp_main[h_id] += (arr_k->arr[l_id] - 48);
					/*printf("%c\n", tmp_main[pos_j]);*/
					if (tmp_main[h_id] > 57 && h_id > 0)
					{
						tmp_main[h_id] -= 10;
						tmp_main[h_id - 1] += 1;
					}
					else if (tmp_main[h_id] > 57 && h_id == 0)
					{
						/*printf("%s\n", tmp_main);*/
						tmp_main[h_id] -= 10;
						char* tmp = (char*)malloc((arr_j->length + 1) * sizeof(char));
						tmp[0] = '1';
						tmp[arr_j->length + 1] = '\0';
						for (int x = arr_j->length; x > 0; --x)
						{
							tmp[x] = tmp_main[x - 1];
							/*printf("%s %s\n", tmp_main, tmp);*/
						}
						tmp_main = tmp;
						arr_i->length++;
						/*printf("co do kurwy\n");*/
					}	
				}
				--l_id;
				--h_id;
			}
			/*printf("%s\n", tmp_main);*/
			arr_i->arr = tmp_main;
			/*printf("success\n");*/
		}
		else if (bigger == 2)
		{
			char* tmp_main = (char*)malloc(arr_k->length * sizeof(char));
			for (int i = 0; i < arr_k->length; ++i)
			{
				tmp_main[i] = arr_k->arr[i];
			}
			tmp_main[arr_k->length] = '\0';
			/*printf("%s chuj\n", tmp_main);*/
			int pos_k = arr_k->length - 1;
			int pos_j = arr_j->length - 1;
			int h_id = arr_k->length - 1;
			int l_id = arr_j->length - 1;
			arr_i->length = arr_k->length;
			while (h_id >= 0)
			{
				if (l_id >= 0)
				{
					/*printf("%s %d\n", tmp_main, pos_k);*/
					tmp_main[h_id] += (arr_j->arr[l_id] - 48);
					/*printf("%c\n", tmp_main[h_id]);*/
					if (tmp_main[h_id] > 57 && h_id > 0)
					{
						tmp_main[h_id] -= 10;
						tmp_main[h_id - 1] += 1;
					}
					else if (tmp_main[h_id] > 57 && h_id == 0)
					{
						/*printf("%s\n", tmp_main);*/
						tmp_main[h_id] -= 10;
						char* tmp = (char*)malloc((arr_k->length + 1) * sizeof(char));
						tmp[0] = '1';
						tmp[arr_k->length + 1] = '\0';
						for (int x = arr_k->length; x > 0; --x)
						{
							tmp[x] = tmp_main[x - 1];
							/*printf("%s %s\n", tmp_main, tmp);*/
						}
						tmp_main = tmp;
						arr_i->length++;
						/*printf("co do kurwy\n");*/
					}
				}
				--h_id;
				--l_id;
			}
			/*printf("%s\n", tmp_main);*/
			arr_i->arr = tmp_main;
			/*printf("success\n");*/
		}
	}
}

void subtraction()
{

}

int main(int argc, char* argv[])
{
	unsigned int n = 0;
	scanf_s("%d", &n);
	type* array = (type*)malloc(n * sizeof(type));
	int* arr_test = (int*)malloc(n * sizeof(int));
	unsigned int size = n;
	unsigned int count = 0;
	int blank = getchar();
	do
	{
		unsigned int arr_size = 1;
		array[count].arr = (char*)malloc(sizeof(char));

		if (array[count].arr != NULL)
		{
			char q;
			unsigned int i = 0;
			while ((q = getchar()) != '\n')
			{
				array[count].arr[i++] = q;
				if (i == arr_size)
				{
					arr_size = i + 1;
					if (char* tmp = (char*)realloc(array[count].arr, arr_size))
					{
						array[count].arr = tmp;
					}
				}
			}
			array[count].sign = (array[count].arr[0] == '-') ? 1 : 0;
			array[count].length = (array[count].sign) ? i - 1 : i; //okreslenie dlugosci ciagu znakow
			array[count].arr[i] = '\0';
			count++;
		}
		arr_test[count] = 0;
	} while (count < n);
	int counter = 0;
	while (true)
	{
		const char sign = '=';
		int i = 0;
		int j = 0;
		int k = 0;
		char action = ' ';
		scanf("%d = %d %c %d", &i, &j, &action, &k);
		if (action != ' ')
		{
			if (action == '+')
			{
				arr_test[i] = 1;
				addition(&array[i], &array[j], &array[k]);
			}
			else if (action == '-')
			{
				printf("Odejmowanko\n");
			}
			else
			{
				printf("Undefined\n");
			}
		}
		char input = getchar();
		if (input == '?')
		{
			counter++;
			for (int i = 0; i < size; i++)
			{
				/*if (arr_test[i] == 1)
				{
					printf("1 ");
				}*/
				/*printf("%d %s\n",array[i].length, array[i].arr);*/
				printf("%s\n", array[i].arr);
			}
		}
		else if (input == 'q')
		{
			/*printf("%d", which_bigger(array[0], array[1]));*/
			break;
		}
		else if (input == 'm')
		{
			char second = getchar();
			char third = getchar();
			if (second == 'i' && third == 'n')
			{
				unsigned int min = find_min(array, size);
				printf("%s\n", array[min].arr);
			}
			else if (second == 'a' && third == 'x')
			{
				unsigned int max = find_max(array, size);
				printf("%s\n", array[max].arr);
			}
		}
	}
	return 0;
}