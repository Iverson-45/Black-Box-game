#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <stack>

using namespace std;
int poczatek();
void WyborPoziomu(int);
void PlanszaLatwy();
void PlanszaSredni();
void PlanszaTrudny();
void Przyciski(char, int&, int&, int&, int&, int[], int[]);
char przycisk;


int atomX[8];
int atomY[8];
unsigned char plansza[12][12];
int LiczbaAtomow = 0;


stack<pair<int, int>> zaznaczoneUndo;
stack<pair<int, int>> zaznaczoneRedo;


int main()
{

	WyborPoziomu(poczatek());

	return 0;
}


int poczatek()
{
	cout << ",-----.  ,--.     ,---.   ,-----.,--. ,--.    ,-----.   ,-----.,--.   ,--." << endl;
	cout << "|  |) /_ |  |    /  O  \\ '  .--./|  .'   /    |  |) /_ '  .-.  '\  `.'  /  " << endl;
	cout << "|  .-.  \\|  |   |  .-.  ||  |    |  .   '     |  .-.  \\|  | |  | .'    \\   " << endl;
	cout << "|  '--' /|  '--.|  | |  |'  '--'\\|  |\\   \\    |  '--' /'  '-'  '/  .'.  \\  " << endl;
	cout << "`------' `-----'`--' `--' `-----'`--' '--'    `------'  `-----''--'   '--' " << endl;
	cout << "Dane autora:" << endl;
	cout << "imie: Jakub | Nazwisko: Litwin | Nr albumu: 198355" << endl;
	cout << "Witaj w grze Black Box!" << endl;
	cout << "wybierz Poziom Trudnosci (wpisz liczbe 1-3)" << endl;
	cout << "___________________________________________" << endl << "" << endl;
	cout << "1. latwy" << endl << "" << endl << "2. sredni" << endl << "" << endl << "3. trudny" << endl << "" << endl;
	int PoziomTrudnosci;
	cin >> PoziomTrudnosci;
	cout << endl;
	return PoziomTrudnosci;
}


void PlanszaLatwy()
{
	LiczbaAtomow = 3;
	bool tab[12][12] = { false };
	int pozycjaX = 6;
	int pozycjaY = 6;
	int granica = 6;
	int atomX[8]{ 0 };
	int atomY[8]{ 0 };


	srand(time(NULL));


	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i == 0 || i == 6 || j == 0 || j == 6)
			{
				plansza[i][j] = 254;
			}
			else
			{
				plansza[i][j] = 249;
			}
		}
	}

	for (int i = 0; i < LiczbaAtomow; i++)
	{
		do
		{
			atomX[i] = rand() % 5 + 1;
			atomY[i] = rand() % 5 + 1;
		} while (tab[atomY[i]][atomX[i]]);

		tab[atomY[i]][atomX[i]] = true;

		plansza[atomY[i]][atomX[i]];
		


	}

	while (true)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == pozycjaY && j == pozycjaX)
				{
					cout << 'P' << ' ';
				}
				else
				{
					cout << plansza[i][j] << ' ';
				}
			}
			cout << endl;
		}
		cout << "Sa 3 ukryte atomy." << endl;

		if (przycisk == 'p' || przycisk == 'P')
		{
			
				cout << "Koniec gry. Gra sie wylaczy za 10 sekund. Dziekuje :)" << endl;
				this_thread::sleep_for(chrono::seconds(10));
				exit(0);
			
		}

		cin.get(przycisk);

		Przyciski(przycisk, pozycjaX, pozycjaY, LiczbaAtomow, granica, atomX, atomY);
	}
}


