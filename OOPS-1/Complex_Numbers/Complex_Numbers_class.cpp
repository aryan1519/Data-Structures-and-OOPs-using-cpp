#include <iostream>

using namespace std;


class ComplexNumbers {
public:
  int rp,ip;

  ComplexNumbers(int rp,int ip)
  {
    this->rp=rp;
    this->ip=ip;
  }

  void plus(const ComplexNumbers &f2)
  {
    this->rp = this->rp + f2.rp;
    this->ip = this->ip + f2.ip;
  }

  void multiply(const ComplexNumbers &f2)
  {
    int k=this->rp;
    rp = (this->rp * f2.rp) - (this->ip * f2.ip);
    ip = (k*f2.ip) + (this->ip*f2.rp);

  }

  void print()
  {
    cout<<this->rp<<" + i"<<this->ip;
  }
};
