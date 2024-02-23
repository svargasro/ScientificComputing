#include <iostream>
#include <math.h>
#include <vector>

using std::cout;
using std::endl;
using std::vector;



vector<float> s1(int N){

  vector<float> s1Vector(N);

  float s1 = 0;
  for (int k=1; k<=N ;k++) {

    s1+= 1.0/k;
    s1Vector[k-1]=s1;

  }
  return s1Vector;
}

float s2(int N){

  //vector<float> s2Vector(N);
  float s2 = 0;

  for (int k=N; k>0 ;k--) {
    s2+= 1.0/k;
    //  s2Vector[N-k]=s2;
  }

  // return s2Vector;
  return s2;
}


int main(int argc, char *argv[]) {

  int N = std::stoi(argv[1]);
  //int N = 1e6;
  vector<float> sum1Vec = s1(N);
  //vector<float> sum2Vec = s2(N);

  float relativDif, sum1, sum2;

  for (int i=1; i<=N ; i++ ) {
    sum1= sum1Vec[i-1];
    sum2 = s2(i);
    //sum2= sum2Vec[i-1];
    relativDif = std::abs(1.0 - sum1/sum2);
    cout<<i<<" "<<sum1<<" "<<sum2<<" "<<" "<<relativDif<<" "<<endl;
  }



  return 0;
}



// Ejecutar en la consola de la forma ./a.out > data.txt

//Código de Python para graficar.

// import numpy as np
// import matplotlib.pyplot as plt


// n, relativDiff = np.genfromtxt('data.txt', unpack=True, usecols=(0, 3))

// plt.style.use('seaborn-v0_8')

// fig, axes = plt.subplots(figsize=(5, 6))

// axes.plot(n, relativDiff, '-', markersize=2, label=r'$\Delta$(N)')

// # Se ajustan demás detalles del gráfico.


// axes.set_xlabel('N', fontsize=12)
// axes.set_ylabel(r'$\Delta$: Diferencia relativa.', fontsize=12)
// # axes.legend(loc='upper left')
// axes.grid(True, linestyle='--')
// axes.set_title(f"Diferencia relativa vs N.", fontsize=14)
// plt.tight_layout()
// fig.savefig('Resultados.pdf')
// plt.show()
