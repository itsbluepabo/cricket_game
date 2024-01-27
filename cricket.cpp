#include<iostream>
#include<cstdlib>
#include <ctime>
#include<limits>
#include<vector>
#include<string>
using namespace std;
class Player {
//#include<string>
public:
	Player();
	std :: string name;
	int id;
	int runScored;
	int ballsPlayed;
	int ballsBowlead;
	int runGiven;
	int wicketsTaken;

};
//cpp#include"player.h"

Player :: Player ()
{
	runScored = 0;
	ballsPlayed = 0;
	ballsBowlead = 0;
	runGiven = 0;
    wicketsTaken = 0;
}
//-----------------------------------------------------------
class Team {
//#include<vector>
//#include"player.h"
public :
	Team () ;
	std :: string name;
	int totalRuns;
	int wicketLost;
	int totalBallsBowled;
	std :: vector<Player>players;

};
//cpp#include"team.h"

Team :: Team ()
{
	totalRuns = 0;
	wicketLost =0;
	totalBallsBowled = 0;

}
//----------------------------------------------------------
class Game {
/*#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include"team.h"
*/
public:
	Game ();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std :: string players[11];
	bool isFirstIn;
	Team teamA , teamB;
	Team *batting , *bowling;
	Player *batsman , *bowler;

	void welcome ();
	void showAllFunction ();
	int takeIntInput ();
	void selectPlayer ();
	bool validateSelectPlayer(int index);
	void showTeam ();
	void toss ();
	void tossChoice (Team);
	void firstIn ();
	void initilizePlayers();
	void playIn();
	void bat ();
	bool validateIn ();
	void showScored ();
	void secondIn ();
	void showMatchSummary();
	void IntNeeds ();


};
//cpp#include"game.h"

Game :: Game()
{
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Shivam";
	players[3] = "Devid";
	players[4] = "Ajay";
	players[5] = "Samer";
	players[6] = "Vijay";
	players[7] = "Vikram";
	players[8] = "Sanket";
	players[9] = "Raj";
	players[10] = "Pavan";

	isFirstIn = false;
	teamA.name = "Team A";
	teamB.name = "Team B";

}
		void Game :: welcome () {
	    cout << "\t\t\t|*********************************|" << endl;
		cout <<"\t\t\t|    Welcome to Virtual Cricket   |" << endl;
		cout <<"\t\t\t|*********************************|" << endl;
		cout << endl << endl;
		cout << "!!*****************Instructions****************!!\n\n" << endl;
		cout <<" 1) Create 2 teams from a given pool of 11 player" << endl;
		cout<< " 2) Lead the toss and decide the choice of play" << endl;
		cout<< " 3) Each inning will be of 6 balls" << endl;
		cout<< "\n\n!!*********************************************!!" << endl;
 }

//================================================================================================================

	void Game  :: showAllFunction () {
		cout << endl;
		 cout <<"**********************************" << endl;
		 cout <<"*              Players           *" << endl;
		 cout <<"**********************************" << endl;
		 cout << endl;
		 for (int i =0;i<totalPlayers;i++)
		 {
			 cout<<"\t ["<< i << "] " << players[i] << endl;
		 }

	}
//=================================================================================================================

	int Game ::  takeIntInput ()	{
		int n;
		while (!(cin >> n))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max() ,'\n');

			cout<<"Invalid input!Please rewrite the input ";
		}
		return n;

	}

//=================================================================================================================

	bool Game :: validateSelectPlayer (int index)
	{
		int n;
		vector<Player>players;

		players = teamA.players;
		n = players.size();
		for(int i =0 ; i < n ; i++ ){
			if(players[i].id == index ){
				return false ;
			}
		}
		players = teamB.players;
		n = players.size();
		for(int i =0 ; i < n ; i++ ){
		if(players[i].id == index ){
			return false ;
			}
		}
		return true ;

	}

