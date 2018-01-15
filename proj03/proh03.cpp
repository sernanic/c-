#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
#include <math.h>
using namespace std;
long biggest_prime(long initial_input){
    long x = 2;
   while(initial_input >x ){
       if (initial_input%x==0){
            initial_input /= x;
            x = 2;
       }
       else{
           x++;
       }
       
   
    }
    return initial_input;
}
long sum_of_divisors(long initial_input){
    long sum_of_divisors = 0;
    for(auto i = 2; i<pow(initial_input,0.5);i++){
        if(initial_input%i==0){
            sum_of_divisors += i;
            sum_of_divisors += initial_input/i;
        }
    }
    sum_of_divisors = sum_of_divisors + 1+ initial_input;
    return sum_of_divisors;
}
long  k_hyperperfect(long initial_input,long k_max){
    for(long i = k_max; i >= 1;i--){
        if(initial_input == 1+i*(sum_of_divisors(initial_input)-initial_input-1)){
            return i;
        }
    }
    return 0;
}
 bool b_smooth(long n,long b){
     if(biggest_prime(n) == b || biggest_prime(n) < b){
         return true;
     }
     else{
         return false;
     }
 }
int main(){
    long initial_input = 0,k_max = 0,b=0;
    
    cin>>initial_input;
    cin>>k_max;
    cin>>b;
    cout<<biggest_prime(initial_input)<<" ";
    cout<<sum_of_divisors(initial_input)<<" ";
    cout<<k_hyperperfect(initial_input,k_max)<<" ";
    cout<<boolalpha<<b_smooth(initial_input,b)<<" "<<endl;
    return 0;
}