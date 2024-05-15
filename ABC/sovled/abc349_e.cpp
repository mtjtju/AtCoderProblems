// Problem: E - Weighted Tic-Tac-Toe
// Contest: AtCoder - AtCoder Beginner Contest 349
// URL: https://atcoder.jp/contests/abc349/tasks/abc349_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string.h>
using namespace std;

const int n = 3;
int as[n][n];
// deck: 0 empty, 1 taka, -1 aoki
bool validStep(int deck[n][n], int i, int j)
{
	return deck[i][j] == 0;
}

void coutDeck(int deck[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << deck[i][j] << ' ';
		cout << endl;
	}
	cout << "---------------" << endl;
}
bool checkTakaWin(int deck[n][n])
{
	long long taka = 0, aoki = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (deck[i][j] == 1)
				taka += as[i][j];
			else
				aoki += as[i][j];
	return taka > aoki;
}

bool TakaWinBy3(int deck[n][n])
{
	for (int i = 0; i < n; i++)
	{
		if (deck[i][0] == 1 && deck[i][1] == 1 && deck[i][2] == 1)
			return true;
		if (deck[0][i] == 1 && deck[1][i] == 1 && deck[2][i] == 1)
			return true;
	}
	if (deck[0][0] == 1 && deck[1][1] == 1 && deck[2][2] == 1)
		return true;
	if (deck[0][2] == 1 && deck[1][1] == 1 && deck[2][0] == 1)
		return true;
	return false;
}

bool dfsTakaWin(int deck[n][n], bool isTaka, int depth)
{
	//cout << depth << endl;
	//if (depth == n * n) coutDeck(deck);
	if (TakaWinBy3(deck)) return true;
	if (depth == n * n)
		return checkTakaWin(deck);

	bool res = true;
	if (isTaka)
	{
		res = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (validStep(deck, i, j))
				{
					deck[i][j] = 1;
					if (dfsTakaWin(deck, !isTaka, depth + 1))
					{
						res = true;deck[i][j] = 0;
						break;						
					}
					deck[i][j] = 0;
				}
	}
	else
	{
		res = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (validStep(deck, i, j))
				{
					deck[i][j] = -1;
					if (!dfsTakaWin(deck, !isTaka, depth + 1))
					{
						res = false;deck[i][j] = 0;
						break;				
					}
					deck[i][j] = 0;
				}
	}
	return res;
}

int main()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> as[i][j];
	int deck[n][n];
	memset(deck, 0, sizeof deck);
	
	if (dfsTakaWin(deck, true, 0))
		cout << "Takahashi" << endl;
	else
		cout << "Aoki" << endl;
}