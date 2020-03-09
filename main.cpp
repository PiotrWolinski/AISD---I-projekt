#define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h>
#include <stdio.h>

struct type {
	char* arr;
	unsigned int length;
	unsigned short sign; // 1 - liczba ujemna, 0 - liczba dodatnia
};

char* remove_sign(type* arr)
{
	char* new_arr;
	if (new_arr = (char*)malloc(arr->length * sizeof(char)))
	{
		for (int i = 0; i < arr->length; i++)
		{
			new_arr[i] = arr->arr[i + 1];
		}
		new_arr[arr->length] = '\0';
	}
	return new_arr;
}

char* add_sign(type* arr)
{
	char* new_arr;
	if (new_arr = (char*)malloc((arr->length + 1) * sizeof(char)))
	{
		for (int i = 1; i < arr->length + 1; i++)
		{
			new_arr[i] = arr->arr[i - 1];
		}
		new_arr[0] = '-';
		new_arr[arr->length + 1] = '\0';
	}
	return new_arr;
}

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
			return 0;
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
			return 0;
		}
	}
	return -1;
}

//jesli absolutnie wieksza jest pierwsza liczba, to zwroci 1, jak wieksza jest druga to 2, a jesli sa rowne to 0
int abs_bigger(type arr1, type arr2)
{
	type* new_arr1 = (type*)malloc(sizeof(type));
	type* new_arr2 = (type*)malloc(sizeof(type));;
	if (arr1.sign != 0)
	{
		new_arr1->arr = remove_sign(&arr1);
	}

	if (arr2.sign != 0)
	{
		new_arr2->arr = remove_sign(&arr2);
	}
	
	return which_bigger(*new_arr1, *new_arr2);
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

//base_arr - nadpisywana liczba, arr1 - wieksza z liczb, arr2 - mniejsza z liczb
void add_to_bigger(type* base_arr, type* arr1, type* arr2)
{
	char* tmp_main = (char*)malloc(arr1->length * sizeof(char)); //musze pamietac o zamianie dlugosci nowej liczby, jak zapisuje
	for (int i = 0; i < arr1->length; ++i)
	{
		tmp_main[i] = arr1->arr[i];
	}
	tmp_main[arr1->length] = '\0';
	int h_id = arr1->length - 1;
	int l_id = arr2->length - 1;
	base_arr->length = arr1->length;
	while (h_id >= 0)
	{
		if (l_id >= 0)
		{
			/*printf("%s %d\n", tmp_main, h_id);*/
			tmp_main[h_id] += (arr2->arr[l_id] - 48);
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
				char* tmp = (char*)malloc((arr1->length + 1) * sizeof(char));
				tmp[0] = '1';
				tmp[arr1->length + 1] = '\0';
				for (int x = arr1->length; x > 0; --x)
				{
					tmp[x] = tmp_main[x - 1];
					/*printf("%s %s\n", tmp_main, tmp);*/
				}
				tmp_main = tmp;
				base_arr->length++;
			}
		}
		--l_id;
		--h_id;
	}
	base_arr->arr = tmp_main;
}

void add_to_lower(type* base_arr, type* arr1, type* arr2)
{
	char* tmp_main = (char*)malloc((arr1->length + 1) * sizeof(char)); //+ 1, poniewaz z przodu jest jeszcze znak
	for (int i = 1; i < arr1->length + 1; ++i) //zaczynam od 1, bo znak
	{
		tmp_main[i] = arr1->arr[i];
	}
	tmp_main[arr1->length + 1] = '\0';
	int h_id = arr1->length;
	int l_id = arr2->length;
	base_arr->length = arr1->length;
	while (h_id > 0)
	{
		if (l_id > 0)
		{
			/*printf("%s %d\n", tmp_main, h_id);*/
			tmp_main[h_id] += (arr2->arr[l_id] - 48);
			/*printf("%c\n", tmp_main[pos_j]);*/
			if (tmp_main[h_id] > 57 && h_id > 1)
			{
				tmp_main[h_id] -= 10;
				tmp_main[h_id - 1] += 1;
			}
			else if (tmp_main[h_id] > 57 && h_id == 1)
			{
				/*printf("%s\n", tmp_main);*/
				tmp_main[h_id] -= 10;
				char* tmp = (char*)malloc((arr1->length + 2) * sizeof(char)); //+ 2, poniewaz musze pamietac o znaku
				tmp[0] = '-';
				tmp[1] = '1';
				tmp[arr1->length + 2] = '\0';
				for (int x = arr1->length + 1; x > 1; --x)
				{
					tmp[x] = tmp_main[x - 1];
					/*printf("%s %s\n", tmp_main, tmp);*/
				}
				tmp_main = tmp;
				base_arr->length++;
			}
		}
		--l_id;
		--h_id;
	}
	base_arr->arr = tmp_main;
}

