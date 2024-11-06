#include "TeamPlayer.h"
#include <iostream>

// Konstruktor
TeamPlayer::TeamPlayer(const std::string &id, const std::string &name, int age, const std::string &position, int games, int goals)
    : player_id(id), name(name), age(age), position(position), games_played(games), scored_goals(goals) {}

// Ökar antalet spelade matcher med ett
void TeamPlayer::addGamePlayed()
{
    games_played++;
    std::cout << name << " has played one more game. Total games played: " << games_played << std::endl;
}

// Nollställer antal spelade matcher för spelaren
void TeamPlayer::resetGamesPlayed()
{
    if (games_played == 0)
    {
        std::cerr << "Error: Games played is already at zero for " << name << "." << std::endl;
    }
    else
    {
        games_played = 0;
        std::cout << "Games played has been reset for " << name << "." << std::endl;
    }
}

// Lägger till ett mål
void TeamPlayer::addGoal()
{
    scored_goals++;
    std::cout << name << " scored! Total goals: " << scored_goals << std::endl;
}

// Nollställer antal mål
void TeamPlayer::resetGoals()
{
    scored_goals = 0;
}

// Returnerar all information om spelaren
std::string TeamPlayer::getPlayerInfo() const
{
    return "Player ID: " + player_id + "\nName: " + name + "\nAge: " + std::to_string(age) +
           "\nPosition: " + position + "\nGames Played: " + std::to_string(games_played) +
           "\nGoals Scored: " + std::to_string(scored_goals);
}

// Returnerar spelarens ID
std::string TeamPlayer::getPlayerID() const
{
    return player_id;
}
