#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

//----------- INTEGER Input filtrers -------------------------------
int Get_Int_SA();				// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();			// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();				// peek&get вариант проверки ввода INTEGER	

//----------- DOUBLE Input filtrers --------------------------------
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
void Fill_Array_with_Random_Int(int arr[], int Size, int Range_min, int Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Homework 18 -----------------------------------------------------

//Task 1
template <typename ANY> ANY Summ_of_5_Numbers(ANY num1, ANY num2=2, ANY num3=3, ANY num4=4, ANY num5=5 )
{
	return  (num1 + num2 + num3 + num4 + num5);
}
void Summ_of_5_Numbers_demo()
{
	std::cout << "\nWhat type of data you want to enter?\n1) INTEGER\n2) DOUBLE \n";
	int user_choice = Get_Int_Positive(), user_choice2=0;
	if (user_choice == 1)
	{
		int Array_Parameters[5];
		std::cout << "\nEnter obligatore parameter for function:\nParameter_1 -> ";
		Array_Parameters[0] = Get_Int_SA();
		std::cout << "\nDo you want to enter other parameters [not obligatore]?\n1 - Yes\n2 - No\n";
		int user_choice2 = Get_Int_Positive();
		if (user_choice2 == 1)
		{
			for (int i = 1; i < 5; i++)
			{
				std::cout << "\nEnter parameter_" <<i+1<<" -> ";
				Array_Parameters[i]= Get_Int_SA();
			}
			std::cout << "\nSumm_of_5_Numbers(";
			for (int k = 0; k < 5; k++)
				std::cout << Array_Parameters[k] << ", ";
			std::cout << "\b\b) = " << Summ_of_5_Numbers(Array_Parameters[0], Array_Parameters[1], Array_Parameters[2], Array_Parameters[3], Array_Parameters[4]);
		}
		else std::cout << "\nSumm_of_5_Numbers(" << Array_Parameters[0] << ", other = default) = " << Summ_of_5_Numbers(Array_Parameters[0]);
	}

	else if (user_choice == 2)
	{
		double Array_Parameters[5];		
		std::cout << "\nEnter obligatore parameter for function:\nParameter_1 -> ";
		Array_Parameters[0] = Get_Dbl_SA();
		std::cout << "\nDo you want to enter other parameters [not obligatore]?\n1 - Yes\n2 - No\n";
		int user_choice2 = Get_Int_Positive();
		if (user_choice2 == 1)
		{
			for (int i = 1; i < 5; i++)
			{
				std::cout << "\nEnter parameter_" << i + 1 << " -> ";
				Array_Parameters[i] = Get_Dbl_SA();
			}
			std::cout << "\nSumm_of_5_Numbers(";
			for (int k = 0; k < 5; k++)
				std::cout << Array_Parameters[k] << ", ";
			std::cout << "\b\b) = " << Summ_of_5_Numbers(Array_Parameters[0], Array_Parameters[1], Array_Parameters[2], Array_Parameters[3], Array_Parameters[4]);
		}
		else std::cout << "\nSumm_of_5_Numbers(" << Array_Parameters[0] << ", other = default) = " << Summ_of_5_Numbers(Array_Parameters[0]);

	}

	else { std::cout << "\nWrong choice\n"; Sleep(1000); return; }	
}

//Task 2
template <typename ANY> double inline Average_of_3_Numbers(ANY num1, ANY num2, ANY num3)
{
	return  (double(num1 + num2 + num3)/3);
}
void Average_of_3_Numbers_demo()
{
	std::cout << "\nAverage_of_3_Numbers(5, 56, 556) = "<< Average_of_3_Numbers(5, 56, 556);
	std::cout << "\nAverage_of_3_Numbers(5.5, 56.5, 556.6) = " << Average_of_3_Numbers(5.5, 56.5, 556.6);
	//std::cout << "\nAverage_of_3_Numbers('5', '55', '555') = " << Average_of_3_Numbers('5', '55', '55');
	std::cout << "\nAverage_of_3_Numbers(5.5F, 55.5F, 555.5F) = " << Average_of_3_Numbers(5.5F, 55.5F, 555.5F);
	std::cout << "\nAverage_of_3_Numbers(5LL, 56LL, 556LL) = " << Average_of_3_Numbers(5LL, 56LL, 556LL);
}

//Task 3
template <typename ANY> ANY  Maximum_from_3(ANY num1, ANY num2, ANY num3)
{
	std::cout <<"\nType of data: " <<  typeid(num1).name() <<'\n';
	return  max(max(num1 , num2), max(num2, num3));
}
int Maximum_from_3(int num1, int num2, int num3)
{
	std::cout << "\nType of data: INTEGER" << '\n';
	return max(max(num1, num2), max(num2, num3));
}
double Maximum_from_3(double num1, double num2, double num3)
{
	std::cout << "\nType of data: DOUBLE" << '\n';
	return max(max(num1, num2), max(num2, num3));
}
void Maximum_from_3_demo()
{
	std::cout << "\n\n*** Overload based function ***\n";
	std::cout << "Maximum_from_3(1, 5, 15) = " << Maximum_from_3(1, 5, 15) << "\n"; //??? почему то что выводится в функции появляется раньше
	std::cout << "Maximum_from_3(1.0, 5.25, -15.5) = " << Maximum_from_3(1.0, 5.25, -15.5) << "\n";
	std::cout << "\n*** Template based function ***\n";
	std::cout << "Maximum_from_3(1.7F, -5.0F, -15.5F) = " << Maximum_from_3(1.7F, -5.0F, -15.5F) << "\n";
}

//Task 4
template <typename ANY> ANY Search_First_Ordinary_in_Array(ANY arr[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		int Divider_Counter = 0;
		for (int k = 1; k <= arr[i]; k++)
			if (arr[i] % k == 0) Divider_Counter++;
		if (Divider_Counter == 2) return arr[i];
	}
	std::cout << "\nThere are no ordinary numbers in array\n";
	return 0;
}
template <typename ANY> int Search_Position_First_Ordinary_in_Array(ANY arr[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		int Divider_Counter = 0;
		for (int k = 1; k <= arr[i]; k++)
			if (arr[i] % k == 0) Divider_Counter++;
		if (Divider_Counter == 2) return i;
	}
	return -1;
}
void Search_First_Ordinary_in_Array_demo()
{
	int const Size = 15;
	int Random_Array[Size];
	srand(time(NULL));
	std::cout << "\nRandom_Array [-999...999]:\n";
	Fill_Array_with_Random_Int(Random_Array, Size, -999, 999);
	Array_Console_Out(Random_Array, Size);
	if (Search_First_Ordinary_in_Array(Random_Array, Size))
	{
		std::cout << "\nFirst ordinary number in array -> " << Search_First_Ordinary_in_Array(Random_Array, Size);
		std::cout << "\nPosition -> " << Search_Position_First_Ordinary_in_Array(Random_Array, Size);
	}
}

//off topic --------------------------------------------------------
void Random_Array_demo()
{
	const int Size = 20;
	double Test_Array[Size];
	double Range_min = -1e4, Range_max = 1e4;
	std::cout << "\nArray of random double\n   ";
	std::cout << "\nRange_min " << Range_min << "\tRange_max " << Range_max;
	Fill_Array_with_Random(Test_Array, Size, Range_min, Range_max);
	std::sort(Test_Array, Test_Array+Size);
	Array_Console_Out(Test_Array, Size);
	
	int Test_Array2[Size];
	std::cout << "\nArray of random integer\n   ";
	std::cout << "\nRange_min " << "\tRange_max\n   ";
	int Range_min2 = Get_Int_SA();
	std::cout << "\t\t";
	int Range_max2 = Get_Int_SA();
	Fill_Array_with_Random(Test_Array2, Size, Range_min2, Range_max2);
	std::cout << "\nRange_min " << Range_min2 << "\tRange_max " << Range_max2;
	std::sort(Test_Array2, Test_Array2 + Size);
	Array_Console_Out(Test_Array2, Size);

}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("mode con cols=110 lines=40"); // ??? текст основного меню не входит в окно консоли по умолчанию. При небольшом увеличении окна (lines < 85) пропадает полоса прокрутки, что не здорово. Как ee оставить и не делать (lines > 85)?
	std::string Name_of_Work = { "Home Work 18: Overloaded, Inlined and Templated Functions" };
	std::string Menu_Element_1 = { "Summ_of_5_Numbers(num1...num5): Summ of 5 numbers" };
	std::string Menu_Element_2 = { "Average_of_3_Numbers(num1..num3): Average of 3 Numbers" };
	std::string Menu_Element_3 = { "Maximum_from_3(num1..num3): Search maximum of 3 Numbers and print it type" };
	std::string Menu_Element_4 = { "Search_First_Ordinary_in_Array(arr[], Size): Returns first ordinary number in an array" };

	do {		
		system("cls");
		std::cout << "\n\t***\t***\t" << Name_of_Work << "\t***\t***\n\n\t\n\nChoose an opion: \n";
		std::cout << "\n 1. " << Menu_Element_1;
		std::cout << "\n 2. " << Menu_Element_2;
		std::cout << "\n 3. " << Menu_Element_3;
		std::cout << "\n 4. " << Menu_Element_4;
		std::cout << "\n\n 0. Exit\n";
		int choice = 0;
		std::cout << "\nYour choice: ";
		choice = Get_Int_Positive();		
		std::cout << "\n";
		// Обработка выбора пользователя
		if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }
		else if (choice == 1) Summ_of_5_Numbers_demo();
		else if (choice == 2) Average_of_3_Numbers_demo();
		else if (choice == 3) Maximum_from_3_demo();
		else if (choice == 4) Search_First_Ordinary_in_Array_demo();

		else if (choice == 5) Random_Array_demo();
			
		else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
		std::cout << "\n\n";
		system("pause");
		} while (true);
		
	//system("pause");
	return 0;
}

