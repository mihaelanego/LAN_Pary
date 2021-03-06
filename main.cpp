
#include <iostream>
#include <fstream>
#include <string>

#include "Player.h"
#include "Team.h"
#include "listPlayers.h"
#include "listTeams.h"
#include "Game.h"
#include "queueGames.h"
#include "teamStack.h"
#include "BST.h"
#include "AVL.h"
using namespace std;

float roundScore(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}


//cerinta1
void cerinta_1(istream& in, ostream& out) {
    int n;
    in >> n;
    listTeams teams;

    for (int i = 0; i < n; i++) {
        Team t;
        in >> t;
        teams.add(t);
    }

    out << teams;
}

//cerinta2
void cerinta_2(istream& in, ostream& out) {
    in.clear();
    in.seekg(0);

    int nrTeams, n = 1;
    in >> nrTeams;
    listTeams teams;
    
    for (int i = 0; i < nrTeams; i++) {
        Team t;
        in >> t;
        teams.add(t);
    }
  
    do {
        n = n * 2;
    } while (n <= nrTeams);

    n = n / 2;  

    while (nrTeams > n) {
        teamNode* current = teams.head;
        double min = current->team.teamScore();
        int minIndex = 0;
        for (int j = 0; j < nrTeams; j++) {
            double score = current->team.teamScore();
            if (score < min) {
                min = score;
                minIndex = j;
            }
            current = current->next;
        }
        teams.deleteNode(minIndex);
        nrTeams--;
    }

    out << teams;
}

//cerinta3
void cerinta_3(istream& in, ostream& out) {
    in.clear();
    in.seekg(0);

    int nrTeams, n = 1;
    in >> nrTeams;
    listTeams teams;

    for (int i = 0; i < nrTeams; i++) {
        Team t;
        in >> t;
        teams.add(t);
    }

    do {
        n = n * 2;
    } while (n <= nrTeams);

    n = n / 2;  

    while (nrTeams > n) {
        teamNode* current = teams.head;
        double min = current->team.teamScore();
        int minIndex = 0;
        for (int j = 0; j < nrTeams; j++) {
            double score = current->team.teamScore();
            if (score < min) {
                min = score;
                minIndex = j;
            }
            current = current->next;
        }
        teams.deleteNode(minIndex);
        nrTeams--;
    }

    out << teams;

    int nrGames;
    nrGames = nrTeams / 2;
    queueGame teamsGame(nrGames);
    teamNode* current = teams.head;

    while (current != NULL) {
        Game game;
        game.set_t1(current->team);
        game.set_t2(current->next->team);

        teamsGame.push(game);
        current = current->next->next;
    }
    
    int nrWinners, nrLosers;
    nrWinners = nrTeams / 2;
    nrLosers = nrTeams / 2;

    teamStack winners(nrWinners), losers(nrLosers);
    Game* lastGame = nullptr;
    int k = 1;
    //string winner;

    do {
        int sizeGames = teamsGame.getSize();
        out << endl << "--- ROUND NO:" << k << endl;
        for (int i = 0; i < sizeGames; i++) {
            if (teamsGame.peek().get_t1().teamScore() > teamsGame.peek().get_t2().teamScore()) { //>=
                Team t1 = teamsGame.peek().get_t1();

                t1.addPoint();
                winners.push(t1);

                Team t2 = teamsGame.peek().get_t2();
                losers.push(t2);
            }
            else {
                Team t1 = teamsGame.peek().get_t1();
                losers.push(t1);

                Team t2 = teamsGame.peek().get_t2();

                t2.addPoint();
                winners.push(t2);
            }
            Game game = teamsGame.pop();
            out << game;
        }

        out << "\nWINNERS OF ROUND NO:" << k << endl;

        Game currentGame;
        bool completed = false;

        while (!winners.isEmpty()) {
            Team tm = winners.pop();
            if (completed) {
                currentGame.set_t2(tm);
                completed = false;
                lastGame = new Game(currentGame);
                teamsGame.push(*lastGame);
            }
            else {
                currentGame.set_t1(tm);
                completed = true;
            }

            out << tm.getTeamName();

            int size1 = tm.getTeamName().size();
            size1 = 37 - size1;
            out.width(size1);

            out << "-  ";

            float score = roundScore(tm.teamScore());
            score = roundScore(tm.teamScore());

            out << to_string(score).substr(0, to_string(score).find(".") + 3) << endl;   
        }

        while (!losers.isEmpty()) {
            losers.pop();
        }

        k++;
    } while (teamsGame.getSize() != 0);
}

