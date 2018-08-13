# r6-lootbox-sim

This is a project to simulate the loot box drop system of Rainbow 6 Siege. The constants are currently set for a 50% win rate and the lootbox drop rates of the casual mode.

The results show that a player with a 1:1 win:loss ratio playing in the casual gamemode should recieve about 7.7 loot box drops per 100 games. 

On my hardware, simulating 1 billion games took only 36 seconds when written in C and compiled. In python, the same program is 100x slower at about 3.6 minutes. Quite the speed diffrence. The python version is included for your pleasure.


Example of output:

>Wins: 500314929
Losses: 499685071
Current Chance: 0.085
Boxes Collected: 77404268
