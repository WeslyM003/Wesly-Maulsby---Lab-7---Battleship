#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;
string topBoard[rows][elements];
string bottomBoard[rows][elements];

void createBoards()
{
	for(int x = 0; x < rows; x++)
	{
		for(int y = 0; y < elements; y++)
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
	for(int x = 1; x < rows + 1; x++)
	{
		if (x < 10)
		{
			cout << " " << x << " ";
		}
		else if(x == 10)
		{
			cout << x << " ";
		}


		for(int y = 0; y < elements; y++)
		{
			cout << bottomBoard[x - 1][y] << " ";
		}
		cout << endl;
	}
}

void placeCarrier()
{	
	int inX = 0;
	int inY = 0;
	int direction;

	cout << "Input the center x coordinate of your Carrier : ";
	cin >> inX;
	if (inX > 10 || inX <= 0)
	{
		cout << "Invalid Input" << endl;
		placeCarrier();
	}
	cout << "Input the center y coordinate of your Carrier: ";
	cin >> inY;
	if (inY > 10 || inY <= 0)
	{
		cout << "Invalid Input" << endl;
		placeCarrier();
	}
	
	cout << "Enter 1 for the ship to go horizontal or any other number for the ship to go vertical ";
	cin >> direction;

	if (direction == 1)
	{
		bottomBoard[inY - 1][inX - 1] = "#";
		bottomBoard[inY - 1][inX - 2] = "#";
		bottomBoard[inY - 1][inX + 1] = "#";
		bottomBoard[inY - 1][inX] = "#";
		bottomBoard[inY - 1][inX - 3] = "#";
	}
	else
	{
		bottomBoard[inY - 1][inX - 1] = "#";
		bottomBoard[inY][inX - 1] = "#";
		bottomBoard[inY + 1][inX - 1] = "#";
		bottomBoard[inY - 2][inX - 1] = "#";
		bottomBoard[inY - 3][inX - 1] = "#";
	}

}

	
	
int main()
{
	int inX;
	int inY;

	createBoards();
	showBoards();

	
	placeCarrier ();

	showBoards();
	return 0;
}
