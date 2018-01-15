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
#include "proj07_functions.h"

vector<string> split(const string &s, char delim){
    
    string new_string = "";
    vector<string> result_vector;
    for(auto ch:s){
        if(ch != delim){
            new_string += ch;
        }else{
            result_vector.push_back(new_string);
            new_string = "";
        }
    }
    result_vector.push_back(new_string);
    return result_vector;
}

void read_data(map<vector<double>, string> &m, unsigned int feature_count, ifstream &inf){

    string line = "";
    vector<string> new_string_vector;
    vector<double> double_vector;
    double new_double;
    if (inf.is_open()){
        while ( getline (inf,line) ){
            new_string_vector = split(line,',');
            for (auto x:new_string_vector)
            {
                try{
                    new_double = stod(x);
                    double_vector.push_back(new_double);
                }catch(std::invalid_argument){
                    m.insert(std::pair<vector<double>, string>(double_vector,x));
                    double_vector.clear();
                    continue;
                }
            }

        }
        inf.close();
    }
}

string pair_to_string(const std::pair<vector<double>, string> &p){

    string str;
    for(auto element:p.first){
        double val = element;
        std::stringstream tmp;
        tmp << std::setprecision(3) << std::fixed << val;
        str += tmp.str() + " ";
    }
    str += p.second;
    return str;
}

void print_map(const map<vector<double>, string> &m,std::ostream &out){

    for(auto element:m){
        out<<pair_to_string(element)<<"\n";
    }

}

double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count){

    double first_result = 0;
    for (int i = 0; i < feature_count; i++)
    {
        first_result += pow(v1.at(i) - v2.at(i),2);
    }
    first_result = sqrt(first_result);
    return first_result;
}

double add_vector(const vector<double> &new_vector){
    //summation of all the elements in a vector<double>
    //used in k_neighbors function
    double result = 0;
    for(auto element: new_vector){
        result += element;
    }
    return result;
}

map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, 
const vector<double> &test, int k){

    double test_summation = add_vector(test);
    double difference = 0;
    map<vector<double>, string> new_map;
    for(auto element: m){
        if(element.first != test){
            difference = std::abs(add_vector(element.first) - test_summation);
            if(difference <= double(k)){
                new_map[element.first] = element.second;
            }
        }
    }
    return new_map;

}

double test_one(const map<vector<double>, string> &m, std::pair<vector<double>, string> test, int k){

    map<vector<double>, string> new_map = k_neighbors(m, test.first, k);
    double count = 0;
    double result_double = 0;
    for(auto element: new_map){
        if(element.second == test.second){
            count++;
            //cout<<count<<endl;
        }
    }
    result_double = count/k;
    return result_double;
}

double test_all(const map<vector<double>, string> &m, int k){
    double result_double = 0;
    for(auto element: m){
        result_double += test_one(m, element, k);
        //cout<< test_one(m, element, k)<<endl;
        //cout<<result_double<<endl;
    }
    cout<<result_double<<endl;
    return result_double/k;
}