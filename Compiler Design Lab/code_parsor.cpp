/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;

class Data
{
private:
  map<string, int> keywords;
  map<string, int> identifiers;
  map<string, int> math_operators;
  map<string, int> logical_operators;
  vector<double> numeric_value;
  map<string, int> other;

public:
  Data()
  {
    keywords.clear();
    identifiers.clear();
    math_operators.clear();
    logical_operators.clear();
    numeric_value.clear();
    other.clear();
  }

  void parse_code( string line )
  {
    stringstream ss(line);
    string word;
    while( ss >> word )
    {
      function< void() > process_word = [&]()
      {
        if( word == "." or word == "," or word == ":" or word == ";" or word == "(" or
            word == ")" or word == "{" or word == "}" or word == "//" or word == "/*" )
        {
          other[word]++;
          return;
        }
        if( word[0] == '.' or word[0] == ',' or word[0] == ';' or
            word[0] == '+' or word[0] == '-' or word[0] == '/' or
            word[0] == '*' or word[0] == '=' )
        {
          other[word.substr(0, 1)]++;
          word = word.substr(1);
        }
        if( word.back() == '.' or word.back() == ',' or word.back() == ';' or
            word.back() == '+' or word.back() == '-' or word.back() == '/' or
            word.back() == '*' or word.back() == '=' )
        {
          int ln = word.size();
          other[word.substr(ln - 1)]++;
          word = word.substr(0, ln - 1);
        }
        if( word[0] >= '0' and word[0] <= '9' )
        {
          stringstream ssn(word);
          double num;
          ssn >> num;
          numeric_value.push_back(num);
          return;
        }
        other[word]++;
      };
      process_word();
    }
  }

  void final_process()
  {
    string tmp = "int";
    if( other.find(tmp) != other.end() )
    {
      keywords[tmp]++;
      other.erase(tmp);
    }
    tmp = "if";
    if( other.find(tmp) != other.end() )
    {
      keywords[tmp]++;
      other.erase(tmp);
    }
    tmp = "else";
    if( other.find(tmp) != other.end() )
    {
      keywords[tmp]++;
      other.erase(tmp);
    }
    tmp = "float";
    if( other.find(tmp) != other.end() )
    {
      keywords[tmp]++;
      other.erase(tmp);
    }
    tmp = "double";
    if( other.find(tmp) != other.end() )
    {
      keywords[tmp]++;
      other.erase(tmp);
    }
    tmp = "for";
    if( other.find(tmp) != other.end() )
    {
      keywords[tmp]++;
      other.erase(tmp);
    }
    tmp = "while";
    if( other.find(tmp) != other.end() )
    {
      keywords[tmp]++;
      other.erase(tmp);
    }


    tmp = "+";
    if( other.find(tmp) != other.end() )
    {
      math_operators[tmp]++;
      other.erase(tmp);
    }
    tmp = "-";
    if( other.find(tmp) != other.end() )
    {
      math_operators[tmp]++;
      other.erase(tmp);
    }
    tmp = "/";
    if( other.find(tmp) != other.end() )
    {
      math_operators[tmp]++;
      other.erase(tmp);
    }
    tmp = "*";
    if( other.find(tmp) != other.end() )
    {
      math_operators[tmp]++;
      other.erase(tmp);
    }
    tmp = "=";
    if( other.find(tmp) != other.end() )
    {
      math_operators[tmp]++;
      other.erase(tmp);
    }

    tmp = "<";
    if( other.find(tmp) != other.end() )
    {
      logical_operators[tmp]++;
      other.erase(tmp);
    }
    tmp = ">";
    if( other.find(tmp) != other.end() )
    {
      logical_operators[tmp]++;
      other.erase(tmp);
    }
    tmp = "==";
    if( other.find(tmp) != other.end() )
    {
      logical_operators[tmp]++;
      other.erase(tmp);
    }
    tmp = "<=";
    if( other.find(tmp) != other.end() )
    {
      logical_operators[tmp]++;
      other.erase(tmp);
    }
    tmp = ">=";
    if( other.find(tmp) != other.end() )
    {
      logical_operators[tmp]++;
      other.erase(tmp);
    }

    vector<string> have;
    for(auto it = other.begin(); it != other.end(); it++)
    {
      tmp = it -> first;
      if( tmp == "." or tmp == "," or tmp == ";" or tmp == "(" or tmp == ")" or
          tmp == "{" or tmp == "}" )
      {
        continue;
      }
      have.push_back(tmp);
    }

    for(auto& s : have)
    {
      other.erase(s);
      identifiers[s]++;
    }
  }

  void show_result()
  {
    final_process();

    cout << "Keywords: ";
    for(auto it = keywords.begin(); it != keywords.end(); it++)
    {
      cout << it -> first << " ";
    }
    cout << endl;
    cout << "Identifiers: ";
    for(auto it = identifiers.begin(); it != identifiers.end(); it++)
    {
      cout << it -> first << " ";
    }
    cout << endl;
    cout << "Math Operators: ";
    for(auto it = math_operators.begin(); it != math_operators.end(); it++)
    {
      cout << it -> first << " ";
    }
    cout << endl;
    cout << "Logical Operators: ";
    for(auto it = logical_operators.begin(); it != logical_operators.end(); it++)
    {
      cout << it -> first << " ";
    }
    cout << endl;
    cout << "Numerical Values: ";
    for(auto& d : numeric_value)
    {
      cout << d << " ";
    }
    cout << endl;
    cout << "Others: ";
    for(auto it = other.begin(); it != other.end(); it++)
    {
      cout << it -> first << " ";
    }
    cout << endl;
  }
};

int main()
{
  freopen("input.txt", "r", stdin);
  Data data = Data();
  string line;
  while( getline(cin, line) )
  {
      data.parse_code( line );
  }
  data.show_result();
  return 0;
}
