//By David Hogan
//email davhogan@pdx.edu
#include "fire.h"
using namespace std;

//This function is virtual and will be implmented by the child fires
bool fire::display()
{
 return true;
}

//Assigns the numbers of each type of equipment based on the level.
//takes in the level of fire and the variables for the number of equpiments
bool fire::equip_assign(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_hv)
{
  return true;
}
//This function builds the doubley linked list of equipment based on how many of each number of equipment there are. It also takes in the id number for each tyoe of equipment so they can be assigned.
bool fire::build_list(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id)
{
   int i;
   //For loops to create new pieces of equipment depending on how many there are for the fire
   for(i=0;i<n_fighters;++i)
   {
     ++f_id;
     d_node * fF = new d_node('F',f_id);
     fF->insertEquip(head,head,fF);
   }
   
   for(i=0;i<n_trucks;++i)
   {
     ++t_id;
     d_node * fT = new d_node('T',t_id);
     fT->insertEquip(head,head,fT);
   }

   for(i=0;i<n_atvs;++i)
   {
     ++a_id;
     d_node * fA = new d_node('A',a_id);
     fA->insertEquip(head,head,fA);
   }
   
   for(i=0;i<n_suvs;++i)
   {
     ++s_id;
     d_node * fS = new d_node('S',s_id);
     fS->insertEquip(head,head,fS);
   }

   for(i=0;i<n_helis;++i)
   {
     ++h_id;
     d_node * fH = new d_node('H',h_id);
     fH->insertEquip(head,head,fH);
   }

  return true; 
}

//Destructor just does the opposite of building the list
fire::~fire()
{}

//Helper function to relieve anyone over worked in the list. Takes in the id numbers in case anyone new has to be assigned. Just calls the d_nodes relieve function
bool fire:: relieve_list(int &n_f, int &n_t, int &n_a, int &n_s, int &n_h)
{
  head->relieve(head,n_f,n_t,n_a,n_s,n_h);
  return true;
}

