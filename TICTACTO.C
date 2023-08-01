/*
  Tic Tac Toe game - tictacto.c
  Author : Shine Jacob(enot)
  Email  : enot06@gmail.com
  
  This is a simple Tic Tac Toe game. I have used conio2.h that is not a part of 
  the C standard and not available in Dev-C++ by default. You can download it
  from http://conio.sourceforge.net/ or if you wish to compile this program in 
  Turbo C++ IDE then replace conio2.h with conio.h.
  
  Please let me know if you find and error or if you have any questions.
  
  I have also attached libconio.a and conio2.h
  
  Enjoy!
*/


#include <stdio.h>
#include <conio2.h>



#define UPARROW     72
#define DOWNARROW   80
#define LEFTARROW   75
#define RIGHTARROW  77
#define ENTER       13
#define QUIT       'q'


int _x,_y; //To track the position of the Tic Tac Toe frame being drawn


//Function to show the Tic Tac Toe Frame
void showframe(int posx, int posy)
{

  int hr=196, vr=179; // These are ascii character which display the lines
  int crossbr=197;    // Another ascii character
  int x=posx, y=posy;   
  int i,j;

  gotoxy(35,4); cprintf("TIC TAC TOE");
  gotoxy(35,5); for(i=0;i<11;i++) cprintf("%c",223);


  for(i=0;i<2;i++)
  {
    for(j=1;j<=11;j++)
     {
      gotoxy(x,y);
      printf("%c",hr);
      x++;
     }
    x=posx; y+=2;  
  }
  x=posx+3; y=posy-1; 

  for(i=0;i<2;i++)
  {

   for(j=1;j<=5;j++)
   {
      gotoxy(x,y);
      printf("%c",vr);
      y++;
   }
   x+=4;y=posy-1;
  }


  x=posx+3; y=posy;     
  gotoxy(x,y);
  printf("%c",crossbr);

   x=posx+7; y=posy;         
  gotoxy(x,y);
  printf("%c",crossbr);

  x=posx+3; y=posy+2;             
  gotoxy(x,y);
  printf("%c",crossbr);

  x=posx+7; y=posy+2;            
  gotoxy(x,y);
  printf("%c",crossbr);

}


//Function to fill random values into the array
void fillrandom(char arr[3][3])
{
  int i=0,j=0;
  char ch='A';

  for(i=0;i<3;i++)
   { for(j=0;j<3;j++)
     { arr[i][j] = ch; ch++; }

   }
}


//Function to show the character in the specified box
void showbox(char ch, int box)
{

   switch(box)
   {
     case 1 :	gotoxy(_x+1,_y-1); printf("%c",ch); break; //1st box
     case 2 :	gotoxy(_x+5,_y-1); printf("%c",ch); break; //2nd box
     case 3 :	gotoxy(_x+9,_y-1); printf("%c",ch); break; //3rd box
     case 4 :	gotoxy(_x+1,_y+1); printf("%c",ch); break; //4th box
     case 5 :	gotoxy(_x+5,_y+1); printf("%c",ch); break; //5th box
     case 6 :	gotoxy(_x+9,_y+1); printf("%c",ch); break; //6th box
     case 7 :	gotoxy(_x+1,_y+3); printf("%c",ch); break; //7th box
     case 8 :	gotoxy(_x+5,_y+3); printf("%c",ch); break; //8th box
     case 9 :	gotoxy(_x+9,_y+3); printf("%c",ch); break; //9th box
   }

}


