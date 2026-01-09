#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 13
#define MAX_PLAYERS 5

enum card { 
    SA = 1, S2, S3, S4, S5, S6, S7, S8, S9, S10, SJ, SQ, SK,
    DA, D2, D3, D4, D5, D6, D7, D8, D9, D10, DJ, DQ, DK,
    CA, C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK,
    HA, H2, H3, H4, H5, H6, H7, H8, H9, H10, HJ, HQ, HK
};

const char* get_card_name(enum card c);
void card_shuffling(int table[][COLS]);
void print_table(int table[][COLS], int table_opened_cards[][COLS]);
void add_points(int points[], int player_id, int win_points);
void print_winners(int points[], int num_players);
int select_card(int table[][COLS], int table_opened_cards[][COLS], int* row, int* col, int player_id, int no_of_card);
int get_card_value(int card_value);
int get_card_rank(int card_value);

int main(void) {
    int table[ROWS][COLS] = {0};
    int table_opened_cards[ROWS][COLS] = {0};
    int points[MAX_PLAYERS] = {0};
    int num_players, current_player = 0;
    int total_opened = 0;
    
    srand(time(NULL));
    
    // Get number of players
    do {
        printf("Enter number of players (2-5): ");
        scanf("%d", &num_players);
        if (num_players < 2 || num_players > 5) {
            printf("Invalid number of players. Please enter a number between 2 and 5.\n");
        }
    } while (num_players < 2 || num_players > 5);
    
    // Initialize the deck
    enum card card_value = SA;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = card_value++;
        }
    }
    
    // Shuffle the deck
    card_shuffling(table);
    
    // Game loop
    while (total_opened < ROWS * COLS) {
        printf("\nPlayer %d's turn\n", current_player + 1);
        
        // Print the game table
        printf("\nGame board:\n");
        print_table(table, table_opened_cards);
        
        int row1, col1, row2, col2, row3 = -1, col3 = -1;
        int card1, card2, card3 = -1;
        int has_third_card = 0;
        
        // Select first card
        if (select_card(table, table_opened_cards, &row1, &col1, current_player, 1) == -1) {
            continue;
        }
        card1 = table[row1][col1];
        
        // Select second card
        if (select_card(table, table_opened_cards, &row2, &col2, current_player, 2) == -1) {
            continue;
        }
        card2 = table[row2][col2];
        
        // Check if either card is King or Ace
        if (get_card_rank(card1) == 13 || get_card_rank(card1) == 1 || 
            get_card_rank(card2) == 13 || get_card_rank(card2) == 1) {
            printf("You have a King or Ace! You can open a third card.\n");
            if (select_card(table, table_opened_cards, &row3, &col3, current_player, 3) != -1) {
                card3 = table[row3][col3];
                has_third_card = 1;
            }
        }
        
        // Check for matches
        int match12 = (get_card_rank(card1) == get_card_rank(card2));
        int match13 = 0, match23 = 0;
        
        if (has_third_card) {
            match13 = (get_card_rank(card1) == get_card_rank(card3));
            match23 = (get_card_rank(card2) == get_card_rank(card3));
        }
        
        // Process matches
        if (match12 || match13 || match23) {
            int points_to_add = 0;
            int card_matched = -1;
            
            if (match12) {
                table_opened_cards[row1][col1] = 1;
                table_opened_cards[row2][col2] = 1;
                total_opened += 2;
                card_matched = card1;
            } else if (match13) {
                table_opened_cards[row1][col1] = 1;
                table_opened_cards[row3][col3] = 1;
                total_opened += 2;
                card_matched = card1;
            } else if (match23) {
                table_opened_cards[row2][col2] = 1;
                table_opened_cards[row3][col3] = 1;
                total_opened += 2;
                card_matched = card2;
            }
            
            // Calculate points
            int rank = get_card_rank(card_matched);
            if (rank == 1) { // Ace
                points_to_add = 20;
            } else if (rank >= 11 && rank <= 13) { // Jack, Queen, King
                points_to_add = 15;
            } else { // Number cards
                points_to_add = rank;
            }
            
            add_points(points, current_player, points_to_add);
            printf("Player %d found a match! +%d points\n", current_player + 1, points_to_add);
            
            // Special rules
            if (rank == 11) { // Jack
                current_player = (current_player + 1) % num_players; // Skip next player
                printf("Next player loses their turn!\n");
            } else if (rank == 12) { // Queen
                printf("Player %d found a Queen pair! They get to play again.\n", current_player + 1);
            } else {
                current_player = (current_player + 1) % num_players;
            }
        } else {
            // No matches, close all cards and move to next player
            printf("No matches found. Cards will be closed again.\n");
            current_player = (current_player + 1) % num_players;
        }
    }
    
    // Game over, print winners
    printf("\nGame over! Final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d points\n", i + 1, points[i]);
    }
    print_winners(points, num_players);
    
    return 0;
}

