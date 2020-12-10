/*
*						Tic Tac Toe Using Socket Programming
*							Computer Networks Mini Project
*		By Chitturi Sai Suman (1602-18-733-097) and Praneeth Kapila (1602-18-733-116)
*								B.E. III/IV SEM - 1
*				Vasavi College of Engineering - Ibrahimbagh, Hyderabad
*/
#include <stdio.h>			
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define and 					&&
#define or 						||
#define not 					!
#define is 						==
#define newline 				printf("\n")
#define space					printf(" ")
#define endl					printf("\n")
#define iter(x,a,b) 			for(int x=a;x<=b;x++)
#define FOR(x,N) 				for(int x=0;x<N;x++)
#define For(x,N) 				for(int x=0;x<N;x++)
#define caseprint 				printf("Case #%d: ",test+1)
#define inverse(a,p) 			power(a,p-2,p)
#define scan(a) 				scanf("%d",&a)
#define scanll(a)				scanf("%lld",&a)
#define print(a) 				printf("%lld",((ll)a))
#define println(a)				printf("%lld\n",((ll)a))
#define getName(var)			#var
#define debug(var)				fprintf(stderr,"%s = %lld\n",getName(var),((ll)var));
#define readInt(arr,nax)		FOR(IT,nax) {scan(arr[IT]);}
#define readLL(arr,nax)			FOR(IT,nax) {scanll(arr[IT]);}
#define write(arr,nax)			FOR(IT,nax) {print(arr[IT]);space;}
#define fill(arr,nax,value)		FOR(IT,nax) {arr[IT] = value;}
#define sort123(arr,nax)		qsort(arr,nax,sizeof(int),ascending)
#define sort321(arr,nax)		qsort(arr,nax,sizeof(int),descending)
#define reverse(arr,nax)		FOR(x,nax/2) {arr[x]=arr[nax-x-1];}
#define newInt(nax)				(int*)malloc(sizeof(int)*nax)
#define newLong(nax)			(ll *)malloc(sizeof(ll)*nax)
#define newString(nax)			(char *)malloc(sizeof(char)*nax)

typedef unsigned long long int ull;
typedef long long int ll;
const ll mod = ((ll)(1e9+7)); // 10**9+7
const ll hell = ((ll)(1e9+9)); // 10**9+9
const ll inf = ((ll)(1e18)); // 10**18

