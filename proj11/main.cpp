#include<sstream>
using std::ostringstream;
#include<string>
using std::string;
#include "proj11_trimap.h"
int main(){
TriMap<long,long> m1;
m1.insert(2,20);
m1.insert(1,10);
m1.insert(4,40);
m1.insert(3,30);

TriMap<long, long> m2(m1);
m2.insert(5,50);
m2.remove(4);

ostringstream oss1;
oss1 << m1;
string s1 = oss1.str();
string ans1 = "1:10:1, 2:20:0, 3:30:3, 4:40:2";
std::cout << s1 << std::endl;
//ASSERT_EQ(s1,ans1);

ostringstream oss2;
oss2 << m2;
string s2 = oss2.str();
string ans2 = "1:10:1, 2:20:0, 3:30:2, 5:50:3";
cout<<s2<<endl;
//ASSERT_EQ(s2,ans2);


}
