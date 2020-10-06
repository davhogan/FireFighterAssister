# FireFighterAssister

The  purpose of this program is to repsent a bunch of fires and residental areas in proximity to each other.
This is accomplished by reprsenting a graph adjancecy list where each element in the graph array has a location and head pointer to a linear linked list of nearby other location. The program has a user enter a number of locations of either fires or residental areas.  
Then builds the graph based on the information provided about either the fire or a residence. It does this by setting each index in the array of g_nodes(locations and a head pointer to an adjancency list) to the given information about the location.
Then it goes through and builds the adjancency list for each element in the array, connecting any locations with in 10 miles of each other.
Then the program allows the user to display any adjancency list for any location. It also can display the information about the equipment at a fire,
or increase the level of the fire,or relieve any over worked pieces of equipment or fire fighter. 
It can also simulate time passing to simulate the hours since the fires have been added.
