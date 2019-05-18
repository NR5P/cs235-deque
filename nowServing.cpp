/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    Griffin Pope, Dan Worwood, Nathan Riggs, Dallen Cluff
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
#include <sstream>
using namespace std;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   displayInstructions();

   //dequeue<Student> currentStudent;
   //dequeue<Student> nextStudent;
   custom::deque<Student> students;

   Student student;
   string userChoice; //used for user input
   stringstream ss;
   int line = 0; //used for displaying which line we are on

   do
   {
      string course;
      string name;
      string minute;

      cout << "<" << line << ">"; 
      std::getline(std::cin, userChoice);
      std::istringstream stream(userChoice);
      stream >> course;
      student.setCourse(course);
      stream >> name;
      student.setName(name);
      stream >> minute;
      student.setMinute(std::stoi(minute));
      ss << userChoice;

      cout << course;
      cout << minute;
      cout << name;
   } while (userChoice != "finished");
   

   cout << "End of simulation\n";

   return;
}

/************************************************
 * displayInstructions()
 * DisplayInstructions
 ***********************************************/
void displayInstructions()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   return;
}

/************************************************
 * displayUpdate()
 * Function to display who is currently being
 * being served, or emergancy info,  and time left.
 ***********************************************/
void displayUpdate(int mins, Student currentStudent)
{
   if (currentStudent.isEmergency())
   {
      cout << "Emergency for " << currentStudent.getName()
      << " for class " << currentStudent.getCourse() 
      << ". Time left: " /* << *Somehow put remaining time here* */
      << endl;
   }
   else
   {
      cout << "Currently serving " << currentStudent.getName()
      << " for class " << currentStudent.getCourse() 
      << ". Time left: " /* << *Somehow put remaining time here* */
      << endl;
   }
   
   return;
}