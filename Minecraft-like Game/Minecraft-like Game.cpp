#include <iostream>

using namespace std;

int day = 1;

bool isStillPlaying = true;

enum class dailyOptions {Farm = 1, Mining, Cooking, Fishing, Smelting, Crafting, Woodcutting, Constructing, Exit};
enum class buildings {House = 1, Field, Fence, Stables};

bool haveShovel = false;
bool haveHammer = false;

int farmSkill = 3;
int fishingSkill = 1;
int rawFoodInv = 0;
int cookingSkill = 1;
int cookedFoodInv = 5;
int miningSkill = 1;
int oreInv = 0;
int smithingSkill = 1;
int barInv = 0;
int woodcuttingSkill = 1;
int woodInv = 0;
int constructionSkill = 1;
int houses = 0;
int fields = 0;
int fences = 0;
int stables = 0;


void startDay()
{
    int choice = 0;
    int toConstruct = 0;
    
    do
    {
        system("cls");
        cout << "It is day " << day << "." << endl;
        cout << "What would you like to do today?" << endl;
        cout << "1. Farm \n2. Go Mining \n3. Cook Food \n4. Go Fishing \n5. Smelt Ore \n6. Craft Tools" << endl;
        cout << "7. Cut Down Trees \n8. Construct Buildings \n9. Exit Game" << endl;
        cin >> choice;

    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 &&
             choice != 6 && choice != 7 && choice != 8 && choice != 9);

    system("cls");

    dailyOptions dailyChoice = static_cast<dailyOptions>(choice);

    switch (dailyChoice)
    {
    case dailyOptions::Farm:
        rawFoodInv = rawFoodInv + farmSkill;
        farmSkill++;
        cout << "You chose to go farming. \nYour farming skill is now " << farmSkill << "." << endl;
        cout << "You have " << rawFoodInv << " raw food and " << cookedFoodInv << " cooked food." << endl;
        break;

    case dailyOptions::Mining:
        oreInv = oreInv + miningSkill;
        miningSkill++;
        cout << "You chose to go mining. \nYour mining skill is now " << miningSkill << "." << endl;
        cout << "You have " << oreInv << " ore." << endl;
        break;

    case dailyOptions::Cooking:
        if (rawFoodInv > cookingSkill)
        {
            cookedFoodInv = cookedFoodInv + cookingSkill;
            rawFoodInv = rawFoodInv - cookingSkill;
        }
        else
        {
            cookedFoodInv = cookedFoodInv + rawFoodInv;
            rawFoodInv = 0;
        }
        cookingSkill++;
        cout << "You chose to cook food. \nYour cooking skill is now " << cookingSkill << "." << endl;
        cout << "You have " << rawFoodInv << " raw food and " << cookedFoodInv << " cooked food." << endl;
        break;

    case dailyOptions::Fishing:
        rawFoodInv = rawFoodInv + fishingSkill;
        fishingSkill++;
        cout << "You chose to go fishing. \nYour fishing skill is now " << fishingSkill << "." << endl;
        cout << "You have " << rawFoodInv << " raw food." << endl;
        break;

    case dailyOptions::Smelting:
        if (oreInv > smithingSkill)
        {
            barInv = barInv + smithingSkill;
            oreInv = oreInv - smithingSkill;
        }
        else
        {
            barInv = barInv + oreInv;
            oreInv = 0;
        }
        smithingSkill++;
        cout << "You chose to smelt ore. \nYour smithing skill is now " << smithingSkill << "." << endl;
        cout << "You have " << oreInv << " ore and " << barInv << " bars." << endl;
        break;

    case dailyOptions::Crafting:
        system("cls");

        if (haveShovel && haveHammer)
        {
            cout << "You have already crafted all the items." << endl;
        }
        else if (haveShovel == false && haveHammer)
        {
            if (woodInv > 1 && barInv > 1)
            {
                woodInv = woodInv - 2;
                barInv = barInv - 2;
                haveShovel = true;
                cout << "You craft a shovel." << endl;
            }
            else
            {
                cout << "You don't have the required building materials." << endl;
            }
        }
        else if (haveShovel && haveHammer == false)
        {
            if (woodInv > 1 && barInv > 1)
            {
                woodInv = woodInv - 2;
                barInv = barInv - 2;
                haveHammer = true;
                cout << "You craft a hammer." << endl;
            }
            else
            {
                cout << "You don't have the required building materials." << endl;
            }
        }
        else 
        {
            int toCraft = 0;

            do
            {
                cout << "What would you like to craft?" << endl;
                cout << "1. A shovel (2 wood, 2 bars) \n2. A hammer (2 wood, 2 bars)" << endl;
                cin >> toCraft;
            } while (toCraft != 1 && toCraft != 2);

            system("cls");

            if (toCraft == 1)
            {
                if (woodInv > 1 && barInv > 1)
                {
                    woodInv = woodInv - 2;
                    barInv = barInv - 2;
                    haveShovel = true;
                    cout << "You craft a shovel." << endl;
                }
                else
                {
                    cout << "You don't have the required building materials." << endl;
                }
            }
            else if (toCraft == 2)
            {
                if (woodInv > 1 && barInv > 1)
                {
                    haveHammer = true;
                    woodInv = woodInv - 2;
                    barInv = barInv - 2;
                    cout << "You craft a hammer." << endl;
                }
                else
                {
                    cout << "You don't have the required building materials." << endl;
                }
            }
        }
        break;

    case dailyOptions::Woodcutting:
        woodInv = woodInv + woodcuttingSkill;
        woodcuttingSkill++;
        cout << "You chose to cut down trees. \nYour woodcutting skill is now " << woodcuttingSkill << "." << endl;
        cout << "You have " << woodInv << " wood." << endl;
        break;

    case dailyOptions::Constructing:
        constructionSkill++;
        cout << "You chose to construct buildings. \nYour construction skill is now " << constructionSkill << "." << endl;

        cout << "\nYou have the following wood and tools" << endl;
        cout << woodInv << " wood" << endl;
        if (haveShovel)
        {
            cout << "Shovel" << endl;
        }
        if (haveHammer)
        {
            cout << "Hammer" << endl;
        }

        do
        {
            cout << "\nWhat would you like to construct?" << endl;
            cout << "1. House (lvl 1, 4 wood)" << endl;
            cout << "2. Field (lvl 3, shovel)" << endl;
            cout << "3. Fence (lvl 5, 2 wood, hammer)" << endl;
            cout << "4. Stables (lvl 7, 4 wood, shovel, hammer)" << endl;
            cin >> toConstruct;
            system("cls");
        } while (toConstruct != 1 && toConstruct != 2 && toConstruct != 3 && toConstruct != 4);

        if (toConstruct == 1)
        {
            if (woodInv > 3)
            {
                houses++;
                woodInv = woodInv - 4;
                cout << "You created a house. \nYou now have " << houses << " houses." << endl;
            }
            else
            {
                cout << "You don't have the required building materials and/or skill level." << endl;
            }
        }
        else if (toConstruct == 2)
        {
            if (constructionSkill > 2 && haveShovel)
            {
                fields++;
                cout << "You have created a field. \nYou now have " << fields << " fields." << endl;
            }
            else
            {
                cout << "You don't have the required building materials and/or skill level." << endl;
            }
        }
        else if (toConstruct == 3)
        {
            if (constructionSkill > 4 && woodInv > 1 && haveHammer)
            {
                fences++;
                woodInv = woodInv - 2;
                cout << "You have created a fence. \nYou now have " << fences << " fences." << endl;
            }
            else
            {
                cout << "You don't have the required building materials and/or skill level." << endl;
            }
        }
        else if (toConstruct == 4)
        {
            if (constructionSkill > 6 && woodInv > 3 && haveShovel && haveHammer)
            {
                stables++;
                woodInv = woodInv - 4;
                cout << "You have created a stable. \nYou now have " << stables << " stables." << endl;
            }
            else
            {
                cout << "You don't have the required building materials and/or skill level." << endl;
            }
        }
        break;

    case dailyOptions::Exit:
        isStillPlaying = false;
        break;

    }

    if (cookedFoodInv < 1)
    {
        cout << "\nDay " << day << " has ended." << endl;
        cout << "You have no food to eat. You die." << endl;
        isStillPlaying = false;
    }

    if (isStillPlaying)
    {
        cout << "\nDay " << day << " has ended. You eat 1 cooked food." << endl;

        cookedFoodInv = cookedFoodInv - 1;

        cout << "\nSkills " << endl;
        cout << "Farm Skill: " << farmSkill << endl;
        cout << "Fishing Skill: " << fishingSkill << endl;
        cout << "Cooking Skill: " << cookingSkill << endl;
        cout << "Mining Skill: " << miningSkill << endl;
        cout << "Smithing Skill: " << smithingSkill << endl;
        cout << "Woodcutting Skill: " << woodcuttingSkill << endl;
        cout << "Construction Skill: " << constructionSkill << endl;

        cout << "\nInventory" << endl;
        cout << "Raw Food: " << rawFoodInv << endl;
        cout << "Cooked Food: " << cookedFoodInv << endl;
        cout << "Ores: " << oreInv << endl;
        cout << "Bars: " << barInv << endl;
        cout << "Wood: " << woodInv << endl;
        cout << "Houses: " << houses << endl;
        cout << "Fields: " << fields << endl;
        cout << "Fences: " << fences << endl;
        cout << "Stables: " << stables << endl;

        day++;

        system("pause");
    }
}



int main()
{
    cout << "Welcome to Valaris. \nYou start with 5 cooked food. \nEach day you eat 1 cooked food." << endl;

    system("pause");

    while (isStillPlaying)
    {
        startDay();
    }

    return 0;
}

