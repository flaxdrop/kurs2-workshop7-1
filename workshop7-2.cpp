#include <iostream>
#include <string>

class TeamPlayer
{
private:
    std::string player_id;
    std::string name;
    int age;
    std::string position;
    int games_played;

public:
    // Konstruktor som initierar en spelare
    TeamPlayer(const std::string &id, const std::string &name, int age, const std::string &position, int games = 0)
        : player_id(id), name(name), age(age), position(position), games_played(games) {}

    // Ökar antalet spelade matcher med ett
    void addGamePlayed()
    {
        games_played++;
        std::cout << name << " has played one more game. Total games played: " << games_played << std::endl;
    }

    // Nollställer antal spelade matcher för spelaren
    void resetGamesPlayed()
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

    // Returnerar all information om spelaren
    std::string getPlayerInfo() const
    {
        return "Player ID: " + player_id + "\nName: " + name + "\nAge: " + std::to_string(age) +
               "\nPosition: " + position + "\nGames Played: " + std::to_string(games_played);
    }
};

int main()
{
    // Initierar två spelare
    TeamPlayer player1("P001", "Alice Smith", 24, "Forward");
    TeamPlayer player2("P002", "Bob Johnson", 28, "Goalkeeper");

    // Visar initial information om spelarna
    std::cout << "Initial Player Information:\n";
    std::cout << player1.getPlayerInfo() << "\n\n";
    std::cout << player2.getPlayerInfo() << "\n\n";

    // Ökar antalet spelade matcher för båda spelarna
    player1.addGamePlayed();
    player1.addGamePlayed();
    player2.addGamePlayed();

    // Visar information efter att matcher har ökat
    std::cout << "\nAfter Adding Games:\n";
    std::cout << player1.getPlayerInfo() << "\n\n";
    std::cout << player2.getPlayerInfo() << "\n\n";

    // Nollställer antal spelade matcher för spelare 1 (klubbbyte)
    player1.resetGamesPlayed();

    // Visar information efter att spelare 1 har nollställts
    std::cout << "\nAfter Resetting Games for Player 1:\n";
    std::cout << player1.getPlayerInfo() << "\n\n";
    std::cout << player2.getPlayerInfo() << std::endl;

    return 0;
}
