#ifndef TEAM_H
#define TEAM_H

#include "TeamPlayer.h"
#include <vector>
#include <string>

class Team
{
private:
    std::string team_name;
    std::vector<TeamPlayer> players;

public:
    Team(const std::string &name);
    void addPlayer(const TeamPlayer &player);
    TeamPlayer *findPlayerByID(const std::string &id);
    void updatePlayerStats(const std::string &id, bool add_game, int goals);
    void displayTeamInfo() const;
};

#endif
