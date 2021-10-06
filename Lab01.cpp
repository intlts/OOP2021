// Lab01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <conio.h>

using namespace std;

int var = 2021;

// Declararea functiilor

void print_data_types_sizes();
void scope_operator_example();
void pointers_example_2();
void pointers_example_1();
void pointers_example_3();
void pointers_example_4();

int main()
{
	// Functie care exemplifica utilizarea operatorului de scop
	scope_operator_example();

	// Functie care afiseaza dimensiunile tipurilor de date - in octeti (bytes)
	print_data_types_sizes();

	// Functie de exemplificare a utilizarii pointerilor - valori vs. adrese de memorie
	// Operatorul de adresare (referentiere) si operatorul de redirectare (dereferentiere)
	pointers_example_1();

	// Functie de exemplificare a operatiilor cu pointeri
	pointers_example_2();

 	pointers_example_3();

	pointers_example_4();

	_getch();
}


// Definirea functiilor

void print_data_types_sizes()
{
	// boolean - true sau false => 0 sau 1
	cout << "bool: " << sizeof(bool) << "   -   bool*: " << sizeof(bool*) << endl;

	// character
	cout << "char: " << sizeof(char) << "   -   char*: " << sizeof(char*) << endl;
	cout << "wchar_t: " << sizeof(wchar_t) << "   -   wchar_t*: " << sizeof(wchar_t*) << endl;

	// integer - valori intregi - fara virgula
	cout << "short: " << sizeof(short) << "   -   short*: " << sizeof(short*) << endl;
	cout << "int: " << sizeof(int) << "   -   int*: " << sizeof(int*) << endl;
	cout << "long: " << sizeof(long) << "   -   long*: " << sizeof(long*) << endl;
	cout << "long long: " << sizeof(long long) << "   -   long long*: " << sizeof(long long*) << endl;

	// floating point - valori care contin si parte fractionara
	cout << "float: " << sizeof(float) << "   -   float*: " << sizeof(float*) << endl;
	cout << "double: " << sizeof(double) << "   -   double*: " << sizeof(double*) << endl;
	cout << "long double: " << sizeof(long double) << "   -   long double*: " << sizeof(long double*) << endl;

	cout << endl;
	// _getch();
}

void scope_operator_example()
{
	int var = 1234;

	cout << "Variabila `var` locala - din scopul functiei curente: " << var << endl;
	cout << "Variabila `var` globala: " << ::var << endl;

	cout << endl;
	// _getch();
}

void pointers_example_1()
{
	// Se declara variabilele locale, vizibile doar in cadrul functiei - function scope
	// Se initializeaza fiecare variabila cu o valoare, in functie de tipul de date

	int a = 3;
	int b = 5;
	int var = 5478;
	int* ptr_a = nullptr;
	int* ptr_b = nullptr;
	int* ptr_var = nullptr;
	int* ptr_global_var = nullptr;
	char c = 'A';
	char* ptr_c = nullptr;

	// Se copiaza adresa variabilei a in variabila de tip pointer -> int *ptr_a
	ptr_a = &a;

	// Se copiaza adresa variabilei b in variabila de tip pointer -> int *ptr_b
	ptr_b = &b;

	// ...
	ptr_var = &var;

	//  ...
	ptr_global_var = &(::var);

	// ...
	ptr_c = &c;

	cout << endl << endl << "### Valorile stocate in variabile si adresele de memorie ale variabilelor" << endl;
	// Afisam valorile stocate si adresele de memorie pentru fiecare variabila
	cout << "a: " << "Valoarea: " << a << "  -  la adresa: " << ptr_a << endl;
	cout << "b: " << "Valoarea: " << b << "  -  la adresa: " << ptr_b << endl;
	cout << "var: " << "Valoarea: " << var << "  -  la adresa: " << ptr_var << endl;
	cout << "::var: " << "Valoarea: " << ::var << "  -  la adresa: " << ptr_global_var << endl;
	cout << "c: " << "Valoarea: " << c << "  -  la adresa: " << (void*)ptr_c << endl;  // De ce (void*)?  Discutie

	// _getch();

	cout << endl << endl << "### Reafisare folosind operatorul de dereferentiere =>  *" << endl;
	// Afisam valorile stocate si adresele de memorie pentru fiecare variabila - folosind referentierea + dereferentierea pentru a obtine valoarea variabilei
	cout << "a: " << "Valoarea: " << *ptr_a << "  -  la adresa: " << ptr_a << endl;
	cout << "b: " << "Valoarea: " << *ptr_b << "  -  la adresa: " << ptr_b << endl;
	cout << "var: " << "Valoarea: " << *ptr_var << "  -  la adresa: " << ptr_var << endl;
	cout << "::var: " << "Valoarea: " << *ptr_global_var << "  -  la adresa: " << ptr_global_var << endl;
	cout << "c: " << "Valoarea: " << *ptr_c << "  -  la adresa: " << (void*)ptr_c << endl;  // De ce (void*)?  Discutie

	cout << endl << endl;
}

