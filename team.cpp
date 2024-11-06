#include "Team.h"
#include <iostream>

// Konstruktor
Team::Team(const std::string &name) : team_name(name) {}

// Lägg till en spelare till laget
void Team::addPlayer(const TeamPlayer &player)
{
    players.push_back(player);
}

// Hitta en spelare med ID
TeamPlayer *Team::findPlayerByID(const std::string &id)
{
    for (auto &player : players)
    {
        if (player.getPlayerID() == id)
        {
            return &player;
        }
    }
    return nullptr; // Returnera nullptr om spelaren inte hittas
}

// Uppdatera spelarens statistik (spelade matcher och mål)
void Team::updatePlayerStats(const std::string &id, bool add_game, int goals)
{
    TeamPlayer *player = findPlayerByID(id);
    if (player)
    {
        if (add_game)
            player->addGamePlayed();
        for (int i = 0; i < goals; i++)
        {
            player->addGoal();
        }
    }
    else
    {
        std::cerr << "Player with ID " << id << " not found." << std::endl;
    }
}

// Skriv ut hela laguppställningen
void Team::displayTeamInfo() const
{
    std::cout << "Team: " << team_name << "\nPlayers:\n";
    for (const auto &player : players)
    {
        std::cout << player.getPlayerInfo() << "\n\n";
    }
}
