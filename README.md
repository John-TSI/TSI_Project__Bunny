# TSI_Project__Bunny
  
Project Outline 
---------------  
A C++ program built to meet the specifications of the Bunny Project:  
  
A list of bunny objects with randomly assigned attributes is created at program initialisation. Each subsequent turn the bunnies grow older, and can breed if certain conditions are satisfied. A boolean attibute determines whether each bunny is 'infected', with infected bunnies having an extended lifespan while being excluded from the breeding process; this infection spreads to a number of healthy bunnies each turn. The user is provided with a terminal output announcing all births and deaths each turn, along with a pritned list of all living bunnies and their various attributes. The program terminates once all bunnies have died.    
  
--------------------------------------------------------------------  
  
User Interaction:  
-----------------  
The user advances the program by one turn each time a key input is supplied. At any point during execution they can input 'k' to implement a cull of the population (randomly selecting and killing half of all bunny objects currently listed), or 'q' to terminate the program.  
  
--------------------------------------------------------------------  
  
Program Structure:  
------------------  
The program is comprised of a source file containing the program entry point, and two classes each separated into their own header and source files. 
  
The bunny header file contains the required attribute members of the Bunny class, together with declarations of a constructor and getter/setter methods. This file also contains definitions of some vectors and enum classes used during object construction, and unordered maps used when printing output to the user. The Field class acts as the program's manager, and is responsible for storing, manipulating, and modifying bunny objects, in addition to controlling the program flow. The main source file consists of a simple while loop, which makes repeated calls to the Advance() method of the Field class so long as at least one bunny is alive and the user has not requested that the program terminates.  
  
--------------------------------------------------------------------  
  
Design Notes:  
-------------  
- The Field class contains a standard container list attribute which stores unique pointers to bunny objects, and this list is operated upon by Field methods using iterators.  
- The Bunny class originally had two constructors: a default constructor called from the Field method Initialise(), and a version which accepted a unique pointer to a bunny object by reference. This design was later modified so that the class requires only a single non-default constructor making use of an initialisation list, wherein the 'colour' attribute is assigned a value based on whether or not the pointer passed as the constructor argument points to a valid bunny object.  
  
--------------------------------------------------------------------  
  
Development Notes:  
------------------  
Development of the program included the use of separate feature branches to implement new functionality:  
  
- branch 'MakeInfected' was used to develop and test the 'SpreadInfection' method of class Field.  
- branch 'FoodShortage' was used to develop and test the 'MassCull' method of class Field.  
- branch 'InputCull' was used to develop and test the extra feature which allows the user to initiate a population cull with a key input.  
- branch 'NoMaxCount' was used to develop and test the extra feature which allows the user to remove the maximum population limit.  
  
These feature branches were each merged with the main development branch once their respective additional functionalities had been tested. 
