#include "fire.h"
//The purpose of this class is to represent the gps location of either a fire or a residence
// The location has either a fire or it has a name if it is a residental area. 
//It also has a char type to represent which type of locatin it is, F for fire R for residental
class location
{
   public:
   location():latitude(0),longitude(0),a_fire(NULL),name(NULL){}//default constructor
   location(float a_latitude, float a_longitude, char a_type, int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry);//Constructor to create a location of a fire   
   location(float a_latitude, float a_longitude,char * a_name);//Constructor to create a residence
   ~location();//Destructore
   bool update_lvl(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h);//Updates the level of the fire.
 bool relieve_list(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id);//Relieves piece of equipment that is over worked
   bool compare(location* &a_loc_2);//calculate the difference between the two gps cooridnates 
   bool is_fire();//checks if the location is a fire
   bool pass_hours(float hrs);//simulates hours passing by
   bool display();//displays the information about the location
   bool disp_warning();//displays warnings levels for fires
   bool disp_list();//displays the list of equipment at the fire

   protected:
     float latitude;//gps latitude
     float longitude;//gps longitude
     char type;//type of location
     fire * a_fire;//a fire
     char * name;//a name of the location


};
