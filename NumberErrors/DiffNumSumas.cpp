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
