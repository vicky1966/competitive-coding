/* 
 * File:   Treasure Hunting .cpp
 * Author: Vicky
 *
 * Created on September 18, 2016, 4:22 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double x,y,a,b,p,q;
    cin>>x>>y>>a>>b;
    p=((b*y)-(a*x))/((b*b)-(a*a));
    q=(p*a-x)/a;
    cout<<p<<" "<<q;
    return 0;
}