void pointers_example_2()
{

	// In acest exemplu nu vom mai afisa valorile/adresele de memorie, vom utiliza doar depanatorul (debugger) din Visual Studio 2019


	// Se declara variabilele locale, vizibile doar in cadrul functiei - function scope
	// Se initializeaza fiecare variabila cu o valoare, in functie de tipul de date

	int a = 3, b = 5, var = 5478, *ptr_a = &a, *ptr_b = &b, *ptr_var = &var, *ptr_global_var = &(::var);

	char c = 'A', *ptr_c = nullptr;

	short s = 3, *ptr_s = &s;

	float f = 54.3, *ptr_f = &f;
	double d = 54.3, *ptr_d = &d;

	// Incrementare valoare (exemplificare cu/fara 
	*ptr_a++;

	*ptr_a--;

	(*ptr_a)++;

	// Incrementare adresa (se incrementeaza valoarea adresei => ptr_a va contine o alta adresa decat adresa de stocare a variabilei a)
	ptr_a++;

	ptr_a--;



	// Asemanator ... dar nu exact la fel:
	// Operatiile cu pointeri se executa tinand cont de dimensiunea tipului de date =>
	// A se observat diferenta dintre ++ aplicat pe int* vs short*

	*ptr_s++;

	*ptr_s--;

	(*ptr_s++);

	ptr_s++;


	// Salvarea unei adrese intr-o variabila de tip pointer
	int* ptr = ptr_b;

	ptr = ptr_b - 12; //  ptr <= ptr_b - 12*sizeof(int) - pentru ca ptr_b retine adresa variabilei b care este de tipul int

	ptr += 12; // Revenim la adresa anterioara - explicatie scurta +=

	int** ptr_ptr = &ptr; // ptr_ptr retine adresa de memorie in care este stocata valoarea variabilei ptr (ptr si ptr_b au valori egale) care retine adresa unde este stocata valoarea variabilei b;

						  // Cum accesam valoarea variabilei b ?
	cout << "Valoarea variabilei b este: " << **ptr_ptr << endl;
	cout << "Valoarea variabilei b este: " << b << endl;


	//// Similar cu float/double si char


	// # Exemplu de modificare a unei zonei de memorie care nu a fost anterior alocata

	// In variabila x de tip int* (pointer catre o adresa de memorie unde este stocata valoarea unei variabile de tip int) se copiaza adresa zonei de memorie vecina cu adresa variabilei a 
	int* x = ptr_a + 1;

	// Se modifica valoarea stocata la adresa salvata anterior in variabila x -  valoarea devine 7	
	// Aceasta modificare va genera o exceptie (in modul debugger) => discutie pe baza exceptiei generate - alocarea memoriei
	//*x = 7;
}

void pointers_example_3()
{
	int array_var[100] = { 0 };
	array_var[0] = 56;

	int* ptr_array_var = new int[100];
	ptr_array_var[0] = 56;
	ptr_array_var[1] = 123;
	*(ptr_array_var + 2) = 125;

	delete ptr_array_var;
}

void pointers_example_4()
{
	char* char_array = new char[17];

	for (int index = 0; index < 16; index++)
	{
		char_array[index] = 'a' + index;
	}

	cout << char_array;
	cout << endl;

	char_array[16] = '\0';

	cout << char_array;
	cout << endl;

	char_array = (char*)"Acesta este test";

	cout << char_array;
	cout << endl;

	char_array[16] = '\0';

	cout << char_array;
	cout << endl;

	_getch();
}
