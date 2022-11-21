#include <stdio.h>

int board[8][8];

int pawn_white=80;
int rook_white=82;
int knight_white=78;
int bishop_white=66;
int queen_white=81;
int king_white=75;
int pawn_black=112;
int rook_black=114;
int knight_black=110;
int bishop_black=98;
int queen_black=113;
int king_black=107;

void initialize_board();
void print_board();

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
			board[i][j]=48;
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

int main() {
	initialize_board();
	print_board();
	return 0;
}
