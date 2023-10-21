#include <stdlib.h>

#define BOARDSIZE 3


void board_print(char board[BOARDSIZE][BOARDSIZE]);
int iscorrect(char cha[2]);
char win_check(char board[BOARDSIZE][BOARDSIZE]);
char row_check(int column, char line[BOARDSIZE][BOARDSIZE]);
char column_check(int row, char line[BOARDSIZE][BOARDSIZE]);
char diagonal_check(char line[BOARDSIZE][BOARDSIZE]);
char inverse_diagonal_check(char line[BOARDSIZE][BOARDSIZE]);

int main(int argc, char *argv[])
{
    char board[BOARDSIZE][BOARDSIZE];

    short count = 1;
    char timmy;
    
    /* main loop */
    while (board)
    {
        /* if (count % 2 == 0) */
        /* { */
        /*     timmy = 'O'; */
        /* } */
        /* else if (count % 2 != 0) */
        /* { */
        /*     timmy = 'X'; */
        /* } */

        timmy = ((count % 2) == 0) ? 'O' : 'X';

        printf("It is %c's turn\n",timmy);
        
        char* input = malloc(sizeof(char[2]));
        board_print(board);


        while (board)
        {


            scanf("%s",input);


            /* printf("%i\n",strlen(input)); */
            input[0] -= 48;
            input[1] -= 48;
            /* printf("%i\n",strlen(input)); */

            int iscor = iscorrect(input);

            /* printf("%i %i %i\n",input[0],input[1],iscor); */

            if (iscor == 0 && board[input[0]-1][input[1]-1] == NULL)
            {
                break;
            }
        }

        board[input[0]-1][input[1]-1] = timmy;
        free(input);

        if (win_check(board))
        {
            board_print(board);
            break;
        }


        count++;

        if ((BOARDSIZE * BOARDSIZE) + 1== count)
        {
            board_print(board);
            printf("Tie!\n");   
            return 0;
        }
    }

    printf("Winner is %c\n",timmy);

    return 0;
}


void board_print(char board[BOARDSIZE][BOARDSIZE])
{
    for (int column = 0; column < BOARDSIZE; column++)
    {
        for (int row = 0; row < BOARDSIZE; row++)
        {
            if (board[column][row] == NULL) {
                printf(" |");
            }
            else {
                printf("%c|", board[column][row]);
            }
        }
        printf("\n");
        for (int row = 0; row < BOARDSIZE; row++)
        {
            printf("-+");
        }
        printf("\n");
    }
    printf("Input your move: <x><y>\n");
}

int iscorrect(char cha[2])
{

    /* printf("iscor %i %i\n",cha[0],cha[1]); */
    if (strlen(cha) != 2)
    {
        /* printf("%i\n",strlen(cha)); */
        return 1;
    }

    /* I dont think im gonna be making 3d ticktack toe */
    else if (cha[0] < 1 || cha[0] > BOARDSIZE)
    {
        return 2;
    }
    else if (cha[1] < 1 || cha[1] > BOARDSIZE)
    {
        return 3;
    }

    return 0;
}

char win_check(char board[BOARDSIZE][BOARDSIZE])
{
    for(int column = 0; column < BOARDSIZE; column++)
    {
        char chard = row_check(column, board);
        if (chard)
        {
            return chard;
        }
    }

    for(int row = 0; row < BOARDSIZE; row++)
    {
        char chard = column_check(row, board);
        if (chard)
        {
            return chard;
        }
    }


    if (diagonal_check(board) || inverse_diagonal_check(board)) 
    {
        return 'D';
    }

    return '\0';
}

char row_check(int column, char line[BOARDSIZE][BOARDSIZE])
{
    char bogos = line[column][0];

    if (bogos == NULL)
    {
        return '\0';
    }

    for(int index = 1; index < BOARDSIZE; index++)
    {
        if (line[column][index] != bogos)
        {
            return '\0';
        }
    }
    return bogos;
}


char column_check(int row, char line[BOARDSIZE][BOARDSIZE])
{
    char bogos = line[0][row];

    if (bogos == NULL)
    {
        return '\0';
    }

    for(int index = 1; index < BOARDSIZE; index++)
    {
        if (line[index][row] != bogos)
        {
            return '\0';
        }
    }
    return bogos;
}

char diagonal_check(char line[BOARDSIZE][BOARDSIZE])
{
    char bogos = line[0][0];

    if (bogos == NULL)
    {
        return '\0';
    }

    for(int index = 1; index < BOARDSIZE; index++)
    {
        if (line[index][index] != bogos)
        {
            return '\0';
        }
    }
    return bogos;
}

char inverse_diagonal_check(char line[BOARDSIZE][BOARDSIZE])
{
    char bogos = line[BOARDSIZE-1][0];

    if (bogos == NULL)
    {
        return '\0';
    }

    for(int index = 1; index < BOARDSIZE; index++)
    {
        /* printf("test: %i %i, %c\n",BOARDSIZE-index-1,index,line[BOARDSIZE-index-1][index]); */
        if (line[BOARDSIZE-index-1][index] != bogos)
        {
            /* printf("fail: %i %i, %c\n",BOARDSIZE-index-1,index,line[BOARDSIZE-index-1][index]); */
            return '\0';
        }
    }
    return bogos;
}
