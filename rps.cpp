#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

int ChooseRPS();
int computerRPS();
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
    (rps == '0'? play = false : play = true);
    while(play){
        game(rps, pscore, cscore);
        rps = ChooseRPS();
        (rps == '0'? play = false : play = true);
    }
    thanksForGames(pscore, cscore);
    return 1;
}

int ChooseRPS()
{
    char ret = '0';
    cout << "Please choose rock, paper, scissors!" << endl;
    cout << "Type 1 for rock, 2 for paper, 3 for scissors, 0 to end the game: ";
    cin >> ret;
    cout << ret << endl;
    if (ret == '0'){
        cout << "You have choosen to end the game!" << endl;
    }else if (ret == '1'){
        cout << "You have choosen rock!" << endl;
    }else if (ret == '2'){
        cout << "You have choosen paper!" << endl;
    }else if (ret == '3'){
        cout << "You have choosen scissors!" << endl;
    }else{
        Clear();
        cout << ret << " is an incorrect input! Please try again!" << endl;
        ret = ChooseRPS();
    }
    return ret;
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
    int ret = (rand() % 3) + 1;
    if (ret == 1){
        cout << "Computer choose rock!" << endl;
    }else if (ret == 2){
        cout << "Computer choose paper!" << endl;
    }else{
        cout << "Computer choose scissors!" << endl;
    }
    return ret;
}

int evaluation(int rps, int crps)
{
    if ((rps + 2) % 3 == crps % 3){
        return 1;
    }else if ((crps + 2) % 3 == rps % 3){
        return -1;
    }else{
        return 0;
    }
}

void thanksForGames(int pscore, int cscore)
{
    Clear();
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
