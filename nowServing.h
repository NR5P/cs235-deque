/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include "deque.h"     // for DEQUE

class Student
{
   private:
      
      bool emergancy;
      string course;
      string name;
      int mins;

   public:
   
   //Default Constructor
   Student() : emergancy(false), course(""), name(""), min(0) {}
   
   //Non-Default Constructor
   Student(bool emergancy, string course, string name, int mins);
   
   //Destructor
   //~Student();

   //Setters and Getters for emergancy/coursse/name/mins


};

void nowServing();
void displayInstructions();
void displayUpdate(int mins, Student currentStudent);

#endif // NOW_SERVING_H

