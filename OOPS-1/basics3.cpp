
/*
CONSTRUCTORS

A constructor is a function with the same name as the class and it is called automatically as an object is created and is used to initialize the value of all the data members
of the class of that object.
Defaualt constructors are created automatically and they initialize data members to a garbage values
the default constructor does not have an agruments and it does not have a return type and no void is specfied for it.


Constrcutor created by us can have arguments.It does not have return type.
we do not need to specify void.

If we create our own constructor then the default constructor isnt made and out constructor is called.

lets say we make a constructor for the Student class ourselves.

Student()
{
cout<<"constructor called";
}

When we create an object the constructor is called and we get the output "constructor called" and the data members are also initialized to garbage value.

Parametrized constructors
we can have parametrs for our constructor
eg

Student(int r)
{
coout<<"constructor called"<<ednl;
age = r;
}


Now id we create an object using

Student s1;

the default constructor is called or if weve created a constructor with no parameters it is called.

if we create and object using

Student s2(10);

the the parametrized constructor is called and the age is set to 10


in case of c=dynamically created object

Student *s3 = new Student(10);


//////////////////////////////////////////////////
IMPORTANT

If we have created any constructor ourselves the default constructor isnt created.

Now if we create parametrized constructor only and no constructor without parameters and create the following object

Student s1;

we will get an error.

as there is no constructor for an object with no parameters.
/////////////////////////////////////////////////////

THIS keyword

this keyword stores the memory address of the current object

eg

we create a parametrized constructor

Student (int roll_no)
{
roll_number = roll_number;
}


it creates a confusion as the name of the parameter is the same as data member.

so to avoid this confusion we use the this keyword


Student (int roll_no)
{
this->roll_number = roll_number;
}


now it creates no confusion as the this keyword stores the memory address of the current object.

We can totally avoid this by having a different name of the argument of the constructor.
////////////////////////////////////

*/


/*
COPY CONSTRUCTORS

if we wan to create an object with the exact same properties as another object we can use the copy constructor

Eg

Student s1(10,100);

//creating an object s2 with the same properties as s1

Student s2(s1);

// creating an object s3 dynamically with the same properties as s1

Student *s3 = new Student(s1);

//

Student *s4 = new Student(20,300);

//creating a static object s5 with the same properties as s4

Student s5(*s4);

//creating a dynamic object s6 with the same properties as s4

Stdeunt *s6 = new Student(*s4);
*/

/*
Copy Assignment Operator

if we have created two objects their constructors are called.for an object in its life time a constructor is called only once.
but if we want to copy the data of one object to another we can use the copy assignment Operator

Eg
Student s1(10,100);

Student s2(30,400);

s2 = s1; // copies data from s1 to s2

Student *s3 = new Student(40,200);

*s3=s1; // copies data from s1 to s3

s2= *s3; copies data from s3 to s2

*/


/*
DESTRCUTOR

used to deallocate the memory of an object

*Has no input arguments
*Has no return type
*We cannot create multiple destructors.
*Only one destructor can be created and once created the default deconstrcutor is not called.
*A constructor is automatically called at the end of main.
*It is invoked when object goes out of the scope.
*It can be declared in private section

Syntax for a deconstrcutor is as follows :-
~Student()
{

}


eg

class Student
{
public:
int age;
int roll_no;

Student()
{
cout<<"constructor called";
}

~Student()
{
cout<<"deconstructor called";
}

};


int main()
{

  Student s1;
  Student s2;
  Student *s3 = new Student;
}


//we would get the following output
//
//constrcutor called
//constructor called
//constrcutor called
//deconstructor called
//deconstructor called


we notice we didnt get a deconstructor for the dynamically created object because it is a pointer and we need to
deallocate memory ourselves. So we can rewrite main as

int main()
{

  Student s1;
  Student s2;
  Student *s3 = new Student();
  delete s3;
}

//now we would get the following output
//
//constrcutor called
//constructor called
//constrcutor called
//deconstructor called
//deconstructor called
//deconstructor called
*/

/*
when we do the following

Student s5 = s2;

where s2 is already an object in memory then.

this isnt interpreted as creating an object and calling the default constructor and then using the assignment operator
but it is interpreted as copy constructor and internally it works as Student s5(s2);
*/
