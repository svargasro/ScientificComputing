/*
  Se varía la semilla para ver, que aunque los datos sean diferentes,
  siguen la misma distribución aleatoria.


  Debo:
  - Adaptar el código para crear un histograma y a partir de él la
  función de probabilidad e imprimirlo en un ARCHIVO. (Para varias semillas)

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
#include <cmath>
#include <fstream>
#include <string>
using std::ofstream;
using std::to_string;
using std::string;
using std::log;
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

  //Se inicializan xmin y xmax de acuerdo a lo explicado.
  xmin = mu - 3.0*sigma;
  xmax = mu + 3.0*sigma;

  vector<int> hist(nbins,0); //Se crea el arreglo que alamenará las frecuencias. El histograma tiene nbins cajas y se inicializa en 0.

  double anchoInt = (xmax - xmin)/nbins; //Se calcula el ancho del intervalo para luego calcular las cajas.



  /*
  Se puede calcular el ancho del intervalo para no obtener basado en nbins, pero para la cantidad de datos que se manejan,
  es preferible usar el basado en nbins puesto que es más pequeño que el obtenido usando criterio de Sturges y demás.

  double rango = xmax-xmin;
  double clases = 1 + log(nsamples)/log(2); //Calculado con criterio de Sturges.
  double ancho2 = rango/clases;
  */


int controlVar = 0; //Controla cuántos datos quedaron por fuera.

  for (int n=0;n<nsamples;++n) {
    double r = dis(gen);
//    cout<<r<<endl;


    if(r==xmax) {
      hist.back()+=1;
      continue;
        } //Se toma el caso en que r==xmax aparte porque en el for siguiente no se toma en cuenta ese valor.


    if(r>xmax or r<xmin){ controlVar+=1; continue;} //Si un valor está fuera del rango, no se usa en la muestra.
    else {
      //Se recorre un for, tomando los intervalos cerrados por izquierda.
      for(int i=0; i<nbins; i++){
        if(r>= (xmin+ i*anchoInt ) and r < (xmin + (i+1)*anchoInt)) {
          hist[i]+=1; //Si cumple la condición, se suma 1 al intervalo correspondiente.
          break; //Se rompe el segundo bucle en caso de que encuentre un valor que cumpla las conidiciones.
        }
      }

    }

  }

//  cout<<"Ancho: "<<anchoInt<<endl;

                             // for (int i=0;i<nbins;i++) {
                             //    cout<<"[ "<<xmin+i*anchoInt<<","<<xmin + (i+1)*anchoInt<<" ]"<<" : "<<hist[i]<<endl;;

                             // }


//cout<<"Datos ignorados: "<<controlVar<<endl;



                             // for (int i=0;i<nbins;i++) {
                             //   cout<<"[ "<<xmin+i*anchoInt<<","<<xmin + (i+1)*anchoInt<<" ]"<<" : ";
                             //                                                            for (int j=0;j<hist[i];j++ ) {
                             //                                                              cout<<"*";
                             //                                                            }
                             //                                                                cout<<endl;
                             // }



//Compute and print the pdf.

/*
Tenemos que para hallar la probabilidad empírica, debemos dividir las frecuencias del histograma por el número total de datos (hist[i]/nsamples).
Luego, para obtener la densidad empírica, batsta dividir la probabilidad empírica entre el ancho del intervalo ((hist[i]/nsamples)/anchoInt)
Y se asigna cada valor de densidad empírica al valor central de cada intervalo.
*/

//cout<<typeid(conversion).name()<<endl;


string dataName = "data" + to_string(seed) + ".txt";
ofstream fout;
fout.open(dataName);


  double SUM = 0.0;
for (int i=0;i<nbins;i++) {

  double xavg = ((xmin+i*anchoInt) + (xmin + (i+1)*anchoInt))/2.0;
  double conversion =  static_cast<double>(1.0/(nsamples*anchoInt));
  double pdfi = hist[i]*conversion;
  fout<<xavg<<"\t"<<"\t"<<pdfi<<endl;
  SUM += pdfi;
 }
fout.close();
//cout<<"Suma :"<<SUM*anchoInt<<endl; //Este valor debería ser 1.



}
