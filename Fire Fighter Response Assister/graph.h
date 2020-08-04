//By David Hogan
//email:davhogan@pdx.edu
#include "g_node.h"
//The purpose of this class is to represent a graph of locations.
//Where each location that is within 10 miles is linked together.
//To accomplish this every element in the array has a head pointer to linear linked list that represents the adjancency list.
//The graph also knows how many elements are in it, and it has all of the id numbers for each piece of equipment.
class graph
{

   public:
          //Constructors
          graph():num_locs(0),array(NULL){}
          graph(int a_num_locs);
          
         ~graph();//Destructor
         
          bool add_adjacent(int to_add,int source);//adds a location to the adjancency list
          bool build_graphArr();//builds the array g_nodes to represent the graph
          bool build_adj_list();//Goes through th array and links up all location with in 10 miles of each other
          bool relieve(int index);//Relieves all pieces of over worked equipment at a given index in the array
          bool update_fire(int lvl,int index);//Update the level of a fire at a given index in the array
          bool pass_hours(float hrs);//Simluates time passing
          bool get_numLocs(int &a_num);//Gets the number of elements in the array
          bool disp_adj(int index);//Displays the adjacency list for a given index in the array
          bool disp_equip(int index);//Displays the equipment at a location a given index in the array
          bool dispArray(int start);//Dispalys information of the location at every element in the array
   
  protected:
          int f_id;//id number for a fire fighter
          int t_id;//id number for a fire truck
          int a_id;//id number for an atv
          int s_id;//id number for an suv
          int h_id;//id number for a helicopter
          int num_locs;//number of elements in the array
          g_node * array;//The array of g_nodes to represent the graph

};
