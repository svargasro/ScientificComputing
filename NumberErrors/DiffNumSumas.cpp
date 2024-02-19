#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;


float s1(int N){
  float s1 = 0;

  for (int k=1; k<=N ;k++) {

    s1+= 1.0/k;
  }
          return s1;
}

  float s2(int N){
      float s2 = 0;

      for (int k=N; k>0 ;k--) {
        s2+= 1.0/k;

      }

      return s2;
    }


int main(int argc, char *argv[]) {

  int N = std::stoi(argv[1]);

  float sum1;
  float sum2;
  float relativDif;

  for (int i=1; i<=N ; i++ ) {
    sum1=s1(N);
    sum2=s2(N);
    relativDif = std::abs(1.0 - sum1/sum2);
    cout<<i<<" "<<sum1<<" "<<sum2<<" "<<" "<<relativDif<<" "<<endl;
  }



                                                         return 0;
}
