#include <iostream>
#include <chrono>
#include <eigen/Eigen/Dense>


int main(){

auto start = std::chrono::steady_clock::now();

std::cout<<"Sí";
auto end = std::chrono::steady_clock::now();

std::cout<<std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<"\n";

    Eigen::MatrixXd m(2, 2);
    m(0, 1) = -9.877;
    std::cout << m << std::endl;

    return 0;







}