//=================================================================================================================

		void Game :: selectPlayer() {
			 cout << endl << endl;
			 cout <<"|********************************|" << endl;
			 cout <<"|        Create the teams        |" << endl;
			 cout <<"|********************************|" << endl;
			 cout << endl;
			 for( int i = 0 ; i < playersPerTeam ; i++)
			 {
				 //for team A
				 teamASelection:
				 	 cout<< endl << "Select the player " << i+1 << " of the team A - ";
				 	 int playerIndexTeamA = takeIntInput ();

				 	 if(playerIndexTeamA < 0 || playerIndexTeamA > 10 )
				 	 {
				 		 cout << endl << "Please select the player from given list :) " <<endl;
				 		 goto teamASelection;
				 	 } else if (!validateSelectPlayer(playerIndexTeamA)) {
						 cout << "Player has been selected already. Please select the another player " << endl;
						 goto teamASelection;
				 	 }
				 	 else {
				 		 Player teamAPlayers;
				 		 teamAPlayers.id = playerIndexTeamA ;
				 		 teamAPlayers.name = players[playerIndexTeamA];    //string players array
				 		 teamA.players.push_back(teamAPlayers);
				 	 	 }

				 //for team B
				teamBSelection:
				 cout<< endl << "Select the player " << i+1 << " of the team B - ";
				 int playerIndexTeamB = takeIntInput ();
				 if(playerIndexTeamB < 0 || playerIndexTeamB > 10 )
				 {
				    cout << endl << "Please select the player from given list :) " <<endl;
				 	goto teamBSelection;
				 } else if (!validateSelectPlayer(playerIndexTeamB)) {
					 cout << "Player has been selected already. Please select the another player " << endl;
					 goto teamBSelection;
				 } else {
				 Player teamBPlayer;
				 teamBPlayer.id = playerIndexTeamB;
				 teamBPlayer.name = players[playerIndexTeamB];
				 teamB.players.push_back(teamBPlayer);
				 }

			 }
		}

//=================================================================================================================

	 void Game :: showTeam ()  {

			 vector<Player> teamAPlayer = teamA.players;
			 vector<Player> teamBPlayer = teamB.players;

			 cout << endl << endl ;
			 cout << "--------------------------\t\t--------------------------" << endl;
			 cout << "__________Team A__________\t\t__________Team B__________" << endl;
			 cout << "--------------------------\t\t--------------------------" << endl;

			 for(int i = 0 ; i<playersPerTeam ; i++)
			 {
				 cout << "|\t" << "[" << i << "] " << teamAPlayer[i].name << "\t |"
					  << "\t\t"
					  << "|\t" << "[" << i << "] " << teamBPlayer[i].name << "\t |" << endl;

			 }

			 cout << "--------------------------\t\t--------------------------" << endl;
		 }

//=================================================================================================================

	 void Game :: toss() {
		 cout << endl << endl;
		 cout <<"**********************************" << endl;
		 cout <<"*           Let's toss           *" << endl;
		 cout <<"**********************************" << endl << endl;

		 cout <<" Tossing the coin................" << endl << endl;

		 srand(time(NULL));

		 int randam = rand () % 2;

		 switch(randam)
		 {
		 case 0:
				 cout << "Team A won the toss " << endl ;
				 tossChoice(teamA);
				 break;
		 case 1:
				 cout << "Team B won the toss " << endl ;
				 tossChoice(teamB);
				 break;
		 }
	 }