//Function to insert the specified character into the array
void putintobox(char arr[3][3], char ch, int box)
{
  switch(box)
  {

    case 1 :	if(arr[0][0] != 'X' && arr[0][0]!= 'O')
                { arr[0][0] = ch;
		          showbox(ch,1);
		        }
		        break;

    case 2 :	if(arr[0][1] != 'X' && arr[0][1]!= 'O')
		        { arr[0][1] = ch;
		          showbox(ch,2);
		        }
		        break;

    case 3 :	if(arr[0][2] != 'X' && arr[0][2]!= 'O')
                { arr[0][2] = ch;
		          showbox(ch,3);
		        }
		        break;

    case 4 :	if(arr[1][0] != 'X' && arr[1][0]!= 'O')
		       { arr[1][0] = ch;
		         showbox(ch,4);
		       }
		        break;

    case 5 :	if(arr[1][1] != 'X' && arr[1][1]!= 'O')
		        { arr[1][1] = ch;
		         showbox(ch,5);
		        }
		        break;

    case 6 :	if(arr[1][2] != 'X' && arr[1][2]!= 'O')
		        { arr[1][2] = ch;
                  showbox(ch,6);
		        }
	        	break;

    case 7 :	if(arr[2][0] != 'X' && arr[2][0]!= 'O')
     		    { arr[2][0] = ch;
		          showbox(ch,7);
		        }
		        break;

    case 8 :	if(arr[2][1] != 'X' && arr[2][1]!= 'O')
		        { arr[2][1] = ch;
		          showbox(ch,8);
		        }
		        break;

    case 9 :	if(arr[2][2] != 'X' && arr[2][2]!= 'O')
		        { arr[2][2] = ch;
		          showbox(ch,9);
		        }
		        break;
   }//end of switch
}


//Function to show the curson on the box specified
//uses the position to check the coordinates
void gotobox(int box)
{
  switch(box)
  {
    case 1 : gotoxy(_x+1,_y-1); break;
    case 2 : gotoxy(_x+5,_y-1); break;
    case 3 : gotoxy(_x+9,_y-1); break;
    case 4 : gotoxy(_x+1,_y+1); break;
    case 5 : gotoxy(_x+5,_y+1); break; //5th box
    case 6 : gotoxy(_x+9,_y+1); break; //6th box
    case 7 : gotoxy(_x+1,_y+3); break; //7th box
    case 8 : gotoxy(_x+5,_y+3); break; //8th box
    case 9 : gotoxy(_x+9,_y+3); break;

  }
}


//Function to handle the navigation
int navigate(char arr[3][3], int box, int player, int key)
{
   switch(key)
   {
     case UPARROW    : if( (box!=1) || (box!=2) || (box!=3) )
		               { box-=3; if(box<1) box = 1; gotobox(box); }
	                   break;

     case DOWNARROW  : if( (box!=7) || (box!=8) || (box!=9) )
		               { box+=3; if(box>9) box = 9; gotobox(box); }
		               break;

     case LEFTARROW  : if( (box!=1) || (box!=4) || (box!=7) )
		               { box--;  if(box<1) box = 1; gotobox(box); }
		               break;

     case RIGHTARROW : if( (box!=3) || (box!=6) || (box!=9) )
		               { box++; if(box>9) box = 9; gotobox(box); }
		               break;

     case ENTER      : if(player == 0)
			            putintobox(arr,'O',box);
		               else if(player == 1)
			            putintobox(arr,'X',box);
		               break;
    }//end of switch(key)

 return box;
}

int checkforwin(char arr[3][3])
{
  int w=0;

/*  0,0   0,1   0,2
    1,0   1,1   1,2
    2,0   2,1   2,2
*/
  //rows
  if((arr[0][0] == arr[0][1]) && (arr[0][1] == arr[0][2])) w = 1;
  else if((arr[1][0] == arr[1][1]) && (arr[1][1] == arr[1][2])) w = 1;
  else if((arr[2][0] == arr[2][1]) && (arr[2][1] == arr[2][2])) w = 1;

  //coloums
  else if((arr[0][0] == arr[1][0]) && (arr[1][0] == arr[2][0])) w = 1;
  else if((arr[0][1] == arr[1][1]) && (arr[1][1] == arr[2][1])) w = 1;
  else if((arr[0][2] == arr[1][2]) && (arr[1][2] == arr[2][2])) w = 1;

  //diagonal
  else if((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2])) w = 1;
  else if((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0])) w = 1;

  return w;
}


int boxesleft(char a[3][3])
{
   int i,j,boxesleft=9;
   
   for(i=0;i<3;i++)
    { for(j=0;j<3;j++)
      { if((a[i][j] == 'X') ||(a[i][j] == 'O'))
          boxesleft--;
      }
    }
   
   return boxesleft;
} 


