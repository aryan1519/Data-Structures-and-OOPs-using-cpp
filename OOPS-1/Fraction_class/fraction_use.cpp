#include <iostream>
#include "fraction_class.cpp"

using namespace std;

int main()
{
int num,den;

cout<<"enter the first fraction:"<<endl;
cout<<"enter numerator "<<endl;
cin>>num;
cout<<"enter denominator "<<endl;
cin>>den;
Fraction f1(num,den);
cout<<"the first fraction is : ";
f1.print();
cout<<"\nenter the second fraction:"<<endl;
cout<<"enter numerator "<<endl;
cin>>num;
cout<<"enter denominator "<<endl;
cin>>den;
Fraction f2(num,den);
cout<<"the second fraction is : ";
f2.print();
f1.add(f2);
cout<<"\nthe sum is : ";
f1.print();

  return 0 ;
}
