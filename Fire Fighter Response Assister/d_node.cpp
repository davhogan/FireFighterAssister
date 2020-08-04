//By David Hogan
//email davhogan@pdx.edu
#include "d_node.h"

//Constructor 
//Creates a new type of equipment based on the type sent in 
d_node::d_node(char a_type, int an_id)
{
  if(a_type=='F')
   an_equip=new fighter(an_id);
  if(a_type=='T')
   an_equip=new truck(an_id);
  if(a_type=='A')
   an_equip=new atv(an_id);
  if(a_type=='S')
   an_equip=new suv(an_id);
  if(a_type=='H')
   an_equip=new helicopter(an_id);
  //Test
  next=NULL;
  prev=NULL;
}

//Destructor
d_node::~d_node()
{
  an_equip=NULL;
  delete an_equip;
}
//Inserts into the doubley linked list recursively.
//It inserts the least worked pieces of equipment to the front.

bool d_node::insertEquip(d_node * &a_head, d_node* &current, d_node* &to_add)
{
  float to_add_hours;//hours for the equipment to add
  float curr_hours;//hours for the current equipment to add
 
  //Check if the equipment to add exists
  if(to_add==NULL)
   return false;
  to_add->an_equip->getHours(to_add_hours);//Get the hours of the piece of equipment to add
 
  //Check if list is empty because head will be passed into current
  if(current==NULL)//List is empty
     curr_hours=0.0;
  else
    current->an_equip->getHours(curr_hours);//Get the hours of the current piece of equipment
  
  //Check if list is empty
  if(a_head==NULL)
  {
   to_add->next=NULL;
   to_add->prev=NULL;   
   a_head=to_add;//Add the equipment
   return true;
  }
  //Check if the hours to add is less than the hours of the current planet
  else if(to_add_hours <= curr_hours)
  {
    to_add->prev=current->prev;
    to_add->next=current;
    //Inserting at the front of a non empty list
    if(current->prev == NULL)
    {   
        current->prev=to_add;
        to_add->next=current;
        to_add->prev=NULL;
        a_head=to_add;//Point head to the new front of the DLL      
      
        
       return true; 
    }
    
    else//Inserting in the middle of the list
     current->prev->next=to_add;
     to_add->prev=current->prev;
     current->prev=to_add; 
     return true;
  }
  
  //Inserting at the end of the list
  else if(current->next==NULL)
   {
     current->next=to_add;
     to_add->next=NULL;
     to_add->prev=current;
     return true;
  }
  
  else
    //Recurssive Step
    insertEquip(a_head,current->next,to_add);
  return false;
   
}

//Goes through and removes a piece of equipment that is passed into it recursively
bool d_node::removeEquip(d_node * &a_head, d_node* &current, d_node* &to_remove)
{
  //Check if list is empty
  if(a_head==NULL||to_remove==NULL)
  {
   return false;
  }
  // 1 equipment in the list
  else if(a_head->next==NULL&&a_head==to_remove)
  {
   a_head=NULL;
   return true;
  }
  // 2 or more equipments in the list
  else if(to_remove==current)
  {

   //Removing from the front of a list with more than 1 equipment
    if(a_head==current)
    {   
        a_head=current->next;//Point head to the new front of the DLL      
        
        current->next->prev=NULL; 
        return true;
    }
    //Removing from the end of a list 
    if(current->next==NULL)
    {  
        current->prev->next=NULL;
        return true;
    }
   //Removing from somewhere in the middle of the list
    else
    { 
      current->next->prev=current->prev;
      current->prev->next=current->next; 
      return true;
    }

  }
  //Equipment not in the list
  else if(current->next==NULL)
  {
    return false;
  }
  else
    //Recurssive Step
    removeEquip(a_head,current->next,to_remove);
  
return true;
   
}
//Function goes through and updates any piece of over worked equipment
//Updates their hours to zero assign a new id
bool d_node::relieve(d_node* &curr, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h)
{
  char eq_type;
  bool is_over;
  
   if(curr==NULL)
    return false;
 
   curr->getType(eq_type);
   is_over=curr->checkOverHours(false);//get if the equipment is over worked
 
   //Check if the piece of equipment is over worked
   //update if it is
   if(is_over)
   {
     curr->updateHours(0.0);
    
     if(eq_type=='F')
       curr->updateId(++n_f);
     else if(eq_type=='T')
       curr->updateId(++n_t);   
     else if(eq_type=='A')
       curr->updateId(++n_a);
     else if(eq_type=='S')
       curr->updateId(++n_s);
     else 
       curr->updateId(++n_h);
   }
//Recursive step
   relieve(curr->next,n_f,n_t,n_a,n_s,n_h);

 return false;
}
 
//helper to update hours
bool d_node::updateHours(float updated_hours)
{
  an_equip->updateHours(updated_hours);
 return true;
}
//helper update id of equipment
bool d_node::updateId(int updated_id)
{
  an_equip->updateId(updated_id);
 return true;
}
//helper get hours of equipment
bool d_node::getHours(float &hours_worked)
{
   an_equip->getHours(hours_worked);
   return true;
}
//helper gets type of equipment
bool d_node::getType(char &a_type)
{
   an_equip->getType(a_type);
   return true;
}
//helper to check if equipment is over worked
bool d_node::checkOverHours(bool disp)
{
  return an_equip->checkOverHours(disp);
}
//Recursively goes through the list to find the largest peice of a specific type of equipment and returns it
d_node*& d_node::largest_hrs(d_node* curr, d_node* &lrg, char a_type)
{
    char  curr_type;
    float curr_hrs,lrg_hrs;
   
    if(lrg==NULL)//list is empty
     return lrg;
    else
     lrg->getHours(lrg_hrs);//Get the distance from the sun of the planet to add
 
  //Check if list is empty because head will be passed into current
  if(curr==NULL)//List is empty
     curr_hrs=0.0;
  else
    curr->getHours(curr_hrs);
    
    //base case
    if(curr==NULL||lrg==NULL)
       return lrg;
    
    curr->getType(curr_type);
   //Check if the current is larger the known largest hours
  if(curr_type==a_type&&curr_hrs>=lrg_hrs)
       lrg=curr;
   
   //Recursive step
    largest_hrs(curr->next,lrg,a_type);
  return lrg; 
}
//Display all pieces of equipment in a list
bool d_node::display(d_node *&a_head)
{
   if(a_head==NULL)
    return false;
   
    a_head->an_equip->display();
 
   display(a_head->next);   
   
   return true;
}
//Simulate hours passing
bool d_node::hours_pass(d_node * &a_head,float hrs)
{
      if(a_head==NULL)
        return false;

      a_head->an_equip->updateHours(hrs);
      //Recurrisive Step
      hours_pass(a_head->next,hrs);
  return false;
}
//Display all over worked equipment
bool d_node::over_display(d_node * &a_head)
{
   if(a_head==NULL)
     return false;
   
    a_head->an_equip->checkOverHours(true);   
  
   over_display(a_head->next);
  
  return false;
}
