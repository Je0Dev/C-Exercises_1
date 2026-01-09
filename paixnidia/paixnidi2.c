#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int draw_card();
void print_card(int card);
int calculate_hand_value(int cards[], int num_cards, int* has_ace);
void play_player_hand(int player_cards[], int* num_player_cards, int dealer_first_card);
void play_dealer_hand(int dealer_cards[], int* num_dealer_cards);
void determine_winner(int player_value, int dealer_value, int num_player_cards);
void split_hand(int first_card, int dealer_first_card);

int main() {
    srand(time(NULL));
    
    printf("Welcome to Blackjack!\n\n");
    
    // Initialize hands
    int dealer_cards[10] = {0};
    int player_cards[10] = {0};
    int num_dealer_cards = 1;
    int num_player_cards = 2;
    
    // Deal initial cards
    dealer_cards[0] = draw_card();
    player_cards[0] = draw_card();
    player_cards[1] = draw_card();
    
    printf("First card of dealer is ");
    print_card(dealer_cards[0]);
    printf("\n");
    
    printf("First card of player is ");
    print_card(player_cards[0]);
    printf("\n");
    
    printf("Second card of player is ");
    print_card(player_cards[1]);
    printf("\n");
    
    // Check for Blackjack
    int has_ace = 0;
    int player_value = calculate_hand_value(player_cards, num_player_cards, &has_ace);
    
    if ((player_cards[0] == 1 && player_cards[1] >= 10) || 
        (player_cards[1] == 1 && player_cards[0] >= 10)) {
        printf("Player has Blackjack!\n");
        
        // Check if dealer also has Blackjack
        int dealer_second_card = draw_card();
        dealer_cards[1] = dealer_second_card;
        num_dealer_cards++;
        
        if ((dealer_cards[0] == 1 && dealer_second_card >= 10) || 
            (dealer_second_card == 1 && dealer_cards[0] >= 10)) {
            printf("Dealer also has Blackjack! It's a tie.\n");
        } else {
            printf("Player wins with Blackjack!\n");
        }
        
        return 0;
    }
    
    // Check for split
    if (player_cards[0] == player_cards[1]) {
        int split_choice;
        printf("You have a pair. Do you want to split (1: for yes, 0: for no)? ");
        scanf("%d", &split_choice);
        
        if (split_choice == 1) {
            split_hand(player_cards[0], dealer_cards[0]);
            return 0;
        }
    }
    
    // Play player hand
    play_player_hand(player_cards, &num_player_cards, dealer_cards[0]);
    player_value = calculate_hand_value(player_cards, num_player_cards, &has_ace);
    
    if (player_value > 21) {
        printf("Player busts! Dealer wins.\n");
        return 0;
    }
    
    // Play dealer hand
    printf("\nDealer's turn:\n");
    play_dealer_hand(dealer_cards, &num_dealer_cards);
    int dealer_value = calculate_hand_value(dealer_cards, num_dealer_cards, &has_ace);
    
    // Determine winner
    determine_winner(player_value, dealer_value, num_player_cards);
    
    return 0;
}

int draw_card() {
    return (rand() % 13) + 1;
}

void print_card(int card) {
    switch(card) {
        case 1: printf("'A'"); break;
        case 11: printf("'J'"); break;
        case 12: printf("'Q'"); break;
        case 13: printf("'K'"); break;
        default: printf("%d", card);
    }
}

int calculate_hand_value(int cards[], int num_cards, int* has_ace) {
    int value = 0;
    int aces = 0;
    
    for (int i = 0; i < num_cards; i++) {
        if (cards[i] == 1) {
            aces++;
        } else if (cards[i] >= 10) {
            value += 10;
        } else {
            value += cards[i];
        }
    }
    
    *has_ace = (aces > 0);
    
    // Add value for aces (1 or 11)
    for (int i = 0; i < aces; i++) {
        if (value + 11 <= 21) {
            value += 11;
        } else {
            value += 1;
        }
    }
    
    return value;
}

void play_player_hand(int player_cards[], int* num_player_cards, int dealer_first_card) {
    int choice;
    int has_ace = 0;
    int hand_value;
    
    while (1) {
        hand_value = calculate_hand_value(player_cards, *num_player_cards, &has_ace);
        printf("Player has total %d", hand_value);
        
        if (has_ace && hand_value - 10 <= 10) {
            printf(" or %d", hand_value - 10);
        }
        printf("\n");
        
        if (hand_value > 21) {
            printf("Player busts with %d!\n", hand_value);
            return;
        }
        
        printf("Do you want to draw another card (1: for yes)? ");
        scanf("%d", &choice);
        
        if (choice != 1) break;
        
        player_cards[(*num_player_cards)++] = draw_card();
        printf("Player draw ");
        print_card(player_cards[*num_player_cards - 1]);
        printf("\n");
    }
}

