#include <stdio.h>
#include<stdlib.h>

int board[8][8];
int *board_future[8][8]; // board[a][b][n]
int depth=3;

const int pawn_white=80;
const int rook_white=82;
const int knight_white=78;
const int bishop_white=66;
const int queen_white=81;
const int king_white=75;
const int pawn_black=112;
const int rook_black=114;
const int knight_black=110;
const int bishop_black=98;
const int queen_black=113;
const int king_black=107;
const int blank=48;

void initialize_board();
void print_board();
void initialize_future_board_arr();
void move_piece(int a, int b, int c, int d); //move (a,b) to (c,d)

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

void initialize_future_board_arr() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board_future[i][j] = (int*)calloc(depth, sizeof(int));
		}
	}
}

void print_board () {
	for (int j=7;j>=0;--j) {
		for (int i=0;i<8;++i) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void move_piece(int a, int b, int c, int d) {
	board[c][d]=board[a][b];
	board[a][b]=blank;
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
