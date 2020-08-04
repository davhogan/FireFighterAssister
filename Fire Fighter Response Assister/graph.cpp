//By David Hogan
//Email: davhogan@pdx.edu
#include "graph.h"
using namespace std;
//Constructor of the array of g_nodes given a number of locations.
graph::graph(int a_num_locs)
{
   f_id=0;
   t_id=0;
   a_id=0;
   s_id=0;
   h_id=0;
   num_locs=a_num_locs;
   array=new g_node[num_locs];
}
//Destructor
graph::~graph()
{
     array=NULL;
     delete array;

}
//This function adds a location to adjancey 
//It takes in the index of the point in the graph to add as well as the source(current index).
//It then copies the location from the point to add and adds it to the adjancey list of the source.
//Then it adds the location from the source to the the adjancey list of the point to add
bool graph::add_adjacent(int to_add,int source)
{
   location * a_loc=NULL;
 
  //Get the location at the index of array in the graph to add
   array[to_add].getLoc(a_loc);
   
   //Create a new node setting its with to_add, the location to add to the adjacency list and then inserting it to the front of the adjacency list. 
   l_node * new_lnode = new l_node(a_loc);
   array[source].insert(new_lnode);

   //Get the location at the index of the source
   array[source].getLoc(a_loc);
    
   //Adding the source to the adjancey list of to_add
   //Create a new node setting its with the source, the location of the source to the adjacency list and then inserting it to the front of the adjacency list.
   new_lnode = new l_node(a_loc);
   array[to_add].insert(new_lnode);

  return true;

}

//This function is used to build the adjancey list.
//The function goes through all points in the graph and compares their location the rest of the location in the graph.
//If a 2 locations are with in 10 miles of each then they each get added to each others adjancey lists.
bool graph::build_adj_list()
{
    location * temp = NULL;
    //Go through the array
    for(int i=0;i<num_locs;++i)
    {
      //Check every other element in the array
      for(int j=i+1;j<num_locs;++j)
      {
        array[j].getLoc(temp);
          
          if(array[i].is_fire())//check if it is a location of a fire
          {
            if(array[i].compare(temp)&&!array[j].is_fire())//check if the location is with range and a residence
            {
              cout<<"in range"<<endl;
              add_adjacent(j,i);//add to adjacency list
            }
        }
      }
    }

   return true;
}

//This function is used to build the array of g_nodes that represents the graph.
//The function asks the user how many location they plan on adding and then creates a new array that is the size of the excpected amount of locations.
//The function then goes through every index in the array and fills it based on the given information by the user.
bool graph::build_graphArr()
{
    bool is_dry;
    int user_num_locs=0;
    char type_loc, user_resp='\0';
    float user_lat,user_long,user_acres=0.0;
    char name[140]={'\0'};
    location * new_loc = NULL;
   
     cout<<"When entering locations. Please enter the locations of all the fires first"<<endl;
    //Find out how many locations are in the graph
    cout<<"Enter the number of total number of residental and fire locations you would like to enter: ";
    cin>>user_num_locs;
    cin.ignore(100,'\n');
    
    num_locs=user_num_locs;//set the number of locations in the graph
    array=new g_node[num_locs];//Create the array of g_nodes
   
    for(int i=0;i<num_locs;++i)
    {
        
        cout<<"Enter the coordinates of the latitude,longitude.Please input as lat,long :";
        cin>>user_lat>>user_resp>>user_long;
        cin.ignore(100,'\n'); 
        cout<<"Is the location of a:\nStructrual Fire(S)\nWild Fire(W)\nResidence(R)\n";
        cin>>type_loc;
        cin.ignore(100,'\n');

        if(type_loc=='S'||type_loc=='s'||type_loc=='W'||type_loc=='w')
        {
           cout<<"Enter the size of the fire in acres: ";
           cin>>user_acres;
           cin.ignore(100,'\n');

           cout<<"Is the area of the fire dry?(y/n): ";
           cin>>user_resp;
           cin.ignore(100,'\n');

           if(user_resp=='y'||user_resp=='Y')
             is_dry=true;
           else
             is_dry=false;

           if(type_loc=='W'||type_loc=='w')
           {
              cout<<"Does the wild fire need aerial support?(y/n):";
              cin>>user_resp;
              cin.ignore(100,'\n');
              
              if(user_resp=='y'||user_resp=='Y')
              {
                  new_loc= new location(user_lat,user_long,'A',f_id,t_id,a_id,s_id,h_id,user_acres,is_dry);
              }
          }
          
          new_loc= new location(user_lat,user_long,type_loc,f_id,t_id,a_id,s_id,h_id,user_acres,is_dry);
        }
        else 
        {
           cout<<"What is the name of the residence?:";
           cin.get(name,139,'\n');
           cin.ignore(100,'\n');
            
           new_loc= new location(user_lat,user_long,name);

        }
      
       g_node * temp = new g_node(new_loc);
       array[i] = *(temp);
    }

  return true;
}

//Helper function to relieve all over worked pieces of equipment at a fire. 
//Takes in the index of the point in the array where the fire is located.
//Calls the relieve function in the g_node class sending in all of the id numbers.
bool graph::relieve(int index)
{
    array[index].relieve(f_id,t_id,a_id,s_id,h_id);
    return true;
}

//Helper function to update a level of a given fire.
//Takes in the index of the point in the array where the fire is located.
// Calls the update level function in the g_node class sending in all of the id numbers.
bool graph::update_fire(int lvl,int index)
{
    array[index].update_lvl(lvl,f_id,t_id,a_id,s_id,h_id);   
    return true;
}

//Function to simulate hours having passed 
//Takes in the amount of hours to simulate.
//Goes through the array updating all pieces of equipment to the new work hours.
//Calls the pass_hours function in the g_node class
bool graph::pass_hours(float hrs)
{
   for(int i=0;i<num_locs;++i)
   {
    array[i].pass_hours(hrs);
   }  
   return true;
}

//Helper function to get the number of locations in the graph.
//Takes in a number to be set to the number of locations by reference
bool graph::get_numLocs(int &a_num)
{
   a_num=num_locs;
   return true;
}

//Displays all adjacent locations for a given index of the array that is passed in
//Calls the g_nodes display list function
bool graph::disp_adj(int index)
{
   array[index].disp_list();
   return true;
}

//Displays all equipment for a given index of the array, that is passed in
//Vhecks if the location is a fire and then calls the equipment display function in the g_node class
bool graph::disp_equip(int index)
{
   if(array[index].is_fire())
   {
      cout<<"List of equipment: \n";
      array[index].disp_equip();
      return true;
   }
   return false; 
}
//Displays the every location in the array.
//Recursively goes through and displays the location and the index number for every element in the array.
bool graph::dispArray(int start)
{
   if(start>=num_locs)
     return false;
    
    //display the location 
    cout<<"\nIndex of location is: "<<start<<endl;
    array[start].disp_loc();
    cout<<endl; 
    dispArray(++start);
    return true;
}
