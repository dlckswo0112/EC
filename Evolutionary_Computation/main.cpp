#include<iostream>
#include<fstream>
#include<string>
#include <assert.h> 
#include<cstdlib>
#include<ctime>
using namespace std;

#define MAX_SIZE 1000
#define POPULATION 50
#define NODE 500

char inputString[MAX_SIZE];

class datalist
{
private:
	int Index;
	int Degree;
	int* Data;
	int length;
public:
	datalist()
	{}
	void SetIndex(int Index) {
		this->Index = Index;
	}
	void SetDegree(int Degree) {
		this->Degree = Degree;
	}
	void SetData(int* Data, int j) {
		this->Data = new int[j];
		memset(this->Data, 0, sizeof(int)*j);
		memcpy(this->Data, Data, sizeof(int)*j);
		this->length = j;
	}
	int getindex()
	{
		return this->Index;
	}

	int getdegree()
	{
		return this->Degree;
	}
	int* getData()
	{
		return this->Data;
	}
	int getlength()
	{
		return this->length;
	}

};
class Chromosome
{
private:
	int Data[NODE];
	int Fitness;
public:
	Chromosome()
	{}
	void SetData(int num)
	{
		assert(num != 2 || num != 32);
		
		if (num == 2)
		{
			for (int j = 0; j < NODE; j++)
			{
				Data[j] = rand() % 2;
			}
		}
		
	}
	void GetData()
	{
		for (int j = 0; j < NODE; j++)
		{
			cout << Data[j] << " ";
		}
		cout << endl;
	}
};
void parse(char* argv[], int a)
{
	ifstream fin;
	fin.open(argv[a]);
	datalist Data[NODE];
	int i = 0;
	while (!fin.eof() && i < NODE)
	{

		int num[100] = { NULL };
		char* list;
		while (fin.peek() == ' ')
			fin.ignore();
		fin.getline(inputString, 100, ' ');
		//cout << inputString << ' ';
		Data[i].SetIndex(atoi(inputString));
		fin.ignore(100, ')');
		while (fin.peek() == ' ')
			fin.ignore();
		fin.getline(inputString, 1000, ' ');

		//cout << inputString << ' ';
		Data[i].SetDegree(atoi(inputString));

		while (fin.peek() == ' ')
			fin.ignore();

		fin.getline(inputString, 1000, '\n');
		//cout << inputString << endl;
		list = strtok(inputString, " ");
		int j = 0;
		while (list)
		{
			num[j++] = atoi(list);
			list = strtok(NULL, " ");

		}
		Data[i].SetData(num, j);

		i++;
	}
	Chromosome chro[POPULATION];
	
	for (int i = 0; i < POPULATION; i++)
	{
		chro[i].SetData(2);
	}
	for (int i = 0; i < POPULATION; i++)
	{
		chro[i].GetData();
	}
		fin.close();
}


int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "invalid error" << endl;
		return -1;
	}
	srand(time(NULL));
	for (int a = 1; a < argc; a++)
	{
		parse(argv, a);
	}


	return 0;
}