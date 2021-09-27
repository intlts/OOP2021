#include <iostream>
#include <conio.h>

using namespace std;

int var = 2021;

void print_data_types_sizes();
void  example_scope_operator();

int main()
{
	//Apelam functia care exemplifica utilitatea operatorului de scop
	example_scope_operator();

	//Apelam functia care afiseaza dimensiunile tipurilor de date - in octeti (bytes)
	print_data_types_sizes();


	// Citeste un singur caracter de la tastatura. 
	//Util pentru a "pune pe pauza" executia aplicatiei, pana la apasarea unei taste
	_getch();
	

 }

void print_data_types_sizes()
{
	cout << "BOOL: " << sizeof(bool) << endl;

	cout << "CHAR: " << sizeof(char) << endl;
	cout << "WCHAR_T: " << sizeof(wchar_t) << endl;

	cout << "SHORT: " << sizeof(short) << endl;
	cout << "INT: " << sizeof(int) << endl;
	cout << "LONG: " << sizeof(long) << endl;
	cout << "LONG LONG: " << sizeof(long long) << endl;

	cout << "FLOAT: " << sizeof(float) << endl;
	cout << "DOUBLE: " << sizeof(double) << endl;
	cout << "LONG DOUBLE: " << sizeof(long double) << endl;

	cout<< endl;
	_getch();

}

void example_scope_operator()
{
	int var = 1234;

	cout << "Variabila `var` locala - din scopul functiei curente: " << var << endl;
	cout << "Variabila `var` globala: " << ::var << endl;

	cout << endl;
	_getch();
}

void pointer_example_1()
{
	//int a = 3, b = 5, *c = nullptr, *d = nullptr;
	////c = &(::a);
	//int* x = c + 1;
	////Asta genereaza eroare pt ca se modifica o valoare din zona de memorie apropiata de zona variabilei a
	////*x = 7;
	//d = &b;

	//int s_a = sizeof(int), s_b = sizeof(b);

	//printf("%h\n", *c);
}
