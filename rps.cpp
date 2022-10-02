#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

int ChooseRPS();
int computerRPS();
void biggerInput(int &rps);
void game(int rps, int &pscore, int &cscore);
void thanksForGames(int a, int b);
int evaluation(int a, int b);
void Clear();
void PressEnterToContinue();


int main(int argc, char *argv[])
{
    bool play = true;
    Clear();
    int rps = ChooseRPS();
    int pscore = 0, cscore = 0;
    (rps == 0? play = false : play = true);
    biggerInput(rps);
    while(play){
        game(rps, pscore, cscore);
        rps = ChooseRPS();
        (rps == 0? play = false : play = true);
        biggerInput(rps);
    }
    if (play == false){
        thanksForGames(pscore, cscore);
    }
    return 1;
}

int ChooseRPS()
{
    int ret = {0};
    cout << "Please choose rock, paper, scissors" << endl;
    cout << "Type 1 for rock, 2 for paper, 3 for scissors, 0 to end the game: ";
    cin >> ret;
    if (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ouch that is incorrect input! Please try again!" << endl;
        ret = ChooseRPS();
    }
    return ret;
}

void biggerInput(int &rps)
{
    if (rps < 0){
        rps = -rps;
    }
    rps = rps % 3;

    if (rps == 0){
        cout << "You've choosen scissors!" << endl;
    }else if (rps == 1){
        cout << "You've choosen rock!" << endl;
    }else{
        cout << "You've choosen paper!" << endl;
    }
}

void game(int rps, int &pscore, int &csore)
{
    int crps = computerRPS();
    if (evaluation(rps, crps) == 1){
        cout << "Player won! Congratulations!" << endl;
        pscore += 1;
    }else if (evaluation(rps, crps) == -1){
        cout << "Computer won! Better luck next time!" << endl;
        csore += 1;
    }else{
        cout << "It was a tie!" << endl;
    }
    system("read -p 'Press Enter to continue...' var");
    Clear();
}

int computerRPS()
{
    return rand() % 3;
}

int evaluation(int rps, int crps)
{
    if ((rps + 1) % 3 == crps){
        return 1;
    }else if ((crps + 1) % 3 == rps){
        return -1;
    }else{
        return 0;
    }
}

void thanksForGames(int pscore, int cscore)
{
    Clear();
    cout << "Sadge that you go! :(" << endl;
    cout << "The final score was " << pscore << " points for player and " << cscore << " points for computer" << endl;
}

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}


void PressEnterToContinue()
  {
  std::cout << "Press ENTER to continue... " << flush;
  std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
  }
