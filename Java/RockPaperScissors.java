/*
 Jack Westbrock
 */
import java.util.Scanner;
import java.util.Random;

public class RockPaperScissors {
	public static final int ROCK = 0;//define constants for equivalents for each choice
	public static final int PAPER = 1;
	public static final int SCISSORS = 2;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Random r = new Random();
		boolean playAgain = true;
		
		while(playAgain == true)//game continues as long as the player wants
		{
			System.out.println("Welcome to Rock Paper Scissors!  Best 2 out of 3!");
			int computerWins = 0;//defines the wins
			int playerWins = 0;
			for(int i = 0; i < 3; i++)//plays each round 3 times increments after each round
			{
				
				System.out.println("Enter \"Rock\", \"Paper\", or \"Scissors\"");
				String playerStr = scan.nextLine().toLowerCase();//stores users choice
				int playerInt = -1;
				if(playerStr.contentEquals("rock"))//converts all the strings of choices to int for ease
					playerInt = ROCK;
				else if(playerStr.contentEquals("paper"))
					playerInt = PAPER;
				else if(playerStr.equals("scissors"))
					playerInt = SCISSORS;
				else
				{
					System.out.println("Not a valid input! Computer wins");//if choice is not rock paper or scissors
					computerWins++;
				}
				int compInt = r.nextInt(3);//randomly chooses a choice for the computer
				String compStr = "";
				if(compInt == ROCK)//makes the int into a string for ease
					compStr = "rock";
				else if(compInt == PAPER)
					compStr = "paper";
				else if(compInt == SCISSORS)
					compStr = "scissors";
				
				if(compInt == playerInt)//if the computer and player chose the same
				{
					System.out.println(compStr + " v " + playerStr + " Tie!");
					System.out.println("It's a tie, player has won " + playerWins + " times and the computer has won " + computerWins + " times\n");
				}
				else if(playerInt == ROCK)//if player chooses rock
				{
					if(compInt == PAPER)//if comp is paper
					{
						System.out.println(playerStr + " v " + compStr + " Computer Wins!");//comp wins
						computerWins++;
						System.out.println("Player has won " + playerWins + " times and the computer has won " + computerWins + " times\n");
					}
					if(compInt == SCISSORS)//if comp is scissors
					{
						System.out.println(playerStr + " v " + compStr + " Player Wins!");//player wins
						playerWins++;
						System.out.println("Player has won " + playerWins + " times and the computer has won " + computerWins + " times\n");
					}
				}
				else if(playerInt == PAPER)//if player chose paper
				{
					if(compInt == SCISSORS)//if comp is scissors
					{
						System.out.println(playerStr + " v " + compStr + " Computer Wins!");//computer wins
						computerWins++;
						System.out.println("Player has won " + playerWins + " times and the computer has won " + computerWins + " times\n");
					}
					if(compInt == ROCK)//if comp is rock
					{
						System.out.println(playerStr + " v " + compStr + " Player Wins!");//player wins
						playerWins++;
						System.out.println("Player has won " + playerWins + " times and the computer has won " + computerWins + " times\n");
					}
				}
				else if(playerInt == SCISSORS)//if player scissors
				{
					if(compInt == ROCK)//if comp is rock
					{
						System.out.println(playerStr + " v " + compStr + " Computer Wins!");//comp wins
						computerWins++;
						System.out.println("Player has won " + playerWins + " times and the computer has won " + computerWins + " times\n");
					}
					if(compInt == PAPER)
					{
						System.out.println(playerStr + " v " + compStr + " Player Wins!");//player wins
						playerWins++;
						System.out.println("Player has won " + playerWins + " times and the computer has won " + computerWins + " times/n");
					}
				}
				
			}
			if(playerWins > computerWins)//prints who won the most of the three rounds
				System.out.println("The player wins!");
			else if(playerWins < computerWins)
				System.out.println("The computer wins!");
			else
				System.out.println("It's a tie");
			System.out.println("Play again? \"Yes\" or \"No\"");//asks to play again
			String again = scan.nextLine().toLowerCase();
			if(again.contentEquals("no"))//if yes then the while loop runs again
				playAgain = false;//if no then the program stops 
		}
		System.out.println("Goodbye!");
	}

}
