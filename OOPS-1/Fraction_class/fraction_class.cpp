#include <iostream>
using namespace std;

class Fraction
{
  private :
    int numerator ;
    int denominator ;

  public:

    //creating constructor to always get input of numerator and denominator while creating an object
    Fraction(int numerator,int denominator)
    {
      this->numerator = numerator;
      this->denominator = denominator;
    }

    void print()
    {
      cout<< this->numerator <<"/"<< this->denominator <<endl;
    }

    void simplify() //we dont need to give any parameters because it will simplify 'this' object
    {
      int hcf =1;
      int h = min(this->numerator,this->denominator);

      for(int i=1;i<=h;i++)
      {
        if(this->numerator %i ==0 && this->denominator %i == 0)
        {
          hcf = i;
        }
      }

      numerator = numerator/hcf;     // we dont need to specify 'this' as it is self implied
      denominator = denominator/hcf; //
    }

    void add(const Fraction &f2)     // we can skip & but then a copy will created and memory is wasted so we use reference
                                     // now since there is reference it can be changed unwillingly hence we use it as a const
    {
    int sum = (this->numerator*f2.denominator)  + ((this->denominator*f2.numerator)) ; //Fraction to add f2 to f1 and store in f1
    int den = this->denominator*f2.denominator;

    numerator = sum;
    denominator = den;

    simplify();
    }

};
