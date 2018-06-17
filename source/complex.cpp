#include "complex.hpp"
Complex::Complex():Re(0.0),Im(0.0){};
Complex::Complex(double re, double im): Re(re), Im(im){}
Complex::Complex(const Complex& other): Re(other.Re), Im(other.Im){}

void Complex::print(ostream& os){
    if(Im < 0){
        os << Re << Im << "i" << endl;
    }else{
        os << Re <<"+"<< Im << "i" << endl;
    }
}

double Complex::real(){
    return Re;
}
double Complex::imaginary(){
    return Im;
}


Complex Complex::add(const Complex& other){
    return Complex(Re+other.Re, Im+other.Im);
}
Complex Complex::sub(const Complex& other){
    return Complex(Re-other.Re, Im-other.Im);
}
Complex Complex::mul(int number){
    return Complex(Re*number, Im*number);
}
Complex Complex::div(int number){
    try{
        if(number == 0){
            throw 1;
        }
        Re = Re/number;
        Im = Im/number;
    }catch (int number){
        cout << "Division by zero" << endl;

    }
    return Complex(Re, Im);
}

Complex Complex::operator*(const Complex& other){
    return Complex(Re*other.Re - Im*other.Im, Im*other.Re + Re*other.Im);
}
Complex Complex::operator/(const Complex& other){
    return Complex((Re*other.Re + Im*other.Im)/(other.Re*other.Re + other.Im*other.Im),(-Re*other.Im + Im*other.Re)/(other.Re*other.Re + other.Im*other.Im));
}
Complex Complex::operator+=(const Complex& other){
    Re += other.Re;
    Im += other.Im;
    return Complex(Re, Im);
}
Complex Complex::operator-=(const Complex& other){
    Re -= other.Re;
    Im -= other.Im;
    return Complex(Re, Im);
}
Complex Complex::operator*=(const Complex& other){
    double  tmp;
    tmp = Re*other.Re - Im*other.Im;
    Im = Im*other.Re + Re*other.Im;
    Re = tmp;
    return Complex(Re,Im);
}
Complex Complex::operator/=(const Complex& other){
    double tmp;
    tmp = (Re*other.Re + Im*other.Im)/(other.Re*other.Re + other.Im*other.Im);
    Im =  (-Re*other.Im + Im*other.Re)/(other.Re*other.Re + other.Im*other.Im);
    Re = tmp;
    return Complex(Re,Im);
}
Complex Complex::operator=(const Complex& other){
    Re = other.Re;
    Im = other.Im;
    return Complex(Re,Im);
}
bool Complex::operator==(const Complex& other){
    return (Re == other.Re && Im == other.Im);
}
template <class CharT, class Traits>

basic_ostream<CharT, Traits>& operator<<(basic_ostream<CharT, Traits>& os, const Complex& other) {

	if (other.Im < 0)

	{

		os << other.Re << other.Im << "i" << std::endl;

	}

	else

	{

		os << other.Re << "+" << other.Im << "i" << std::endl;

	}

	return os;

}



template <class CharT, class Traits>

basic_istream<CharT, Traits>& operator>>(basic_istream<CharT, Traits>& is, Complex& other) {

	cout << "Введите дeйcтвительную и мнимую части числа: ";

	is >> other.Re >> other.Im;

	return is;

};
