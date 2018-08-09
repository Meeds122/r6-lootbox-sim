#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player{
    int wins;
    int losses;
    float current_chance;
    int boxes_collected;
};

void initializePlayer(struct Player *player){
    player->boxes_collected = 0;
    player->current_chance = .02;
    player->wins = 0;
    player->losses = 0;
}

void printPlayer(struct Player *player){
    printf("\n=====\nWins: %d\nLosses: %d\nCurrent Chance: %.3f\nBoxes Collected: %d\n=====\n\n", player->wins, player->losses, player->current_chance, player->boxes_collected);
}

int rollPlayerWin(){
    //return 1 for random player win, 0 for loss
    return rand()%2; // currently simulates win/loss 1:1 ratio
}

int rollPlayerLootbox(float current_chance){
    //return 1 if player should get loot box based on random roll
    int rand_result = rand();
    int comparator1 = rand_result%1000;
    int comparator2 = current_chance * 1000;
    if( comparator1 <= comparator2){
        return 1;
    }
    return 0;
}

void simulateGame(struct Player *player){
    if(rollPlayerWin()){
        player->wins++;
        if(rollPlayerLootbox(player->current_chance)){
            player->boxes_collected++;
            player->current_chance = .02; // player wins game and gets loot box. chance to win resets.
        }
        else{
            player->current_chance = player->current_chance + .020; // player win game but gets no loot box
        }
    }
    else{
        player->losses++;
        player->current_chance = player->current_chance + .015; // player loses game increase chance to win by less
    }
}

int main()
{
    printf("[*] Seeding random number generator\n");
    srand(time(0));

    printf("[*] Creating Player struct\n");
    struct Player *player = malloc(sizeof(struct Player));

    printf("[*] Initializing Player struct to default values\n");
    initializePlayer(player);
    printf("[*] Current status of Player struct\n");
    printPlayer(player);

    printf("[*] Simulating one game\n");
    simulateGame(player);
    printPlayer(player);

    printf("[*] Simulating 1,000,000,000 games ignoring previous simulation\n");
    initializePlayer(player); // delete old data from previous single simulation
    for(int i = 0; i < 1000000000; i++){
        simulateGame(player);
    }
    printPlayer(player);



    printf("[*] Freeing Player struct\n");
    free(player);
    return 0;
}
