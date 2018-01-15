#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;

bool check_base(std::string n,int base){
    int character_check;
    for(char& ch:n){
       try{
          character_check = std::stoi (&ch,nullptr,base);
          
        }
        catch(const std::invalid_argument& x){
            return false;
            }
        }
    return true;
}
bool metadrome(std::string n,int base){
    std::string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";
    if(check_base(n,base) == false){
        return false;
    }
    for(char &a:n){
        try{
              if(base_vals.find(a) < base_vals.find(n.at(n.find(a)+1))){
                  continue;
              }
              else{
                  return false;
              }
        }
        catch(const std::out_of_range& x){
            return true;
            
            }
        
        }
    return true;
}
bool plaindrome(std::string n, int base){
    std::string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";
    if(check_base(n,base) == false){
        return false;
    }
    if(metadrome(n,base) == true){
        return true;
    }
     for(char &a:n){
        try{
              if(base_vals.find(a) < base_vals.find(n.at(n.find(a)+1)) || base_vals.find(a) == base_vals.find(n.at(n.find(a)+1))){
                  continue;
              }
              else{
                  return false;
              }
        }
        catch(const std::out_of_range& x){
            return true;
            
            }
        
        }
    return true;
}
bool katadrome(std::string n,int base){
    std::string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";
    if(check_base(n,base) == false){
        return false;
    }
    for(char &a:n){
        try{
              if(base_vals.find(a) > base_vals.find(n.at(n.find(a)+1))){
                  continue;
              }
              else{
                  return false;
              }
        }
        catch(const std::out_of_range& x){
            return true;
            
            }
        
        }
    return true;
}
bool nialpdrome(std::string n,int base){
    std::string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";
    if(check_base(n,base) == false){
        return false;
    }
    for(char &a:n){
        try{
              if(base_vals.find(a) > base_vals.find(n.at(n.find(a)+1))||base_vals.find(a) == base_vals.find(n.at(n.find(a)+1))){
                  continue;
              }
              else{
                  return false;
              }
        }
        catch(const std::out_of_range& x){
            return true;
            
            }
        
        }
    return true;
}
std::string classify(std::string n,int base){
    if(metadrome(n,base) == true){
        return "metadrome";
    }
    else if(plaindrome(n,base) == true){
        return "plaindrome";
    }
    else if(katadrome(n,base) == true){
        return "katadrome";
    }
    else if(nialpdrome(n,base)==true){
        return "nialpdrome";
    }
    else{
        return "nondrome";
    }
}
int main(){
    std::string num;
 long base;
cout << boolalpha;
  cin >> num >> base;
  cout << metadrome (num, base) << " "
       << plaindrome (num, base) << " "
       << katadrome (num, base) << " "
       << nialpdrome (num, base) << " "
       << classify(num, base) << endl;
}