#include "Team.h"
#include "TeamPlayer.h"
#include <iostream>

int main()
{
    // Skapa ett nytt lag
    Team myTeam("The Mighty Eagles");

    // Skapa och lägg till två spelare till laget
    TeamPlayer player1("P001", "Alice Smith", 24, "Forward");
    TeamPlayer player2("P002", "Bob Johnson", 28, "Goalkeeper");

    myTeam.addPlayer(player1);
    myTeam.addPlayer(player2);

    // Öka matcher och mål för spelare
    myTeam.updatePlayerStats("P001", true, 3); // Öka spelade matcher och lägg till 3 mål för Alice
    myTeam.updatePlayerStats("P002", true, 1); // Öka spelade matcher och lägg till 1 mål för Bob

    // Lägg till ytterligare en spelare
    TeamPlayer player3("P003", "Charlie Brown", 22, "Defender");
    myTeam.addPlayer(player3);

    // Skriv ut info om den nya spelaren
    TeamPlayer *newPlayer = myTeam.findPlayerByID("P003");
    if (newPlayer)
    {
        std::cout << "New Player Info:\n"
                  << newPlayer->getPlayerInfo() << "\n\n";
    }

    // Skriv ut hela laguppställningen
    std::cout << "Full Team Info:\n";
    myTeam.displayTeamInfo();

    return 0;
}
