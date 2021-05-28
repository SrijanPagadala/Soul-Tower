# Soul Tower
  Authors: [Siddharth Sondhi](https://github.com/SiddharthSondhi),
   [Srijan Pagadala](https://github.com/SrijanPagadala),
   [Nabil Khalil](https://github.com/nabil-k)

## Project Description
  * We love Minecraft, but we love RPGs too. So we combined two of our most favorite things, and made a Minecraft text-based role-playing game (RPG).
  * Languages/Tools/Technologies:
    * C++
    * [wxWidgets](https://www.wxwidgets.org/) - A C++ GUI Framework.
  * Input/Output of The Project:
    * Users input choices that corresspond to numbers to make game decisions.
    * GUI displays User's health, mana, and inventory.
    * Console echos user input as well as prompts from the game.
  * Design Patterns Being Used:
    * Abstract Factory:
      * Since we will have a variety of classes in our games and each of those classes will have items specific to them. We will have the issue of figuring out how to reuse methods we believe all classes should have in their interface and how to seperate each classes behaviors as well. Using an Abstract Factory class will allow use to create a variety of classs from an abstract base class and create a variey of different class behaviors by having abstract base classes for the behaviors we desire that then create class behvaiors specific to a class.
      * Using an Abstract factory will make the code base a lot more maintainable since developers can already expect what interface an entity of the type enemy will have. It will also make creating new enemies much faster since we won't have to rewrite code that all enemies would already be expected to have.
    * State:
      * Our character will often end up in different states, for example when he is in a fight, or has to go to a shop, or is exploring, etc. Much of the functionality will be similar during these states while other details will be different. Having a State for each of these scenarios will allow us to create differences in states of what the user is allowed to do without having to retype code.  
      * Having the ability to switch between states will allow us to quickly and cleanly switch between what the user can do. For example, the user may have the ability to attack, run, heal, etc. while the "fight" state is activated and the user may have the ability to purchase various things when the "shop" state is activated. 

## Class Diagrams
 ### Abstract Factory Diagram
 Description:
 For our Abstract Factory diagram, we are utilizing the class CharacterType (which inherits from Entity) to be our AbstractFactory class. We have three Concrete Factories: Archer, Warrior, and Mage. Each one represents a separate character type that the player can choose. We have two Abstract Products, a Weapon class and an Armor class. Both of those have three Products. The Weapon class has child classes Bow, Sword, and Wand. The armor class has child classes Leather, Chain, and Robes. We plan to create the products (weapons/armor) in our concrete factory classes (Archer/Warrior/Mage) in the constructor and change them using setters if necessary. 
 <br/>
 ![Abstract Factory](./AbstractFactory (1).png?raw=true "Abstract")
 ### State Diagram
 Description:
 The State class will be an abstract class that the GameState class, the FightState class, and the ShopState class inherit from. Each of these classes will have a display function which will allow us to display the correct information depending on whatever state is selected. The Game class will be able to set the state using the setState function. Then depending on which state is set, the correct display function will be called.
  <br/>
 ![State](./State.png?raw=true "Stage")
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
