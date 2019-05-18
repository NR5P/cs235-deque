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


class helpRequest
{
public:
   helpRequest();
   helpRequest(std::string sClass, std::string name, int minutesRemaining);
   ~helpRequest() {};

   bool getIsPriority() const { return isPriority; }
   void setIsPriority(bool isPriority) { this->isPriority = isPriority; }

   std::string getName() const { return name; }
   void setName(std::string name) { this->name = name; }

   std::string getClass() const { return sClass; }
   void setClass(std::string sClass) { this->sClass = sClass; }

   int getMinutesRemaining() const { return minutesRemaining; }
   void setMinutesRemaining(int minutes) { this->minutesRemaining = minutes; }
   void subtractOneMinute()
   {
       --minutesRemaining;
   }

   void processRequest();
   void display();

private:
   std::string name;
   std::string sClass;
   int minutesRemaining;
   bool isPriority;
};


// the interactive nowServing program
void nowServing();

#endif // NOW_SERVING_H