// Вспомагательные функции -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); // заклинание средней силы против неудачного чтения getline
	std::cin.clear(); // заклинание малой силы против неудачного чтения getline
	getline(std::cin, a);
	//std::cout << "\nFunction: working with " << a << "\n"; для отладки
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	//std::cin.ignore(1024, '\n');
	getline(std::cin, a);
	if (a != "") // оказывается getline считывает пустую строку которую stoi уже не берет
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Incorrect input: INTEGER overflow. Decrease input\n";
			}
		}
		else
		{
			std::cout << "Incorrect symbols: positive INTEGER expected. Try again...\n";
			return Get_Int_Positive();
		}
		//return Get_Int_Positive();
	}
	else
		std::cout << "Input Error: NULL input\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Data type overflow\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: REAL expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = "."; // = "";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{
				//std::cout << "\na[" << i << "] ->" << a[i]<< " == " <<dot[0];
				//std::cout << "\nflag -> " << One_Dot_already;
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "dot placement error\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{
				//std::cout << "trying stod: " << a;
				//system("pause");
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Incorrect input: Data type [DOUBLE] overflow. Decrease input\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: positive REAL expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999, double Range_max=9999)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
void Fill_Array_with_Random_Int(int arr[], int Size, int Range_min, int Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);
	}
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