void card_shuffling(int table[][COLS]) {
    for (int i = 0; i < 1000; i++) {
        int r1 = rand() % ROWS;
        int c1 = rand() % COLS;
        int r2 = rand() % ROWS;
        int c2 = rand() % COLS;
        
        // Swap cards
        int temp = table[r1][c1];
        table[r1][c1] = table[r2][c2];
        table[r2][c2] = temp;
    }
}

void print_table(int table[][COLS], int table_opened_cards[][COLS]) {
    printf("\n   ");
    for (int j = 0; j < COLS; j++) {
        printf("%3d ", j + 1);
    }
    printf("\n");
    
    for (int i = 0; i < ROWS; i++) {
        printf("%2d|", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (table_opened_cards[i][j]) {
                printf("%4s ", get_card_name(table[i][j]));
            } else {
                printf("  X  ");
            }
        }
        printf("\n");
    }
}

const char* get_card_name(enum card c) {
    switch(c) {
        case SA: return "A\u2660"; case S2: return "2\u2660"; case S3: return "3\u2660";
        case S4: return "4\u2660"; case S5: return "5\u2660"; case S6: return "6\u2660";
        case S7: return "7\u2660"; case S8: return "8\u2660"; case S9: return "9\u2660";
        case S10: return "10\u2660"; case SJ: return "J\u2660"; case SQ: return "Q\u2660";
        case SK: return "K\u2660"; case DA: return "A\u2666"; case D2: return "2\u2666";
        case D3: return "3\u2666"; case D4: return "4\u2666"; case D5: return "5\u2666";
        case D6: return "6\u2666"; case D7: return "7\u2666"; case D8: return "8\u2666";
        case D9: return "9\u2666"; case D10: return "10\u2666"; case DJ: return "J\u2666";
        case DQ: return "Q\u2666"; case DK: return "K\u2666"; case CA: return "A\u2663";
        case C2: return "2\u2663"; case C3: return "3\u2663"; case C4: return "4\u2663";
        case C5: return "5\u2663"; case C6: return "6\u2663"; case C7: return "7\u2663";
        case C8: return "8\u2663"; case C9: return "9\u2663"; case C10: return "10\u2663";
        case CJ: return "J\u2663"; case CQ: return "Q\u2663"; case CK: return "K\u2663";
        case HA: return "A\u2665"; case H2: return "2\u2665"; case H3: return "3\u2665";
        case H4: return "4\u2665"; case H5: return "5\u2665"; case H6: return "6\u2665";
        case H7: return "7\u2665"; case H8: return "8\u2665"; case H9: return "9\u2665";
        case H10: return "10\u2665"; case HJ: return "J\u2665"; case HQ: return "Q\u2665";
        case HK: return "K\u2665";
        default: return "???";
    }
}

void add_points(int points[], int player_id, int win_points) {
    points[player_id] += win_points;
}

void print_winners(int points[], int num_players) {
    int max_points = -1;
    int winners[MAX_PLAYERS] = {0};
    int num_winners = 0;
    
    // Find maximum points
    for (int i = 0; i < num_players; i++) {
        if (points[i] > max_points) {
            max_points = points[i];
        }
    }
    
    // Find all players with max points
    for (int i = 0; i < num_players; i++) {
        if (points[i] == max_points) {
            winners[num_winners++] = i;
        }
    }
    
    printf("\nWinners:\n");
    for (int i = 0; i < num_winners; i++) {
        printf("Player %d with %d points\n", winners[i] + 1, max_points);
    }
}

int select_card(int table[][COLS], int table_opened_cards[][COLS], int* row, int* col, int player_id, int no_of_card) {
    int r, c;
    
    do {
        printf("Player %d, select %s card (row col): ", player_id + 1, 
               no_of_card == 1 ? "first" : no_of_card == 2 ? "second" : "third");
        scanf("%d %d", &r, &c);
        r--; c--; // Adjust for 0-based indexing
        
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
            printf("Invalid position. Please select a position within the board (1-%d, 1-%d).\n", ROWS, COLS);
        } else if (table_opened_cards[r][c]) {
            printf("This card is already open. Please select a closed card.\n");
        } else {
            *row = r;
            *col = c;
            printf("You selected: %s\n", get_card_name(table[r][c]));
            return 0;
        }
    } while (1);
    
    return -1;
}

int get_card_value(int card_value) {
    int rank = get_card_rank(card_value);
    if (rank >= 2 && rank <= 10) {
        return rank;
    } else if (rank == 1) { // Ace
        return 1;
    } else { // Jack, Queen, King
        return 10;
    }
}

int get_card_rank(int card_value) {
    // Get the rank (1-13) from the card enum value
    if (card_value <= 13) return card_value; // Spades
    else if (card_value <= 26) return card_value - 13; // Diamonds
    else if (card_value <= 39) return card_value - 26; // Clubs
    else return card_value - 39; // Hearts
}