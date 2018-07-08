#include <iostream>
#include <random>
#include <chrono>       //std::chrono::system_clock, std::chrono_literals
#include <thread>       // std::this_thread::sleep_for
#include <string>

using namespace std;

// does a 3 second countdown before each player's choice is revealed
void countdown()
{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;
    
    for (int i = 3; i > 0; i--)
    {
        cout << i << endl;
        sleep_for(1s);
    }
    cout << endl << endl << endl;
}


// determines player choice of attack
string determineChoice(int person_play)
{
    if (person_play ==  1)
        return "Rock";
    else if (person_play == 2)
        return "Paper";
    else if (person_play == 3)
        return "Scissors";
}


//determines winner of each round
string determineWinner(int user_play, int bot_play)
{
    if (user_play == bot_play)
    {
        cout << "Tie. No one won." << endl;
        return "tie";
    }
    else if ((user_play == 1 && bot_play == 3) || (user_play == 2 && bot_play == 1) || (user_play == 3 && bot_play == 2))
    {
        cout << "You win!" << endl;
        return "player_win";
    }
    else
    {
        cout << "Awww you lost." << endl;
        return "bot_win";
    }
}


int main()
{
    cout << "Welcome to \"Rock, Papper, Scissors\". "
    << "You are playing against a bot and the best two out of three wins." << endl;
    
    bool someone_won = false; //determines if someone won the game
    int player_wins = 0; //no. of rounds player won
    int bot_wins = 0; //no. of rounds bot won
    int user_play, bot_play;

    //*************************************************//
    //********* RANDOM PLAY GENERATOR FOR BOT *********//
        int min = 1,
        max = 3;
        random_device rd;
        mt19937 bot_eng(rd());
        uniform_int_distribution <> uniformDist(min, max);
    //*************************************************//

    // Play more rounds until someone wins
    while (!someone_won)
    {
        cout << endl << "Press Enter key when ready..." << endl;
        cin.ignore(); // accepts a newline character

        cout << "Choose one of the following:\n1. Rock\n2. Paper\n3. Scissors" << endl
            << "Task ====> ";
        cin >> user_play;

        // While user input is invalid (e.g. string)
        while (cin.fail())
        {
            cin.clear(); // Clear error flags. This corrects the stream
            cin.ignore(1000, '\n'); // This skips the left over stream data
                                    // first param: arbitrarily large value
                                    // second param: character to ignore until in stream data  
            cout << "Please enter a number only." << endl
                << "Task ====> ";
            cin >> user_play;
        }

        bot_play = uniformDist(bot_eng); // Generate the bot's choice of attack

        countdown(); // Do a dramatic countdown

        // Reveal player attacks
        cout << "Player chose " << determineChoice(user_play) << endl;
        cout << "Bot chose " << determineChoice(bot_play) << endl;

        // Determine the winner of the round
        string round_winner = determineWinner(user_play, bot_play);

        if (round_winner == "player_win")
            player_wins++;
        else if (round_winner == "bot_win")
            bot_wins++;
        
        if (player_wins == 2 || bot_wins == 2)
            someone_won = true;
    }

    cout << endl << endl;
    if (player_wins == 2)
        cout << "You won the game!!! CONGRATULATIONS!!! ^_^" << endl;
    else
        cout << "The bot remains superior! Better luck next time." << endl;
}