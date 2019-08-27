#include <iostream>
#include <string>
using namespace std;

class Name
{
public:
	string famile, name;
	int a, b, c;
	double sred;
	int Id;
	static int Count;
	Name()
	{
		Count++;
		Id = Count;
	}
	void Set_Name(string famile, string name, int a, int b, int c)
	{
		this->famile = famile;
		this->name = name;
		this->a = a;
		this->b = b;
		this->c = c;
		this->sred =(double)(a + b + c) / 3;
	}
	void Print()
	{
		cout << this->famile << " " << this->name << endl;
	}
};

int Name::Count = 0;

int main()
{
	int n;
	string famile, name;
	int a, b, c;
	cin >> n;
	Name *A = new Name[n];
	for (int i = 0; i < n; i++)//ввод двнных
	{
		cin >> famile >> name >> a >> b >> c;
		A[i].Set_Name(famile, name, a, b, c);
	}
	for (int i = 0; i < n; i++) //сортировка на максимальный средний балл
	{	
		int max = i;
		for (int j = i; j < n; j++)
		{	
			if (A[j].sred > A[max].sred) 
			{ 
				max = j;
			}			
		}
		Name temp;
		temp = A[i];
		A[i] = A[max];
		A[max] = temp;
	}
	for (int i = 0; i < n; i++) //сортировка по id
	{
		for (int j = i; j < n; j++)
		{
			if (A[j].sred == A[i].sred && A[j].Id < A[i].Id)
			{
				Name temp;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}		
	}
	
	for (int i = 0; i < n; i++)//вывод
	{
		A[i].Print();
	}
	delete[] A;
    return 0;
}

