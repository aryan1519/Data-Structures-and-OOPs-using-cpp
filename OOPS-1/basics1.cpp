/*
Creating a basic class

class Student
{

int roll_number;
int age;
};
/////////////////////////
Creating an object statically

Student s1;
////////////////////////
Creating an object dynamically

Student *s2 = new Student;
////////////////////////

Assigning values to an object(static)

s1.age = 24;
s1.roll_number = 101;
//////////////////////////////////

Assigning values to an object(dynamic)

(*s2).age = 21;
(*s2).roll_number = 26;

the above can also be written as

s2->age=21;
s2->roll_number=36;
///////////////////////////////

Access Modifiers

They are of three type:-
private
public
protected

By default every element of  a classs is private

Assigning access Modifiers

class Student
{
public:
int roll_number;
int age;
};

or

class Student
{
public:
int roll_number;
private:
int age;
};


Public elements can be acceseed outside the class unlike
private elements
/////////////////////////

Functions can be created in a similar manner

eg

public:
void display()
{
cout<<age<<" "<<roll_number;
}
/////////////////////////

Calling functions

for static objects
s1.display();

for dynamic objects
(*s2).dispaly();
or
s2->display();
///////////////////////
if an element is private neither can we access it nor can we assign values to it
*/
