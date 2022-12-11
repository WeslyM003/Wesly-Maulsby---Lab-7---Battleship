#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;
string topBoard[rows][elements];
string bottomBoard[rows][elements];
string enemyBoard[rows][elements];

void createBoards()
{
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < elements; y++)
		{
			topBoard[x][y] = "~";
		}
	}

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < elements; y++)
		{
			bottomBoard[x][y] = "~";
		}
	}

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < elements; y++)
		{
			enemyBoard[x][y] = "~";
		}
	}
}

void showBoards()
{
	cout << endl << endl << "   1 2 3 4 5 6 7 8 9 10" << endl;
	for (int x = 1; x < rows + 1; x++)
	{
		if (x < 10)
		{
			cout << " " << x << " ";
		}
		else if (x == 10)
		{
			cout << x << " ";
		}


		for (int y = 0; y < elements; y++)
		{
			cout << topBoard[x - 1][y] << " ";
		}
		cout << endl;

	}


	cout << endl << endl << "   1 2 3 4 5 6 7 8 9 10" << endl;
	for (int x = 1; x < rows + 1; x++)
	{
		if (x < 10)
		{
			cout << " " << x << " ";
		}
		else if (x == 10)
		{
			cout << x << " ";
		}


		for (int y = 0; y < elements; y++)
		{
			cout << bottomBoard[x - 1][y] << " ";
		}
		cout << endl;
	}
}


void introduction()
{
	cout << "Welcome to Battleship, The classic sinking game made in C++.\nTo get started, why not show you the ropes.\nFirst up are your two boards, they will consist of a top and a bottom board, like this:\n";
	showBoards();
	cout << "\nThe top board is to show where you shoot, use it to keep track of where you have and haven't shot, and where you have missed or have hit!\n";
	cout << "The Bottom board is where you will see your ships, as well as see where your enemy has fired and where they have hit or missed.\n";
	cout << "The boards use symbols to designate Ships (#), water(~), hits (H) or misses (M)\n";
	cout << "You will start by placing your ships, you have 5 ships, a Carrier that takes 5 spaces, a Battleship that takes 4, a Cruizer and a Submarine that both take 3, and a Destroyer that takes 2 \n";
	cout << "Follow the directions to place each ship as they appear, after you place a ship the boards will update to show where your ships are.\n";
	cout << "Once the game starts, you will enter a coordinate each turn to fire, try to hit the enemy by guessing their location.";
	cout << "\nThe first person to sink all their enemies ships wins, Good Luck!\n";
}


void placeCarrier()
{	
	for (int l = 0; l == 0; l++)
	{
		int inX;
		int inY;
		int inD;


		cout << "Please enter the first X Coordinate of your Carrier: ";
		cin >> inX;
		if (inX < 1 || inX > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeCarrier();
			break;
		}

		cout << "Please enter the first Y Coordinate of your Carrier: ";
		cin >> inY;
		if (inY < 1 || inY > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeCarrier();
			break;
		}

		cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		cin >> inD;
		if (inD == 1 && inY < 5)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeCarrier();
			break;
		}
		else if (inD == 1 && inY >= 5)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 2][inX - 1] = "#";
			bottomBoard[inY - 3][inX - 1] = "#";
			bottomBoard[inY - 4][inX - 1] = "#";
			bottomBoard[inY - 5][inX - 1] = "#";
		}
		else if (inD == 2 && inY > 5)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeCarrier();
			break;
		}
		else if (inD == 2 && inY <= 5)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY][inX - 1] = "#";
			bottomBoard[inY + 1][inX - 1] = "#";
			bottomBoard[inY + 2][inX - 1] = "#";
			bottomBoard[inY + 3][inX - 1] = "#";
		}
		else if (inD == 3 && inX < 5)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeCarrier();
			break;
		}
		else if (inD == 3 && inX >= 5)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX - 2] = "#";
			bottomBoard[inY - 1][inX - 3] = "#";
			bottomBoard[inY - 1][inX - 4] = "#";
			bottomBoard[inY - 1][inX - 5] = "#";
		}
		else if (inD == 4 && inX > 5)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeCarrier();
			break;
		}
		else if (inD == 4 && inX <= 5)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX] = "#";
			bottomBoard[inY - 1][inX + 1] = "#";
			bottomBoard[inY - 1][inX + 2] = "#";
			bottomBoard[inY - 1][inX + 3] = "#";
		}
		else if (inD < 1 || inD > 4)
		{
			cout << "Invalid Input" << endl;
			placeCarrier();
			break;
		}


	}
}

void placeBattleship()
{
	for (int l = 0; l == 0; l++)
	{
		int inX;
		int inY;
		int inD;


		cout << "Please enter the first X Coordinate of your Battleship: ";
		cin >> inX;
		if (inX < 1 || inX > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeBattleship();
			break;
		}

		cout << "Please enter the first Y Coordinate of your Battleship: ";
		cin >> inY;
		if (inY < 1 || inY > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeBattleship();
			break;
		}

		cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		cin >> inD;
		if (inD == 1 && inY < 4)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeBattleship();
			break;
		}
		else if (inD == 1 && inY >= 4)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 2][inX - 1] = "#";
			bottomBoard[inY - 3][inX - 1] = "#";
			bottomBoard[inY - 4][inX - 1] = "#";

		}
		else if (inD == 2 && inY > 7)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeBattleship();
			break;
		}
		else if (inD == 2 && inY <= 7)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY][inX - 1] = "#";
			bottomBoard[inY + 1][inX - 1] = "#";
			bottomBoard[inY + 2][inX - 1] = "#";

		}
		else if (inD == 3 && inX < 4)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeBattleship();
			break;
		}
		else if (inD == 3 && inX >= 4)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX - 2] = "#";
			bottomBoard[inY - 1][inX - 3] = "#";
			bottomBoard[inY - 1][inX - 4] = "#";

		}
		else if (inD == 4 && inX > 7)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeBattleship();
			break;
		}
		else if (inD == 4 && inX <= 7)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX] = "#";
			bottomBoard[inY - 1][inX + 1] = "#";
			bottomBoard[inY - 1][inX + 2] = "#";

		}
		else if (inD < 1 || inD > 4)
		{
			cout << "Invalid Input" << endl;
			placeBattleship();
			break;
		}


	}
}

