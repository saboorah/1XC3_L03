#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ♔ ♕ ♖ ♗ ♘ ♙ 
/* ┌ └ ┐ ┘

├ ┤ ┬ ┴
 
─ │ ┼
 
 might need these...
 
 ╟ ╢ ╧ ╤
 
*/

// SHOW BOARD PRETTIER START
void showBoard (int board[8][8]) {

        printf("\n\n   0 1 2 3 4 5 6 7\n");
	printf("  ┌─┬─┬─┬─┬─┬─┬─┬─┐\n"); //added
//-	printf("╔══════════╗\n");

	for (int i = 0; i < 8; i++) {
//-		printf("║");
 
		printf("%d ", i);
		printf("│"); //added

		bool flag = true;   //added

		for (int j = 0; j < 8; j++) {

			//adding if statement
			if (!flag) {
				printf("│"); 
			}
			flag = false;

			if (board[i][j] == 0) {
				
				if ((i + j) % 2 == 0) {
					printf(" ");
				} else {
					printf("▒");
				}
			} else if (board[i][j] == 1) {
				printf("♔");
 			} else if (board[i][j] == 2) {
				printf("♕");
			} else if (board[i][j] == 3) {
				printf("♗");
			} else if (board[i][j] == 4) {
				printf("♘");
			} else if (board[i][j] == 5) {
				printf("♖");
			} else if (board[i][j] == 6) {
				printf("♙");
			}
			
			
		} //for j

	//added this
	printf("│\n") ;
	if (i < 7) {
		printf("  ├─┼─┼─┼─┼─┼─┼─┼─┤\n") ;
	}

//		printf("\n"); } //added }

//-	printf("║\n") ; 

	} //for i

	//after loops
	printf("  └─┴─┴─┴─┴─┴─┴─┴─┘\n");
//-	printf("╚══════════╝\n");
	
} //end of showboard func

// SHOW BOARD PRETTIER END

//- moving bool  on top of main -nO
//bool isValidMove (int x1, int x2, int y1, int y2, int board[8][8]) ;

//MOVEMENT CHECKS START

//bool memberOf (int *ValidMoves[2], int x, int y) ; 

bool isValidMove (char* input, int board[8][8]) {
	int start_y = input[0] - 48;
	int start_x = input[1] - 48;
	int end_y = input[3] - 48;
	int end_x = input[4] - 48;
	
	// out of bounds check
	if (start_x > 7 || start_x < 0) {
		return false;
	} else if (start_y > 7 || start_y < 0) {
		return false;
	} else if (end_x > 7 || end_x < 0) {
		return false;
	} else if (end_y > 7 || end_y < 0) {
		return false;
	}
	
	// piece move checks 
	int* validMoves[2];
	int xcheck = start_x;
	int ycheck = start_y;
	int piecesInWay = 0;
	switch (board[start_x][start_y]) {
		case 0: // moving a blank spot is never valid
			return false;
		case 1: // King
			break;
		case 2: // Queen
		//printf("Queen Selected\n");
			while (true) {
				xcheck += (start_x > end_x)? -1 : 1;
				ycheck += (start_y > end_y)? -1 : 1;
				if (xcheck < 0 || ycheck < 0 || xcheck > 7 || ycheck > 7) {
					break;
				}
				if (board[xcheck][ycheck] != 0) {
					piecesInWay += 1;
				} 
				if (piecesInWay == 2) {
					break;
				}
				if (xcheck == end_x && ycheck == end_y) {
					return true;
				}
			}
			xcheck = start_x;
			ycheck = start_y;
			piecesInWay = 0;		
			while (true) {
				//printf("Calculating Rook Movement at %d, %d\n", ycheck, xcheck);
				if (start_y == end_y) {
					//printf("Horzontal!\n");
					xcheck += (start_x > end_x)? -1 : 1;
				} else if (start_x == end_x) {
					//printf("Vertical!\n");
					ycheck += (start_y > end_y)? -1 : 1;
				} 
				//printf("Now checking %d, %d\n", ycheck, xcheck);
			
				if (xcheck < 0 || ycheck < 0 || xcheck > 7 || ycheck > 7) {
					//printf("Out of bounds!\n");
					break;
				}
				if (board[xcheck][ycheck] != 0) {
					//printf("Hit Piece: %d\n", board[xcheck][ycheck]);
					piecesInWay += 1;
				} 	
				if (piecesInWay == 2) {
					//printf("Hit Second Piece: %d\n", board[xcheck][ycheck]);
					break;
				}	
				if (xcheck == end_x && ycheck == end_y) {
					return true;
				}
			}	
			break;
		case 3 : // Bishop
			break;
		case 4 : // Knight
			break;
		case 5 : // Rook
			break;
		case 6 : // Pawn
			break;
 	}

} //added? 
	/*
	if (!memberOf(validMoves, end_x, end_y)) {
		return false;
	}
	*/

/*bool isValidMove (char* input, int board[8][8]) {
	// Add move validity checks some other time! Too lazy!! 

	return true;
}*/

void makeMove (char* input, int board[8][8]) {

	int start_x = input[0] - 48;
	int start_y = input[1] - 48;
	int end_x = input[3] - 48;
	int end_y = input[4] - 48;

	board[end_x][end_y] = board[start_x][start_y];
	board[start_x][start_y] = 0;

}

//MOVENT CHECKS ENDS


int main () {
	printf("Welcome to Terminal Chess!\n");
	printf("Initializing Board...\n")	;
	int board [8][8] = { {5, 4, 3, 1, 2, 3, 4, 5}
		           , {6, 6, 6, 6, 6, 6, 6, 6}
			   , {0, 0, 0, 0, 0, 0, 0, 0}
			   , {0, 0, 0, 0, 0, 0, 0, 0}
		           , {0, 0, 0, 0, 0, 0, 0, 0}
			   , {0, 0, 0, 0, 0, 0, 0, 0}
			   , {6, 6, 6, 6, 6, 6, 6, 6}
			   , {5, 4, 3, 2, 1, 3, 4, 5}

							} ;
  char buf[100];
  bool whitesMove = true;
	printf("Board Initialized!\n") ;

	//added showboard
//-	showBoard(board);


  printf("Enter `q` to quit at any time.\n");
  printf("Moves are entered as co-ordinate pairs, such as \"13-33\" \n");
  do {
    bool flag = false; 
    showBoard(board);
    do {
	if (flag) {
		printf("Move Invalid! Try again!\n");
	}
    	if (whitesMove) {
      		printf("White to move.\n");
    	} else {
      		printf("Black to move.\n");
    	}

    	printf("♔ >> ");
	scanf("%s", buf);
	flag = true;

    } while (!isValidMove(buf, board) && buf[0] != 'q' && buf[0] != 'Q');
    makeMove(buf, board);

    //added
    whitesMove = !whitesMove;

  } while (buf[0] != 'q' && buf[0] != 'Q') ;
    
	printf("Terminating...\n") ; 

} 