//=================================================================================================================

	 void Game :: tossChoice (Team tossWin) {
		 cout << "Enter the 1 for batting AND 2 for bowling " << endl
			  << "1.Bat " << endl
		 	  << "2 Bowl " << endl;

		 int tossInput = takeIntInput ();

		 cin.ignore(numeric_limits<streamsize> :: max() ,'\n');

		switch (tossInput) {
		case 1 :
			 cout << endl << tossWin.name << " won the toss and selected to batting first" << endl << endl;

			 if (tossWin.name.compare("Team A") == 0)   //if team A in win the toss
			 {
				 batting = &teamA;
				 bowling = &teamB;
			 }else  {  //else team B is toss winner

				 batting = &teamB;
				 bowling = &teamA;
			 }

			 break;
		case 2 :
			 cout << endl << tossWin.name << " won the toss and selected to bowling first" << endl << endl;

			 if (tossWin.name.compare("Team B") == 0)     ///if team B in win the toss
			  {
				 batting = &teamA;
			 	 bowling = &teamB
			 			 ;
			  } else     { //if the team A wins the toss {
			 	batting = &teamB;
			 	bowling = &teamA;
			 }
			 break ;

			 default:
			 cout << endl << " Invalid Input :( " << endl << endl;
			 tossChoice(tossWin);
			 break;
			}
	 }

//=================================================================================================================
	 void Game :: firstIn ()
	 {
		 cout << "\t\t______First Inning_______" << endl << endl;

		 isFirstIn = true ;

		 initilizePlayers();
		 playIn();
	 }
//=================================================================================================================

	 void  Game :: initilizePlayers()
	 {
		 //choose batsman and bowler : Initialize *batsman and *bowler

		 batsman = &batting->players[0];
		 bowler = &bowling->players[0];

		 cout << batting->name << " - " << batsman->name << " is batting " << endl;
		 cout << bowling->name << " - " << bowler->name << " is bowling " << endl << endl ;
	 }
//=================================================================================================================
	 void Game :: playIn ()
	 {
	 for(int i = 0 ; i < maxBalls ; i++ )
	{
		 cout << "Press the to bowl........";
		 getchar();

		 cout << "\nBowing..................." << endl;


		 bat ();

		 if (! validateIn())
		 {
			 break;
		 }


	 }
}
//=================================================================================================================

	 void Game :: bat ()
	 {
		 srand(time(NULL));
		  int runScored = rand () % 7;
		  //update the score
		  batsman->runScored = batsman->runScored + runScored;
		  batting->totalRuns = batting->totalRuns + runScored;
		  batsman->ballsPlayed = batsman->ballsPlayed +1 ;

		  //update bowling score
		  bowler->ballsBowlead = bowler->ballsBowlead + 1;
		  bowling->totalBallsBowled = bowling->totalBallsBowled +1;
		  bowler->runGiven = bowler->runGiven + runScored;

		  if(runScored != 0 ) {		//if runScored = 1,2,3,4,5,,6
			  cout << endl << bowler->name << " to " << batsman->name << " " << runScored << " runs scored ! " << endl << endl;
			  showScored();
		  } else {     //else runScored = 0 so the batsman is out
			 cout << endl << bowler->name << " to " << batsman->name  << " OUT! :((( " << endl << endl;

			 batting->wicketLost = batting->wicketLost+1;
			 bowler->wicketsTaken = bowler->wicketsTaken +1;
			 showScored();

			 int  nextPlayerIndex = batting->wicketLost;
			 batsman = &batting->players[nextPlayerIndex];

		  }


	 }
