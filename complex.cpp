#include <iostream>
#include "complex.hpp"

int main(void)
{
	using com = complex<double>;

	com c3(2.1, 3.4);
	com c2(4.7, -5.1);
	const double d = -3.4;

	//Costruttore default
	com c0 = complex<double>();
	std::cout << "Costruttore di default:\n" << "c0 = " << c0 << std::endl;

	//Costruttore user defined
	com c1 = complex(-7.0, -12.0);
	std::cout << "Costruttore user-defined:\n" << "c1 = " << c1 << std::endl;

	//Overload Stampa per positivi e negativi
	std::cout << "Overload di stampa:\n" << "c2 = " << c2 << std::endl;
	std::cout << "c3 = " << c3 << std::endl;

	//Estrarre Parte reale, Parte Immaginaria, Coniugato
	std::cout << "Estrazione di Parte Reale, Parte Immaginaria e Costruzione del Complesso Coniugato:\n" << "Parte reale di c1 = " << c1.Re() << "\nParte immaginaria di c1 = " << c1.Im() << std::endl;
	std::cout << "Complesso coniugato di c1 = " << c1.conjugate() << std::endl;

	//Somma e prodotto tra complex
	std::cout << "Somma e prodotto tra due numeri complessi:\n" << "(" << c1 << ") + (" << c2 << ") = (" << c1+c2 << ")" << std::endl;
	std::cout <<  "(" << c1 << ") * (" << c2 << ") = (" << c1*c2 << ")" << std::endl;

	//Somma commutativa tra complex e T
	std::cout << "Somma(commutativa) tra un numero complesso e un tipo floating_point:\n" << "(" << c1 << ") + (" << d << ") = (" << c1+d << ")" << std::endl;
	std::cout <<  "(" << d << ") + (" << c1 << ") = (" << d+c1 << ")" << std::endl;

	//Prodotto commutativo tra complex e T
	std::cout << "Prodotto(commutativo) tra un numero complesso e un tipo floating_point:\n" << "(" << c1 << ") * (" << d << ") = (" << c1*d << ")" << std::endl;
	std::cout <<  "(" << d << ") * (" << c1 << ") = (" << d*c1 << ")" << std::endl;
	
}