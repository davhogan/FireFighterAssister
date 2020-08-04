//By David Hogan
//email:davhogan@pdx.edu

#include "g_node.h"

//Destructor
g_node::~g_node()
{
  g_loc=NULL;
  delete g_loc;
  head=NULL;
  delete head;  
}

//The constructor for a g_node given a location
g_node::g_node(location * &a_loc)
{
  g_loc=a_loc;
  head=NULL;
}

//Inserts a node to the front of the adjcancey list
//Calls the l_nodes insert function
bool g_node::insert(l_node * &a_lnode)
{

  head->insert(head,head,a_lnode);
  return true;
}

//Displays the adjacency list
//Calls the l_nodes list displaying class
bool g_node::disp_list()
{  
  head->disp_list(head);
  return true;
}

//Displays a the location of the location in the graph
//Calls the location class's display function
bool g_node::disp_loc()
{
    if(g_loc==NULL)
     return false;

   g_loc->display();
  
  return true;
}

//Displays all of the equipment at the fire
//Calls the location class's display equipment list function
bool g_node::disp_equip()
{
    if(g_loc==NULL)
     return false;

  g_loc->disp_list();
   return true;
}

//Displays the warning level of the location
//Calls the location class's display warning function
bool g_node::disp_warning()
{
    if(g_loc==NULL)
     return false;

    g_loc->disp_warning();
    return true;
}
//Simulates hours passing by.
//Takes in the amount of hours to simulate.
//Calls the location class's pass hours function.
bool g_node::pass_hours(float hrs)
{
   if(g_loc==NULL)
     return false;

   g_loc->pass_hours(hrs);
   return true;
}

//Checks if the location is a fire.
//Returns true if it is.
//Calls the location class's is fire function
bool g_node::is_fire()
{
   if(g_loc==NULL)
     return false;

  return g_loc->is_fire();
}

//Updates the level of the fire.
//Takes in the new level of the fire as well as the number the id numbers for the equipment 
//Calls the location class's update level function
bool g_node::update_lvl(int lvl, int &f_id, int &t_id, int &a_id, int &s_id, int &h_id)
{
   if(g_loc==NULL)
     return false;

   g_loc->update_lvl(lvl,f_id,t_id,a_id,s_id,h_id);
   return true;
}

//Relieve any over worked equipment at the fire.
//Takes in the id numbers for the equipment 
//Calls the location class's relieve function
bool g_node::relieve(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id)
{
  if(g_loc==NULL)
     return false;
  
   g_loc->relieve_list(f_id,t_id,a_id,s_id,h_id);
   return true;
}

//Helper Function to set the location of a point in the graph. 
//Takes in the location to set
bool g_node::setLoc(location * &a_loc)
{
  if(g_loc==NULL)
     return false;
  g_loc=a_loc;
  return true;
}

//Helper Function to get the a copy of the head of the adjancey list. 
//Takes in the location to compare then calls the location class's compare function. 
//Returns true if the two locations are with in 10 miles of each other.
bool g_node::compare(location * &a_loc)
{
   if(g_loc==NULL)
     return false;
 
  return g_loc->compare(a_loc); 

}

//Helper Function to get the a copy of the location of the adjancey list. 
//Takes in the location that will be the copy
bool g_node::getLoc(location * &a_loc)
{
  if(g_loc==NULL)
     return false;

  a_loc=g_loc;
  return true;
}

//Helper Function to get the a copy of the head of the adjancey list. 
//Takes in the l_node head that will be the copy
bool g_node::getHead(l_node * &a_head)
{
    if(head==NULL)
     return false;

    a_head=head;
   return true;
}