void PlanszaSredni()
{
	LiczbaAtomow = 5;
	bool tab[12][12] = { false };
	int pozycjaX = 9;
	int pozycjaY = 9;
	int granica = 9;
	int atomX[8]{ 0 };
	int atomY[8]{ 0 };


	srand(time(NULL));


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 || i == 9 || j == 0 || j == 9)
			{
				plansza[i][j] = 254;
			}
			else
			{
				plansza[i][j] = 249;
			}
		}
	}

	for (int i = 0; i < LiczbaAtomow; i++)
	{
		do
		{
			atomX[i] = rand() % 8 + 1;
			atomY[i] = rand() % 8 + 1;
		} while (tab[atomY[i]][atomX[i]]);

		tab[atomY[i]][atomX[i]] = true;

		plansza[atomY[i]][atomX[i]];
	}

	while (true)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == pozycjaY && j == pozycjaX)
				{
					cout << 'P' << ' ';
				}
				else
				{
					cout << plansza[i][j] << ' ';
				}
			}
			cout << endl;
		}
		cout << "jest 5 ukrytych atomow." << endl;

		if (przycisk == 'p' || przycisk == 'P')
		{
		
				cout << "Koniec gry. Gra sie wylaczy za 10 sekund. Dziekuje :)" << endl;
				this_thread::sleep_for(chrono::seconds(10));
				exit(0);
			
		}

		cin.get(przycisk);

		Przyciski(przycisk, pozycjaX, pozycjaY, LiczbaAtomow, granica, atomX, atomY);
	}
}


void PlanszaTrudny()
{
	LiczbaAtomow = 8;
	bool tab[12][12] = { false };
	int pozycjaX = 11;
	int pozycjaY = 11;
	int atomX[8]{ 0 };
	int atomY[8]{ 0 };
	int granica = 11;
	

	srand(time(NULL));


	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i == 0 || i == 11 || j == 0 || j == 11)
			{
				plansza[i][j] = 254;
			}
			else
			{
				plansza[i][j] = 249;
			}
		}
	}

	for (int i = 0; i < LiczbaAtomow; i++)
	{
		do
		{
			atomX[i] = rand() % 10 + 1;
			atomY[i] = rand() % 10 + 1;
		} while (tab[atomY[i]][atomX[i]]);

		tab[atomY[i]][atomX[i]] = true;

		plansza[atomY[i]][atomX[i]];
	}

	while (true)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (i == pozycjaY && j == pozycjaX)
				{
					cout << 'P' << ' ';
				}
				else
				{
					cout << plansza[i][j] << ' ';
				}
			}
			cout << endl;
		}
		cout << "jest 8 ukrytych atomow." << endl;

		if (przycisk == 'p' || przycisk == 'P')
		{
			
				cout << "Koniec gry. Gra sie wylaczy za 10 sekund. Dziekuje :)" << endl;
				this_thread::sleep_for(chrono::seconds(10));
				exit(0);
			
		}

		cin.get(przycisk);

		Przyciski(przycisk, pozycjaX, pozycjaY, LiczbaAtomow, granica, atomX, atomY);
	}
}


void WyborPoziomu(int PoziomTrudnosci)
{
	switch (PoziomTrudnosci)
	{
	case 1:
		system("cls");
		PlanszaLatwy();
		break;

	case 2:
		system("cls");
		PlanszaSredni();
		break;

	case 3:
		system("cls");
		PlanszaTrudny();
		break;

	default:
		system("cls");
		cout << endl << "nie ma takiego wyboru !!!" << endl <<endl;
		main();
		break;
	}
}


