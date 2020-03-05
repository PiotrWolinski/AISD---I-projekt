#include <iostream>

struct type {
	char* arr
};

unsigned long check_length(char* arr)
{
	unsigned long length = 0;
	while (arr[length] != NULL)
	{
		length++;
	}
	return length;
}

void find_min(char** arr)
{
	unsigned long tmp_length = 0;
	unsigned int index = 0;
	unsigned int tmp_index = 0;
	bool if_sign = false;
	unsigned int current = 0;
	while (arr != NULL)
	{
		if_sign = (arr[current][0] == '-') ? true : false; //true jesli dana liczba jest z minusem
		if (if_sign)
		{

		}
	}
	printf("%s", arr[index]);
}

int main(int argc, char* argv[])
{
	int n = 0;
	scanf_s("%d", &n);
	char** main_arr = (char**)malloc(n * sizeof(char*));
	int size = n;
	unsigned int count = 0;
	bool first = true;
	int enter = getchar();
	do
	{
		int arr_size = 1;
		main_arr[count] = (char*)malloc(sizeof(char));

		if (main_arr[count] != NULL)
		{
			char q;
			unsigned int i = 0;
			while ((q = getchar()) != '\n')
			{
				main_arr[count][i++] = q;
				if (i == arr_size)
				{
					arr_size = i + 10;
					main_arr[count] = (char*)realloc(main_arr[count], arr_size);
				}
			}
			main_arr[count][i] = '\0';
			count++;
		}
	} while (count < n);

	while (true)
	{
		char input = getchar();
		if(input == '?')
		{
			for (int i = 0; i < size; i++)
			{
				printf("%s\n", main_arr[i]);
			}
		}
		else if (input == 'q')
		{
			break;
		}
	}

	/*char a = '4';
	char b = '3';
	std::cout << (char)(a - b  + 48);*/

	return 0;
}