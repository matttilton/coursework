//Matthew Tilton
//2-7-2017

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//Some code for triming whitespace off of strings that I found
string trim(std::string const &str)
{
    if (str.empty())
        return str;

    size_t firstScan = str.find_first_not_of(' ');
    size_t first = firstScan == std::string::npos ? str.length() : firstScan;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

//Some code that I found that splits strings on a specified delimiter
std::vector<std::string> split(const std::string &text, char sep)
{
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos)
    {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

int main()
{
    string s1;
    cout << "please enter a string: ";
    getline(cin, s1);
    //counts tokens
    int c1 = 0;

    //counts commands
    int c2 = 0;

    string s2;

    //stores tokens
    vector<string> svec1;

    //Parse string for different commands
    for (int i = 0; i < s1.length(); i++)
    {
        char tok = s1[i];
        if (tok != '|')
        {
            s2 = s2 + tok;
        }
        else
        {
            svec1.push_back(s2);
            s2 = "";
            c2++;
        }
    }

    //Catch the last command
    svec1.push_back(s2);
    s2 = "";
    c2++;

    //Parse commands for tokens
    //counter for token
    int c3 = 0;

    vector<string> svec2;

    //Iterate over all found commands
    for (int i = 0; i < svec1.size(); i++)
    {
        //split on tabs and iterate of returned std::vector
        svec1[i] = trim(svec1[i]);
        vector<string> svec3 = split(svec1[i], '\t');
        for (int j = 0; j < svec3.size(); j++)
        {
            //split on spaces and put the result into svec2
            vector<string> svec4 = split(svec3[j], ' ');
            for (int k = 0; k < svec4.size(); k++)
            {
                svec2.push_back(svec4[k]);
            }
        }
    }

    //Printing to console
    for (int i = 0; i < svec2.size(); i++)
    {
        cout << i + 1;
        cout << ": ";
        cout << svec2[i] << endl;
    }
    cout << "there are ";
    cout << svec2.size();
    cout << " tokens, ";
    cout << svec1.size();
    if (svec1.size() == 1)
    {
        cout << " command" << endl;
    }
    else
    {
        cout << " commands" << endl;
    }
    for (int i = 0; i < svec1.size(); i++)
    {
        cout << '"';
        cout << svec1[i];
        cout << '"' << endl;
    }
}