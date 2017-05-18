/*  Copyright 2016 George Le
    
*/
#ifndef CHARACTER_SETUP_H
#define CHARACTER_SETUP_H

#include <string>

//including primary and secondary stat for function parameter in class 
//character set up's member function character creation
#include "ingame_entity.h"
#include "primary_stats.h"
#include "secondary_stats.h"
#include "scene.h"

enum Custom_or_premade { NOTCREATED, CUSTOM, PREMADE };

Custom_or_premade get_custom_or_premade();

class Character_set_up_command
{
    public:
    Character_set_up_command() {}
    virtual void primary_stats_setup(Job player_class, Primary_stats& stats_to_be_setup) = 0;
    virtual void secondary_stats_setup(Job player_class, Secondary_stats& learned_character_stats) = 0;
};

class Character_set_up_player_characters : public Character_set_up_command
{
    public:
    Character_set_up_player_characters() : script_name("Diadal_script_character_creation.txt"), factory_secondary_stats(script_name), 
                                            m_user_choice(NOTCREATED) 
    { 
        while(m_user_choice)
        {
            m_user_choice = get_custom_or_premade(); 
        }
    }
    
    void primary_stats_setup(Job player_class, Primary_stats& stats_to_be_setup);
    void secondary_stats_setup(Job player_class, Secondary_stats& learned_character_stats);
    
    private:
    const std::string script_name;
    Secondary_stats_initializer factory_secondary_stats;
    
    Custom_or_premade m_user_choice;
};

class Character_set_up_hostile_characters : public Character_set_up_command
{
    //does something different than for player characters   
};

class Character_set_up_npc : public Character_set_up_command
{
    //sets up character for npcs  
};

#endif