//Simulates the amount of hours passed.
//It takes in the hrs to simulate passing
//calls d_node hours pass function
bool fire::hours_pass(float hrs)
{
   head->hours_pass(head,hrs);
   return true;
}
//This funstion is to update a fires level and then to update the list accordingly. Either growing larger or smaller.
//The fire takes in the new level of the fire and the id numbers in case new equipment has to be assigned
bool fire::update_lvl(int a_lvl,int &f_id, int &t_id, int &a_id, int &s_id, int &h_id)
{
  int new_f,new_t,new_a,new_s,new_h=0;//new number of each equipment
  int chng_f,chng_t,chng_a,chng_s,chng_h=0;//difference between new and old level
  int i;
  d_node * temp;
  equip_assign(a_lvl,new_f,new_t,new_a,new_s,new_h);
  //If the level is raised 
  if(a_lvl > lvl)
   {
     //Calculate differnce between new to old
     chng_f= new_f - n_fighters;
     chng_t= new_t - n_trucks;
     chng_a= new_a - n_atvs;
     chng_s= new_s - n_suvs;
      chng_h= new_h - n_helis;
    //For loops to fill up the list with more equipment based on the change in level
      for(i=0;i<chng_f;++i)
      {
       ++f_id;
       d_node * fF = new d_node('F',f_id);
       fF->insertEquip(head,head,fF);
      }
   
      for(i=0;i<chng_t;++i)
      {
        ++t_id;
        d_node * fT = new d_node('T',t_id);
        fT->insertEquip(head,head,fT);
      }

      for(i=0;i<chng_a;++i)
      {  
        ++a_id;
        d_node * fA = new d_node('A',a_id);
        fA->insertEquip(head,head,fA);
      }
   
      for(i=0;i<chng_s;++i)
      {
       ++s_id;
       d_node * fS = new d_node('S',s_id);
       fS->insertEquip(head,head,fS);
      }

     for(i=0;i<chng_h;++i)
     {
       ++h_id;
       d_node * fH = new d_node('H',h_id);
       fH->insertEquip(head,head,fH);
     }
     //Assign level and number of each equipment
     lvl=a_lvl;    
     n_fighters = new_f;
     n_trucks = new_t;
     n_atvs= new_a;
     n_suvs= new_s;
     n_helis= new_h;
   return true;
   }
    //If the level has been lowered
    if(a_lvl < lvl)
   {
     //Calculate difference between new and old
     chng_f= n_fighters - new_f;
     chng_t= n_trucks - new_t;
     chng_a= n_atvs - new_a;
     chng_s= n_suvs - new_s;
     chng_h= n_helis - new_h;
     //For Loops to go through and find the longest working piece of equipment and then remove it until the number of equioment needed is corrected based on the level
      for(i=0;i<chng_f;++i)
      {
       d_node * fF = head->largest_hrs(head,head,'F');
       temp=head;
       fF->removeEquip(head,temp,fF);
       fF=NULL;
       delete fF;
      }
   
      for(i=0;i<chng_t;++i)
      {
       d_node * fT = head->largest_hrs(head,head,'T');
       temp = head;
       fT->removeEquip(head,temp,fT);
       fT=NULL;
       delete fT;
     }

      for(i=0;i<chng_a;++i)
      { 
        d_node * fA = head->largest_hrs(head,head,'A');
        temp=head;
        fA->removeEquip(head,temp,fA);
        fA=NULL;
        delete fA; 
     }
   
      for(i=0;i<chng_s;++i)
      { 
        d_node * fS = head->largest_hrs(head,head,'S');
        temp=head;
        fS->removeEquip(head,temp,fS);
        fS=NULL;
        delete fS;
      }

     for(i=0;i<chng_h;++i)
     {
       d_node * fH = head->largest_hrs(head,head,'H');
       fH->removeEquip(head,head,fH);
       fH=NULL;
       delete fH; 
    }
     //Assign new level and number of each equipment
     lvl=a_lvl; 
     n_fighters = new_f;
     n_trucks = new_t;
     n_atvs= new_a;
     n_suvs= new_s;
     n_helis= new_h;    
    
   return true;
   }

 return false;
}

//Displays the list
//Calls the display function of the the d_node
bool fire::disp_list()
{
  if(head==NULL)
   return false;
  else
   head->display(head);
  
  return true;
}

//Simple function to display the warning level message for a fire.
bool fire::disp_warning()
{

  if(lvl==1)
   cout<<"Small fire nearby. Please check back shortly for any updates"<<endl;
  else if(lvl==2)
   cout<<"Fire nearby. Please be on alert. Please check back shortly for any updates"<<endl;
   else if(lvl==3)
    cout<<"Large fire nearby. Be reasy to evacuate. Please check back shortly for any updates"<<endl;
   else if(lvl==4)
    cout<<"Large fire is dangerous. Evacuate immediatley Small fire nearby. Please check back shortly for any updates"<<endl;
   else
    cout<<"Large fire is dangerous. Evacuate immediatley Small fire nearby. Please check back shortly for any updates"<<endl;

  return true;
}
//Constructor taking in all of the id numbers for labeling as well as the number of acres a fire is and if it is dry. Assigns the level of the fire by how large it isthen assigns the correct ammount of each equipment item to the list.
s_fire::s_fire(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry)
{  
     acres=n_acres;
     radi=sqrt(acres/M_PI);
     
      if(acres<=.1)
         lvl=1;
      if(acres>.1&&acres<=.5)
         lvl=2;
      if(acres>.5&&acres<=1)
         lvl=3;
      if(acres>1&&acres<=2)
         lvl=4;
      if(acres>2)
         lvl=5;

      if(dryness)
       ++lvl;

       if(lvl>5)
         lvl=5;
      //Assign variables based on level 
      equip_assign(lvl,n_fighters,n_trucks,n_atvs,n_suvs,n_helis);
      //Build the list of equipment needed
      build_list(f_id,t_id,a_id,s_id,h_id); 
}
//destructor does the opposite of building the list
s_fire::~s_fire()
{
	int i;
	for(i=0;i<n_fighters;++i)
	{
	  d_node * fF = head->largest_hrs(head,head,'F');
	  fF->removeEquip(head,head,fF);
          fF=NULL;
          delete fF;
	}  

	for(i=0;i<n_trucks;++i)
	{
	  d_node * fT = head->largest_hrs(head,head,'T');
	  fT->removeEquip(head,head,fT);
          fT=NULL;
  	  delete fT;
	}

	for(i=0;i<n_atvs;++i)
	{ 
	  d_node * fA = head->largest_hrs(head,head,'A');
	  fA->removeEquip(head,head,fA);
	  fA=NULL;
	  delete fA; 
	 
        }

	for(i=0;i<n_suvs;++i)
	{ 
	  d_node * fS = head->largest_hrs(head,head,'S');
	  fS->removeEquip(head,head,fS);
	  fS=NULL;
	  delete fS;
       
	}

	for(i=0;i<n_helis;++i)
	{
	   d_node * fH = head->largest_hrs(head,head,'H');
	   fH->removeEquip(head,head,fH);
	   fH=NULL;
	   delete fH;
           
	}

}

