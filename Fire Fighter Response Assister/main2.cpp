//By David Hogan
//email davhogan@pdx.edu
#include "graph.h"
using namespace std;

//The  purpose of this program is to repsent a bunch of fires and residental areas in proximity to each other.
//This is accomplished by reprsenting a graph adjancecy list where each element in the graph array has a location and head
//pointer to a linear linked list of nearby other location. The program has a user enter a number of locations of either fires or residental areas. 
//Then builds the graph based on the information provided about either the fire or a residence. It does this by setting
//each index in the array of g_nodes(locations and a head pointer to an adjancency list) to the given information about the location.
//Then it goes through and builds the adjancency list for each element in the array, connecting any locations with in 10 miles of each other.
//Then the program allows the user to display any adjancency list for any location. It also can display the information about the equipment at a fire,
//or increase the level of the fire,or relieve any over worked pieces of equipment or fire fighter. 
//It can also simulate time passing to simulate the hours since the fires have been added.
int main()
{
    int user_resp,num_locs,lvl=0;
    char cont='y'; 
    float hours = 0.0;
    graph obj;

    obj.build_graphArr();//create the array of g_nodes to represent a graph
    obj.get_numLocs(num_locs);//get the number of locations for checking inputs to the array
    obj.build_adj_list();//link all locations to each through adjancency lists
    
    cout<<"\nHere Are All the locations entered :\n\n";
    obj.dispArray(0);

    //While the user wants to continue displaying information about the locations in the graph   
    while(cont=='y' || cont=='Y')
    {

        cout<<"[1] To display all residental areas in proximity of a fire"<<endl;
        cout<<"[2] To display all fires in proximity of a given residence"<<endl;  
        cout<<"[3] To display the equpiment at a fire"<<endl;
        cout<<"[4] To relieve all over worked fire fighter and equipment at a fire"<<endl;
        cout<<"[5] To increase a fire's level"<<endl;  
        cout<<"[6] To simulate hours passing by"<<endl;
         
        cin>>user_resp;
        cin.ignore(100,'\n');
    
        if(user_resp < 0|| user_resp > 6)
        {
          while(user_resp < 0|| user_resp > 6)
          {
            cout<<"That isn't an acceptable command"<<endl;
            cout<<"[1] To display all residental areas in proximity of a fire"<<endl;
            cout<<"[2] To display all fires in proximity of a given residence"<<endl;  
            cout<<"[3] To display the equpiment at a fire"<<endl;
            cout<<"[4] To relieve all over worked fire fighter and equipment at a fire"<<endl;
            cout<<"[5] To update a fire's level"<<endl;  
            cout<<"[6] To simulate hours passing by"<<endl;
            cin>>user_resp;
            cin.ignore(100,'\n');
          }
        }

        if(user_resp==1)//Display residences near a fire
        {
          cout<<"Enter the index of the fire: ";
          cin>>user_resp;
          cin.ignore(100,'\n');
          
          if(user_resp < 0|| user_resp > num_locs)
          {
            while(user_resp < 0|| user_resp > num_locs)
            {
              cout<<"That isn't an acceptable index"<<endl;
              cout<<"Enter the index of the fire: ";
              cin>>user_resp;
              cin.ignore(100,'\n');
            }
          }
           obj.disp_adj(user_resp);
        }

        else if(user_resp==2)//display fires adjacent to a residence
        {
          cout<<"Enter the index of the residence: ";
          cin>>user_resp;
          cin.ignore(100,'\n');
          
          if(user_resp < 0|| user_resp > num_locs)
          {
            while(user_resp < 0|| user_resp > num_locs)
            {
              cout<<"That isn't an acceptable index"<<endl;
              cout<<"Enter the index of the residence: ";
              cin>>user_resp;
              cin.ignore(100,'\n');
            }
          }
          obj.disp_adj(user_resp);
        }

        else if(user_resp==3)//display equipment
        {
          cout<<"Enter the index of the fire: ";
          cin>>user_resp;
          cin.ignore(100,'\n');
          
          if(user_resp < 0|| user_resp > num_locs)
          {
            while(user_resp < 0|| user_resp > num_locs)
            {
              cout<<"That isn't an acceptable index"<<endl;
              cout<<"Enter the index of the fire: ";
              cin>>user_resp;
              cin.ignore(100,'\n');
            }
          }
          obj.disp_equip(user_resp);
        }

        else if(user_resp==4)//relieve overworked equipment
        {
          cout<<"Enter the index of the fire: ";
          cin>>user_resp;
          cin.ignore(100,'\n');
          
          if(user_resp < 0|| user_resp > num_locs)
          {
            while(user_resp < 0|| user_resp > num_locs)
            {
              cout<<"That isn't an acceptable index"<<endl;
              cout<<"Enter the index of the fire: "<<endl;
              cin>>user_resp;
              cin.ignore(100,'\n');
            }
          }
          obj.relieve(user_resp);
        }
        
        else if(user_resp==5)//Increase the level of the fire
        {
          cout<<"Enter the index of the fire: "<<endl;
          cin>>user_resp;
          cin.ignore(100,'\n');
          
          if(user_resp < 0|| user_resp > num_locs)
          {
            while(user_resp < 0|| user_resp > num_locs)
            {
              cout<<"That isn't an acceptable index"<<endl;
              cout<<"Enter the index of the fire: "<<endl;
              cin>>user_resp;
              cin.ignore(100,'\n');
            }
          }
          
         cout<<"Enter the new level of the fire: ";
         cin>>lvl;
         cin.ignore(100,'\n');
         
         obj.update_fire(lvl,user_resp);
 
        }
        
        else if(user_resp==6)//simulate hours passing
        {
          cout<<"Enter the number of hours to simulate having passed: ";
          cin>>hours;
          cin.ignore(100,'\n');
     
          obj.pass_hours(hours);  
            
        }
       
       cout<<"Would you like to do anything else?(y/n): ";
       cin>>cont;
       cin.ignore(100,'\n');
       cout<<"cont is: "<<cont<<endl;
    }
 
  
 return 0;
}
