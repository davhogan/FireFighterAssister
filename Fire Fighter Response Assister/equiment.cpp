//By David Hogan
//email davhogan@pdx.edu
#include "equipment.h"
using namespace std;

const int MAX_FIGHTER_HOURS=12;
const int MAX_TRUCK_HOURS=50;
const int MAX_SUV_HOURS=100;
const int MAX_ATV_HOURS=30;
const int MAX_HELI_HOURS=10;

//Destructor
equip::~equip()
{
  label=NULL;
  delete(label);
}
//Helper to get hours worked
bool equip::getHours(float &hours_worked)
{
   hours_worked=hours;
   return true;
}   
//helper to get the id
bool equip::getId(equip * &an_equip, int &an_id)
{
   an_id=an_equip->id;
   return true;
}
//helper to get the type
bool equip::getType(char  &a_type)
{
   a_type = type; 
   return true;
}
//helper to update hours
bool equip::updateHours(float updated_hours)
{
    hours=hours+updated_hours;
    return true;
}
//helper to update Id
bool equip::updateId(int updated_id)
{
    id=updated_id;
    return true;
}
//Virtual will be implemented by the child classes
bool equip::checkOverHours(bool disp_on)
{
return true;
}
//Displays the amount of time a piece of equipment has worked for
bool equip::display()
{
  cout<<label<<" "<<id<<" has worked for "<<hours<<" hours"<<endl;
  return true;
}

//Fighter is a child Class of equip

//Destructor
fighter::~fighter()
{
  label=NULL;
  delete label;
}
//Checks if a fire fighter is over worked
bool fighter::checkOverHours(bool disp_on)
{
  if(disp_on)
  {
    if(hours>=MAX_FIGHTER_HOURS)
    {
      cout<<"Firefighter ID #"<<id<<" is over hours"<<endl;
      cout<<"They have worked "<<hours<<" hours\n"<<endl;
      return true;
    }
    else
      return false;
  }
  else
    if(hours>=MAX_FIGHTER_HOURS)
      return true;
    else 
     return false;
 return false;
}
 
//Truck is a child Class of equip
truck::~truck()
{
  label=NULL;
  delete label;
}
//Checks if a truck is over worked
bool truck::checkOverHours(bool disp_on)
{
  if(disp_on)
  {
   if(hours>=MAX_TRUCK_HOURS)
   {
    cout<<"Truck ID #"<<id<<" is over hours"<<endl;
    cout<<"Has been in operation for "<<hours<<" hours\n"<<endl;
    return true;
   }
  }
  else
    if(hours>=MAX_TRUCK_HOURS)
      return true;
    else 
      return false;
 return false;
}

//SUV is a child Class of equip
suv::~suv()
{
  label=NULL;
  delete label;
}
//Checks if an SUV is over worked
bool suv::checkOverHours(bool disp_on)
{
  if(disp_on)
  {
   if(hours>=MAX_SUV_HOURS)
   {
    cout<<"SUV ID #"<<id<<" is over hours"<<endl;
    cout<<"It has been in operation for "<<hours<<" hours\n"<<endl;
    return true;
   }
  }
  else
    if(hours>=MAX_SUV_HOURS)
      return true;
    else 
      return false;
 return false;
}

//ATV is a child Class of equip
atv::~atv()
{
  label=NULL;
  delete label;
}
//Checks if an atv is overworked
bool atv::checkOverHours(bool disp_on)
{
  if(disp_on)
  {
   if(hours>=MAX_ATV_HOURS)
   {
    cout<<"ATV ID #"<<id<<" is over hours"<<endl;
    cout<<"It has been in operation for "<<hours<<" hours\n"<<endl;
    return true;
   }
  }
  else
    if(hours>=MAX_ATV_HOURS)
      return true;
    else 
      return false;
 return false;
}

//Helicopter is a child Class of equip
helicopter::~helicopter()
{
  label=NULL;
  delete label;
}
//Checks if helicopter is over worked
bool helicopter::checkOverHours(bool disp_on)
{ 
   if(disp_on)
  {
   if(hours>=MAX_HELI_HOURS)
   {
    cout<<"Helicopter ID #"<<id<<" is over hours"<<endl;
    cout<<"It has been in operation for "<<hours<<" hours\n"<<endl;
    return true;
   }
  }
  else
    if(hours>=MAX_HELI_HOURS)
      return true;
    else 
      return false;
 return false;
}