//Simple functon that takes in all the different numbers of each equipment by reference then assigns them based on the level of the fire.
bool s_fire::equip_assign(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h)
{
      n_f=3*lvl;
      n_t=2*lvl;
      n_a=0;
      n_s=0;
      n_h=0;

    return true;
}
//Display function to show how information about the fire
bool s_fire::display()
{
  cout<<"Number of acres: "<<acres<<endl;
  cout<<"Radi: "<<radi<<endl;
  cout<<"The number of fighters: "<<n_fighters<<endl;
  cout<<"Trucks: "<<n_trucks<<endl;
  cout<<"The Warning Level is: "<<lvl<<endl;
  return true;
}
//Constructor taking in all of the id numbers for labeling as well as the number of acres a fire is and if it is dry. Assigns the level of the fire by how large it isthen assigns the correct ammount of each equipment item to the list.
ar_fire::ar_fire(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry)
{  
     acres=n_acres;
     radi=sqrt(acres/M_PI);
     
      if(acres<=.1)
         lvl=1;
      if(acres>.1&&acres<=.5)
         lvl=2;
      if(acres>.5&&acres<=1)
         lvl=3;
      if(acres>1&&acres<=2)
         lvl=4;
      if(acres>2)
         lvl=5;

      if(dryness)
       ++lvl;

       if(lvl>5)
         lvl=5;
      //Assign variables based on level 
      equip_assign(lvl,n_fighters,n_trucks,n_atvs,n_suvs,n_helis);
      //Build the list of equipment needed
      build_list(f_id,t_id,a_id,s_id,h_id); 
}
//Destructor does the opposite of building the list
ar_fire::~ar_fire()
{
	int i;
	for(i=0;i<n_fighters;++i)
	{
	  d_node * fF = head->largest_hrs(head,head,'F');
	  fF->removeEquip(head,head,fF);
          fF=NULL;
          delete fF;
	}  

	for(i=0;i<n_trucks;++i)
	{
	  d_node * fT = head->largest_hrs(head,head,'T');
	  fT->removeEquip(head,head,fT);
          fT=NULL;
  	  delete fT;
	}

	for(i=0;i<n_atvs;++i)
	{ 
	  d_node * fA = head->largest_hrs(head,head,'A');
	  fA->removeEquip(head,head,fA);
	  fA=NULL;
	  delete fA; 
	 
        }

	for(i=0;i<n_suvs;++i)
	{ 
	  d_node * fS = head->largest_hrs(head,head,'S');
	  fS->removeEquip(head,head,fS);
	  fS=NULL;
	  delete fS;
       
	}

	for(i=0;i<n_helis;++i)
	{
	   d_node * fH = head->largest_hrs(head,head,'H');
	   fH->removeEquip(head,head,fH);
	   fH=NULL;
	   delete fH;
           
	}

}

