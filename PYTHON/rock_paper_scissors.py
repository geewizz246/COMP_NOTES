import random
import time


class Game:
    def __init__(self, new_player_name):
        self.player_name = new_player_name
        self.player_hand = "NA"
        self.bot_hand = "NA"
        self.winner = "No winner yet"
        print("New instance of game class for " + self.player_name)

    def run_game(self):
        if self.player_hand == self.bot_hand:
            self.winner = "Tie. No one won."
        elif (self.player_hand == 'Rock' and self.bot_hand == 'Scissors') or (self.player_hand == 'Paper' and self.bot_hand == 'Rock') or (
                self.player_hand == 'Scissors' and self.bot_hand == 'Paper'):
            self.winner = "You win!"
        elif (self.player_hand == 'Rock' and self.bot_hand == 'Paper') or (self.player_hand == 'Paper' and self.bot_hand == 'Scissors') or (
                self.player_hand == 'Scissors' and self.bot_hand == 'Rock'):
            self.winner = "Awww you lost."


def countdown():
    for i in range(3, 0, -1):
        print(i)
        time.sleep(1)


def determine_choice(person_play):
    if person_play == 1:
        return "Rock"
    elif person_play == 2:
        return "Paper"
    elif person_play == 3:
        return "Scissors"


def determine_winner(user_play, bot_play):
    if user_play == bot_play:
        print("Tie. No one won.")
        return "tie"
    elif (user_play == 'Rock' and bot_play == 'Scissors') or (user_play == 'Paper' and bot_play == 'Rock') or (user_play == 'Scissors' and bot_play == 'Paper'):
        print("You win!")
        return "win"
    elif (user_play == 'Rock' and bot_play == 'Paper') or (user_play == 'Paper' and bot_play == 'Scissors') or (user_play == 'Scissors' and bot_play == 'Rock'):
        print("Awww you lost.")
        return "lose"


def main():
    print("Welcome to rock player scissors. You are playing against a bot and the best two out of three wins!")
    name = input("Can I ask of your name? ====> ")
    print("Pleased to meet you, " + name + ".")
    my_game = Game(name)
    print(my_game.player_name)
    print(my_game.player_hand)
    print(my_game.bot_hand)
    print(my_game.winner)

    my_game.player_hand = 'Paper'
    my_game.bot_hand = 'Scissors'
    my_game.run_game()

    print(my_game.winner)
    """
    print("Welcome to rock player scissors. You are playing against a bot and the best two out of three wins!")
    someone_won = False
    player_wins = 0
    bot_wins = 0
    while not someone_won:
        input("Press Enter key when ready...")

        while True:
            try:
                user_play = int(input("Choose one of the following:\n1. Rock\n2. Paper\n3. Scissors"
                                      "\nTask ====> "))
            except ValueError:
                print("Invalid input. Try again.")
                continue
            if user_play < 1 or user_play > 3:
                print("I don't understand. Please try again.")
            else:
                break
        bot_play = random.randint(1, 3)

        Countdown()
        print("Player chose", DetermineChoice(user_play))
        print("Bot chose", DetermineChoice(bot_play))
        round_winner = DetermineWinner(user_play, bot_play)
        if round_winner == "win":
            player_wins += 1
        elif round_winner == "lose":
            bot_wins += 1

        if player_wins == 2 or bot_wins == 2:
            someone_won = True

    print("\n\n")
    if player_wins == 2:
        print("You won the game!!! CONGRATULATIONS!!! ^_^")
    else:
        print("The bot remains superior! Better luck next time.")
    """


main()
