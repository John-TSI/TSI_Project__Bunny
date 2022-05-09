# TSI_Project__Bunny

A C++ program built to meet the required project specifications described below.

--------------------------------------------------------------------------------  

PROJECT OUTLINE:

Write a program that creates a list of bunny objects. Each bunny object must have:  
Sex: 		Male, Female (50/50 randomly assigned at creation)  
Colour: 		White, Brown, Black, Spotted  
Age: 		0-10 (years old)  
Name: 		Randomly chosen at creation from a list of bunny names  
Infected: 	True/false (decided at time of bunny creation, 2% chance of True)  
  
GOALS:  
⦁	At program initialization: 5 bunnies must be created and given random colours, age can be 0 or a random value between 0 and 9.  
⦁	Each turn the bunnies age 1 year.  
⦁	As long as there is at least one male (aged 2 or older): for each female (aged 2 or older) a new bunny is created each turn. (e.g. if there was 1 adult male and 3 adult females, three new bunnies would be born).  
⦁	Newborn bunnies should be the same colour as their mother.  
⦁	If a bunny becomes older than 10 years old, it dies.  
⦁	If an infected bunny is born, each turn it will change one normal bunny into an infected bunny (e.g. if there are two infected bunnies, then two bunnies will be changed).  
⦁	Infected bunnies are excluded from regular breeding and do not count as adult bunnies.  
⦁	Infected bunnies do not die until they reach age 50.  
⦁	Each turn the program should output a list of all bunnies in the colony with their attributes, sorted by age.  
⦁	Each turn the program should also output announcements of all births and deaths (e.g. "Bunny Whiskers was born!").  
⦁	If the bunny population exceeds 1000 a food shortage must occur, killing exactly half of the bunnies (randomly chosen).  
⦁	When all of the bunnies have died the program should terminate.  
  
EXTRAS:  
⦁	Remove the population limit and see how many bunnies your program can handle.   
⦁	Allow the user to hit the 'k' key to initiate a mass rabbit cull, which causes half of the bunny population to be killed (randomly chosen).

  
--------------------------------------------------------------------------------  
  
Development of the program included the use of separate feature branches to implement new functionality:  
  
- branch 'MakeInfected' was used to develop and test the 'SpreadInfection' method of class Field.  
- branch 'FoodShortage' was used to develop and test the 'MassCull' method of class Field.  
- branch 'InputCull' was used to develop and test the extra feature which allows the user to initiate a population cull with a key input.  
- branch 'NoMaxCount' was used to develop and test the extra feature which allows the user to remove the maximum population limit.  
  
These feature branches were each merged with the main development branch once their respective additional functionalities had been tested. 


Notes:
- class 'Field' acts as the program's manager class, and is responsible for storing, manipulating, and modifying all Bunny objects.