#include <iostream>
using namespace std;

enum PieceType
{
	PieceTypeKing, PieceTypeQueen, PieceTypeRook, PieceTypePawn
};

enum class PieceTypeClass
{
	King, Queen, Rook, Pawn
};

//int main() {
//	PieceType myPiece;
//	PieceTypeClass myPieceClass = PieceTypeClass::King;
//	myPiece = PieceTypeRook;
//	cout << myPiece;
//}