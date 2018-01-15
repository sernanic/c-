#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
#include<cmath>
#include <iomanip>
#include <fstream>
#include <map>
using std::map;
using std::ostringstream;
using std::ifstream;
#include "proj08_twod.h"

TwoD::TwoD(double a, double b){
    x = a;
    y = b;
}

TwoD TwoD::diff (TwoD k){
    x = x - k.x; 
    y = y - k.y;
    return TwoD(x,y);
    
     
 }
 TwoD TwoD::mult (double a){
    x = x * a;
    y = y * a;
    return TwoD(x,y);
    
     
 }
 double TwoD::dot_product(TwoD k){
    auto m = x * k.x; 
    auto n = y * k.y;
    double result = m + n;
    return result;  
     
 }
 
 double TwoD::magnitude_squared(){
    return pow(x,2) + pow(y,2); 
   
 }
 string TwoD::to_string(){
     std::stringstream tmp;
     tmp << std::setprecision(2) << std::fixed << '('<<x<<", "<<y<<')';
     return tmp.str();
     
 }
