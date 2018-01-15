#include<iostream>
using std::cout; using std::endl;using std::cin;
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
#include <fstream>
//#include "proj10_package.cpp"
#include "proj10_package.h"
#include "proj10_knapsack.h"

Knapsack::Knapsack(size_t wlimit){
    /*the arg wlimit is the maximum weight the Knapsack can take, no default
    thus initializes weight_limit_ and the other variables
    */
    
    weight_limit_ = wlimit;
    capacity_ = 10;
    size_ = 0;
    data_ = new Package[capacity_];
}
Knapsack::~Knapsack(){
    delete  []data_;
}

Knapsack::Knapsack(size_t wlimit, size_t cap){
    weight_limit_ = wlimit;
    capacity_ = cap;
    size_ = 0;
    data_ = new Package[capacity_];
}
Knapsack::Knapsack(const Knapsack& initial){
        
       
    data_ =new Package[initial.capacity_];
    copy(initial.data_, initial.data_+initial.size_, data_);
    weight_limit_ = initial.weight_limit_;
    capacity_ = initial.capacity_;
    size_ = initial.size_;
}
long Knapsack::capacity() const{
    /*return the present capacity_ of the underlying array, the number of Packages the array could
hold before having to grow.*/
    return capacity_;
}
long Knapsack::size() const{
    //return the present size_ , the number of Packages presently in the underlying array.
    return size_;
}
long Knapsack::weight_limit() const{
    //return the present weight_limit that is set for this Knapsack instance.
    return weight_limit_;
}
bool Knapsack::empty() const{
    //checks if the data_array is empty or not
    if(size_==0){
        return true;
    }
    return false;
}
bool Knapsack::add(const Package& new_package){
    //adds a Package to the data_ array
  if(this->weight() + new_package.weight_ > weight_limit_){
        return false;
    }
    Package *new_ary;

  if (size_ == 0){
    new_ary = new Package[1]{};
    size_ = 1;
    std::swap(data_,new_ary);
    data_[size_-1] = new_package;
  }
  else{
      /*in this instance the capacity of the array is doubled if 
      if the size exceeds the capacity
      */
    new_ary = new Package[size_ * 2]{};
    new_ary[size_] = new_package;
    copy(data_, data_+size_, new_ary);
    size_ *= 2;
    std::swap (new_ary, data_);
    long new_size = 0;
    for(auto i = 0;i < size_;i++){
        if(data_[i].weight_!= 0){
            new_size++;
        }
    }
    size_ = new_size;
    if(size_>capacity_){
        capacity_*=2;
    }
    delete [] new_ary;
  }
    return true;
}
long Knapsack::weight() const{
    //obtains the total weight of the arry
    long weight = 0;
    for(auto i = 0; i <size_;++i){
        weight = weight + data_[i].weight_;
    }
    return weight;
    
}
long Knapsack::priority() const{
    //obtains the total priority of the array
    long priority = 0;
    for(auto i = 0; i <size_;++i){
        priority = priority + data_[i].priority_;
    }
    return priority;
}
ostream& operator<<(ostream& out, Knapsack &ks){
//outputs the contents of the array in the following format: weight:priority,
    string new_string = "";
    for(auto i = 0; i < ks.size_ ; i++){
        new_string += to_string(ks.data_[i].weight_)+":"+to_string(ks.data_[i]          .priority_)+", ";
    }
    new_string = new_string.substr(0,new_string.length()-2);
    out<<new_string;
    return out;
}
void solve_KS(string file_str, Knapsack&ks){
    //adds the Package from a file to the data_ array in a sorted manner
    std::ifstream inFile;
    inFile.open(file_str);
    string line;
    string string_weight;
    string string_priority;
    int index = 0;
    vector<Package> v;
    long weight_result = 0;
    long priority_result = 0;
    if(inFile.fail()){
        throw std::runtime_error("nope");
    }
    if (inFile && v.size() == 0){
        while(getline(inFile,line)){
            weight_result = stol(line.substr(0,line.find(" ")));
            priority_result = stol(line.substr(line.find(" "),line.length()));
            Package P1(weight_result,priority_result);
            v.push_back(P1);
            index++;;
        }
        sort(v.begin(), v.end(), package_compare);
        bool new_bool = true;
        for(auto i = 0; i<index;i++){
            new_bool = ks.add(v[i]);
            if(new_bool == false){
                break;
            }
        }
  }
  else{
        throw std::runtime_error("hello");
   }
   inFile.close();
}

