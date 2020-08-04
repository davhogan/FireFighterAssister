//By David Hogan
//email davhogan@pdx.edu
#include "d_node.h"
//The puropse of these classes is to represent a fire.
//A fire has a size in acres, a radius(assume fire is circular), check if it is dry, a level of danger
//It also has a doubley linked list of pieces of equipment ordered by their hours worked.
//It also has variables to know how many of each kind of equipment are in the list.
//The fire builds and maintains the list based on the size of the fire.
 
//Base Class
class fire
{
   public:
 
        fire(){};//default constructor

        //constructor when give the size and if it is dry
        fire(int n_acres, bool dry):acres(n_acres),dryness(dry)
        {
           radi=sqrt(acres/M_PI);
           if(dryness)
            ++lvl;
            if(lvl>5)
             lvl=5;
           head=NULL;
        } 
      
      virtual ~fire();//destructor to be invoked by the child classes
    
      bool build_list(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id);//builds a list of equipment assigning them id numbers 
      virtual bool equip_assign(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h);//Assigns the variables representing the number of each equipment
      bool relieve_list(int &n_f, int &n_t, int &n_a, int &n_s, int &n_h);//Relieves overworked equipment. Helper function to call the d_nodes relieve function
      bool hours_pass(float hrs);//Simulates hours passing 
      bool update_lvl(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h);//update the level of the fire takes in the new lvl and the id numbers
      virtual bool display();//displays all information about the fire aside from the list
      bool disp_list();//displays the list of equipment
      bool disp_warning();//displays the warning level for the fire

   protected:
        int n_fighters;//number of firefighters
        int n_trucks;//number of fire trucks
        int n_atvs;//number of ATVs
        int n_suvs;//number of SUVs
        int n_helis;//number of helicopters
        float acres;//size of the fire in acres
        float radi;//radius from the center of the fire
        bool dryness;//whether or not it's dry
        int lvl;//The danger level of the fire
        d_node* head;//DLL of equipment at the fire
};

//Child class of fire used to represent a structral fire
class s_fire: public fire
{
   public:
   //Constructors 
   s_fire();
   s_fire(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry);
  //Destructor
  ~s_fire();
    
   bool equip_assign(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_hv);//assign equipment number variables
   bool display();//display info about the fire not the list
   bool disp_list();//displays the DLL list of equipment
};

//Child class of fire used to represent a wildfire
class w_fire: public fire
{
   public:
   //Constructors
   w_fire();
   w_fire(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry);
  //Destructors
  ~w_fire();
   bool equip_assign(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_hv);//assign equipent variables
   bool display();//display all info of fire except the list
   bool disp_list();//display DLL of equipment
};

   
//Child Class of the fire to rerpesent an ariel fire
class ar_fire: public fire
{
   public:
   //Constructors
   ar_fire();
   ar_fire(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry);
  //Destructors
  ~ar_fire();
    bool equip_assign(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_hv);//assign equipent variables
   bool display();//display all info of fire except the list
   bool disp_list();//display DLL of equipment
};

  

