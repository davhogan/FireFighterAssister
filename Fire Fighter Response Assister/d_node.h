#include "equipment.h"
//The puropse of this class is to represent a node in a doubley linked list
//As well as to help build and display that list
//The node has a piece of equipment
//It also has a next and previous pointer to other items in the list.
class d_node
{
  public:
        //Constructors
        d_node():an_equip(NULL),next(NULL),prev(NULL){}
        d_node(char a_type, int an_id);//a_type is the kind of equipment
        ~d_node();//destructor
        bool insertEquip(d_node * &a_head, d_node* &current, d_node* &to_add);//insert a new piece of equipment into a list
        bool removeEquip(d_node * &a_head, d_node* &current, d_node* &to_remove);//remove a piece of equiment from the list
        bool relieve(d_node* &curr, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h);//update the list to relieve all over worked equipment
        bool updateHours(float updated_hours);//update the hours equipment has worked
        bool updateId(int updated_id);//update the Id of the
       //Helper functions
        bool getHours(float & hours_worked);
        bool getType(char &a_type);
        bool checkOverHours(bool disp); 
        //Finds the a specific type of equipment that has worked the longest
        d_node*& largest_hrs(d_node* curr,d_node* &lrg, char a_type);  
        
        bool display(d_node * &a_head);//display the list
        bool over_display(d_node * &a_head);//display every equipment that is over worked
        bool hours_pass(d_node * &a_head,float hrs);//simulate hours passing
  protected:
        equip * an_equip;
        d_node * next;
        d_node * prev;

};
