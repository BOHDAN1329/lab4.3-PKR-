#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;
struct Perekaz {
	string rozrax_platn;
	string rozrax_otrum;
	double sum;
};
void Create(char* filename, Perekaz* p, int N)
{
	ofstream f(filename);
	int name;
	f << "---------------------------------------------------"
		<< endl
		<< "| � | ������� ��������| ������� ���������� | ���� |"
		<< endl
		<< "---------------------------------------------------" <<
		endl;

	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cout << " ������� ��������: "; cin >> p[i].rozrax_platn;
		cout << " ������� ����������: "; cin >> p[i].rozrax_otrum;
		cout << " ����: "; cin >> p[i].sum;

		f << "| " << setw(2) << right << i + 1 << " ";
		f << "| " << setw(15) << left << p[i].rozrax_platn
			<< "| " << setw(19) << right << p[i].rozrax_otrum
			<< "| " << setw(5) << left << p[i].sum << "|" << endl;
		f <<
			"---------------------------------------------------" << endl;
	}
}
void Print(char* filename)
{
	ifstream fin(filename);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
}


void Add(char* filename, Perekaz* p, int N)
{
	ofstream f(filename, ios::app);
	int name;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cout << " ������� ��������: "; cin >> p[i].rozrax_platn;
		cout << " ������� ����������: "; cin >> p[i].rozrax_otrum;
		cout << " ����: "; cin >> p[i].sum;

		f << "| " << setw(2) << right << i + 1 << " ";
		f << "| " << setw(15) << left << p[i].rozrax_platn
			<< "| " << setw(19) << right << p[i].rozrax_otrum
			<< "| " << setw(5) << left << p[i].sum << " |" << endl;
		f <<
			"---------------------------------------------------" << endl;
	}
}

void lookforSum(char* filename, char* raxynok)
{
	ifstream fin(filename);
	string s;
	bool ShoworNOT = 0;
	cout << "---------------------------------------------------"
		<< endl
		<< "| � | ������� ��������| ������� ���������� | ���� |"
		<< endl
		<< "---------------------------------------------------" <<
		endl;
	while (getline(fin, s))
	{
		if (s.find(raxynok, 0) != -1 && s[s.find(raxynok, 0) - 1] == ' ' )
		{
			cout << s << endl;
			ShoworNOT = 1;
		}
	}
	if (ShoworNOT == 0) cout << " Not found " << endl;
		cout << "---------------------------------------------------"
		<< endl;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char Raxynok[20];
	Perekaz* p;
	char filename[100];
	int N;
	cout << "������ ����� �����: "; cin >> filename;
	int menuItem;
	do {
		cout << " [1] - ��������� ������" << endl;
		cout << " [2] - �������� ������" << endl;
		cout << " [3] - ���������� ������" << endl;
		cout << " [4] - ���� ���� �� ����� " << endl;
			cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cout << "������ ������� ��������: "; cin >> N;
			p = new Perekaz[N];
			Create(filename, p, N);
			delete[] p;
			break;
		case 2:
			Print(filename);
			break;
		case 3:
			cout << "������ ������� ��������: "; cin >> N;
			p = new Perekaz[N];
			Add(filename, p, N);
			delete[] p;
			break;
		case 4:
			cout << "������ ����� �������������� ������� �������� : "; cin >> Raxynok;
			lookforSum(filename, Raxynok);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}