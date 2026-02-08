#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int randomCard(void);

int main(void)
{
    srand((unsigned) time(NULL));

    randomCard();

    return 0;
}

/**
 * @brief Generates a random hand of unique playing cards via Rejection Sampling.
 *
 * Algorithm:
 * 1. Initializes a boolean matrix (in_hand) representing a 4x13 deck.
 * 2. Continuously generates random (suit, rank) coordinates.
 * 3. Checks if the card at those coordinates has already been selected.
 * 4. If not selected: marks it as true, decrements the counter, and prints it.
 * 5. If selected: discards the choice and retries (collision).
 *
 * @warning Potential Infinite Loop: If the user requests > 52 cards,
 * the loop will never terminate because unique cards are exhausted.
 *
 * @note Time Complexity is non-deterministic due to the random collision handling.
 * Performance degrades as 'num_cards' approaches 52.
 * @return 0 on success
 */
int randomCard(void)
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9',
                              't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};

    printf("Enter a number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand: ");
    while (num_cards > 0)
    {
        suit = rand() % NUM_SUITS; // picks a random suit
        rank = rand() % NUM_RANKS; // picks a random rank

        if (!in_hand[suit][rank])
        {
            num_cards--;
            printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");

    return 0;
}


