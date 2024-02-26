#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
using std::ofstream;
using std::to_string;
using std::string;
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
    xmin = miu - 4*sigma  y xmax = miu + 4*sigma.
    Para más información, puede consultar "68–95–99.7 rule".
    Con 3 sigma también funciona, pero 4 sigma da un mejor coeficiente de correlación.
  */

  //Variables del histograma.

  //Se inicializan xmin y xmax de acuerdo a lo explicado.
  xmin = mu - 4.0*sigma;
  xmax = mu + 4.0*sigma;

  vector<int> hist(nbins,0); //Se crea el arreglo que alamcenará las frecuencias. El histograma tiene nbins cajas y se inicializa en 0.

  double anchoInt = (xmax - xmin)/nbins; //Se calcula el ancho del intervalo para luego calcular las cajas.



  /*

    Se puede calcular el ancho del intervalo usando criterio de Sturges y demás, sin hacer uso de nbins, pero el ancho del intervalo
    dado por nbins es más pequeño, lo cual para este caso nos aporta más y mejor información.
    double rango = xmax-xmin;
    double clases = 1 + log(nsamples)/log(2); //Calculado con criterio de Sturges.
    double ancho2 = rango/clases;
  */


  int controlVar = 0; //Controla cuántos datos quedaron por fuera.

  for (int n=0;n<nsamples;++n) {
    double r = dis(gen);

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

  /*
    Código para verificar el ancho, intervalos, conteos y número de datos ignorados.
    cout<<"Ancho: "<<anchoInt<<endl;

    for (int i=0;i<nbins;i++) {
    cout<<"[ "<<xmin+i*anchoInt<<","<<xmin + (i+1)*anchoInt<<" ]"<<" : "<<hist[i]<<endl;;
    }


    cout<<"Datos ignorados: "<<controlVar<<endl;

  */



  //Compute and print the pdf.

  /*
    Tenemos que para hallar la probabilidad empírica, debemos dividir las frecuencias del histograma por el número total de datos: (hist[i]/nsamples).
    Luego, para obtener la densidad empírica, batsta dividir la probabilidad empírica entre el ancho del intervalo: ((hist[i]/nsamples)/anchoInt).
    Así, se asigna cada valor de densidad empírica al valor central de cada intervalo.
  */


  string dataName = "data" + to_string(seed) + ".txt";
  ofstream fout;
  fout.open(dataName);


  double SUM = 0.0; //Variable para verificar que SUM*anchoInt sea igual a 1.

  for (int i=0;i<nbins;i++) {

    double xavg = ((xmin+i*anchoInt) + (xmin + (i+1)*anchoInt))/2.0; //Calcula el valor central del intervalo
    double conversion =  static_cast<double>(1.0/(nsamples*anchoInt));
    double pdfi = hist[i]*conversion; //Valor de la función de densidad de probabilidad.
    fout<<xavg<<"\t"<<"\t"<<pdfi<<endl;
    SUM += pdfi;
  }
  fout.close();
  //cout<<"Suma :"<<SUM*anchoInt<<endl; //Este valor debería ser 1.

}

/*
  Código de Python usado para graficar: Graphics.py

import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit


# Se define la función de ajuste:
def gaussiana(x, mu, sigma, A):
    return A * np.exp(-0.5 * ((x - mu) / sigma)**2)


#Se leen los datos de cada semilla:
x, pdf1 = np.genfromtxt('data1.txt', unpack=True, usecols=(0, 1))

pdf2 = np.genfromtxt('data2.txt', unpack=True, usecols=(1))

pdf3 = np.genfromtxt('data5.txt', unpack=True, usecols=(1))


# Se obtienen los parámetros de ajuste.
parametros1, matrizCov1 = curve_fit(gaussiana, x, pdf1, p0=[3.1, 0.7, 1])
parametros2, matrizCov2 = curve_fit(gaussiana, x, pdf2, p0=[3.1, 0.7, 1])
parametros3, matrizCov3 = curve_fit(gaussiana, x, pdf3, p0=[3.1, 0.7, 1])

#Se calcula R^2, el coeficiente de correlación para cada ajuste haciendo uso de la suma de la suma residual de los cuadrados
#y la suma total de cuadrados, que es proporcional a la varianza.

pdf1Ajustado = gaussiana(x, *parametros1)
sumaResidual1 = np.sum((pdf1 - pdf1Ajustado)**2)
varianzaTotalpdf1 = np.sum((pdf1 - np.mean(pdf1))**2)

R2_1 = 1 - sumaResidual1 / varianzaTotalpdf1

pdf2Ajustado = gaussiana(x, *parametros2)
sumaResidual2 = np.sum((pdf2 - pdf2Ajustado)**2)
varianzaTotalpdf2 = np.sum((pdf2 - np.mean(pdf2))**2)

R2_2 = 1 - sumaResidual2 / varianzaTotalpdf2

pdf3Ajustado = gaussiana(x, *parametros3)
sumaResidual3 = np.sum((pdf3 - pdf3Ajustado)**2)
varianzaTotalpdf3 = np.sum((pdf3 - np.mean(pdf3))**2)

R2_3 = 1 - sumaResidual3 / varianzaTotalpdf3


# Imprimir los parámetros óptimos del ajuste y R^2
print("Parámetros óptimos del ajuste gaussiano 1 (mu, sigma,A):", parametros1)
print("Coeficiente de determinación R^2_1:", R2_1)

print("Parámetros óptimos del ajuste gaussiano 2 (mu, sigma,A):", parametros2)
print("Coeficiente de determinación R^2_2:", R2_2)

print("Parámetros óptimos del ajuste gaussiano 3 (mu, sigma,A):", parametros3)
print("Coeficiente de determinación R^2_3:", R2_3)




#Ajustes y gráficas:

plt.style.use('seaborn-v0_8')

fig, axes = plt.subplots(figsize=(6, 7))

axes.plot(x, pdf1, '.', label=r'$f(x)$. Semilla: 1',color="cadetblue")
axes.plot(x, pdf1Ajustado, label=r'Curva ajuste. Semilla 1',color="cadetblue")

axes.plot(x, pdf2, '*', label=r'$f(x)$. Semilla: 2', color="crimson")
axes.plot(x, pdf2Ajustado, label=r'Curva ajuste. Semilla 2', color="crimson")

axes.plot(x, pdf3, '^', markersize = 5, label=r'$f(x)$. Semilla: 5', color='black')
axes.plot(x, pdf3Ajustado, label=r'Curva ajuste. Semilla 5', color="black")


# Se ajustan demás detalles del gráfico.
axes.set_xlabel('x', fontsize=12)
axes.set_ylabel(r'$f(x)$: Densidad de probabilidad.', fontsize=12)
# axes.legend(loc='upper left')
axes.grid(True, linestyle='--')
axes.set_title("Aproximación a funciones densidad \n de probabilidad para semillas 1,2 y 5.", fontsize=14)
axes.legend()
plt.tight_layout()
plt.show()
fig.savefig('random_pdf.pdf')
*/


// comment ////////////////////////////////////////////////////////////////////

/* Código de Makefile:

all: random_pdf.pdf

random_pdf.x: random_pdf.cpp
	g++ random_pdf.cpp -o random_pdf.x

data1.txt data2.txt data5.txt: random_pdf.x
	./random_pdf.x 1 5000 3.5 0.4 2.7 4.6 50
	./random_pdf.x 2 5000 3.5 0.4 2.7 4.6 50
	./random_pdf.x 5 5000 3.5 0.4 2.7 4.6 50

random_pdf.pdf: data1.txt data2.txt data5.txt
	python3 Graphics.py

*/