int main()
{
  char arr[3][3];
  char player[3][30],O_OR_X[2],ch;
  int  x,y,turns,chance,enter,box,win,quit,winner;
  int  movesfinished = 0; 

  O_OR_X[0] = 'O'; O_OR_X[1] = 'X';
  do{

   textbackground(7); textcolor(0); //Set the specified background and textcolor
   clrscr(); //Clears the screen - defined in conio.h(conio2.h)

  _x = 35; _y = 12;
   x = _x; y = _y;

  showframe(x,y); //Draws the frame of Tic Tac Toe
  showbox('O',1); //Displays O in box 1
  showbox('X',2); //Displays X in box 2
  showbox('O',3); //Displays O in box 3 
  showbox('X',4); //Displays X in box 4
  showbox('O',5); //Displays O in box 5
  showbox('X',6); //Displays X in box 6
  showbox('O',7); //Displays O in box 7
  showbox('X',8); //Displays X in box 8
  showbox('O',9); //Displays O in box 9

  gotoxy(2,18);
  printf("Welcome to Tic Tac Toe");
  printf("\n Rules are simple. Navigate to the box with arrow keys [%c %c %c %c] and hit enter.",30,31,17,16);
  printf("\n If you try to overwrite a box, then your chance will be passed on.");
  fillrandom(arr); //Filling random character to the array

  printf("\n Player 1, enter your name: "); gets(player[0]); //Get player1's name
  printf(" Player 2, enter your name: ");   gets(player[1]); //Get player2's name

  printf("\n %s, you have been given O             %s, you have been given X",player[0],player[1]);
  printf("\n Lets begin ( press any key )"); getch();


  turns  = 0;  //to count the total number of turns
  chance = 0;  //to check whose chance is it
  enter  = 0;  //variable to track if Enter was pressed
  box    = 1;  //Track the current box number
  win    = 0;  //Check if someone won
  quit   = 0;  //Check if player wants to quit
  winner = 10; //To see who is the winner


  

  clrscr();
  showframe(x,y);

  while((!win))
  {

   
     gotoxy(2,20);
     printf("%s(%c), its your chance.     ",player[chance],O_OR_X[chance]);
   
     while(!enter && !quit)
     {
  	  if(kbhit())
	  {
	    ch = getch();

	    switch(ch)
	    {
	      case UPARROW    :  box=navigate(arr,box,chance,UPARROW);
	 	    		         break;
	      case DOWNARROW  :  box=navigate(arr,box,chance,DOWNARROW);
				             break;
	      case LEFTARROW  :  box=navigate(arr,box,chance,LEFTARROW);
				             break;
	      case RIGHTARROW :  box=navigate(arr,box,chance,RIGHTARROW);
				             break;
	      case ENTER      :  box=navigate(arr,box,chance,ENTER);
				             enter=1; break;
	      case QUIT       :  quit = 1; break;
	    }//end of switch(ch)
	 }//end of if(kbhit())

     }//end of while

     if(quit) break;   //Quits the program

     if(chance == 0)
      { putintobox(arr,box,'O'); box = 1; } //player1
     else if(chance == 1)
      { putintobox(arr,box,'X'); box = 1; } //player2

     if( (win = checkforwin(arr)) == 1)
      winner = chance;

     if(chance == 1) chance = 0;
     else chance = 1;

     enter = 0;
     turns++;
     
     if(!boxesleft(arr))
      movesfinished = 1;

     //If its a draw
     if((!win) && (turns==9) && (movesfinished))
      break;

  }//end of while(win)

  if(win)
  { gotoxy(22,22);
    textbackground(4); textcolor(15);

    if(winner == 0)
     cprintf(" Congratulations %s, you win the game! ",player[0]);

    else
     cprintf(" Congratulations %s, you win the game! ",player[1]);

  }
  
  else if(quit)
   {
      gotoxy(10,22);
      textbackground(4); textcolor(15);
      cprintf(" Ok, lets play again sometime. See you later. Press any key to exit.\n\n");
      getch();
      return 1;
   }
  else if((!win) && (turns==9) && (movesfinished))
  { gotoxy(22,22);
    printf("No one wins. Its a draw.");
  }

   printf("\n\n Do you want to play again? (Y/N): "); ch = getch();


  }while(ch=='Y' || ch=='y'); //playagain

  return 0;

}

