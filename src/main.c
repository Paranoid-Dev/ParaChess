#include <stdio.h>
#include <stdlib.h>

int board[8][8];
long long int *board_future[8][8]; // board[a][b][n]
long long int *board_move[5]; // board_move[x][n]={prev_n abcd,n}
int depth=3;
long long int n=0;

//white : 66~85
const int pawn_white=80;
const int pawn_white_enpassant_capturable=69; //E
const int rook_white=82;
const int rook_white_uncastleable=85; //U
const int knight_white=78;
const int bishop_white=66;
const int queen_white=81;
const int king_white=75;
//black : 98 ~ 117
const int pawn_black=112;
const int pawn_black_enpassant_capturable=101; //e
const int rook_black=114;
const int rook_black_uncastleable=117; //u
const int knight_black=110;
const int bishop_black=98;
const int queen_black=113;
const int king_black=107;

const int blank=48;

void initialize_board();
void print_board();
void initialize_future_board_arr(int s);
void free_future_board_arr();
void move_piece(int a, int b, int c, int d); //move (a,b) to (c,d)
long long int get_next_moves(long long int prev_n); // n=-1 for first iter

void initialize_board() {
	board[0][0]=rook_white;
	board[1][0]=knight_white;
	board[2][0]=bishop_white;
	board[3][0]=queen_white;
	board[4][0]=king_white;
	board[5][0]=bishop_white;
	board[6][0]=knight_white;
	board[7][0]=rook_white;
	board[0][1]=pawn_white;
	board[1][1]=pawn_white;
	board[2][1]=pawn_white;
	board[3][1]=pawn_white;
	board[4][1]=pawn_white;
	board[5][1]=pawn_white;
	board[6][1]=pawn_white;
	board[7][1]=pawn_white;
	
	board[0][7]=rook_black;
	board[1][7]=knight_black;
	board[2][7]=bishop_black;
	board[3][7]=queen_black;
	board[4][7]=king_black;
	board[5][7]=bishop_black;
	board[6][7]=knight_black;
	board[7][7]=rook_black;
	board[0][6]=pawn_black;
	board[1][6]=pawn_black;
	board[2][6]=pawn_black;
	board[3][6]=pawn_black;
	board[4][6]=pawn_black;
	board[5][6]=pawn_black;
	board[6][6]=pawn_black;
	board[7][6]=pawn_black;
	
	for (int i=0;i<8;++i) {
		for (int j=2;j<6;++j) {
			board[i][j]=blank;
		}
	}
}

void initialize_future_board_arr(int s) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board_future[i][j] = (long long int*)calloc(s, sizeof(long long int));
		}
	}
	for (int i = 0; i < 5; i++) {
		board_move[i] = (long long int*)calloc(s, sizeof(long long int));
	}
	n=0;
}

void free_future_board_arr() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			free(board_future[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		free(board_move[i]);
	}
	n=0;
}

void print_board () {
	for (int j = 7; j >= 0; --j) {
		for (int i = 0; i < 8; ++i) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void move_piece(int a, int b, int c, int d) {
	board[c][d]=board[a][b];
	board[a][b]=blank;
}

long long int get_next_moves(long long int prev_n) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == pawn_white_enpassant_capturable) {
				board[i][j]=pawn_white;
			}
			if (board[i][j] == pawn_white) { //if white pawn
				if (board[i][j+1] == blank) { //go ahead 1 square
					board_future[i][j][n]=blank;
					if (j==2) {
						board_future[i][j+1][n]=pawn_white_enpassant_capturable;
					}
					else {
						board_future[i][j+1][n]=pawn_white;
					}
					board_move[0][n]=prev_n;
					board_move[1][n]=i;
					board_move[2][n]=j;
					board_move[3][n]=i;
					board_move[4][n]=j+1;
					n++;
				}
				if (board[i][j+1] == blank && board[i][j+2] == blank) { //go ahead 2 squares
					board_future[i][j][n]=blank;
					if (j==1) {
						board_future[i][j+2][n]=pawn_white_enpassant_capturable;
					}
					else {
						board_future[i][j+2][n]=pawn_white;
					}
					board_move[0][n]=prev_n;
					board_move[1][n]=i;
					board_move[2][n]=j;
					board_move[3][n]=i;
					board_move[4][n]=j+2;
					n++;
				}
				if (i > 0 && j < 7 && board[i-1][j+1] != blank && board[i-1][j+1] > 90) { //if can take left diagonally
					board_future[i][j][n]=blank;
					if (j==2) {
						board_future[i-1][j+1][n]=pawn_white_enpassant_capturable;
					}
					else {
						board_future[i-1][j+1][n]=pawn_white;
					}
					board_move[0][n]=prev_n;
					board_move[1][n]=i;
					board_move[2][n]=j;
					board_move[3][n]=i-1;
					board_move[4][n]=j+1;
					n++;
				}
				if (i < 7 && j < 7 && board[i+1][j+1] != blank && board[i+1][j+1] > 90) { //if can take right diagonally
					board_future[i][j][n]=blank;
					if (j==2) {
						board_future[i+1][j+1][n]=pawn_white_enpassant_capturable;
					}
					else {
						board_future[i+1][j+1][n]=pawn_white;
					}
					board_move[0][n]=prev_n;
					board_move[1][n]=i;
					board_move[2][n]=j;
					board_move[3][n]=i+1;
					board_move[4][n]=j+1;
					n++;
				}
				if (j == 4 && i > 0 && board[i-1][j] == pawn_black_enpassant_capturable) { //if can take left en passant
					board_future[i][j][n]=blank;
					board_future[i-1][j+1][n]=pawn_white;
					board_move[0][n]=prev_n;
					board_move[1][n]=i;
					board_move[2][n]=j;
					board_move[3][n]=i-1;
					board_move[4][n]=j+1;
					n++;
				}
				if (j == 4 && i < 7 && board[i+1][j] == pawn_black_enpassant_capturable) { //if can take right en passant
					board_future[i][j][n]=blank;
					board_future[i+1][j+1][n]=pawn_white;
					board_move[0][n]=prev_n;
					board_move[1][n]=i;
					board_move[2][n]=j;
					board_move[3][n]=i+1;
					board_move[4][n]=j+1;
					n++;
				}
			}
		}
	}
	return n;
}

int main() {
	initialize_board();
	print_board();
	int a_scan, b_scan, c_scan, d_scan;
	scanf("%d %d %d %d", &a_scan, &b_scan, &c_scan, &d_scan);
	move_piece(a_scan, b_scan, c_scan, d_scan);
	print_board();
	return 0;
}
