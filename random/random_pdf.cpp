/*
  Se varía la semilla para ver, que aunque los datos sean diferentes,
  siguen la misma distribución aleatoria.


  Debo:
  - Adaptar el código para crear un histograma y a partir de él la
  función de probabilidad e imprimirlo en un archivo. (Para varias semillas)

  - Crear una figura con las 3 pdf en la misma.

  - No guardar muestras.

  - vector<int> es histograma de conteo, muestra las veces que cae
  una muestra en caja dada. -> Con esto se calcula la pdf.

  - Código calcula NSAMPLES muestras de la distribución normal,
  para una semilla dada.


*/
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
using std::cout;
using std::endl;

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);


int main(int argc, char *argv[]) {

  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const int MU = std::atoi(argv[3]);
  const int SIGMA = std::atoi(argv[4]);
  const int XMIN = std::atoi(argv[5]);
  const int XMAX = std::atoi(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED,NSAMPLES,MU,SIGMA,XMIN,XMAX,NBINS);


  return 0;
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins){
  //random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu,sigma};

  cout<<dis<<endl;
  //TODO: histogram stuff

  for (int n=0;n<nsamples;++n) {
    double r = dis(gen);
    //TODO: fil here the counting histogram stuff
  }


//TODO: compute and print the pdf.

}
