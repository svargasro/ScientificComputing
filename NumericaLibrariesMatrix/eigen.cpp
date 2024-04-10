#include <iostream>
#include <chrono>

int main(){

auto start = std::chrono::steady_clock::now();

std::cout<<"Sí";
auto end = std::chrono::steady_clock::now();

std::cout<<std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<"\n";

}
