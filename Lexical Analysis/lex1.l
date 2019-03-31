%{
#include <bits/stdc++.h>
using namespace std;

int cntID;
int cntkey;

vector<string> v;
vector<string> K;

%}

delim [ \t\n]
ws {delim}+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
number {digit}+(\.{digit}+)?
relop <|>|=|==
arithop [+|-|*|/]
lp "("
rp ")"
semicolon ";"
%%

{ws};
int|float|long|double|char {cout << "Data Type: " << yytext << endl; cntID++;}
if|then|return|for|while {
	K.push_back(yytext);
	//cout << "Found keyword: " << yytext << endl; 
	cntkey++;
}
{id} {
	v.push_back(yytext); cntID++;
	//cout << "Found ID: " << yytext << endl; cntID++;
}
{number} {cout << "Found number: " << yytext << endl;}
{relop} {cout << "Found relational operator: " << yytext << endl;}
{lp} {cout << "Found Left Parenthisis: " << yytext << endl;}
{rp} {cout << "Found Right Parenthisis: " << yytext << endl;}
{semicolon} {cout << "Found semicolon: " << yytext << endl;}
{arithop} {cout << "Found arithmatic operator: " << yytext << endl;}
. ;
%%

int yywrap() {
	return 1;
}

int main() {
	freopen("C:\\Users\\CSE\\Desktop\\Lexical Analysis\\file1.txt", "r", stdin);
	freopen("C:\\Users\\CSE\\Desktop\\Lexical Analysis\\file2.txt", "w", stdout);
	yylex();
	cout << "ID List:";
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i = 0; i < (int)v.size(); i++) {
		cout << " " << v[i];
	}
	cout << endl;
	cout << "Keyword List:";
	sort(K.begin(),K.end());
	K.erase(unique(K.begin(),K.end()),K.end());
	for(int i = 0; i < (int)K.size(); i++) {
		cout << " " << K[i];
	}
	cout << endl;
	getchar();
	return 0;
}
