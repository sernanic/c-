#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<algorithm>
#include<sstream>
#include<cmath>
#include <iomanip>
#include "proj08_ball.h"
#include "proj08_twod.h"
//#include "proj08_twod.cpp"
Ball::Ball(double m, TwoD pos, TwoD speed, double r){
    mass = m;
    coords = pos;
    velocity = speed;
    radius = r;
}
string Ball::to_string(){
    //first is mass, second is coords, third is velocity, fourth is radius
     std::stringstream result;
     result << std::setprecision(2) << std::fixed <<mass<<", "<<'('<< coords.x<<", "<<coords.y<<')'<<", "<<'('<<velocity.x<<", "<<velocity.y<<')'<<", "<<radius;
     return result.str();
     
 }
 bool Ball::contact_ball(Ball ball_variable){
     //distance formula: sqrt((x2-x1)^2+(y2-y1)^2)
     double bool_result;
     double distance_formula = sqrt(pow(ball_variable.coords.x - coords.x,2) +       pow(ball_variable.coords.y - coords.y,2));
     double total_radius = ball_variable.radius + radius;
     distance_formula < total_radius? bool_result = true : bool_result = false;
     return bool_result;
 }
 bool Ball::contact_wall(long xdim, long ydim){
     
     bool bool_result;
     double contact_xdim = radius + coords.x;
     double contact_ydim = radius + coords.y;
     contact_xdim >= xdim || contact_ydim >= ydim? bool_result = true :              bool_result = false;
     return bool_result;
 }
 
 TwoD Ball::update_velocity_wall(long xdim, long ydim){
     
     TwoD new_vector;
     double contact_xdim = radius + coords.x;
     double contact_ydim = radius + coords.y;
     double contact_xdim_left = coords.x - radius;
     double contact_ydim_left = coords.y - radius;
     if(contact_xdim >= xdim){
         new_vector.x = -velocity.x;
         new_vector.y = velocity.y;
     }
     else if(contact_ydim >= ydim){
         new_vector.x = velocity.x;
         new_vector.y = -velocity.y;
     }
     else if(contact_xdim_left <= 0){
         new_vector.x = -velocity.x;
         new_vector.y = velocity.y;
     }
     else if(contact_ydim_left<=0){
         new_vector.x = velocity.x;
         new_vector.y = -velocity.y;
     }
     else{
         new_vector.x = velocity.x;
         new_vector.y = velocity.y;
     }
     return new_vector;
 }
 
 TwoD Ball::update_velocity_ball(Ball new_ball){
     TwoD v1_v2 = velocity.diff(new_ball.velocity);
     TwoD x1_x2 = coords.diff(new_ball.coords);
     double TwoD_section = v1_v2.dot_product(x1_x2)/(x1_x2.magnitude_squared());
     double mass_section = 2*new_ball.mass/(mass+new_ball.mass);
     double semi_result = TwoD_section * mass_section;
     TwoD semi_result_2 = x1_x2.mult(semi_result);
     TwoD result = velocity.diff(semi_result_2);
     //TwoD velocity_diff = coords.diff(new_ball.coords);
     return result;
 }
 /*int main(){
     Ball b1(3, {2,9}, {1,1}, 1.05);
     TwoD new_v = b1.update_velocity_wall(10,10);
     cout<<new_v.x<<" "<<new_v.y<<endl;

 }*/