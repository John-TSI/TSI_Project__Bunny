# TSI_Project__Bunny
  
Project Outline 
---------------  
A C++ program built to meet the specifications of the Bunny Project:  
  
A list of bunny objects with randomly assigned attributes is created at program initialisation. Each subsequent turn the bunnies grow older, and can breed if certain conditions are satisfied. A boolean attribute determines whether each bunny is 'infected', with infected bunnies having an extended lifespan while being excluded from the breeding process; this infected status spreads to a number of healthy bunnies each turn. The user is provided with terminal output announcing all births and deaths each turn, along with a printed list of all living bunnies and their various attribute values. The program terminates once all bunnies have died.    
  
--------------------------------------------------------------------  
  
User Interaction:  
-----------------  
The user advances the program by one turn each time a key input is supplied. At any point during execution they can input 'k' to implement a cull of the population (randomly selecting and killing half of all bunny objects currently listed), or 'q' to terminate the program.  
  
--------------------------------------------------------------------  
  
Program Structure:  
------------------  
The program is comprised of a source file containing the program entry point, and two classes each separated into their own header and source files. 
  
The bunny header file contains the attribute members of the Bunny class, together with declarations for a constructor and getter/setter methods. This file also contains definitions for some vectors and enum classes used during object construction, and unordered maps used when printing output to the user. The Field class acts as the program's manager, and is responsible for storing, manipulating, and modifying bunny objects, in addition to controlling the program flow. The main source file consists of a simple while loop which makes repeated calls to the Advance() method of the Field class, so long as at least one bunny is alive and the user has not requested that the program terminates early.  
  
--------------------------------------------------------------------  
  
Design Notes:  
-------------  
- The Field class contains a standard container list attribute which stores unique pointers to bunny objects, and this list is operated upon by Field methods using iterators. This design was deemed convenient for the repeated add/remove operations necessary during program execution, in addition to ensuring that borrowed heap memory is properly deallocated. 
- The Bunny class originally had two constructors: a default constructor called when creating the initial five bunny objects, and a version which accepted a unique pointer to a bunny object by reference. This design was later modified so that the class requires only a single non-default constructor making use of an initialisation list, in which the 'colour' attribute is assigned a value determined by whether the unique pointer passed by reference as the constructor's argument points to a valid bunny object.  
  
--------------------------------------------------------------------  
  
Development Notes:  
------------------  
Development of the program included the creation of separate feature branches to implement additional functionality beyond the project's minimum requirements:  
  
- branch 'MakeInfected' was used to develop and test the 'SpreadInfection' method of class Field.  
- branch 'FoodShortage' was used to develop and test the 'MassCull' method of class Field.  
- branch 'InputCull' was used to develop and test the extra feature which allows the user to manually initiate a population cull with a key input.  
- branch 'NoMaxCount' was used to develop and test the extra feature which allows the user to remove the maximum population limit.  
  
These feature branches were each merged with the main development branch once their respective functionalities had been tested. Another feature branch, 'Real-Time', was created to develop additional functionality which would allow the program to print updates to the user in real-time. Work towards the implementation of this feature is ongoing, and hence this branch has not yet been merged with the main development branch.
