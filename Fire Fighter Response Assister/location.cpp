//By David Hogan
//email davhogan@pdx.edu
#include "location.h"
using namespace std;
//Constructor to build a fire or residental area based on given variables
location::location(float a_latitude, float a_longitude, char a_type,int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry)
{
  latitude=a_latitude;
  longitude=a_longitude;
 
 //Create a structrual fire
  if(a_type=='S')
   {
    a_fire=new s_fire(f_id,t_id,a_id,s_id,h_id,n_acres,dry);
    type='F';
    name=NULL;
   }
  //Create a wildfire 
   else if(a_type=='W')
  {
    a_fire=new w_fire(f_id,t_id,a_id,s_id,h_id,n_acres,dry);
    type='F';
    name=NULL;
  }
  //Create an ariel fire
   else if(a_type=='A')
  {
    a_fire=new ar_fire(f_id,t_id,a_id,s_id,h_id,n_acres,dry);
    type='F';
    name=NULL;
  }
}

//Constructor to create a residence
location::location(float a_latitude, float a_longitude,char * a_name)
{
    latitude=a_latitude;
    longitude=a_longitude;  
    a_fire=NULL;
    type='R';
    name = new char[strlen(a_name)+1];
    strcpy(name,a_name);

}


//Destructor 
location::~location()
{
   if(a_fire)
   {
     a_fire=NULL;
     delete a_fire;
   }
   else
   {
     name=NULL;
     delete name;
   }
}
//Helper function to update to lvl of the fire by calling the fires update level
bool location::update_lvl(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h)
{
  if(!a_fire)
    return false;

  a_fire->update_lvl(lvl,n_f,n_t,n_a,n_s,n_h);
  return true;
}

//relieves any overworked equipment at the fire calls the fires relieve function
bool location::relieve_list(int &n_f, int &n_t, int &n_a, int &n_s, int &n_h)
{
   if(a_fire==NULL)
    return false;
   else
    a_fire->relieve_list(n_f,n_t,n_a,n_s,n_h);
   return true;
}
//This function compares the current location with a given location that is passed in.
//The function then finds the difference in longitude and latitude of the two location, then calculates the difference using the haversine formula.
//It returns true if the two locations are within 10 miles(16km) of each other.
//Otherwise it returns false.
bool location::compare(location* &a_loc_2)
{  
    float lat_dif, long_dif,a,c,dist=0.0;
    float s_a=0.0;
    float s_1=0.0;  
    
    lat_dif=latitude - a_loc_2->latitude;
    long_dif=longitude - a_loc_2->longitude;

    //To find the distance the haversine formula was used    
    lat_dif=(lat_dif*M_PI)/180;
    long_dif=(long_dif*M_PI)/180;
    a=sin(lat_dif/2)*sin(lat_dif/2)+cos(lat_dif)*cos(long_dif)*sin(long_dif/2)*sin(long_dif/2);
    s_a=sqrt(a);
    
      s_1=sqrt(1-a);

    c=2*atan2(s_a,s_1);
    dist=c*6371;
   
    //locations are within 10 miles of each other
    if(dist<=16)
    {
      return true;
    }
     return false;
}
//Checks if it is a fire
bool location::is_fire()
{
  if(a_fire)
   return true;
  
  return false;
}
//Simulate passing hours calls fires passing hour function
bool location::pass_hours(float hrs)
{
    if(a_fire==NULL)
     return false;
    else
     a_fire->hours_pass(hrs);
    
  return true;
}
//Displays information about the location based on if it is or isn't a fire
bool location::display()
{
  cout<<"Location located at gps coordinates: "<<latitude<<','<<longitude<<endl;
  if(a_fire)
   a_fire->display();
  else
   cout<<"Name of location is: "<<name<<endl;
  
  return true;
}
//Displays all warnings for fires
bool location::disp_warning()
{
  if(a_fire==NULL)
    return false;
  else
  a_fire->disp_warning();
  
  return true;
}
//Displays the list of equipment at a fire
bool location::disp_list()
{
   if(a_fire==NULL)
    return false;
   else
    a_fire->disp_list();
    return true;
}
