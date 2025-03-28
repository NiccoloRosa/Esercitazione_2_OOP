#pragma once 

template <typename T> requires std::floating_point<T>
class complex
{
	//Private members
	T z_Re, z_Im;

	public:
		//Costruttore di default:
		complex()
			: z_Re(0.0), z_Im(1.0)
		{}

		explicit complex(T n) : z_Re(n), z_Im(0.0)
		{
			std::cout << "converting constructor called" << std::endl;
		}

		//Costruttore user-defined. Prende due parametri:parte reale e parte immaginaria
		complex(T r, T i)
			: z_Re(r), z_Im(i)
		{}

		//Restituire parte reale.il 'const' indica che la funzione non modifica l'istanza su cui è chiamata
		T Re(void) const
		{
			return z_Re;
		}

		//Restituire parte immmaginaria.il 'const' indica che la funzione non modifica l'istanza su cui è chiamata
		T Im(void) const
		{
			return z_Im;
		}
		//Restituire il coniugato. 
		complex conjugate(void) const
		{
			return complex(z_Re, -z_Im);
		}

		//Operatore +=. Prende un unico parametro 'other'di tipo complex:
		complex& operator+=(const complex& other) 
		{
			T a = z_Re;
			T b = z_Im;
			T c = other.z_Re;
			T d = other.z_Im;
			z_Re = a + c;
			z_Im = b + d;
			return *this;
		}

		//Operatore + definito a partire dall'operatore +=:
		complex operator+(const complex& other) const 
		{
			complex cpx = *this;
			cpx += other;
			return cpx;
		}

		//Operatore += tra un complex a sinistra e un T a destra. prende un solo parametro 'other' di tipo T:
		complex& operator+=(const T& other) 
		{
			z_Re += other;
			return *this;
		}

		//Operatore + tra un complex a sinistra e un T a destra a partire dall'operatore +=:
		complex operator+(const T& other) const 
		{
			complex cpx  = *this;
			cpx += other;
			return cpx;
		}

		//Operatore *=. Unico parametro di tipo complex
		complex& operator*=(const complex& other) 
		{
			T a = z_Re;
			T b = z_Im;
			T c = other.z_Re;
			T d = other.z_Im;
			z_Re = a*c - b*d;
			z_Im = a*d + b*c;
			return *this;
		}

		//Operatore * definito a partire dall'operatore *=:
		complex operator*(const complex& other) const 
		{
			complex cpx = *this;
			cpx *= other;
			return cpx;
		}

		//Operatore *= tra un complex a sinistra e un T a destra. prende un solo parametro 'other' di tipo T:
		complex& operator*=(const T& other) 
		{
			z_Re *= other;
			z_Im *= other;
			return *this;
		}

		//Operatore * tra un complex a sinistra e un T a destra a partire dall'operatore *=:
		complex operator*(const T& other) const 
		{
			complex cpx  = *this;
			cpx *= other;
			return cpx;
		}
};

//Operatore + definito fuori dalla classe complex per permettere la somma tra un T a sinistra e un complex detsra
template<typename T> complex<T>
operator+(const T& t, const complex<T>& c)
{
    return c + t;
}

//Operatore * definito fuori dalla classe complex per permettere il prodotto tra un T a sinistra e un complex detsra
template<typename T> complex<T>
operator*(const T& t, const complex<T>& c)
{
    return c * t;
}

/* Overload of <<, to make the rationals printable. */
template<typename T> std::ostream&
operator<<(std::ostream& os, const complex<T>& z) 
{
    if (z.Im() != 0)
		if (z.Re()!=0)
			if (z.Im() > 0)
				if(z.Re() > 0)
					os << "+" << z.Re() << " + " << z.Im() << "i";
				else 
					os << "-" << -z.Re() << " + " << z.Im() << "i";
			else
				if (z.Re() > 0)
					os << "+" << z.Re() << " - " << -z.Im() << "i";
				else 
					os << "-" << -z.Re() << " - " << -z.Im() << "i";
		else
			os << z.Im() << "i";
    else
        os << z.Re();

    return os;
}