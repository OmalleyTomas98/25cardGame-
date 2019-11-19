#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITES 4    //number suits = dcsh
#define NUM_CARDS  13   /* number of cards in each suite */

//functions used in program
void ShowCard(int card);
void ShowDeck(int deck[]);
void Shuffle(int deck[]);
void Sort(int deck[]);
void Swap(int deck[], int first, int second);
void TwoplayerGame(int deck[]);
void sixPLayerGame(int deck[]);

int main()
{
    //declared variables in main
    int deck[NUM_SUITES*NUM_CARDS];
    int userGame;
    int trump;

    printf("Press 2 if you'd like a two player game  or 6 for 6 player game \n");
    scanf("%d", &userGame);

    if (userGame == 2)
    {
    printf("n              Started 2 player Game !                    \n");
    /* Initialize random number generator */
    srand(time(NULL));
    printf("                 Shuffled Deck\n ");
    printf("=========================================================\n ");
    //calls and displays shuffle method
    Shuffle(deck);
    //calls and displays show Deck method
    ShowDeck(deck);
    printf("\n\n");
    printf("                  Full Deck\n ");
    printf("=========================================================\n ");
    //calls and displays sort function shows the deck from card 1 - 52 in suits
    Sort(deck);
    //when called displays entire deck
    ShowDeck(deck);
    printf("                   \n ");
    printf("=========================================================\n ");
    //calls and displays show two Player Method
    TwoplayerGame(deck);

        }
    // any thing pressed that isnt 2 the application will ternminate
    else if (userGame == 6)
    {
        sixPLayerGame( deck);
    }
    else if(userGame =! 6 || 2){
        printf("Exited");

    }
}
//show cardfunction gives card its suit , picture card
void ShowCard(int card)
{
    /* Print the suite first. hearts  are going to be the values 0-12, */
    /* Diamonds the values 13-25, Clubs the values 26-38 and Spades */
    /* the values 39-51. */
    switch (card / NUM_CARDS)
    {
        //allocates suits to the cards
        case 0:
            printf("H");
            break;
        case 1:
            printf("D");
            break;
        case 2:
            printf("C");
            break;
        case 3:
            printf("S");
            break;
    }
    /* Print the card face value. 0 through 8 will correspond */
    /* to 2 through 10, 9-12 will correspond to Jack-Ace */
    if ((card % NUM_CARDS) < 9)
    {
        printf("%d", (card % NUM_CARDS) + 2);
    }
    else
    {
        //adds remainder pictures to cards from 10 - onwards
        switch (card % NUM_CARDS)
        {
            case 9:
                printf("J");
                break;
            case 10:
                printf("Q");
                break;
            case 11:
                printf("K");
                break;
            case 12:
                printf("A");
                break;
        }
    }
}
//show deck function to display the entire deck
void ShowDeck(int deck[])
{
    int suite, card=0;

    for (suite = 0; suite < NUM_SUITES; suite++)
    {
        for (card = 0; card < NUM_CARDS; card++)
        {

            //use of showCard method to map the suits and pictures togther in the deck
            ShowCard(deck[suite*NUM_CARDS + card]);
            printf("\t");

        }
        printf("\n");
    }
}
//swap function used to shuffle the deck is called in shuffle method
void Swap(int deck[], int first, int second)
{
    int temp = deck[first];
    deck[first] = deck[second];
    deck[second] = temp;
}
//shuffle fuction used to shuffke deck
void Shuffle(int deck[])
{
    int card, choice;

    for (card = 0; card < (NUM_SUITES * NUM_CARDS); card++)
    {
        deck[card] = card;
    }

    for (card = (NUM_SUITES * NUM_CARDS) - 1; card > 1; card--)
    {
        choice = rand() % card;

        Swap(deck, card, choice);
    }
}

