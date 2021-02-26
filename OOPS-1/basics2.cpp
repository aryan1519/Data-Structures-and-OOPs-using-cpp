/*
class Student
{
public:
  int roll_number;

private:
  int age;

public:
  void display()
  {
    cout<<age<<" "<<rol_number<<endl;
  }

  int get_age()
  {
    return age;
  }

};

int main()
{
  Student s1;

  Student *s2 = new Student;
}

we cannot access age as its a private element
but we can get the age using the getage function which is a public function

s1.age=20 ;  //this is an invalid statement

cout<<s1.get_age<<endl; //this is an invalid statement

to get the age we can do the following

cout<<s1.get_age()<<endl;

Similarly we can set the age or in general set the value of a private variable using the a public set function

These are known as GETTERS AND SETTERS

Using getter and setter fucntions we can change the values/acces private  variable too
this is useful as we can enforce a condition with the fuction so as to make th changes meaningful like adding an if condition int get_age function to not all negative values

or we can have an extra password parameter in our function which allows inly select users who know the password to make changes
eg
public:
int set_age(int a,int password)
{
if(password !=123)
  return;

age = a;
}
*/
