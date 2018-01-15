#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
#include <math.h>
using std::setprecision;
int main() {
    int initial_input;
    cin>>initial_input;
    //bypass negative numbers
    if(initial_input >0){
        int n = 1, w =1;
        int count = 1,second_count = 1;
        int answer,second_answer;
        //begining of while loop to find numbers divisible by n
        while(n != initial_input){
            answer = initial_input%n;
            if(answer == 0){
                count =count+1;
            }
            n++;
        }
        //end of while loop
        int biggest_count = 0,biggest_number = 0,final_count = 0,final_number = 0;
        int new_variable = initial_input -1;
        //begining of while loop to find numbers divisible till n-1
        while(w != initial_input){
            if(new_variable == w){
                if(second_count > biggest_count){
                    biggest_number = new_variable;
                    biggest_count = second_count;
                }
                else if(biggest_count == second_count){
                    biggest_number = new_variable;
                    second_count = 1;
                    new_variable--;
                    w = 1;
                }
                else{
                    second_count = 1;
                    new_variable--;
                    w = 1;
                }
            }
            else{
                if(new_variable%w == 0){
                    second_count++;
                }
                w++;
            }
        }
            //end of while loop
        //end of while loop
        //compare counts from both while loops
        if(biggest_count >= count){
            cout<<"False "<<initial_input<<" "<<biggest_number<<" "<<biggest_count<<endl;
        }else{
            cout<<"True "<<initial_input<<" "<<count<<endl;
    }
}//end of if statement
else{
    cout<<"Error"<<endl;
}
}