//creates deck and sorts teh cards from suit to -13 by 4 suits
void Sort(int deck[])
{
    int firstCard, card;

    for (firstCard = 0; firstCard < (NUM_CARDS * NUM_SUITES - 1); firstCard++)
    {
        for (card = firstCard + 1; card < (NUM_CARDS * NUM_SUITES); card++)
        {
            if (deck[card] < deck[firstCard])
            {
                Swap(deck, card, firstCard);
            }
        }
    }
}
//function called allows two players to enter game
void TwoplayerGame(int deck[]) {
    //declared variables
    int i = 0;
    int numberHolder;
    int userScore;
    int userAddPoints;
    int suite, card;
    int PLayer1cardGiven = 0;
    int PLayer2cardGiven=0;

    printf(" \n");
    printf("               Player 1 Hand \n");
    printf("                   \n ");
    printf("=========================================================\n ");
    printf("                  \n");

    //rand method defnintion to give random numbers
    srand(time(NULL));
    //creates the 5 cards in users hand
    for (i = 0; i < 5; i++)
    {
        int i = rand() % 52;
        //print user cards
        ShowCard(deck[i]);
        //stores users cards
        PLayer1cardGiven = deck[i];
        printf("\t");
        printf("CardGivenTEST =%d", PLayer1cardGiven);
        printf("\n");
    }
    printf(" \n");
    printf(" \n");
    printf("               Player 2 Hand \n");
    printf("                \n");
    printf("=========================================================\n ");
    printf("                \n");

    rand();
    //rand method defnintion to give random numbers
    srand(time(NULL));
    //creates the 5 cards in users hand
    for (i = 0; i < 5; i++)
    {
        int i = rand() % 50;
        ShowCard(deck[i]);
        //print user cards
        PLayer2cardGiven =deck[i] ;
        //stores users cards
        printf("\t");
        printf("CardGivenTEST =%d", PLayer2cardGiven);

        printf("\n");
    }
    printf("                \n");
    printf("=========================================================\n ");
    printf("                \n");
    printf("               the Trump Card  \n");
    srand(time(NULL));


        //Creates the deck trump card
        int trump = rand() % 50;
        ShowCard(deck[i]);

        printf("\n");
        printf("=========================================================\n ");

    printf("\n");
    int userChoice;
    printf("\n");
    printf("Please press either 1  2  3  4  5 : To the play the card in your hand  \n ");
    scanf("%d", &userChoice);

    while (userChoice < 6) {
        switch (userChoice)
        {
            case 1:
                printf(" You picked Card 1 %d= ", PLayer1cardGiven);

                break;
            case 2:
                printf(" You picked Card 2 %d= ", PLayer1cardGiven);
                break;
            case 3:
                printf(" You picked Card 3 %d= ", PLayer1cardGiven);
                break;
            case 4:
                printf(" You picked Card 4 %d= ", PLayer1cardGiven);
                break;
            case 5:
                printf(" You picked Card 5  %d=", PLayer1cardGiven);
                break;
        }
          scanf("%d", &userChoice);
    }
}
void sixPLayerGame(int deck[]) {
    //declared variables
    int i = 0;
    int numberHolder;
    int userScore;
    int userAddPoints;
    int suite, card;
    int PLayer1cardGiven = 0;
    int PLayer2cardGiven=0;

    printf(" \n");
    printf("               Player 1 Hand \n");
    printf("                   \n ");
    printf("=========================================================\n ");
    printf("                  \n");

    //rand method defnintion to give random numbers
    srand(time(NULL));
    //creates the 5 cards in users hand
    for (i = 0; i < 5; i++)
    {
        int i = rand() % 52;
        //print user cards
        ShowCard(deck[i]);
        //stores users cards
        PLayer1cardGiven = deck[i];
        printf("\t");
        printf("CardGivenTEST =%d", PLayer1cardGiven);
        printf("\n");
    }
    printf(" \n");
    printf(" \n");
    printf("               Player 2 Hand \n");
    printf("                \n");
    printf("=========================================================\n ");
    printf("                \n");

    rand();
    //rand method defnintion to give random numbers
    srand(time(NULL));
    //creates the 5 cards in users hand
    for (i = 0; i < 5; i++)
    {
        int i = rand() % 50;
        ShowCard(deck[i]);
        //print user cards
        PLayer2cardGiven =deck[i] ;
        //stores users cards
        printf("\t");
        printf("CardGivenTEST =%d", PLayer2cardGiven);

        printf("\n");
    }
    printf("                \n");
    printf("=========================================================\n ");
    printf("                \n");
    printf("               the Trump Card  \n");
    srand(time(NULL));


    //Creates the deck trump card
    int trump = rand() % 50;
    ShowCard(deck[i]);

    printf("\n");
    printf("=========================================================\n ");



    printf(" \n");
    printf("               Player 3 Hand \n");
    printf("                   \n ");
    printf("=========================================================\n ");
    printf("                  \n");

    //rand method defnintion to give random numbers
    srand(time(NULL));
    //creates the 5 cards in users hand
    for (i = 0; i < 5; i++)
    {
        int i = rand() % 52;
        //print user cards
        ShowCard(deck[i]);
        //stores users cards
        PLayer1cardGiven = deck[i];
        printf("\t");
        printf("CardGivenTEST =%d", PLayer1cardGiven);
        printf("\n");
    }
    printf(" \n");
    printf(" \n");
    printf("               Player 4 Hand \n");
    printf("                \n");
    printf("=========================================================\n ");
    printf("                \n");

    rand();
    //rand method defnintion to give random numbers
    srand(time(NULL));
    //creates the 5 cards in users hand
    for (i = 0; i < 5; i++)
    {
        int i = rand() % 50;
        ShowCard(deck[i]);
        //print user cards
        PLayer2cardGiven =deck[i] ;
        //stores users cards
        printf("\t");
        printf("CardGivenTEST =%d", PLayer2cardGiven);

        printf("\n");
    }
    printf("                \n");
    printf("=========================================================\n ");
    printf("                \n");
    srand(time(NULL));



    printf("\n");
    printf("=========================================================\n ");



    printf(" \n");
    printf("               Player 5 Hand \n");
    printf("                   \n ");
    printf("=========================================================\n ");
    printf("                  \n");

    //rand method defnintion to give random numbers
    srand(time(NULL));
    //creates the 5 cards in users hand
    for (i = 0; i < 5; i++)
    {
        int i = rand() % 52;
        //print user cards
        ShowCard(deck[i]);
        //stores users cards
        PLayer1cardGiven = deck[i];
        printf("\t");
        printf("CardGivenTEST =%d", PLayer1cardGiven);
        printf("\n");
    }
    printf(" \n");
    printf(" \n");
    printf("               Player 6 Hand \n");
    printf("                \n");
    printf("=========================================================\n ");
    printf("                \n");

    rand();
    //rand method defnintion to give random numbers
    srand(time(NULL));
    //creates the 5 cards in users hand
    for (i = 0; i < 5; i++)
    {
        int i = rand() % 50;
        ShowCard(deck[i]);
        //print user cards
        PLayer2cardGiven =deck[i] ;
        //stores users cards
        printf("\t");
        printf("CardGivenTEST =%d", PLayer2cardGiven);

        printf("\n");
    }
    printf("                \n");
    printf("=========================================================\n ");
    printf("                \n");
    printf("               the Trump Card  \n");
    srand(time(NULL));


    //Creates the deck trump card

    printf("\n");
    printf("=========================================================\n ");



    printf("\n");
    int userChoice;
    printf("\n");
    printf("Please press either 1  2  3  4  5 : To the play the card in your hand  \n ");
    scanf("%d", &userChoice);

    while (userChoice < 6) {
        switch (userChoice)
        {
            case 1:
                printf(" You picked Card 1 %d= ", PLayer1cardGiven);

                break;
            case 2:
                printf(" You picked Card 2 %d= ", PLayer1cardGiven);
                break;
            case 3:
                printf(" You picked Card 3 %d= ", PLayer1cardGiven);
                break;
            case 4:
                printf(" You picked Card 4 %d= ", PLayer1cardGiven);
                break;
            case 5:
                printf(" You picked Card 5  %d=", PLayer1cardGiven);
                break;
        }
        scanf("%d", &userChoice);
    }
}
