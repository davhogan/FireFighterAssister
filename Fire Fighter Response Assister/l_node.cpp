#include "l_node.h"
using namespace std;

//Constructor for an l_node that takes in all variables needed to crete a new location object.
l_node::l_node(int a_dest,float a_latitude, float a_longitude, char a_type, char * a_name, int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry)
{
   a_loc=new location(a_latitude,a_longitude,a_type,f_id,t_id,a_id,s_id,h_id,n_acres,dry);
   next=NULL;
}

//Constructor given a destination and a location pointer
l_node::l_node(location * &a_location)
{
   a_loc=a_location;
   
}
//Destructor
l_node::~l_node()
{
   a_loc=NULL;
   delete a_loc;
}

//Recursively insert into the linear linked list. The function takes in a head pointer and a pointer to the current l_node. Then recurively travels to the end of thelist and add the new location. The function has to taken in a lot of information for an location so it can properly create one.
bool l_node::insert(l_node * &a_head, l_node * &curr,l_node *& to_add)
{
  //base case
  if(a_head==NULL) 
  {
    a_head=to_add;
   return false; 
  }
  //insert at the end of the list
  else if(curr->next==NULL)
  { 
     to_add->next=a_head;
     a_head=to_add;
      return true;
   } 
  //recurssive step
  insert(a_head,curr->next,to_add);

 return false;
}

//Recursively displays the information about a locationusing the locations display function.
bool l_node::disp_list(l_node * &a_head)
{
   //base case
   if(a_head==NULL)
    return false;
   
   //call disp of location
   a_head->a_loc->display();
   std::cout<<"\n";
   //Recursive 
   disp_list(a_head->next);

  return true;
}

bool l_node::disp_loc()
{
  a_loc->display();
  return true;
}

//Function to recursively display any warnings for a fire using the disp warning function in the location class
bool l_node::disp_warning(l_node * &a_head)
{
   //base case
   if(a_head==NULL)
    return false;
   
   //call disp of location
   a_loc->disp_warning();
   
   //Recursive 
   disp_warning(a_head->next);

  return true;
}


