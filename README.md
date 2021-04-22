 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Soul Tower
 > Authors: \<[Siddharth Sondhi](https://github.com/SiddharthSondhi)\>,
 >  \<[Srijan Pagadala](https://github.com/SrijanPagadala)\>,
 >  \<[Nabil Khalil](https://github.com/nabil-k)\>

 > You will be forming a group of **THREE** students and working on an interesting project. A list of proposed project ideas that have been successful in previous quarters is given in the project specifications link on iLearn. You can select an idea from the list, start thinking about the features you will implement, what design patterns can help you implement them, and why. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal. Your project needs to implement two design patterns.The project work should be divided almost equally among team members and each member is expected to work on at least one design pattern (more than one partner may work on a pattern) and some of its test cases. You can of course help each other, but it needs to be clear who will be responsible for which patterns and for which features.
 
 > ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory, Visitor, or Decorator
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group.

## Project Description
 > * Why is it important or interesting to you?
 >   * We love Minecraft, but we also love RPGs too. So we combined two of our most favorite things, and made a Minecraft RPG game.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * C++
 >   * [wxWidgets](https://www.wxwidgets.org/) - A C++ GUI Framework.
 > * What will be the input/output of your project?
 >   * Users input choices that corresspond to numbers to make game decisions.
 >   * GUI displays User's health, mana, and inventory.
 >   * Console echos user input as well as prompts from the game.
 > * What are the two design patterns you will be using? For each design pattern you must explain in 4-5 sentences:
 >   * Abstract Factory
 >     * What problem you anticipate encountering when implementing your project that you will solve using the design pattern
 >       * Since we will have a variety of enemies in our game that will share a lot of the same behaviors. We will have the issue of figuring out how to reuse methods we believe all enemies should have in their interface. Using an Abstract Factory class will allow us to create a variety of enemies from a abstract enemy class, and that abstract enemy class will have methods we can readily reuse.
 >      * Why the chosen design pattern will lead to a good solution to that problem
 >         * Using an Abstract factory will make the code base a lot more maintainable since developers can already expect what interface a entity of the type enemy will have. It will also make creating new enemies much faster since we won't have to rewrite code that all enemies would already be expected to have.
 >   * State
 >     * What problem you anticipate encountering when implementing your project that you will solve using the design pattern
 >       * Our character will often end up in different states, for example when he is in a fight, or has to go to a shop, or is exploring, etc. Much of the functionality will be similar during these states while other details will be different. Having a State for each of these scenarios will allow us to create differences in states of what the user is allowed to do without having to retype code.  
 >     * Why the chosen design pattern will lead to a good solution to that problem
 >       * Having the ability to switch between states will allow us to quickly and cleanly switch between what the user can do. For example, the user may have the ability to attack, run, heal, etc. while the "fight" state is activated and the user may have the ability to purchase various things when the "shop" state is activated. 
 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 