//cerinta4
void cerinta_4(istream& in, ostream& out) {

    cerinta_3(in, out); 

    in.clear();
    in.seekg(0);

    int nrTeams, n = 1;
    in >> nrTeams;
    listTeams teams;

    for (int i = 0; i < nrTeams; i++) {
        Team t;
        in >> t;
        teams.add(t);
    }

    do {
        n = n * 2;
    } while (n <= nrTeams);

    n = n / 2;

    while (nrTeams > n) {
        teamNode* current = teams.head;
        double min = current->team.teamScore();
        int minIndex = 0;
        for (int j = 0; j < nrTeams; j++) {
            double score = current->team.teamScore();
            if (score < min) {
                min = score;
                minIndex = j;
            }
            current = current->next;
        }
        teams.deleteNode(minIndex);
        nrTeams--;
    }

    while (nrTeams > n) {
        teamNode* current = teams.head;
        double min = current->team.teamScore();
        int minIndex = 0;
        for (int j = 0; j < nrTeams; j++) {
            double score = current->team.teamScore();
            if (score < min) {
                min = score;
                minIndex = j;
            }
            current = current->next;
        }
        teams.deleteNode(minIndex);
        nrTeams--;
    }

    int nrGames;
    nrGames = nrTeams / 2;
    queueGame teamsGame(nrGames);
    teamNode* current = teams.head;

    while (current != NULL) {
        Game game;
        game.set_t1(current->team);
        game.set_t2(current->next->team);

        teamsGame.push(game);
        current = current->next->next;
    }

    int nrWinners, nrLosers;
    nrWinners = nrTeams / 2;
    nrLosers = nrTeams / 2;

    teamStack winners(nrWinners), losers(nrLosers);
    Game* lastGame = nullptr;
    int k = 1;
    string winner;

    do {
        int sizeGames = teamsGame.getSize();
        for (int i = 0; i < sizeGames; i++) {
            if (teamsGame.peek().get_t1().teamScore() > teamsGame.peek().get_t2().teamScore()) { //>=
                Team t1 = teamsGame.peek().get_t1();

                t1.addPoint();
                winners.push(t1);

                Team t2 = teamsGame.peek().get_t2();
                losers.push(t2);
            }
            else {
                Team t1 = teamsGame.peek().get_t1();
                losers.push(t1);

                Team t2 = teamsGame.peek().get_t2();

                t2.addPoint();
                winners.push(t2);
            }
            Game game = teamsGame.pop();
        }

        Game currentGame;
        bool completed = false;

        while (!winners.isEmpty()) {
            Team tm = winners.pop();
            if (completed) {
                currentGame.set_t2(tm);
                completed = false;
                lastGame = new Game(currentGame);
                teamsGame.push(*lastGame);
            }
            else {
                currentGame.set_t1(tm);
                completed = true;
            }
        }

        while (!losers.isEmpty()) {
            losers.pop();
        }

        k++;
    } while (teamsGame.getSize() != 4);

    BST bst_teams;
    BST* root = NULL;

    root = bst_teams.insert_team(root, teamsGame.peek().get_t1());
    bst_teams.insert_team(root, teamsGame.peek().get_t2());

    teamsGame.pop();

    for (int i = 0; i < 3; i++) {
        bst_teams.insert_team(root, teamsGame.peek().get_t1());
        bst_teams.insert_team(root, teamsGame.peek().get_t2());

        teamsGame.pop();
    }
    
    out << endl << "TOP 8 TEAMS:" << endl;
    bst_teams.display_teams(out, root);

}