void placeCruizer()
{
	for (int l = 0; l == 0; l++)
	{
		int inX;
		int inY;
		int inD;


		cout << "Please enter the first X Coordinate of your Cruizer: ";
		cin >> inX;
		if (inX < 1 || inX > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeCruizer();
			break;
		}

		cout << "Please enter the first Y Coordinate of your Cruizer: ";
		cin >> inY;
		if (inY < 1 || inY > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeCruizer();
			break;
		}

		cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		cin >> inD;
		if (inD == 1 && inY < 3)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeCruizer();
			break;
		}
		else if (inD == 1 && inY >= 3)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 2][inX - 1] = "#";
			bottomBoard[inY - 3][inX - 1] = "#";

		}
		else if (inD == 2 && inY > 8)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeCruizer();
			break;
		}
		else if (inD == 2 && inY <= 8)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY][inX - 1] = "#";
			bottomBoard[inY + 1][inX - 1] = "#";

		}
		else if (inD == 3 && inX < 3)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeCruizer();
			break;
		}
		else if (inD == 3 && inX >= 3)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX - 2] = "#";
			bottomBoard[inY - 1][inX - 3] = "#";

		}
		else if (inD == 4 && inX > 8)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeCruizer();
			break;
		}
		else if (inD == 4 && inX <= 8)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX] = "#";
			bottomBoard[inY - 1][inX + 1] = "#";

		}
		else if (inD < 1 || inD > 4)
		{
			cout << "Invalid Input" << endl;
			placeCruizer();
			break;
		}


	}
}

void placeSubmarine()
{
	for (int l = 0; l == 0; l++)
	{
		int inX;
		int inY;
		int inD;


		cout << "Please enter the first X Coordinate of your Submarine: ";
		cin >> inX;
		if (inX < 1 || inX > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeSubmarine();
			break;
		}

		cout << "Please enter the first Y Coordinate of your Submarine: ";
		cin >> inY;
		if (inY < 1 || inY > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeSubmarine();
			break;
		}

		cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		cin >> inD;
		if (inD == 1 && inY < 3)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeSubmarine();
			break;
		}
		else if (inD == 1 && inY >= 3)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 2][inX - 1] = "#";
			bottomBoard[inY - 3][inX - 1] = "#";

		}
		else if (inD == 2 && inY > 8)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeSubmarine();
			break;
		}
		else if (inD == 2 && inY <= 8)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY][inX - 1] = "#";
			bottomBoard[inY + 1][inX - 1] = "#";

		}
		else if (inD == 3 && inX < 3)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeSubmarine();
			break;
		}
		else if (inD == 3 && inX >= 3)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX - 2] = "#";
			bottomBoard[inY - 1][inX - 3] = "#";

		}
		else if (inD == 4 && inX > 8)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeSubmarine();
			break;
		}
		else if (inD == 4 && inX <= 8)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX] = "#";
			bottomBoard[inY - 1][inX + 1] = "#";

		}
		else if (inD < 1 || inD > 4)
		{
			cout << "Invalid Input" << endl;
			placeSubmarine();
			break;
		}


	}
}

void placeDestroyer()
{
	for (int l = 0; l == 0; l++)
	{
		int inX;
		int inY;
		int inD;


		cout << "Please enter the first X Coordinate of your Destroyer: ";
		cin >> inX;
		if (inX < 1 || inX > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeDestroyer();
			break;
		}

		cout << "Please enter the first Y Coordinate of your Destroyer: ";
		cin >> inY;
		if (inY < 1 || inY > 10)
		{
			cout << "Invalid Coordinate" << endl;
			placeDestroyer();
			break;
		}

		cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		cin >> inD;
		if (inD == 1 && inY < 2)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeDestroyer();
			break;
		}
		else if (inD == 1 && inY >= 2)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 2][inX - 1] = "#";


		}
		else if (inD == 2 && inY > 9)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeDestroyer();
			break;
		}
		else if (inD == 2 && inY <= 9)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY][inX - 1] = "#";


		}
		else if (inD == 3 && inX < 2)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeDestroyer();
			break;
		}
		else if (inD == 3 && inX >= 2)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX - 2] = "#";


		}
		else if (inD == 4 && inX > 9)
		{
			cout << "Cannot place ship out of bounds" << endl;
			placeDestroyer();
			break;
		}
		else if (inD == 4 && inX <= 9)
		{
			bottomBoard[inY - 1][inX - 1] = "#";
			bottomBoard[inY - 1][inX] = "#";


		}
		else if (inD < 1 || inD > 4)
		{
			cout << "Invalid Input" << endl;
			placeDestroyer();
			break;
		}


	}
}


int main()
{

	createBoards();
	introduction();

	placeCarrier();
	showBoards();
	placeBattleship();
	showBoards();
	placeCruizer();
	showBoards();
	placeSubmarine();
	showBoards();
	placeDestroyer();
	showBoards();
	return 0;
}
