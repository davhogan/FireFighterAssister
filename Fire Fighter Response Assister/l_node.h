#include "location.h"
#include <string.h>

//The purpose of this class is to represent a node in a linear linked list. The node has a location of either a fire or a residance and a pointer to the next node in the list
class l_node
{
   public:
   
   l_node():a_loc(NULL),next(NULL){}//default constructor
   l_node(location * &a_location); 
   l_node(int a_dest,float a_latitude, float a_longitude, char a_type, char * a_name, int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry);//constructor for creting a new location
   ~l_node();//Destructor

   bool insert(l_node * &a_head,l_node * &curr, l_node * &to_add);//Insert function to insert at the front of the list
   bool disp_list(l_node * &a_head);//Display locations in the list
   bool disp_loc();
   bool disp_warning(l_node * &a_head);//Display all warning for residance in the list

   protected:
   location * a_loc;//a location of either a fire or a residance
   l_node * next;


};
