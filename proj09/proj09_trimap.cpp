#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<algorithm>
#include<sstream>
#include<cmath>
#include <iomanip>
#include<iterator>
using std::ostream_iterator;
#include "proj09_trimap.h"
using std::ostringstream;
using std::ostream;
size_t TriMap::size(){
    //This function takes the vector<Element> and return the size of the vector
    
    return vec_.size();
}
bool TriMap::insert(string key,string value){
    bool result = true;
    Element *new_element = new Element;
    new_element->key_ = key;
    new_element->value_ = value;
    new_element->index_ = vec_.size();
    vector<Element>::iterator it;
    for (it = vec_.begin(); it != vec_.end(); ++it) {
        if(it->key_ == new_element->key_){
            result = false;
        }
    }
    if(result == true){
        vec_.push_back(*new_element);
    }
    return result;
}
bool TriMap::remove(string key){
    bool result = false;
    vector<Element> new_vector;
    Element *new_element = new Element;
    new_element->key_ = key;
    vector<Element>::iterator it;
    for (it = vec_.begin(); it != vec_.end(); ++it) {
        if(it->key_ != new_element->key_){
            new_vector.push_back(*it);
        }else{
            result = true;
        }
    }
    this->vec_ = new_vector;
    return result;
}
Element* TriMap::find_key(const string& key){
    /*
    The find_key function takes in an argument and looks for 
    the argument as a key in the trimap vector<Element>
    */
    vector<Element> new_vector;
    Element *new_element = new Element;
    new_element->key_ = key;
    vector<Element>::iterator it;
    size_t count =0;
    for (it = vec_.begin(); it != vec_.end(); ++it) {
        if(it->key_ == new_element->key_){
            it->index_ = count;
            return  &(*it); 
        }
        count++;
    }
    return nullptr;
}
Element* TriMap::find_value(const string& value){
    /*
    The find_key function takes in an argument and looks for 
    the argument as a value in the trimap vector<Element>
    */
    vector<Element> new_vector;
    Element *new_element = new Element;
    new_element->value_ = value;
    vector<Element>::iterator it;
    size_t count =0;
    for (it = vec_.begin(); it != vec_.end(); ++it) {
        if(it->value_ == new_element->value_){
            it->index_ = count;
            return  &(*it); 
        }
        count++;
    }
    return nullptr;
}
Element* TriMap::find_index(size_t index){
    /*
    The find_key function takes in an argument and looks for 
    the argument as a index in the trimap vector<Element>
    */
    vector<Element> new_vector;
    Element *new_element = new Element;
    new_element->index_ = index;
    vector<Element>::iterator it;
    for (it = vec_.begin(); it != vec_.end(); ++it) {
        if(it->index_ == new_element->index_){
            return  &(*it); 
        }
    }
    return nullptr;
}
ostream& operator<<(ostream& out, const Element& h){
     out<< h.key_<<":"<<h.value_<<":"<<h.index_;
     return out;
}
TriMap::TriMap(const Element& hello){
    vec_.push_back(hello);
    sz_ = vec_.size();
}
ostream& operator<<(ostream& out, const TriMap& l){
  ostringstream oss;
  copy(l.vec_.begin(), l.vec_.end(), ostream_iterator<Element>(oss, ", "));
  string s = oss.str();
  out << s.substr(0, s.size()-2);
  return out;
}
TriMap::TriMap(initializer_list<Element> t){
    const Element* it = t.begin();  
    const Element* const end = t.end();    
 
      for (; it != end; ++it){
        vec_.push_back(*it);
      }
}