//cerinta5
void cerinta_5(istream& in, ostream& out) {
    cerinta_4(in, out);

    in.clear();
    in.seekg(0);

    int nrTeams, n = 1;
    in >> nrTeams;
    listTeams teams;

    for (int i = 0; i < nrTeams; i++) {
        Team t;
        in >> t;
        teams.add(t);
    }

    do {
        n = n * 2;
    } while (n <= nrTeams);

    n = n / 2;

    while (nrTeams > n) {
        teamNode* current = teams.head;
        double min = current->team.teamScore();
        int minIndex = 0;
        for (int j = 0; j < nrTeams; j++) {
            double score = current->team.teamScore();
            if (score < min) {
                min = score;
                minIndex = j;
            }
            current = current->next;
        }
        teams.deleteNode(minIndex);
        nrTeams--;
    }

    while (nrTeams > n) {
        teamNode* current = teams.head;
        double min = current->team.teamScore();
        int minIndex = 0;
        for (int j = 0; j < nrTeams; j++) {
            double score = current->team.teamScore();
            if (score < min) {
                min = score;
                minIndex = j;
            }
            current = current->next;
        }
        teams.deleteNode(minIndex);
        nrTeams--;
    }

    int nrGames;
    nrGames = nrTeams / 2;
    queueGame teamsGame(nrGames);
    teamNode* current = teams.head;

    while (current != NULL) {
        Game game;
        game.set_t1(current->team);
        game.set_t2(current->next->team);

        teamsGame.push(game);
        current = current->next->next;
    }

    int nrWinners, nrLosers;
    nrWinners = nrTeams / 2;
    nrLosers = nrTeams / 2;

    teamStack winners(nrWinners), losers(nrLosers);
    Game* lastGame = nullptr;
    int k = 1;
    string winner;

    do {
        int sizeGames = teamsGame.getSize();
        for (int i = 0; i < sizeGames; i++) {
            if (teamsGame.peek().get_t1().teamScore() > teamsGame.peek().get_t2().teamScore()) { //>=
                Team t1 = teamsGame.peek().get_t1();

                t1.addPoint();
                winners.push(t1);

                Team t2 = teamsGame.peek().get_t2();
                losers.push(t2);
            }
            else {
                Team t1 = teamsGame.peek().get_t1();
                losers.push(t1);

                Team t2 = teamsGame.peek().get_t2();

                t2.addPoint();
                winners.push(t2);
            }
            Game game = teamsGame.pop();
        }

        Game currentGame;
        bool completed = false;

        while (!winners.isEmpty()) {
            Team tm = winners.pop();
            if (completed) {
                currentGame.set_t2(tm);
                completed = false;
                lastGame = new Game(currentGame);
                teamsGame.push(*lastGame);
            }
            else {
                currentGame.set_t1(tm);
                completed = true;
            }
        }

        while (!losers.isEmpty()) {
            losers.pop();
        }

        k++;
    } while (teamsGame.getSize() != 4);

    BST bst_teams;
    BST* root = NULL;

    root = bst_teams.insert_team(root, teamsGame.peek().get_t1());
    bst_teams.insert_team(root, teamsGame.peek().get_t2());

    teamsGame.pop();

    for (int i = 0; i < 3; i++) {
        bst_teams.insert_team(root, teamsGame.peek().get_t1());
        bst_teams.insert_team(root, teamsGame.peek().get_t2());

        teamsGame.pop();
    }

    out << endl << "THE LEVEL 2 TEAMS ARE:" << endl;

    AVL_tree avl;
    AVL* r = NULL;

    avl.readBST(root, r);
    avl.printLevel(out, r);
}

int main(int argc, char *argv[]) {
    ifstream c(argv[1]);
    ifstream d(argv[2]);
    ofstream r(argv[3]);

    if (!c)
        cout << "Nu s-a putut deschide fisierul de cerinte.";

    if (!d)
        cout << "Nu s-a putut deschide fisierul de date.";

    int mcr = 0;
    for (int cr = 0; cr < 5; cr++) {
        int temp = 0;
        c >> temp;
        if (temp == 0) break;
        mcr++;
    };

    switch (mcr)
    {
    case 1: cerinta_1(d, r); break;
    case 2: cerinta_2(d, r); break;
    case 3: cerinta_3(d, r); break;
    case 4: cerinta_4(d, r); break;
    case 5: cerinta_5(d, r); break;

    default:
        break;
    }

    return 0;
}