void add_different(type* base_arr, type* arr1, type* arr2)
{

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
			add_to_bigger(arr_i, arr_j, arr_k);	
		}
		else if (bigger == 2)
		{
			add_to_bigger(arr_i, arr_k, arr_j);
		}
		else
		{
			add_to_bigger(arr_i, arr_j, arr_j);
		}
	}
	else if (sign1 == sign2 && sign1 == 1) //z uzyciem funkcji bede zawsze dodawal do mniejszego 
	{
		if (bigger == 1)
		{
			add_to_lower(arr_i, arr_k, arr_j);
		}
		else if (bigger == 2)
		{
			add_to_lower(arr_i, arr_j, arr_k);
		}
		else
		{
			add_to_lower(arr_i, arr_j, arr_k);
		}
	}
	else //rozne znaki :/ to bedzie po prostu zamienione na odejmowanie
	{

	}
}

void subtraction_from_bigger(type* base_arr, type* arr1, type* arr2)
{
	char* tmp_main = (char*)malloc(arr1->length * sizeof(char));
	for (int i = 0; i < arr1->length; ++i)
	{
		tmp_main[i] = arr1->arr[i];
	}
	tmp_main[arr1->length] = '\0';
	int h_id = arr1->length - 1;
	int l_id = arr2->length - 1;
	base_arr->length = arr1->length;
	while (h_id >= 0)
	{
		if (l_id >= 0)
		{
			tmp_main[h_id] -= (arr2->arr[l_id] - 48);
			if (tmp_main[h_id] < 48)
			{
				tmp_main[h_id] += 10;
				tmp_main[h_id - 1] -= 1;
			}
		}
		--l_id;
		--h_id;
	}
	//musze wyszyscic 0 z poczatku
	int count = 0;
	while (tmp_main[0] == '0')
	{
		for (int i = 0; i < arr2->length; i++)
		{
			tmp_main[i] = tmp_main[i + 1];
		}
		base_arr->length--;
	}
	base_arr->arr = tmp_main;
}

void subtraction(type* arr_i, type* arr_j, type* arr_k)
{
	unsigned short sign1 = arr_j->sign;
	unsigned short sign2 = arr_k->sign;
	unsigned short bigger = abs_bigger(*arr_j, *arr_k);
	
	if (!sign1 && !sign2 && which_bigger(*arr_j, *arr_k) == 1)
	{
		subtraction_from_bigger(arr_i, arr_j, arr_k);
	}
	else if (!sign1 && !sign2 && which_bigger(*arr_j, *arr_k) == 2) //wynik bedzie na minusie
	{
		arr_i->sign = 1;
		subtraction_from_bigger(arr_i, arr_k, arr_j);
		arr_i->arr = add_sign(arr_i);
	}
	else if (!sign1 && !sign2 && which_bigger(*arr_j, *arr_k) == 0)
	{
		char* tmp = (char*)malloc(2 * sizeof(char));
		arr_i->sign = 0;
		arr_i->length = 0;
		arr_i->arr[0] = '0';
		arr_i->arr[1] = '\0';
	}
	else if (!sign1 && sign2) //pierwsza liczba dodatnia, druga ujemna = dodawanie
	{
		type* tmp;
		if (tmp = (type*)malloc(sizeof(type)))
		{
			tmp->length = arr_k->length;
			tmp->sign = 0;
			tmp->arr = remove_sign(arr_k);
		}
		short int bigger = which_bigger(*arr_j, *tmp);
		if (bigger == 1) 
		{
			add_to_bigger(arr_i, arr_j, tmp);
		}
		else if (bigger == 2)
		{
			add_to_bigger(arr_i, tmp, arr_j);
		}
		else
		{
			add_to_bigger(arr_i, arr_j, arr_j);
		}
	}
	else if (sign1 && !sign2)
	{

	}
}

int main(int argc, char* argv[])
{
	unsigned int n = 0;
	scanf_s("%d", &n);
	type* array = (type*)malloc(n * sizeof(type));
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
	} while (count < n);

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
				addition(&array[i], &array[j], &array[k]);
			}
			else if (action == '-')
			{
				subtraction(&array[i], &array[j], &array[k]);
			}
			else
			{
				printf("Undefined\n");
			}
		}
		char input = getchar();
		if (input == '?')
		{
			for (int i = 0; i < size; i++)
			{
				/*printf("%d ", array[i].length);*/
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
	free(array);
	return 0;
}