#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <math.h>

//The purpose of these classes is to represent a piece of equipment.
//A piece of equipment can either be a firefighter, firetruck, ATV, SUV or Helicopter
//Every piece of equipment has an id, the amount of hours it has worked, what type it is and a label based on that type

class equip
{
   public:
          equip():id(0),hours(0),type('\0'){}         
          virtual  ~equip();
          bool getHours(float &hours_worked);
          bool getId(equip * &an_equip, int &id);
          bool getType(char &type);
          bool updateHours(float updated_hours);
          bool updateId(int updated_id);
          virtual  bool checkOverHours(bool disp_on);
          bool display();
   protected:
	  int id;
          float hours;
          char type;
          char * label;

};
//Child Class of equip used to represent a fire fighter
class fighter: public equip
{
  public:
       //Constructors
       fighter();
       fighter(int an_id)//used when given an id number for the equipment;
       {
         id=an_id;
         hours=0.0;
         type = 'F';
         label = new char[11];
         strncpy(label,"Firefighter",11);
       }
      ~fighter();//Destructor
      bool checkOverHours(bool disp_on);//checks if equipment is overworked
};
//Child Class of equip used to represent a fire fighter
class truck: public equip
{
  public:
       //Constructors
       truck();
       truck(int an_id)//given a truck id
       {
         id=an_id;
         hours=0.0;
         type='T';
         label = new char[9];
         strncpy(label,"FireTruck",9);
       }
      ~truck();
      bool checkOverHours(bool disp_on);//Check if over worked
};

//Child Class of equip used to represent an suv fighter
class suv: public equip
{
  public:
       //Constructors 
       suv();
       suv(int an_id)//given an suv id
       {
         id=an_id;
         hours=0.0;
         type='S';
         label = new char[3];
         strncpy(label,"SUV",3);
       }
       ~suv();
       bool checkOverHours(bool disp_on);//Check if over worked
};

//Child Class of equip used to represent an atv fighter
class atv: public equip
{
  public:
       //constructors
       atv();
       atv(int an_id)//given an atv id
       {
         id=an_id;
         hours=0.0;
         type='A';
         label = new char[3];
         strncpy(label,"ATV",3);
       }
       ~atv();
       bool checkOverHours(bool disp_on);//Check if over worked
};

//Child class of equip used to represent a helicopter
class helicopter: public equip
{
  public:
       //constructors
       helicopter();
       helicopter(int an_id)//given a helicopter id
       {
         id=an_id;
         hours=0.0;
         type='H';
         label = new char[10];
         strncpy(label,"Helicopter",10);
       }
      ~helicopter();
      bool checkOverHours(bool disp_on);//Check if over worked
};