static inline void swapInt(int *a, int *b) 		{int temp=*a;*a=*b;*b=temp;}
static inline void swapChar(char *a, char *b)	{char c=*a;*a=*b;*b=c;}
static inline void swapLong(ll *a, ll *b)		{ll temp=*a;*a=*b;*b=temp;}
static inline int setBitCount(ll n)				{int ans=0;for(;n>0;n/=2,ans+=n%2);return ans;}
static inline ll gcd(ll a, ll b) 				{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll lcm(ll a, ll b) 				{return (a*b)/(gcd(a,b));}
static inline ll max(ll a, ll b) 				{return (a>b?a:b);}
static inline ll min(ll a, ll b) 				{return (a<b?a:b);}
static inline ll mul(ll a, ll b, ll p) 			{return ((a%p*b%p)%p);}
static inline ll add(ll a, ll b, ll p) 			{return ((a%p+b%p)%p);}
static inline ll sub(ll a, ll b, ll p) 			{return ((a%p-b%p)+p)%p;}
static inline int sumOfDigits(ll n) 			{return n>0?n%10+sumOfDigits(n/10):0;}
static inline int numberOfDigits(ll n)			{return n>0?1+numberOfDigits(n/10):0;}

void printTab(int n) {
	while (n--) {
		printf("\t");
	}
}

void clear() {
	system("clear");
}

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void board() {
    
    printf("\n\n\t\t\t\tTic Tac Toe\n\n");

    printf("\t\t\tCLIENT (X)  -  SERVER (O)\n\n\n");

    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");

    printf("\t\t\t  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");

    printf("\t\t\t  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("\t\t\t     |     |     \n\n");
}

int checkwin() {
	for(int i=1;i<=3;i++) {
		if(square[3*i] == square[3*i-1] and square[3*i] == square[3*i-2])
			return 1;
	}
    for(int i=1;i<=3;i++) {
		if(square[i] == square[i+3] and square[i] == square[i+6])
			return 1;
	}

    if(square[1] == square[5] and square[5] == square[9]) 
		return 1;
        
    if(square[3] == square[5] and square[5] == square[7])
		return 1;

	bool flag = true;
	for(int i=1;i<=9;i++) {
		if(square[i] == i+'0')
			flag = false;
	}
	if(!flag)
		return 0;
	printf("\n\n\t\tGAME ENDED IN A DRAW\n");
	system("sleep 3");
	clear();
	exit(0);
}

void rawInput() {
	system("/bin/stty raw");
    char trash = tolower(getchar());
    system("/bin/stty cooked");
}

void printIntroduction() {
	FILE *fptr = fopen("Introduction.txt","r");
	char ch = '0';
	clear();
	while(fscanf(fptr,"%c",&ch)!=-1) {
		printf("%c",ch);
	}
	fclose(fptr);
	rawInput();
}
void printConclusion() {
	FILE *fptr = fopen("Conclusion.txt","r");
	char ch = '0';
	clear();
	while(fscanf(fptr,"%c",&ch)!=-1) {
		printf("%c",ch);
	}
	fclose(fptr);
}
int main() {
	
	int ssid = 0;
	int a = 0, b = 0, s = 0;
	int msgbyte = 0;
	char str[100];
	int cid = 0;

	int i = 0, choice = 0;
	char mark = 0;

	printIntroduction();
	clear();
	ssid = socket(AF_INET, SOCK_STREAM, 0);
	printTab(2);
	if(ssid == -1) {
		printf("FAILED TO CREATE SOCKET AT SERVER SIDE\n");
		exit(0);
	}
	printf("SUCCESSFULLY CREATED SOCKET AT SERVER SIDE\n");
	int sid = 1;
	struct sockaddr_in ssadd;
	ssadd.sin_family = AF_INET;
	ssadd.sin_port = htons(6999);
	ssadd.sin_addr.s_addr = inet_addr("127.0.0.1");
	sid = bind(ssid, (struct sockaddr *) &ssadd, sizeof(ssadd));
	printTab(2);
	if(sid == -1) {
		printf("BINDING FAILURE AT SERVER SIDE\n");
		exit(0);
	}
	printf("BINDING SUCCESSFUL AT SERVER SIDE\n");
	listen(ssid,5);
	struct sockaddr_in fadd;
	int len = sizeof(fadd);
	int fd1 = accept(ssid, (struct sockaddr*) &fadd, &len);
	if(fd1 == (-1)) {
		printf("SERVER IS NOT ACCEPTING THE MOVE\n");
		exit(0);
	}
	system("sleep 3");
	i= checkwin();
	while(i != 1) {
		printf("\n\n\t\tWaiting for Client's Move\n");
		msgbyte=recv(fd1,&choice,sizeof(choice),0);
		if(choice == 11) {
			printf("\n\n\t\tCongratulations! You WON\n");
			close(ssid);
			break;
		}
		mark = 'X';
		if(choice>=1 and choice<=9 and square[choice] == choice + '0')
			square[choice] = mark;
		    
		i = checkwin();
		printf("\n%d\n",i);
		clear();
		if(i == 1) {
			board();
			int flag=10;
			printf("\n\n\t\tYOU LOSE\n");
			printf("\n\t\tClient Won the Match\n");
			msgbyte=send(fd1,&flag,sizeof(flag),0);
			close(ssid);
			break;
		}

		board();
		printf("\n\n\tYou are Playing as O\n\n");
		printf("\tPlease Enter Your Choice(O): ");
		scanf("%d",&choice);
		while(!(choice>=1 and choice<=9)) {
		    printf("Invalid move \n");
		    printf("Please Enter a Valid Move between 1-9: ");
		    scanf("%d",&choice);
		}
		mark='O';

		if(choice<=9 and choice>=1) {
			while(square[choice] != choice + '0') {
				printf("\n\t\tInvalid Move!!!\n");
				printf("\n\t\tPlease Enter Your Choice(O): ");
				scanf("%d",&choice);
			}
		}
		square[choice] = mark;
		    
		msgbyte=send(fd1,&choice,sizeof(choice),0);
		
	}
	system("sleep 5");
	close(ssid);
	printConclusion();
	sleep(5);
	clear();
	return 0;
}
