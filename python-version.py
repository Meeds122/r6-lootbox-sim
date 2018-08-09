# companion to the r6-lootbox-sim

from random import seed, randrange
import time

"""
I could have wrapped many of the functions into the Player object and
not have had to copy the returned Player to the existing player variable
in simulateGame(). This was to retain at least a passing structural similarity
to the C program included.
"""

class Player(object):
    def __init__(self):
        self.wins = 0
        self.losses = 0
        self.current_chance = 0.02
        self.lootboxes = 0
    def __str__(self):
        r = "\n=====\nWins: " + str(self.wins) + "\nLosses: " + str(self.losses) + "\nCurrent Chance: " + str(self.current_chance) + "\nBoxes Collected: " + str(self.lootboxes) + "\n=====\n\n"
        return r

def rollPlayerWin():
    if randrange(0,2) == 1:
        return True
    else:
        return False

def rollPlayerLootbox(current_chance):
    if randrange(0,1001) <= (current_chance*1000):
        return True
    else:
        return False

def simulateGame(player):
    if rollPlayerWin():
        player.wins += 1
        if rollPlayerLootbox(player.current_chance):
            player.current_chance = 0.02
            player.lootboxes += 1
        else:
            player.current_chance += 0.02
    else:
        player.losses += 1
        player.current_chance += .015
    return player

def main():
    seed() # use current time to seed random number generator
    
    player = Player()

    print("Simulating one game")
    player = simulateGame(player)
    print(player)

    print("Reseting stats and simulating 1,000,000 games")
    player.__init__()
    for i in range(1000000):
        player = simulateGame(player)
    print(player)

if __name__ == "__main__":
    start_time = time.time()
    main()
    print(" --- %s seconds ---" % (time.time() - start_time))
    
