/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, start)
{
	TicTacToeBoard B;
	for(int i=0; i<BOARDSIZE; i++)
    	   for(int j=0; j<BOARDSIZE; j++)
	      EXPECT_EQ(Blank, B.getPiece(i,j));
}

TEST(TicTacToeBoardTest, firstTurn)
{
	TicTacToeBoard B;
	B.placePiece(1,1);
	ASSERT_EQ(X, B.getPiece(1,1));

        B.placePiece(2,2);
        ASSERT_EQ(O, B.getPiece(2,2));
}

TEST(TicTacToeBoardTest, bounds)
{
	TicTacToeBoard B;
	ASSERT_EQ(Invalid, B.getPiece(4,4));

        ASSERT_EQ(Invalid, B.getPiece(-1,-1));
}

TEST(TicTacToeBoardTest, quickGame)
{
	TicTacToeBoard B;
	B.placePiece(0,0);
	B.placePiece(1,0);
 
        ASSERT_EQ(Invalid, B.getWinner());

	B.placePiece(0,1);
	B.placePiece(0,0);
	B.placePiece(0,2);
        ASSERT_EQ(X, B.getPiece(0,0));
}

TEST(TicTacToeBoardTest, full)
{
        TicTacToeBoard B;
	B.placePiece(0,0);
	B.placePiece(0,1);
	B.placePiece(0,2);
	B.placePiece(1,0);
	B.placePiece(1,1);
	B.placePiece(1,2);
	B.placePiece(2,1);
	B.placePiece(2,2);
	B.placePiece(2,0);
        ASSERT_EQ(Blank, B.getWinner());
}

TEST(TicTacToeBoardTest, over)
{
	TicTacToeBoard B;
        B.placePiece(0,0);
        B.placePiece(0,0);
	ASSERT_EQ(X, B.getPiece(0,0));
}

TEST(TicTacToeBoardTest, row)
{
	TicTacToeBoard B;
        B.placePiece(7,0);
        B.placePiece(0,7);
	B.placePiece(7,7);

}

 /*
 BUG: Switched the OR's for AND's in this for loop, normally wouldn't allow and of these things when placing
 a pice but will allow with bug if one holds true. Note it breaks when trying to get the pice.
 */

TEST(TicTacToeBoardTest, brok)
{
        TicTacToeBoard B;
        B.placePiece(0,0);
        ASSERT_EQ(X, B.getPiece(0,0));
        B.placePiece(0,7);
	ASSERT_EQ(X, B.getPiece(0,7));
        B.placePiece(0,0);
	ASSERT_EQ(X, B.getPiece(0,0));
        B.placePiece(0,1);
	ASSERT_EQ(X, B.getPiece(0,1));
}
