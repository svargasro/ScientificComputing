#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

double fun(double x);

void generate_data(double xmin, double xmax, double dx);





int main(int argc, char *argv[]) {

  double XMIN = std::stod(argv[1]);
  double XMAX = std::stod(argv[2]);
  double DX = std::stod(argv[3]);
  generate_data(XMIN, XMAX,DX);

  return 0;
}



double fun(double x){
  return std::sin(2*x);
}


void generate_data(double xmin, double xmax, double dx){

  std::ofstream fout;
  fout.open("data.txt");
  fout.precision(15);
  fout.setf(std::ios::scientific);


  for (double x=xmin; x<= xmax; x=x+dx){

    double deriv_f = (fun(x+dx)-fun(x))/dx;
    double deriv_c = (fun(x+dx)-fun(x-dx))/(2*dx);
    double deriv= 2*std::cos(2*x);
    double error_f = std::fabs(1.0 - deriv_f/(deriv));
    double error_c = std::fabs(1.0 - deriv_c/(deriv));


    fout << "\t" << x
         << "\t" << fun(x)
         << "\t" << deriv_f
         << "\t" << deriv_c
         << "\t" << error_f
         << "\t" << error_c

         <<std::endl;
  }

  fout.close();
}
