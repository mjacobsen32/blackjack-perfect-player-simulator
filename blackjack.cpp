#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

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
    return((rand() % 13) + 2);
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

int get_dealer_hand(vector<int> cards){
    int total = 0;
    total = cards[0];
    while  (total < 17) {
        total = total + get_card();
    }
    return(total);
}

int play_hands(vector<int> dealer_cards, vector<vector<int> > player_cards){
    int dealer_hand = get_dealer_hand(dealer_cards);
    for (int i = 0; i < player_cards.size(); i++ ){
        for (int j = 0; j < player_cards[i].size(); j++ ){
            while
        }
    }

}
char get_decision(int card_1, int card_2, int dealer){
    if(card_1 == card_2){
        return(splitting[card_1][dealer]);
    }
    else if(card_1 == 1){
        return(soft_total[card_1][dealer]);
    }
    else if(card_2 == 1){
        return(soft_total[card_2][dealer]);
    }
    else {
        return(hard_total[card_1 + card_2][dealer]);
    }
}

void print_vector(vector<vector<int> > vtr){
    
    for ( int i = 0 ; i < vtr.size(); i++ ){
        for ( int j = 0; j < vtr[i].size() ; j++ ){
            cout << vtr[i][j] << " " ;
        }
        cout << endl ;
    }
}
int main(){
    srand(time(NULL));
    int cash = 100;
    vector<int> dealer_cards;
    vector<vector<int> > player_cards;

    while(cash > 0) {
        vector<int> dealer_cards;
        vector<vector<int> > player_cards;

        dealer_cards.push_back(get_card()); // dealer card 1

        vector<int> player;
        player.push_back(get_card());
        player.push_back(get_card());
        player_cards.push_back(player);

        bool split = true;

        while(split == true){
            split = false;
            print_vector(player_cards);
            for(int i = 0; i < player_cards.size(); i++){
                if((player_cards[i][0] == player_cards[i][1]) && (splitting[player_cards[i][0]][dealer_cards[0]] == 'P')){
                    cout << "SPLITTING" << endl;
                    player_cards[i][1] = get_card();
                    vector<int> player;
                    player.push_back(player_cards[i][0]);
                    player.push_back(get_card());
                    split = true;
                }
            }
        }

        cash += play_hands(dealer_cards, player_cards);
    }
    return 0;
}