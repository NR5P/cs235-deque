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

void checkIfTimeOut(helpRequest &request)
{
   //if the current request is done/empty, check if there's
   //another one.
   if (request.empty() && !helpRequestDequeue.empty())
   {
      request = helpRequestDequeue.front();
      helpRequestDequeue.pop_front();
   }
}

void updateTimeoutAndDisplay(helpRequest &request)
{
   checkIfTimeOut(request);
   if (!request.empty())
   {
      request.display();
      request.subtractOneMinute();
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
   helpRequest currentRequest;

   do
   {
      cout << "<" << lineCount << "> ";
      lineCount++;
      cin.clear();
      cin >> command;

      if (command == "!!")
      {
         string name;
         string classname;
         int minutesRemaining;
         cin >> classname;
         cin >> name;
         cin >> minutesRemaining;
         helpRequest newRequest(classname, name, minutesRemaining);
         newRequest.setIsPriority(true);

         helpRequestDequeue.push_front(newRequest);

         updateTimeoutAndDisplay(currentRequest);

         //processRequest to shift the request
      }
      else if (command == "none")
      {
         //processRequest to shift the request
         updateTimeoutAndDisplay(currentRequest);
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
         helpRequest newRequest(command, name, minutesRemaining);
         helpRequestDequeue.push_back(newRequest);

         updateTimeoutAndDisplay(currentRequest);
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

bool helpRequest::empty() const
{
   //if minutesRemaining is 0, we'll treat this as empty
   //maybe we should also check "name"...
   return this->minutesRemaining == 0;
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
