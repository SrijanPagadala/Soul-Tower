#include "../header/ExploreState.hpp"
#include "../header/ArcherGoblin.hpp"
#include "../header/WarriorGoblin.hpp"
#include "../header/MageGoblin.hpp"

ExploreState::ExploreState(){
    level = 1;
    input = "";
    choice1 = "";
    choice2 = "";
    coinsEarned = 0;
    healthPotionsEarned = 0;
    damageTaken = 0;
}

ExploreState::ExploreState(int levelToSet){
    level = levelToSet;
    input = "";
    choice1 = "";
    choice2 = "";
    coinsEarned = 0;
    healthPotionsEarned = 0;
    damageTaken = 0;
}

void ExploreState::display(Game* game, cMain* gui){
    bool validInput = true;

    //first level exploration
    if(level == 1){ 
 
        gui->DisplayOut("You wake up at the bottom of a large tower, very confused on how you got there.\n");
        gui->DisplayOut("You faintly remember being on a quest to save something or someone... but you are unsure.\n");
        gui->DisplayOut("It seems like you have amnesia, with faint memories of why you are in this tower in the first place.\n");
        gui->DisplayOut("You notice you are equipped with weaponry and armor, you must be a warrior or hero.\n");
        gui->DisplayOut("You notice a large spiral staircase, stretching to the top of the tower.\n");
        gui->DisplayOut("At the base of the stairs, you see a sign that states \"SOUL TOWER: ENTER AT YOUR OWN RISK.\"\n");
        gui->DisplayOut("Being the tremendously smart traveler you are, you decide to step up the stairs.\n");
        gui->DisplayOut("You see a sign that states: \"WELCOME TO THE FIRST FLOOR\"\n");
        gui->DisplayOut("\n");
        gui->DisplayOut("As you walk through the corridoors of the first floor, you see a bright light coming from a room.\n");
        gui->DisplayOut("You decide to walk closer to the bright lit room, and notice that the room is actually split into two rooms with two doors.\n");
        gui->DisplayOut("Although both rooms have a shining light creeping through the doors, you notice distinct differences between the rooms.\n");
        gui->DisplayOut("You feel a small wave of heat coming from Room 1, and notice that the light in Room 1 is much darker than the light from Room 2.\n");
        gui->DisplayOut("\n");
        gui->DisplayOut("Which room do you decide to go in?\n"); //CHOICE 1: LAVA ROOM OR COINS ROOM
        choice1 = "1. Room 1";
        choice2 = "2. Room 2";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        while (input != "1" && input != "2") {
            gui->DisplayOut("Invalid input, please enter \"1\" or \"2\"\n");
            input = gui->GetChoice();
        }
        if (input == "1") { //They walk into a room of lava and take 5 damage
            gui->DisplayOut("You open the door and walk straight into a pool of lava!\n");
            gui->DisplayOut("You discover that your skin is fire-resistant, and you manage to get out alive.\n");
            gui->DisplayOut("However, you realize you are not fire-proof, merely fire-resistant - you take 5 damage!\n");
            gui->DisplayOut("-5 health\n");
            game->getPlayer()->takeDamage(5);
        }
        else { //They walk into a room of coins and gain 200 coins
            gui->DisplayOut("You open the door and see a pile of shining coins!\n");
            gui->DisplayOut("You happily decide to collect all of them in your pockets.\n");
            gui->DisplayOut("+200 coins\n");
            game->changeCoins(200);
        }
        gui->DisplayOut("\n");
        gui->DisplayOut("You continue traveling further throughout the floor.\n");
        gui->DisplayOut("You are still very much confused as to how you got here and the purpose of your peresence in the tower.\n");
        gui->DisplayOut("However, it seems you are drawn towards the top floor.\n");
        gui->DisplayOut("You walk past another room, when you hear faint whispering coming from inside.\n");
        if(input == "1"){ //If they walked into the lava last time
            gui->DisplayOut("Remembering what happened with the last room you entered, you were unsure of whether to enter this room.\n");
            gui->DisplayOut("You slowly walk past the room, but, as the whipsering gets louder--you cannot resist.\n");
            gui->DisplayOut("Bracing yourself for the worst, you open the door and walk in.\n");
        } else { //If they walked into the coins last time
            gui->DisplayOut("Remembering what happened with the last room you entered, you eagerly opened the door and walked in.\n");
        }
        gui->DisplayOut("You see a goblin whispering to itself in the corner of the room.\n");
        gui->DisplayOut("You decide to walk closer to it.\n");
        gui->DisplayOut("Suddenly, the goblin turns around and screams in a mystic language.\n");
        gui->DisplayOut("Startled, you take out your weapon and pin it to the wall, ready to kill it.\n");
        gui->DisplayOut("Do you kill the goblin?\n"); //CHOICE 2: Kill or spare the goblin
        choice1 = "1. Kill the goblin";
        choice2 = "2. Let the goblin live";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        while (input != "1" && input != "2") {
            gui->DisplayOut("Invalid input, please enter \"1\" or \"2\"\n");
            input = gui->GetChoice();
        }
        if(input == "1"){ //Player kills goblin
            gui->DisplayOut("You go through with it and kill the goblin.\n");
            gui->DisplayOut("You find 100 coins in its pockets.\n");
            gui->DisplayOut("+100 coins\n");
            game->changeCoins(100);
        } else { //Player spares goblin
            gui->DisplayOut("You decide to let the goblin live and you put your weapon away.\n");
            gui->DisplayOut("As you let your guard down, the goblin reaches into its pockets.\n");
            gui->DisplayOut("It pulls out 50 coins and... eats them.\n");
            gui->DisplayOut("You are confused and concerned, but then you see that the goblin's eyes glow yellow.\n");
            gui->DisplayOut("The goblin starts screaming louder in its mystic language and bites you.\n");
            gui->DisplayOut("-5 health.\n");
            game->getPlayer()->takeDamage(5);
            gui->DisplayOut("In pain, you pull out your weapon and kill the goblin.\n");
            gui->DisplayOut("You find 50 coins in its pockets.\n");
            gui->DisplayOut("+50 coins\n");
            game->changeCoins(50);
        }
        gui->DisplayOut("You look around the room, very confused as to what just happened.\n");
        gui->DisplayOut("On one of the walls, you see a note.\n");
        gui->DisplayOut("\"PLEASE DO NOT FEED THE COIN GOBLINS!\"\n");
        gui->DisplayOut("You realize that this goblin has an appetite for coins - and is NOT friendly.\n");
        gui->DisplayOut("\n");
        gui->DisplayOut("Shaken up by the encounter with the coin goblin, you decide to continue on your mysterious quest.\n");
        gui->DisplayOut("You walk around the floor more, looking for any sign of the stairs to the higher floors.\n");
        gui->DisplayOut("You once again wonder why you are drawn to the top of the tower, and if it is even worth it to continue.\n");
        gui->DisplayOut("However, you know that you must continue.\n");
        gui->DisplayOut("As you walk throughout the maze-like halls of the first floor, you find yourself deciding whether to go left or right.\n");
        gui->DisplayOut("Both of the paths seem the same, yet you know each leads a separate way and you need to choose.\n");
        gui->DisplayOut("\n");
        gui->DisplayOut("Do you go left or do you go right?\n"); //CHOICE 3: Left or right?
        choice1 = "1. Go left";
        choice2 = "2. Go right";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        while (input != "1" && input != "2") {
            gui->DisplayOut("Invalid input, please enter \"1\" or \"2\"\n");
            input = gui->GetChoice();
        }
        if(input == "1"){ //If left
            gui->DisplayOut("You decide to go left.\n");
            gui->DisplayOut("As you continue along this path, you hear that dreaded noice once again - the scream of a coin goblin.\n");
            gui->DisplayOut("However, this time, you can hear the screams of dozens of coin goblins.\n");
            gui->DisplayOut("In the distance, you see dozens of coin goblins racing towards you, with shining yellow eyes.\n");
            gui->DisplayOut("In a moment of desparation, you throw 25 coins at them to divery them and run back.\n");
            gui->DisplayOut("-25 coins\n");
            game->changeCoins(-25);
            gui->DisplayOut("You backtrack to before you went left, and realize that you made the wrong decision.\n");
            gui->DisplayOut("This time, you decide to go right.\n");
        } else {
            gui->DisplayOut("You decide to go right.\n");
        }
        gui->DisplayOut("As you travel along the path, you see a bright light in the distance.\n");
        gui->DisplayOut("You tread with caution, as you are fearful of yet another coin goblin.\n");
        gui->DisplayOut("As you walk up, you realize that the light is coming from a room up ahead.\n");
        gui->DisplayOut("A sign above the room reads: \"FLOOR 2 AHEAD\"\n");
        gui->DisplayOut("You realize you have finally found the room with the stairs.\n");
        gui->DisplayOut("Finally, some progress...\n");
        gui->DisplayOut("As you inch closer towards the stairs, you hear the mysterious screams of a coin goblin once again.\n");
        gui->DisplayOut("Here we go again.\n");
        gui->DisplayOut("Except, this time, the screeches of the goblin are much deeper.\n");
        gui->DisplayOut("The coin goblin jumps down from the stairs in front of you, ready to attack.\n");
        gui->DisplayOut("This coin goblin looks different than before.\n");
        
        gui->DisplayOut("Its eyes are glowing red instead of yellow, and it is TEN TIMES THE SIZE!\n");
        gui->DisplayOut("You take out your weapon quickly, ready for battle!\n");
        // Sets enemy for fight
        game->setEnemy(new WarriorGoblin("Coin Goblin"));
    }
    // Level 2
    else if (level == 2){
        gui->DisplayOut("As you walk about floor 2, you start getting faint memories.\n");
        gui->DisplayOut("This place... the walls... something about them...\n");
        gui->DisplayOut("You feel more drawn to the top floor.\n");
        gui->DisplayOut("In the distance, you spot two wooden chests.\n");
        gui->DisplayOut("You walk up to both of those chests.\n");
        gui->DisplayOut("The left chest seems to be shining yellow, while the right seems to be leaking with a pink elixir.\n");
        gui->DisplayOut("Which chest do you open first?\n"); //CHOICE 1: Left or right chest
        choice1 = "1. Left";
        choice2 = "2. Right";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        while (input != "1" && input != "2") {
            gui->DisplayOut("Invalid input, please enter \"1\" or \"2\"\n");
            input = gui->GetChoice();
        }

        if(input == "1"){
            gui->DisplayOut("You decide to open the left chest.\n");
            gui->DisplayOut("When opening the chest, you are delighted to see a handful of coins!\n");
            gui->DisplayOut("+50 coins\n");
            game->changeCoins(50);
            gui->DisplayOut("Suddenly, the wall crumbles.\n");
            gui->DisplayOut("You run away as the wall crumbles, shattering the other chest and its contents.\n");
        } else {
            gui->DisplayOut("You decide to open the right chest.\n");
            gui->DisplayOut("When opening the chest, you are delighted to see a health potion!\n");
            gui->DisplayOut("+1 health potion\n");
            game->changePotions(1);
            gui->DisplayOut("Suddenly, the wall crumbles.\n");
            gui->DisplayOut("You run away as the wall crumbles, shattering the other chest and its contents.\n");
        }
        gui->DisplayOut("As you continue your journey to the next set of stairs, you hear screaming.\n");
        gui->DisplayOut("Alarmed, you hold your weapon close, ready to attack.\n");
        gui->DisplayOut("You hear the screeches of a coin goblin.\n");
        gui->DisplayOut("You start running towards the screeches and screaming, prepared to slay yet another coin goblin.\n");
        gui->DisplayOut("You come accross a hallway with a corner.\n");
        gui->DisplayOut("The screaming is coming from around the corner.\n");
        gui->DisplayOut("You turn the corner and kill the coin goblin in one swoop.\n");
        gui->DisplayOut("As the corpse of the goblin falls over, you see a man in robes behind it.\n");
        gui->DisplayOut("???: \"Thank you so much!\"\n");
        gui->DisplayOut("???: \"Those goblins can be real pesky.\"\n");
        gui->DisplayOut("You look at the man in robes with a confused look.\n");
        gui->DisplayOut("You did not realize there were other humans in this tower.\n");
        gui->DisplayOut("William: \"My name is William, and I am the resident wizard of the region of Nabbarthjan.\"\n");
        gui->DisplayOut("William: \"Here, take this potion.\"\n");
        gui->DisplayOut("+1 Health Potion\n");
        game->changePotions(1);
        gui->DisplayOut("William: \"It's the least I can do.\"\n");
        gui->DisplayOut("William: \"How would you like to travel together?\"\n"); //CHOICE 2: Travel with William?
        choice1 = "1. Yes";
        choice2 = "2. No";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        while (input != "1" && input != "2") {
            gui->DisplayOut("Invalid input, please enter \"1\" or \"2\"\n");
            input = gui->GetChoice();
        }
        if (input == "1") {
            gui->DisplayOut("William: \"Delightful!\"\n");
            gui->DisplayOut("William: \"Let's be on our way then.\"\n");
        }
        else {
            gui->DisplayOut("William: \"I won't take no for an answer!\"\n");
            gui->DisplayOut("William: \"We should really stick together.\"\n");
            gui->DisplayOut("William: \"I promise I can be of assistance.\"\n");
            gui->DisplayOut("William: \"Here, take this.\"\n");
            gui->DisplayOut("William hands you 50 coins.\n");
            gui->DisplayOut("+50 coins\n");
            game->changeCoins(100);
            gui->DisplayOut("You wonder why William bribes you to travel with him.\n");
            gui->DisplayOut("Perhaps he is desparate for your help in escaping the tower.\n");
        }
        gui->DisplayOut("\n");
        gui->DisplayOut("You and William continue forward.\n");
        gui->DisplayOut("You wonder how William even got here.\n");
        gui->DisplayOut("You are glad to have a companion in your adventures.\n");
        gui->DisplayOut("You starting thinking about how YOU got here, and why you are so drawn to the top of the tower.\n");
        gui->DisplayOut("As you think, pebbles start falling on you.\n");
        gui->DisplayOut("You are lost in thought.\n");
        gui->DisplayOut("The roof above you starts crumbling.\n");
        gui->DisplayOut("You are too lost in thought to notice.\n");
        gui->DisplayOut("You realize too late.\n");
        gui->DisplayOut("You look up and see rocks mere inches above you.\n");
        gui->DisplayOut("William: \"Etativel meht!\"\n");
        gui->DisplayOut("Suddenly, the rocks start levitating.\n");
        gui->DisplayOut("William: \"That was close!\"\n");
        gui->DisplayOut("You are glad you and William are traveling together.\n");
        gui->DisplayOut("You wonder how only a part of the roof crumbled.\n");
        gui->DisplayOut("You look at William and thank him.\n");
        gui->DisplayOut("You shake off what just happened and continue on.\n");
        gui->DisplayOut("You and William come accross a path that splits into two directions.\n");
        gui->DisplayOut("There is a right path and a left path.\n");
        gui->DisplayOut("You decide to split up.\n");
        gui->DisplayOut("Do you go right or left?\n"); //CHOICE 3: Right or left path
        choice1 = "1. Right";
        choice2 = "2. Left";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        while (input != "1" && input != "2") {
            gui->DisplayOut("Invalid input, please enter \"1\" or \"2\"\n");
            input = gui->GetChoice();
        }
        if (input == "1") {
            gui->DisplayOut("You decide to go right.\n");
            gui->DisplayOut("William goes left.\n");
        }
        else {
            gui->DisplayOut("You decide to go left.\n");
            gui->DisplayOut("William goes right.\n");
        }
        gui->DisplayOut("\n");
        gui->DisplayOut("On your path, you find some coins scattered along the way.\n");
        gui->DisplayOut("+5 coins\n");
        game->changeCoins(5);
        gui->DisplayOut("+5 coins\n");
        game->changeCoins(5);
        gui->DisplayOut("+10 coins\n");
        game->changeCoins(10);
        gui->DisplayOut("+5 coins\n");
        game->changeCoins(5);
        gui->DisplayOut("The path is dark.\n");
        gui->DisplayOut("You hear a distant sound.\n");
        gui->DisplayOut("ssssssss\n");
        gui->DisplayOut("ssssssssssssss\n");
        gui->DisplayOut("SSSSSSSSSSSSSSSSSSSSSSSSSSSS!\n");
        gui->DisplayOut("A snake jumps at you!\n");
        gui->DisplayOut("It bites you.\n");
        gui->DisplayOut("You take 5 damage.\n");
        gui->DisplayOut("-5 health\n");
        game->getPlayer()->takeDamage(5);
        gui->DisplayOut("You strike back and end its life.\n");
        gui->DisplayOut("You wonder whether this was the right path to take.\n");
        gui->DisplayOut("You wonder how William is doing.\n");
        gui->DisplayOut("You continue along the path.\n");
        gui->DisplayOut("As you head further, you see a light.\n");
        gui->DisplayOut("You head towards it.\n");
        gui->DisplayOut("As you get closer, you see the stairs!\n");
        gui->DisplayOut("Finally, the next floor.\n");
        gui->DisplayOut("You wonder whether you should go back for William or not.\n");
        gui->DisplayOut("As you turn around to head back, you see another path leading to these stairs.\n");
        gui->DisplayOut("You realize that William's path should have already led him here.\n");
        gui->DisplayOut("You are worried about him.\n");
        gui->DisplayOut("William: \"Etativel mih!\"\n");
        gui->DisplayOut("You feel yourself rise in the air.\n");
        gui->DisplayOut("CRASH! You are flung into the wall.\n");
        gui->DisplayOut("-5 health\n");
        game->getPlayer()->takeDamage(5);
        gui->DisplayOut("Dazed and confused, you look up.\n");
        gui->DisplayOut("William: \"You are a fool if you think you can make it to The Soulkeeper.\"\n");
        gui->DisplayOut("You are confused and hurt by William's betrayal.\n");
        gui->DisplayOut("That name... why does The Soulkeeper sound so familiar?\n");
        gui->DisplayOut("You have no time to think as William raises his wand to fight.\n");
        gui->DisplayOut("William: \"He knew you would easily trust me.\"\n");
        gui->DisplayOut("You ask him what he is talking about, and who The Soulkeeper is.\n");
        gui->DisplayOut("William: \"It doesn't matter now. You won't be alive to meet him.\"\n");
    } else if (level == 3) {
        gui->DisplayOut("You enter the third floor.\n");
        gui->DisplayOut("On your right is a window.\n");
        gui->DisplayOut("Something about the view seems so uncanny--familiar, yet also unfamiliar.\n");
        gui->DisplayOut("You debate whether it is worth it to even reach the top.\n");
        gui->DisplayOut("After all, you don't even know why you are so drawn to the top.\n");
        gui->DisplayOut("You look back at the stairs behind you, William's wand snapped in half nearby.\n");
        gui->DisplayOut("Do you decide to head back and abandon your journey?\n"); //CHOICE 1: Go back or continue
        choice1 = "1. Go back";
        choice2 = "2. Continue";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        while (input != "1" && input != "2") {
            gui->DisplayOut("Invalid input, please enter \"1\" or \"2\"\n");
            input = gui->GetChoice();
        }
        if (input == "1") {
            gui->DisplayOut("You start walking back, in defeat.\n");
            gui->DisplayOut("You cannot handle the surprises of this tower anymore.\n");
            gui->DisplayOut("Surely this is the logical decision.\n");
            gui->DisplayOut("*BOOM*\n");
            gui->DisplayOut("The stairs seem to have magically crumbled.\n");
            gui->DisplayOut("There is no way out.\n");
            gui->DisplayOut("You look back at the window to see if you can escape.\n");
            gui->DisplayOut("There is no way out.\n");
            gui->DisplayOut("You try to smash open the window.\n");
            gui->DisplayOut("Suddenly, you see the window disappear in front of your own eyes.\n");
            gui->DisplayOut("You are left staring at a blank wall.\n");
            gui->DisplayOut("THERE IS NO WAY OUT.\n");
            gui->DisplayOut("You now know that you must continue to the top.\n");
            gui->DisplayOut("It is fate.\n");
        }
        else {
            gui->DisplayOut("You think about heading back, but you decide to soldier on.\n");
            gui->DisplayOut("*BOOM*\n");
            gui->DisplayOut("The stairs behind you seem to have magically crumbled.\n");
            gui->DisplayOut("There is no way out.\n");
            gui->DisplayOut("You look back at the window and see it magically disappear.\n");
            gui->DisplayOut("THERE IS NO WAY OUT.\n");
            gui->DisplayOut("You know that you must continue to the top.\n");
            gui->DisplayOut("It is fate.\n");
        }
        gui->DisplayOut("You continue walking throughout the halls of the third floor.\n");
        gui->DisplayOut("It feels like a maze.\n");
        gui->DisplayOut("There are dozens of rooms, but most of them empty.\n");
        gui->DisplayOut("You walk into a room with a chest.\n");
        gui->DisplayOut("Happily, you approach the chest ready to open it.\n");
        gui->DisplayOut("However, you hear a slight noise coming from inside the chest.\n");
        gui->DisplayOut("A noise you are familiar with - sssssssssss.\n");
        gui->DisplayOut("ssssssssSSSSSS\n");
        gui->DisplayOut("Do you open the chest?\n"); //CHOICE 2: Open chest or not
        choice1 = "1. Open the chest";
        choice2 = "2. Leave the room";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        while (input != "1" && input != "2") {
            gui->DisplayOut("Invalid input, please enter \"1\" or \"2\"\n");
            input = gui->GetChoice();
        }
        if (input == "1") {
            gui->DisplayOut("You decide to open the chest.\n");
            gui->DisplayOut("You tread with caution while opening it.\n");
            gui->DisplayOut("You raise your weapon in one hand, while opening the chest with the other.\n");
            gui->DisplayOut("Suddenly, a snake jumps at you.\n");
            gui->DisplayOut("You kill it midair as it tries to jump at you.\n");
            gui->DisplayOut("You smirk to yourself as you examine and loot the contents of the chest.\n");
            gui->DisplayOut("+50 coins\n");
            game->changeCoins(50);
            gui->DisplayOut("+1 health potion\n");
            game->changePotions(1);
        }
        else {
            gui->DisplayOut("You decide to not risk it and walk away.\n");
            gui->DisplayOut("As you turn your back and walk away, you hear a creek sound.\n");
            gui->DisplayOut("Startled, you turn around to notice the chest is open.\n");
            gui->DisplayOut("You walk up to the chest and loot it.\n");
            gui->DisplayOut("+50 coins\n");
            game->changeCoins(50);
            gui->DisplayOut("+1 health potion\n");
            game->changePotions(1);
            gui->DisplayOut("Suddenly, a snake bites your leg.\n");
            gui->DisplayOut("-5 health\n");
            game->getPlayer()->takeDamage(5);
            gui->DisplayOut("You quickly pull out your weapon and end its life.\n");
        }
    }

}