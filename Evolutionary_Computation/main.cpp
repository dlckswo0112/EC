#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX_SIZE 1000

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
	void SetData(int* Data,int j) {
		this->Data = new int[j];
		memset(this->Data, 0, sizeof(int)*j);
		memcpy(this->Data, Data,sizeof(int)*j);
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

public:

};
int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "invalid error" << endl;
		return -1;
	}
	ifstream fin;
	for (int a = 1; a < argc; a++)
	{
		fin.open(argv[a]);
		datalist Data[500];
		int i = 0;
		while (!fin.eof() && i < 500)
		{
			
			int num[100] = { NULL };
			char* list;
			while (fin.peek()==' ')
				fin.ignore();
			fin.getline(inputString, 100, ' ');
			cout << inputString << ' ';
			Data[i].SetIndex(atoi(inputString));
			fin.ignore(100, ')');
			while (fin.peek() == ' ')
				fin.ignore();
			fin.getline(inputString, 1000, ' ');

			cout << inputString<<' ';
			Data[i].SetDegree(atoi(inputString));
			
			while (fin.peek() == ' ')
				fin.ignore();
			
			fin.getline(inputString, 1000, '\n');
			cout << inputString << endl;
			list = strtok(inputString, " ");
			int j = 0;
			while (list)
			{
				num[j++] = atoi(list);
				list = strtok(NULL, " ");

			}
			Data[i].SetData(num,j);
			
			i++;
			if (i == 500)
				cout << "hi" << endl;
		}
		fin.close();
	}


		return 0;
}