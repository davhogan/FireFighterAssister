//By David Hogan
//email: davhogan@pdx.edu
#include"l_node.h"
//The purpose of this class is to represent an index/location in the graph.
//The g_node has a loction and an adjaceny point to all other locations that are in the graph and within 10 miles.
class g_node
{
   public:
     //Constructors
     g_node():g_loc(NULL),head(NULL){} 
     g_node(location * &a_location);
     ~g_node();//destructor
            
      bool insert(l_node * &a_lnode);//Inserts a new item into the adjacency list
      bool disp_loc();//displays the location information
      bool disp_equip();//displays all equipment at the fire if it is a fire
      bool disp_warning();//displays the arning level of the fire if it is a fire
      bool pass_hours(float hrs);//Simulates time passing
      bool is_fire();//Checks if the location is a fire
      bool update_lvl(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h);//updates the level of the fire
      bool relieve(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id);//Relieves any over worked pieces of equipment
      bool disp_list();//Displays the adjacency list
      bool setLoc(location * &a_loc);//Set the location
      bool compare(location * &a_loc);//compares 2 locations to see if they are with in 10 miles of each other
      bool getLoc(location * &a_loc);//gets the location 
      bool getHead(l_node * &a_head);//gets the head of the adjacency list
      
   protected:
     location * g_loc;//Location information
     l_node * head;//A linear linked list of adjancent locations in the graph


};
