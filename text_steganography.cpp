
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char CTG[70][100]={
"color",
"The cheer doubles as color before the variance. ",
"A lunchtime boils color without the concerned yeti.",
"Color smells like the blessed angle. ",
"favorite",
"Outside the decade abides favorite.  ",
" How will a bloody bigot kid within favorite? ",
"Favorite pulses above a scrap. ",
"fulfill",
"The explosive bookshop functions as fulfill within a spy. ",
"Beneath the bass farms fulfill. ",
"The tending complex shifts a profile polices fulfill. ",
"critisize",
"a critisize sands a sundry orbital. ",
"Critisize pales around the static. ",
"Critisize overflows! With the loophole despairs the hail. ",
"center",
"A lavatory pieces center opposite the assigned nick. ",
"Why does the heart stretch throughout center? ",
"Center punctures an author near the flaw. ",
"tire",
"Tire expands! ",
"Tire distracts the bulletin below a welcome. ",
"Will a thread prosecute beside tire? A volume bubbles! ",
"defense",
"The vessel tanks the cold past and defense apologizes. ",
"Defense surnames a panic without a cider. ",
"The won treat dreads defense near a copper. ",
"dialog",
"Dialog reacts to a converter near the jest. ",
"Will a terse package pitch dialog? The worth fiddles. ",
"The dread viewer soils dialog. ",
"dialogue",
"The catholic stretches beneath dialogue. ",
" Can another historian flip over dialogue? ",
"Dialogue features the guilt throughout his important sunshine. ",
"defence",
"Defence coughs across the board. ",
"The dream fakes defence throughout an intervening leather. ",
"Defence grasses the island outside a frustrate roof. ",
"tyre",
"The chalk gates tyre against the rank thread. ",
"Tyre denotes the visit over the criterion. ",
"The comfort represents tyre. ",
"centre",
"Centre surfaces after the marital gas. ",
"Every straw misprint fingers centre. ",
"Centre works beneath a rival festival. ", 
"critisice",
"Whatever ink affects critisice before an addict. ",
"Critisice arrays the registered orchestra after a fear. ",
"Critisice positions the laboratory with the complementary pattern. ",
"fullfill",
"A guard reaches. Past the machine puzzles fullfill. ",
"On top of fullfill reigns the sympathy. ",
"Does fullfill clog above the suicide? ", 
"favourite",
"Favourite cites the amazing, fashionable carpet tones an orbital. ",
"When can the dummy fudge within favourite? ",
"Our jury surnames favourite past the considerate school. ",
"colour",
"Colour charges the interview beneath the toad. ",
"How can the memory lodge and will a software mandate colour? ",
"The message accounts colour. "
};




 char CV[1000];
 int count=0,count1=0;


int CT[64][3];
char US[8][20]={"color","favorite","fulfill","critisize","center","tire","defense","dialog"};
char UK[8][20]={"dialogue","defence","tyre","centre","critisice","fullfill","favourite","colour"};




void dispCTG()
{int i;
for(i=0;i<20;i++)
cout<<CTG[i];
}


void iniCT()
{
int i,j=0,l=0,k=0;
for(i=0;i<64;i++)
	{
		CT[i][0]=i;
		CT[i][1]=l;
		j++;
		if(j>7)
			{
				l++;
				j=0;
			}
		CT[i][2]=k++;
		if(k>7)
		k=0;
	}
}

void dispinitCT()
{ int i;
for(i=0;i<64;i++)
cout<<CT[i][0]<<" "<<CT[i][1]<<" "<<CT[i][2]<<"\n";
}




char GENERCP[100][100];
int arr[50];

void dispGENERCP()
{
int i;
for(i=0;i<count1;i++)
cout<<GENERCP[i]<<"\n";
}


void encode(char message[20])
{
int len,i,a;
char m;

len=strlen(message);
for(i=0;i<len;i++)
	{
	 m=message[i];
	 a=m-'0';
	 if(a>=17&&a<=42)
	 a=a-17;
	 else if (a>=49&&a<=74)
	 a=a-23;
	 else if (a>=0&&a<=9)
	 a=a+52;
	 else if (a==-4)
	 a=a+66;
	 else if(a==-16)
	 a=a+79;
	 else
		{
			cout<<"wrong message, parameters out of range ....";
			return;
		}
	 arr[count++]=a;
  }

}
void GENRCP()
{
int i,p1,j,k,p2;
char RCP1[20],RCP2[20];
for(i=0;i<count;i++)
{
	for(k=0;k<64;k++)
		{
			if(CT[k][0]==arr[i])
				{
				 p1=CT[k][1];
				 p2=CT[k][2];
				 strcpy(RCP1,US[p1]);
				 strcpy(RCP2,UK[p2]);
				 strcpy(GENERCP[count1++],RCP1);
				 strcpy(GENERCP[count1++],RCP2);
				 for(j=0;j<20;j++)
					{
					 RCP1[j]='\0';
					 RCP2[j]='\0';
					}
				break;
				}
		}
}
}
void disparr()
{
int i;
for(i=0;i<count;i++)
{
cout<<arr[i]<<"\n";
}
}

void CVgen()
 {
 int i,j,k=0;
 for(i=0;i<count1;i++)
	{
	for(j=0;j<70;j=j+4)
	{
	 if(strcmp(GENERCP[i],CTG[j])==0)
		{
		 k=(k+1)%4;
		 if(k!=0)
		 {
		 strcat(CV,CTG[j+k]);
		 }
		 else
		 {
		 k++;
		 strcat(CV,CTG[j+k]);
		 }
		 break;
		}
	 }
  }
}
void main()
{
clrscr();
iniCT();
char msg[20];
cout<<"\nenter the message \n";
cin>>msg;
encode(msg);
//disparr();
GENRCP();
//dispGENERCP();
CVgen();
cout<<CV;
//for(int q=0;q<70;q++)
//cout<<q<<" "<<CTG[q]<<"\n";
//dispCTG();
//dispinitCT();
}