void play_dealer_hand(int dealer_cards[], int* num_dealer_cards) {
    int has_ace = 0;
    int hand_value;
    
    while (1) {
        hand_value = calculate_hand_value(dealer_cards, *num_dealer_cards, &has_ace);
        printf("Dealer has total %d", hand_value);
        
        if (has_ace && hand_value - 10 <= 10) {
            printf(" or %d", hand_value - 10);
        }
        printf("\n");
        
        if (hand_value > 21) {
            printf("Dealer busts with %d!\n", hand_value);
            return;
        }
        
        if (hand_value > 16) {
            break;
        }
        
        dealer_cards[(*num_dealer_cards)++] = draw_card();
        printf("Dealer draw ");
        print_card(dealer_cards[*num_dealer_cards - 1]);
        printf("\n");
    }
}

void determine_winner(int player_value, int dealer_value, int num_player_cards) {
    printf("\nFinal results:\n");
    printf("Player total: %d\n", player_value);
    printf("Dealer total: %d\n", dealer_value);
    
    if (dealer_value > 21) {
        printf("Dealer busts! Player wins!\n");
    } else if (player_value > dealer_value) {
        printf("Player wins!\n");
    } else if (player_value < dealer_value) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

void split_hand(int first_card, int dealer_first_card) {
    // First hand
    printf("\nHand_1:\n");
    int hand1_cards[10] = {first_card, 0};
    int num_hand1_cards = 2;
    int has_ace = 0;
    
    hand1_cards[1] = draw_card();
    printf("First card of hand_1 is ");
    print_card(hand1_cards[0]);
    printf("\n");
    printf("Second card of hand_1 is ");
    print_card(hand1_cards[1]);
    printf("\n");
    
    int choice;
    printf("Hand_1: Do you want to draw another card (1: for yes)? ");
    scanf("%d", &choice);
    
    while (choice == 1) {
        hand1_cards[num_hand1_cards++] = draw_card();
        printf("Player draw ");
        print_card(hand1_cards[num_hand1_cards - 1]);
        printf("\n");
        
        int hand_value = calculate_hand_value(hand1_cards, num_hand1_cards, &has_ace);
        printf("Player has total %d", hand_value);
        if (has_ace && hand_value - 10 <= 10) {
            printf(" or %d", hand_value - 10);
        }
        printf("\n");
        
        if (hand_value > 21) {
            printf("Player busts!\n");
            break;
        }
        
        printf("Hand_1: Do you want to draw another card (1: for yes)? ");
        scanf("%d", &choice);
    }
    
    // Second hand
    printf("\nHand_2:\n");
    int hand2_cards[10] = {first_card, 0};
    int num_hand2_cards = 2;
    
    hand2_cards[1] = draw_card();
    printf("First card of hand_2 is ");
    print_card(hand2_cards[0]);
    printf("\n");
    printf("Second card of hand_2 is ");
    print_card(hand2_cards[1]);
    printf("\n");
    
    printf("Hand_2: Do you want to draw another card (1: for yes)? ");
    scanf("%d", &choice);
    
    while (choice == 1) {
        hand2_cards[num_hand2_cards++] = draw_card();
        printf("Player draw ");
        print_card(hand2_cards[num_hand2_cards - 1]);
        printf("\n");
        
        int hand_value = calculate_hand_value(hand2_cards, num_hand2_cards, &has_ace);
        printf("Player has total %d", hand_value);
        if (has_ace && hand_value - 10 <= 10) {
            printf(" or %d", hand_value - 10);
        }
        printf("\n");
        
        if (hand_value > 21) {
            printf("Player busts!\n");
            break;
        }
        
        printf("Hand_2: Do you want to draw another card (1: for yes)? ");
        scanf("%d", &choice);
    }
    
    // Dealer plays
    printf("\nDealer's turn:\n");
    int dealer_cards[10] = {dealer_first_card, 0};
    int num_dealer_cards = 1;
    play_dealer_hand(dealer_cards, &num_dealer_cards);
    int dealer_value = calculate_hand_value(dealer_cards, num_dealer_cards, &has_ace);
    
    // Calculate hand values
    int hand1_value = calculate_hand_value(hand1_cards, num_hand1_cards, &has_ace);
    int hand2_value = calculate_hand_value(hand2_cards, num_hand2_cards, &has_ace);
    
    // Determine winners for both hands
    printf("\nResults for split hands:\n");
    
    printf("Hand_1: ");
    if (hand1_value > 21) {
        printf("Player busts! Dealer wins.\n");
    } else if (dealer_value > 21) {
        printf("Dealer busts! Player wins.\n");
    } else if (hand1_value > dealer_value) {
        printf("Player wins!\n");
    } else if (hand1_value < dealer_value) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    printf("Hand_2: ");
    if (hand2_value > 21) {
        printf("Player busts! Dealer wins.\n");
    } else if (dealer_value > 21) {
        printf("Dealer busts! Player wins.\n");
    } else if (hand2_value > dealer_value) {
        printf("Player wins!\n");
    } else if (hand2_value < dealer_value) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}