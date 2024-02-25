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
using std::vector;
using std::cout;
using std::endl;

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);


int main(int argc, char *argv[]) {

  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::stod(argv[3]);
  const double SIGMA = std::stod(argv[4]);
  const double XMIN = std::stod(argv[5]);
  const double XMAX = std::stod(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED,NSAMPLES,MU,SIGMA,XMIN,XMAX,NBINS);


  return 0;
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins){
  //random stuff
  std::mt19937 gen(seed); //Se crea una instancia del generador de números aleatorios.
  std::normal_distribution<double> dis{mu,sigma}; //Objeto que representa la distribución normal.
                                                  //Al generar números aleatorios usando dis, seguirán una distribución normal.

/*
Se tiene que en una distribución normal, aproximadamente el 95.45% de los datos se encuentran en el intervalo [miu - 2*sigma, miu + 2*sigma]
Por otro lado, aproximadamente el 99.73% de los datos se encuentran en el intervalo [miu - 3*sigma, miu + 3*sigma].
Por último, aproximadamente el 99.99% de los datos se encuentran entre [miu - 4*sigma, miu + 4*sigma], por lo cual tiene sentido tomar
xmin = miu - 3*sigma  y xmax = miu + 3*sigma.
Para más información, puede consultar "68–95–99.7 rule".
  */

  //Variables del histograma.
  xmin = mu - 3.0*sigma;
  xmax = mu + 3.0*sigma;




  for (int n=0;n<nsamples;++n) {
    double r = dis(gen);
    cout<<r<<endl;
    //TODO: fil here the counting histogram stuff
  }






//TODO: compute and print the pdf.

}
