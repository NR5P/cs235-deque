/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std;

custom::deque<helpRequest> helpRequestDequeue;

// to show how many minutes its been for other students
int minutesSince = 1;
bool isTherePriority = false;

void checkIfTimeOut()
{
   if(helpRequestDequeue.front().getMinutesRemaining() - minutesSince < 1)
      helpRequestDequeue.pop_front();
   else if(helpRequestDequeue.back().getMinutesRemaining() - minutesSince < 1)
   {
      helpRequestDequeue.pop_back();
      isTherePriority = false;
   }
}

void display()
{
   checkIfTimeOut();
   if (isTherePriority == false)
   {
      cout << "\tCurrently serving " << helpRequestDequeue.front().getName()
      << " for class " << helpRequestDequeue.front().getClass()
      << ". Time left: " << helpRequestDequeue.front().getMinutesRemaining() - minutesSince
      << endl;
   }
   else
   {
      cout << "\tEmergency for " << helpRequestDequeue.back().getName()
      << " for class " << helpRequestDequeue.back().getClass()
      << ". Time left: " << helpRequestDequeue.back().getMinutesRemaining() - minutesSince
      << endl;
   }
   
}



/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here
   string command;
   int lineCount = 0;
   helpRequest currentRequest();


   do
   {
      cout << "<" << lineCount << "> ";
      lineCount++;
      cin.clear();
      cin >> command;

      if (command == "!!")
      {
         isTherePriority == true;
         string name;
         int minutesRemaining;
         cin >> name;
         cin >> minutesRemaining;
         helpRequest newRequest(command, name, minutesRemaining + minutesSince + 1);
         newRequest.setIsPriority(true);

         helpRequestDequeue.push_front(newRequest);

         minutesSince++;

         display();

         //processRequest to shift the request
      }
      else if (command == "none")
      {
         //processRequest to shift the request
         minutesSince++;
         display();
      }
      else if (command == "finished")
      {
         break;
      }
      else
      {
         string name;
         int minutesRemaining;
         cin >> name;
         cin >> minutesRemaining;
         helpRequest newRequest(command, name, minutesRemaining + minutesSince + 1);
         helpRequestDequeue.push_back(newRequest);

         minutesSince++;
         display();
         //processRequest to shift the request
      }

   } while (command != "finished");

   // end
   cout << "End of simulation\n";
}

helpRequest::helpRequest()
{
   this->name = "";
   this->sClass = "";
   this->minutesRemaining = 0;
   this->isPriority = false;
}

helpRequest::helpRequest(string sClass, string name, int minutesRemaining)
{
   this->name = name;
   this->sClass = sClass;
   this->minutesRemaining = minutesRemaining;
   this->isPriority = false;
}

void helpRequest::processRequest()
{
   int minutesRemaining = this->getMinutesRemaining();
   if (helpRequestDequeue.empty())
   {
      return;
   }
   if (this->getMinutesRemaining() > 0)
   {
      //display if minutes are remaining
      this->display();
      this->setMinutesRemaining(minutesRemaining - 1);
   }
   else
   {
      *this = helpRequestDequeue.front();
      helpRequestDequeue.pop_front();
      this->display();
      this->setMinutesRemaining(minutesRemaining - 1);
   }
}

void helpRequest::display()
{
   if (this->getIsPriority())
   {
      cout << "\tEmergency for " << this->name
         << " for class " << this->sClass
         << ". Time left: " << this->minutesRemaining
         << endl;
   }
   else
   {
      cout << "\tCurrently serving " << this->name
         << " for class " << this->sClass
         << ". Time left: " << this->minutesRemaining
         << endl;
   }
}