void Przyciski(char przycisk, int& pozycjaX, int& pozycjaY, int& LiczbaAtomow, int& granica, int atomY[], int atomX[])
{
	static int LiczbaZaznaczenS = 0;
	static int LiczbaStrzalow = 49;
	static int LiczbaZaznaczenO = 0;
	static int punkty = 0;
	bool promien = true;
	int promienX = 0;
	int promienY = 0;
	int kierunek = 0;


	zaznaczoneUndo.push(make_pair(pozycjaX, pozycjaY));


	switch (przycisk)
	{
	case 'q':
	case 'Q':
		system("cls");
		LiczbaZaznaczenS = 0;
		LiczbaStrzalow = 49;
		LiczbaZaznaczenO = 0;
		main();
		break;
		
	case 'W':
	case 'w':
		if (pozycjaY > 0)
			pozycjaY--;
		break;

	case 'A':
	case 'a':
		if (pozycjaX > 0)
			pozycjaX--;
		break;

	case 'S':
	case 's':
		if (pozycjaY < granica)
			pozycjaY++;
		break;

	case 'D':
	case 'd':
		if (pozycjaX < granica)
			pozycjaX++;
		break;

	case 'o':
	case 'O':

		if (plansza[pozycjaY][pozycjaX] != 'o')
		{
			if (pozycjaX > 0 && pozycjaX < granica && pozycjaY > 0 && pozycjaY < granica)
			{
				if (LiczbaZaznaczenO < LiczbaAtomow)
				{
					plansza[pozycjaY][pozycjaX] = 'o';
					LiczbaZaznaczenO++;
				}
			}
		}
		break;

	case 'h':
	case 'H':



		for (int i = 0; i < LiczbaAtomow; i++)
		{
				plansza[atomY[i]][atomX[i]] = 'X';
		}

		system("cls");

		for (int i = 0; i <= granica; i++)
		{
			for (int j = 0; j <= granica; j++)
			{
				if (i == pozycjaY && j == pozycjaX)
				{
					cout << 'P' << ' ';
				}
				else
				{
					cout << plansza[i][j] << ' ';
				}
			}
			cout << endl;
		}

		this_thread::sleep_for(chrono::milliseconds(500));

		for (int i = 0; i < LiczbaAtomow; i++)
		{
			plansza[atomY[i]][atomX[i]] = 249;
		}

		break;

	case ' ':

		if (plansza[pozycjaY][pozycjaX] != LiczbaStrzalow)
		{
			if (((pozycjaX == 0) && (pozycjaY != 0 && pozycjaY != granica)) ||
				((pozycjaX == granica) && (granica > pozycjaY > 0 && pozycjaY != granica)) ||
				((pozycjaY == 0) && (granica > pozycjaX > 0 && pozycjaX != granica)) ||
				((pozycjaY == granica) && (granica > pozycjaX > 0 && pozycjaX != granica)))
			{
				if (!((pozycjaX == 0 && pozycjaY == 0) ||
					(pozycjaX == 0 && pozycjaY == granica) ||
					(pozycjaX == granica && pozycjaY == 0) ||
					(pozycjaX == granica && pozycjaY == granica)))
				{
					if (LiczbaZaznaczenS < 10)
					{
						LiczbaZaznaczenS++;

						promienX = pozycjaX;
						promienY = pozycjaY;

						while (promien)
						{
							if (promienX == 0 || kierunek == 1)
							{
								kierunek = 1;

								promienX++;
								if (promienX == granica)
								{
									promien = false;
								}


								plansza[promienY][promienX];

							}
							else if (promienX == granica || kierunek == 2)
							{
								kierunek = 2;

								promienX--;

								if (promienX == 0)
								{
									promien = false;
								}
								plansza[promienY][promienX];

							}
							else if (promienY == 0 || kierunek == 3)
							{
								kierunek = 3;

								promienY++;


								if (promienY == granica)
								{
									promien = false;
								}
								plansza[promienY][promienX];


							}
							else if (promienY == granica || kierunek == 4)
							{
								kierunek = 4;

								promienY--;

								if (promienY == 0)
								{
									promien = false;
								}
								plansza[promienY][promienX];


							}
							for (int i = 0; i < LiczbaAtomow; i++)
							{
								

								if (promienY == atomY[i] + 1 && promienX == atomX[i] - 1) 
								{
									if (kierunek == 4)
									{
										kierunek = 2;
										break;
											plansza[promienY][promienX];

									}
									else
									{
										kierunek = 3;
										break;
											plansza[promienY][promienX];
									}
								}

								if (promienY == atomY[i] + 1 && promienX == atomX[i] + 1)
								{
									if (kierunek == 4)
									{
										kierunek = 1;
										break;
											plansza[promienY][promienX];	
									}
									else
									{
										kierunek = 3;
										break;
											plansza[promienY][promienX];
									}
								}
								if (promienY == atomY[i] - 1 && promienX == atomX[i] - 1)
								{
									if (kierunek == 3)
									{
										kierunek = 2;
										break;
											plansza[promienY][promienX];
									}
									else
									{
										kierunek = 4;
										break;
											plansza[promienY][promienX];
									}

								}
								if (promienY == atomY[i] - 1 && promienX == atomX[i] + 1) 
								{
									if (kierunek == 3)
									{
										kierunek = 1;
										break;
											plansza[promienY][promienX];
									}
									else
									{
										kierunek = 4;
										break;
											plansza[promienY][promienX];
									}
								}
								else if (promienX == atomX[i] && promienY == atomY[i])
								{
									
									plansza[pozycjaY][pozycjaX] = 'H';
									LiczbaStrzalow++;
									promien = false;
									break;
								}
								else if ((atomX[i] == 1 && pozycjaX == 0 && (pozycjaY == atomY[i] - 1 || pozycjaY == atomY[i] + 1)) ||
									(atomX[i] == granica - 1 && pozycjaX == granica && (pozycjaY == atomY[i] - 1 || pozycjaY == atomY[i] + 1)) ||
									(atomY[i] == granica - 1 && pozycjaY == granica && (pozycjaX == atomX[i] - 1 || pozycjaX == atomX[i] + 1)) ||
									(atomY[i] == 1 && pozycjaY == 0 && (pozycjaX == atomX[i] - 1 || pozycjaX == atomX[i] + 1)))
								{
									plansza[pozycjaY][pozycjaX] = 'R';
									LiczbaStrzalow++;
									promien = false;
									break;
								}
							}
						}
						if (promienY == 0)
						{
							plansza[pozycjaY][pozycjaX] = LiczbaStrzalow++;
							plansza[promienY][promienX] = LiczbaStrzalow-1;
						}
						else if (promienY == granica)
						{
							plansza[pozycjaY][pozycjaX] = LiczbaStrzalow++;
							plansza[promienY][promienX] = LiczbaStrzalow - 1;
						}
						else if (promienX == 0)
						{
							plansza[pozycjaY][pozycjaX] = LiczbaStrzalow++;
							plansza[promienY][promienX] = LiczbaStrzalow - 1;
						}
						else if (promienX == granica)
						{
							plansza[pozycjaY][pozycjaX] = LiczbaStrzalow++;
							plansza[promienY][promienX] = LiczbaStrzalow - 1;
						}
					}
				}
			}
		}
		break;

	case 'p':

		for (int i = 0; i < LiczbaAtomow; i++)
		{
			plansza[atomY[i]][atomX[i]] = 'X';
		}

		break;

	case 'k':
	case 'K':
		
		system("cls");

		for (int i = 0; i < LiczbaAtomow; i++)
		{
			if ('o' == plansza[atomY[i]][atomX[i]])
			{
				plansza[atomY[i]][atomX[i]] = 'O';
				punkty++;
			}
			else
			{
				plansza[atomY[i]][atomX[i]] = 'a';
			}
		}

		for (int i = 0; i <= granica; i++)
		{
			for (int j = 0; j <= granica; j++)
			{
					cout << plansza[i][j] << ' ';
			}
			cout << endl;
		}

		cout << "liczba punktow: " << (punkty)*10 << endl;
		cout << "Koniec gry. Gra sie wylaczy za 10 sekund. Dziekuje :)" << endl;
	        this_thread::sleep_for(chrono::seconds(10));
		exit(0);
		break;

	case 'u':
	case 'U':
		if (plansza[pozycjaY][pozycjaX] == 'o')
		{
			if (!zaznaczoneUndo.empty())
			{
				zaznaczoneRedo.push(zaznaczoneUndo.top());
				zaznaczoneUndo.pop();
				plansza[zaznaczoneRedo.top().second][zaznaczoneRedo.top().first] = 249;
			}
			LiczbaZaznaczenO--;
		}
		
		break;

	case 'r':
	case 'R':
		if (LiczbaZaznaczenO < LiczbaAtomow)
		{
			if (!zaznaczoneRedo.empty())
			{
				zaznaczoneUndo.push(zaznaczoneRedo.top());
				zaznaczoneRedo.pop();
				plansza[zaznaczoneUndo.top().second][zaznaczoneUndo.top().first] = 'o';
			}
			LiczbaZaznaczenO++;
		}
		
		break;
	}
	
	system("cls");
}
