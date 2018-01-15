#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include<string>
using std::string; using std::to_string;
#include<iomanip>
using std::boolalpha;
#include<cassert>
#include "proj10_package.h"
/*Package::Package(long w, long p){
    weight_ = w;
    priority_ = p;
}*/
ostream& operator<<(ostream& out, Package& p){
    out<<p.weight_<<":"<<p.priority_;
    return out;
}
bool package_compare(const Package &p1, const Package &p2){
    //we compare two packages based on their ratio of priority_/weight
    //compares the lhs Package with the argument rhs Package, returning true if     the lhs Package is larger (in priority_/weight_ ratio), false otherwise.
    //lhs rhs
    double lhs_ratio = double(p1.priority_)/double(p1.weight_);
    double rhs_ratio = double(p2.priority_)/double(p2.weight_);
    bool result = true;
    if(lhs_ratio >= rhs_ratio){
        result = true;
    }else{
        result = false;
    }
    return result;
}
/*int main(){
    Package hello(10,10);
    cout<<hello.weight_<<endl;
    return 0;
}*/