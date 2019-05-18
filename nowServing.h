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
#include <string>

class Student
{
   private:
      
      bool emergency;
      std::string course;
      std::string name;
      int minutes;

   public:
   
   //Default Constructor
   Student() : emergency(false), course(""), name(""), minutes(0) {}
   
   //Non-Default Constructor
   Student(bool emergancy, std::string course, std::string name, int mins);
   
   bool isEmergency() 
   {
       return emergency;
   }

   std::string getName()
   {
       return name;
   }

   std::string getCourse()
   {
       return course;
   }

   void setCourse(std::string course)
   {
       this->course = course;
   }
   void setName(std::string name)
   {
       this->name = name;
   }
   void setMinute(int minute)
   {
       this->minutes = minute;
   }

};

void nowServing();
void displayInstructions();
void displayUpdate(int mins, Student currentStudent);

#endif // NOW_SERVING_H