//=================================================================================================================

	 bool Game :: validateIn ()
	 {
		 if (isFirstIn)
		 {
			if(batting->wicketLost == playersPerTeam || bowling->totalBallsBowled == maxBalls )
			{
				cout << "\t ..........first Inning ends..........." << endl << endl ;



				cout << batting->name << "  " << batting->totalRuns << " - "
					 <<batting->wicketLost << "(" << bowling->totalBallsBowled
					 << ")" << endl;
	            cout << "\n\t!!! RESULT !!!\n\n";

				cout << bowling->name << " needs " << batting->totalRuns + 1
					 << " runs to win the match." << endl ;

				return false ;
			}
		 } else {
			 if (batting->totalRuns > bowling->totalRuns) {

			         	    cout << batting->name << " WON THE MATCH" << "\n\n";
			         	    return false;
			             }
			             else if (batting->wicketLost == playersPerTeam || bowling->totalBallsBowled == maxBalls) {

			                 if (batting->totalRuns < bowling->totalRuns) {

			             	cout << bowling->name << " WON THE MATCH" << "\n\n";
			             }
			             else {

			             	cout << "MATCH DRAW" << "\n\n";
			             }
			             return false;
			         }

			     return true;

		 }
		 return true;
	 }
 //=================================================================================================================


	 void Game :: showScored (){

		 cout << "**************************************************************************" << endl;

		 cout << "\t" << batting->name << " " << batting-> totalRuns << " - "
			  << batting->wicketLost << " (" << bowling->totalBallsBowled << ") | " << batsman->name
			  << " " << batsman->runScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
	          << bowler->ballsBowlead << " - " << bowler->runGiven << " - " << bowler->wicketsTaken << "\t" << endl;

		 cout << "**************************************************************************" <<endl << endl;

	 }

//=================================================================================================================

	 void Game ::  secondIn ()
	 {
		  cout << "\t\t______Second Inning_______" << endl << endl;

		 		 isFirstIn = false ;

		 		 Team tempteam = *batting;
		 		 *batting = *bowling;
		 		 *bowling = tempteam ;

		 		 initilizePlayers();
		 		 playIn();
	}


//=================================================================================================================

 void Game :: showMatchSummary() {

	 	cout << "\t\t\t\t ||| MATCH ENDS ||| " << "\n\n";

	 	 cout << batting->name << " " << batting->totalRuns << "-" << batting->wicketLost << " (" << bowling->totalBallsBowled << ")" << "\n";

	     cout << "\t\t\t==========================================" << "\n";
	     cout << "\t\t\t| PLAYER \t BATTING \t BOWLING |" << "\n";

	     for (int j = 0; j < playersPerTeam; j++) {
	     	Player player = batting->players[j];
	     	cout << "\t\t\t|----------------------------------------|" << "\n";
	     	cout << "\t\t\t| " << "[" << j << "] " << player.name << "  \t ";
	         cout << player.runScored << "(" << player.ballsPlayed << ") \t\t ";
	 		cout << player.ballsBowlead << "-" << player.runGiven << "-";
	 		cout << player.wicketsTaken << "\t |" << "\n";
	     }
	     cout << "\t\t\t==========================================" << "\n\n";

	     cout << bowling->name << " " << bowling->totalRuns << "-" << bowling->wicketLost << "(" << batting->totalBallsBowled << ")" << "\n";

	     cout << "\t\t\t==========================================" << "\n";
	     cout << "\t\t\t| PLAYER \t BATTING \t BOWLING |" << "\n";

	     for (int i = 0; i < playersPerTeam; i++) {


	    	 Player player = bowling->players[i];
	         cout << "\t\t\t|----------------------------------------|" << "\n";
	         cout << "\t\t\t| " << "[" << i << "] " << player.name << "  \t ";
	         cout << player.runScored << "(" << player.ballsPlayed << ") \t\t ";
	         cout << player.ballsBowlead << "-" << player.runGiven << "-";
	 		cout << player.wicketsTaken << "\t |" << "\n";
	     }
	     cout << "\t\t\t==========================================" << "\n\n";
	 }
//---------------------------------------------------------

int main ()
{
	Game game;
	game.welcome();

    cout << "\nPress Enter to continue\n\n";
    getchar();

    game.showAllFunction();

    cout << "\nPress Enter to continue\n\n";
    getchar();

    game.selectPlayer();

    game.showTeam();

	cout << "\nPress enter to toss\n\n";
	getchar();
	getchar();

	game.toss();

    cout << "\n\nPress enter to start first innings...\n\n";
    getchar();

	game.firstIn();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nPress enter to start second innings...\n\n";
    getchar();

    game.secondIn();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n\nPress enter to see match summary.\n\n\n";
    getchar();


	 game.showMatchSummary();

	return 0;

}

