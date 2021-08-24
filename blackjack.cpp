#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const char hard_total[18][10] = {   // 2   3   4   5   6   7   8   9  10   A
                                          'H','H','H','H','H','H','H','H','H','H', // 4
                                          'H','H','H','H','H','H','H','H','H','H', // 5
                                          'H','H','H','H','H','H','H','H','H','H', // 6
                                          'H','H','H','H','H','H','H','H','H','H', // 7
                                          'H','H','H','H','H','H','H','H','H','H', // 8
                                          'H','D','D','D','D','H','H','H','H','H', // 9
                                          'D','D','D','D','D','D','D','D','H','H', // 10
                                          'D','D','D','D','D','D','D','D','D','H', // 11
                                          'H','H','S','S','S','H','H','H','H','H', // 12
                                          'S','S','S','S','S','H','H','H','H','H', // 13
                                          'S','S','S','S','S','H','H','H','H','H', // 14
                                          'S','S','S','S','S','H','H','H','H','H', // 15
                                          'S','S','S','S','S','H','H','H','H','H', // 16
                                          'S','S','S','S','S','S','S','S','S','S', // 17
                                          'S','S','S','S','S','S','S','S','S','S', // 18
                                          'S','S','S','S','S','S','S','S','S','S', // 19
                                          'S','S','S','S','S','S','S','S','S','S', // 20
                                          'S','S','S','S','S','S','S','S','S','S', // 21
                                    };
    const char splitting[11][10] =  {  // 2   3   4   5   6   7   8   9   10   A
                                         'H','H','P','P','P','P','H','H','H','H', // 22
                                         'H','H','P','P','P','P','H','H','H','H', // 33
                                         'H','H','H','H','H','H','H','H','H','H', // 44
                                         'D','D','D','D','D','D','D','D','H','H', // 55
                                         'H','P','P','P','P','H','H','H','H','H', // 66
                                         'P','P','P','P','P','P','H','H','H','H', // 77
                                         'P','P','P','P','P','P','P','P','P','P', // 88
                                         'P','P','P','P','P','S','P','P','S','S', // 99
                                         'S','S','S','S','S','S','S','S','S','S', // TT
                                         'P','P','P','P','P','P','P','P','P','P', // AA
                                    };
    const char soft_total[8][10] =  {  // 2   3   4   5   6   7   8   9   10   A
                                         'H','H','H','D','D','H','H','H','H','H', // A2
                                         'H','H','H','D','D','H','H','H','H','H', // A3
                                         'H','H','D','D','D','H','H','H','H','H', // A4
                                         'H','H','D','D','D','H','H','H','H','H', // A5
                                         'H','D','D','D','D','H','H','H','H','H', // A6
                                         'S','D','D','D','D','S','S','H','H','H', // A7
                                         'S','S','S','S','S','S','S','S','S','S', // A8
                                         'S','S','S','S','S','S','S','S','S','S', // A9
                                    };

int get_card(){
    srand(time(NULL));
    return((rand() % 13) + 1);
}

float get_pay(int dealer, int user, float bet){
    if (dealer == 21){
        return(bet * -1);
    }
    else if (user > 21){
        return(bet * -1);
    }
    else if (user == 21){
        return(bet + (bet * .5));
    }
    else if (dealer > 21){
        return(bet);
    }
    else if (user > dealer){
        return(bet);
    }
    else if (user == dealer){
        return(0);
    }
    else if (user < dealer){
        return(bet * -1);
    }
    return(0);
}

char get_decision_1(int card_1, int card_2, int dealer){
    if(card_1 == 1){
        return(soft_total[card_1][dealer]);
    }
    else if(card_2 == 1){
        return(soft_total[card_2][dealer]);
    }
    else {
        return(hard_total[card_1 + card_2][dealer]);
    }
}

int main(){
    int cash = 100;
    int dealer_card = 0;
    int player_card_1 = 0;
    int player_card_2 = 0;
    char player_decision = '0';

    while(cash > 0) {
        dealer_card = get_card();
        player_card_1 = get_card();
        player_card_2 = get_card();
        player_decision = get_decision_1(player_card_1, player_card_2, dealer_card);

    }
}