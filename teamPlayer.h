#ifndef TEAMPLAYER_H
#define TEAMPLAYER_H

#include <string>

class TeamPlayer
{
private:
    std::string player_id;
    std::string name;
    int age;
    std::string position;
    int games_played;
    int scored_goals; // Ny variabel för antal mål

public:
    TeamPlayer(const std::string &id, const std::string &name, int age, const std::string &position, int games = 0, int goals = 0);

    void addGamePlayed();
    void resetGamesPlayed();
    void addGoal();
    void resetGoals();

    std::string getPlayerInfo() const;
    std::string getPlayerID() const; // Lägger till för att få spelares ID i Team-klassen
};

#endif
