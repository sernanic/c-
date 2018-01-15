#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
#include <math.h>
using std::setprecision;

double additionAnswerReal(double a,double b){
    double Result;
    Result = a + b;
    return Result;
}
double additionAnswerImaginary(double c,double d){
    double Result;
    Result = c + d;
    return Result;
}
double subtractionAnswerReal(double a,double b){
    double Result;
    Result = a - b;
    return Result;
}
double subtractionAnswerImaginary(double c,double d){
    double Result;
    Result = c - d;
    return Result;
}

double multiplicationAnswerReal(double a,double b,double c,double d){
    double Result;
    Result = (a * c) - (b * d);
    return Result;
}
double multiplicationAnswerImaginary(double a,double b,double c,double d){
    double Result;
    Result = (b * c) + (a * d);
    return Result;
}
double divisionAnswerReal(double a,double b,double c,double d){
    double Result;
    Result = (a*c+b*d)/(pow(c,2) + pow(d,2));
    return Result;
    
}
double divisionAnswerImaginary(double a,double b,double c,double d){
    double Result;
    Result = ((b * c) - (a * d))/(pow(c,2) + pow(d,2));
    return Result;
}

int main() {
    cout << fixed << setprecision(2);
    double a,c;
    double b, d;
    //recieves input
    cin>>a>>b;
    cin>>c>>d;
    //addition Answer
    cout<<additionAnswerReal(a,c)<< " + "<< additionAnswerImaginary(b,d)<<"i"<<endl;
    //subtraction Answer
    cout<<subtractionAnswerReal(a,c)<< " + "<< subtractionAnswerImaginary(b,d)<<"i"<<endl;
    //multiplication Answer
    cout<<multiplicationAnswerReal(a,b,c,d)<<" + "<<multiplicationAnswerImaginary(a,b,c,d)<<"i"<<endl;
    //division Answer
    cout<<divisionAnswerReal(a,b,c,d)<<" + "<<divisionAnswerImaginary(a,b,c,d)<<"i"<<endl;
    
    
    
    return 0;
}