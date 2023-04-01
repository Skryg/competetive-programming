#include <iostream>
#include <complex>
using namespace std;
typedef std::complex<double> Zespolona;

// Funkcja szablonowa gdzie T jest typem przekazanego argumentu
template <typename T>
T fun (T x){
	return exp(sin(exp(cos(x) + 2.0*x*x*x*x*x)));
}
// Liczy iloraz różnicowy dla fukcji fun w punkcie x0 i dla przyrostu h
double iloraz(double x0, double h){
	return(fun(x0+h)-fun(x0))/(h);
	
}

// Liczy iloraz różnicowy wykorzystując "trick" zespolony
// dla fukcji fun w punkcie x0 i dla przyrostu h
double ilorazZespolony(double x0, double h){
	return imag(fun(x0+h*complex<double>(0,1)))/h;
	
}

int main(){
	cout.precision(17);
	double x0, h;
	int N;
	cin >> x0 >> N;
	for(int i=0; i<N; i++){
		cin >> h;
		cout << iloraz(x0, h) <<  " " << ilorazZespolony(x0, h) << endl;
	}
	return 0;
}
