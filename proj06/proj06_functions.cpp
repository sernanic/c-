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
#include <fstream>
using namespace std;
using std::ostringstream;

#include "proj06_functions.h"

string reverse(string intial_string){
    string new_s = "";
    for(int i = intial_string.size() -1;i >= 0;i--){
         new_s += intial_string.at(i);
    }
    return new_s;
}

int next_val (const vector<int> &v, const string &s){
    int index = 0;
    int result = 0;
    char m;
    string vector_to_str = "";
    for(auto element:v){
        vector_to_str += to_string(element);
    }
    vector_to_str = reverse(vector_to_str);
    for(auto ch:vector_to_str){
        if(ch == '1'){
        result += pow(2,index);
        index++;
        }else{
            index++;
            continue;
        }
    }
    m = reverse(s).at(result);
    result = m -'0';
    return result;
}
vector<int> one_iteration(const vector<int> &v, const string &s){
    vector<int> three_digit_vector;
    int count = 0;
    string new_string = "";
    vector<int> final_answer;
    vector<int> new_vector = v;
    new_vector.insert(new_vector.begin(),0);
    new_vector.push_back(0);
    while(count < new_vector.size()-2){
        three_digit_vector.push_back(new_vector.at(count));
        three_digit_vector.push_back(new_vector.at(count + 1));
        three_digit_vector.push_back(new_vector.at(count + 2));
        final_answer.push_back(next_val(three_digit_vector,s));
        three_digit_vector = {};
        count++;
    }
    cout<<vector_to_string(three_digit_vector)<<endl;
    return final_answer;
}
void read_vector(vector<int> &v, string file_str) {
    string line;
    int result = 0;
  ifstream myfile (file_str);
  if (myfile.is_open() && v.size() == 0)
  {
    while ( getline (myfile,line) )
    {
      for(auto element: line){
          if(element != ' '){
              result = element - '0';
              v.push_back(result);
          }
      }
    }
    myfile.close();
  }
}
string to_binary(int val){
    int quotient = val;
    int remain = 0;
    string final_answer = "";
    string new_s = "";
    if(val < 0 || val > 255){
        return "00000000";
    }
    while(quotient != 0){
        remain = quotient;
        final_answer += to_string(remain %= 2);
        quotient /= 2;
    }
    //reverses the string
    new_s = reverse(final_answer);
    while(new_s.length() != 8){
        new_s= "0"+ new_s;
    }
    return new_s;
}
string vector_to_string(const vector<int> &v){
    string vector_to_str = "";
    for(auto element:v){
        vector_to_str = vector_to_str + std::to_string(element) + ",";
    }
    vector_to_str = vector_to_str.substr(0,vector_to_str.length()-1);
    return vector_to_str;
}
string pretty_print(vector<int> & v){
  ostringstream oss;
  transform(v.begin(), v.end(), ostream_iterator<char>(oss),
	    [] (int i) {
	      return (i==0) ? '_' : '*';
	    }
	    );
    return oss.str();
}
/*int main(){
    vector<int> hello;
    hello = one_iteration({0,0,1,1,1,0,0}, "11011100");
    cout<<vector_to_string(hello)<<endl;
    vector<int> v2{1,1,0} ;
    cout<<next_val (v2, "010101010")<<endl;
    read_vector(v2,"inf.txt");
    cout<<pretty_print(v2)<<endl;
    cout<<to_binary(16)<<endl;
    cout<<vector_to_string(v2)<<endl;
    return 0;
}*/