//Simple functon that takes in all the different numbers of each equipment by reference then assigns them based on the level of the fire.

bool ar_fire::equip_assign(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h)
{
      n_f=5*lvl;
      n_t=3*lvl;
      n_a=2*lvl;
      n_s=3*lvl;
      n_h=1*lvl;

    return true;
}

//Display function to show how information about the fire
bool ar_fire::display()
{
  cout<<"Number of acres: "<<acres<<endl;
  cout<<"Radi: "<<radi<<endl;
  cout<<"The number of fighters: "<<n_fighters<<endl;
  cout<<"Trucks: "<<n_trucks<<endl;
  cout<<"ATVs: "<<n_atvs<<endl;
  cout<<"SUVs: "<<n_suvs<<endl;
  cout<<"Helicopters: "<<n_helis<<endl; 
  cout<<"The Warning Level is: "<<lvl<<endl;
  return true;
}
//Constructor taking in all of the id numbers for labeling as well as the number of acres a fire is and if it is dry. Assigns the level of the fire by how large it isthen assigns the correct ammount of each equipment item to the list.
w_fire::w_fire(int &f_id, int &t_id, int &a_id, int &s_id, int &h_id, float n_acres, bool dry)
{  
     acres=n_acres;
     radi=sqrt(acres/M_PI);
     
      if(acres<=.1)
         lvl=1;
      if(acres>.1&&acres<=.5)
         lvl=2;
      if(acres>.5&&acres<=1)
         lvl=3;
      if(acres>1&&acres<=2)
         lvl=4;
      if(acres>2)
         lvl=5;

      if(dryness)
       ++lvl;

       if(lvl>5)
         lvl=5;
      //Assign variables based on level 
      equip_assign(lvl,n_fighters,n_trucks,n_atvs,n_suvs,n_helis);
      //Build the list of equipment needed
      build_list(f_id,t_id,a_id,s_id,h_id); 
}

w_fire::~w_fire()
{
	int i;
	for(i=0;i<n_fighters;++i)
	{
	  d_node * fF = head->largest_hrs(head,head,'F');
	  fF->removeEquip(head,head,fF);
          fF=NULL;
          delete fF;
	}  

	for(i=0;i<n_trucks;++i)
	{
	  d_node * fT = head->largest_hrs(head,head,'T');
	  fT->removeEquip(head,head,fT);
          fT=NULL;
  	  delete fT;
	}

	for(i=0;i<n_atvs;++i)
	{ 
	  d_node * fA = head->largest_hrs(head,head,'A');
	  fA->removeEquip(head,head,fA);
	  fA=NULL;
	  delete fA; 
	 
        }

	for(i=0;i<n_suvs;++i)
	{ 
	  d_node * fS = head->largest_hrs(head,head,'S');
	  fS->removeEquip(head,head,fS);
	  fS=NULL;
	  delete fS;
       
	}

	for(i=0;i<n_helis;++i)
	{
	   d_node * fH = head->largest_hrs(head,head,'H');
	   fH->removeEquip(head,head,fH);
	   fH=NULL;
	   delete fH;
           
	}

}
//Simple functon that takes in all the different numbers of each equipment by reference then assigns them based on the level of the fire.
bool w_fire::equip_assign(int lvl, int &n_f, int &n_t, int &n_a, int &n_s, int &n_h)
{
      n_f=3*lvl;
      n_t=2*lvl;
      n_a=4*lvl;
      n_s=4*lvl;
      n_h=0;

    return true;
}
//Display function to show how information about the fire
bool w_fire::display()
{
  cout<<"Number of acres: "<<acres<<endl;
  cout<<"Radi: "<<radi<<endl;
  cout<<"The number of fighters: "<<n_fighters<<endl;
  cout<<"Trucks: "<<n_trucks<<endl;
  cout<<"ATVs: "<<n_atvs<<endl;
  cout<<"SUVs: "<<n_suvs<<endl;
  cout<<"The Warning Level is: "<<lvl<<endl;
  return true;
}
