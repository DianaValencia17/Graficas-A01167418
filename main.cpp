/*********************************************************
Materia: Graficas computacionales
Fecha: 14 de agosto de 2017
Autor: Diana Laura Valencia Dominguez A01167418
*********************************************************/
//
//  Tarea1 Diana Valencia.cpp
//  DianaValenciaTarea1
//
//  Created by Diana Valencia  on 2017-08-14.
//
//

#include <iostream>
using namespace std;

class Ejercicios1 {
public:
	// Perimetro rectangulo
	int PerimetroRectangulo(int base, int altura) {
		int p = (base + altura) * 2;
		return p;
	}
public:
	// Area rectanculo
	float AreaRectangulo(float base, float altura) {
		float a = (base *  altura) / 2;
		return a;
	}
public:
	// Numero mayor
	int Mayor(int n1, int n2, int n3) {
		if (n1>n2 && n1>n3) {
			return n1;
		}
		else if (n2>n1 && n2>n3) {
			return n2;
		}
		else if (n3>n1 && n3>n2) {
			return n3;
		}
	}
public:
	// Numero menor
	int Menor(int n1, int n2, int n3) {
		if (n1<n2 && n1<n3) {
			return n1;
		}
		else if (n2<n1 && n2<n3) {
			return n2;
		}
		else if (n3<n1 && n3<n2) {
			return n3;
		}
	}
public:
	// Fila estrellas
	void FilaEstrellas(int n) {
		int cont = 0;
		while (cont <= n) {
			cout << "*";
			cont++;
		}
	}
public:
	// Matiz estrellas
	void MatrizEstrellas(int n) {
		int cont, cont2;
		for (cont = 0; cont <= n; cont++) {
			cout << "\n";
			cont2 = 0;
			while (cont2 <= n) {
				cout << "*";
				cont2++;
			}
		}
	}
public:
	//Piramide estrellas
	void PiramideEstrellas(int n) {
		int cont = 0, cont2 = 0;
		for (cont; cont < n; cont++) {
			cont2 = 0;
			while (cont2 <= cont) {
				cout << "*";
				cont2++;

			}cout << "\n";
		}
	}

public:
	//Piramide estrellas
	void FlechaEstrellas(int n) {
		int cont = 0, cont2 = 0;
		for (cont; cont < n; cont++) {
			cont2 = 0;
			while (cont2 <= cont) {
				cout << "*";
				cont2++;

			}cout << "\n";
		}

		for (cont = n-1; cont >= 0; cont--) {
			cont2 = cont;
			while (cont2 > 0) {
				cout << "*";
				cont2--;

			}cout << "\n";
		}
	}
public:
	// Sucesión Fibonacci
	void Fibonacci(int n) {
		int num1 = 1, num2 = 1, suma=1, r;
		cout << num1;
		for (r = 1; r < n; r++) {
			cout << " " << suma;
			suma = num1 + num2;
			num1 = num2;
			num2 = suma;
		}
		cout << "\n";
		}
public:
	// Numero Primo
	bool EsPrimo(int n) {
		if (n == 2 || n == 3) {
			cout << "true" << "\n";
			return true;
		}if (n % 2 != 0 && n % 3 != 0) {
			cout << "true" << "\n";
			return true;
		}
		else cout << "false" << "\n";
		return false;
	}
};
int main() {
	Ejercicios1 ej1;
	cout << "El perimetro es: \n";
	int perimetro = ej1.PerimetroRectangulo(5, 3);
	cout << perimetro;

	cout << "\nEl area es: \n";
	int area = ej1.AreaRectangulo(5.0f, 3.0f);
	cout << area;

	cout << "\nEl numero mayor es: \n";
	int mayor = ej1.Mayor(5, 9, 1);
	cout << mayor;

	cout << "\nEl numero menor es: \n";
	int menor = ej1.Menor(5, 9, 1);
	cout << menor;

	cout << "\n";
	ej1.FilaEstrellas(5);

	cout << "\n";
	ej1.MatrizEstrellas(4);

	cout << "\n";
	ej1.PiramideEstrellas(6);

	cout << "\n";
	ej1.FlechaEstrellas(3);

	cout << "\n Sucesion Fibonacci: \n";
	ej1.Fibonacci(9);

	cout << "\n Es primo: \n";
	ej1.EsPrimo(79);

	cout << "\n Es primo:\n";
	ej1.EsPrimo(52);



	std::cin.get();
}

