/**
 * Implementation of the horspool algorithm
 * Author: Arjun Rao
 * Usage: 
 * Run	./horspool or ./horspool -v (verbose output)
 *
 **/


#include<iostream>
#include<string>
#include<algorithm>
#include<unistd.h>
using namespace std;


int* generateShiftTable(string pattern)
{
	int *table = new int[255];
	for(int i=0;i<256;i++)
		table[i] = pattern.length()-1;
	for(int i=0;i<pattern.length()-1;i++)
	{
		table[pattern[i]] = pattern.length()-i-1;
	}
	return table;

}

int isMatch(string pattern,string text,int verbose=0,int icase=0)
{
	if(icase)
	{
	   std::transform(text.begin(), text.end(), text.begin(), ::tolower);
	   std::transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
	}
	int *stable = generateShiftTable(pattern);
	int skip =0,i,tlength= text.length(),plength= pattern.length();
	while( tlength-skip >= plength)
	{
		if(verbose){
		cout<<"\ntext:\n"<<text<<endl;
		for(int j=0;j<skip;j++)cout<<" ";
		cout<<pattern<<endl;}
		i = plength-1;
		while(text[skip+i] == pattern[i])
		{
			if(i==0)
				return skip;
			i--;
		}
		if(verbose)
		cout<<"Shifting by: "<<stable[text[skip+i]]<<endl;
		skip+=stable[text[skip+i]];
	}
	return -1;

}


int main(int argc,char *argv[])
{
	int *generateShiftTable,found,verbose=0,icase =0;
	string pattern,text;
	opterr=0;
	int option;
	while((option = getopt(argc,argv,"vi"))!=-1)
	{
		switch(option)
		{
			case 'v':
				verbose=1;
				break;
			case 'i':
				icase=1;
				break;
		}			
	}
	cout<<"Pattern: ";
	getline(cin,pattern);
	cout<<"Text: ";
	getline(cin,text);
	if((found = isMatch(pattern,text,verbose,icase))!=-1)
		cout<<"Found at position: "<<found+1<<endl;
	else
		cout<<"Pattern not found"<<endl;
}

