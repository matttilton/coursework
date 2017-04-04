//Matthew Tilton
//2017-02-17
//TechShell
//Most things work but I could not get redirection to function correctly.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

using namespace std;

//Function promises
int parse();
int startCommand(vector<string> commands, vector<string> tokens);
string trim(std::string const &str);
std::vector<std::string> split(const std::string &text, char sep);
int cd(char **tokens);
int exit();
void pwd();
bool IsBuiltIn(char **tokens);

int main(int argc, char *argv[]) {
   char *command;
   char **arguments;
   bool flag = true;

   while(flag) {
        char buff[500];
        char* cwd;

        cwd = getcwd(buff, 500);
        printf("%s>", cwd);
        flag = parse();

   }
}

int parse() {
    
    string s1;
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
        if (tok != '|' && tok != '<' && tok != '>')
        {
            s2 = s2 + tok;
        }
        else
        {
            svec1.push_back(s2);
            s2 = "";
            s2 = s2 + tok;
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

    // Printing to console. This should be commented but im leaving it here for now so that I can debug this more easily.
    // for (int i = 0; i < svec2.size(); i++)
    // {
    //     cout << i + 1;
    //     cout << ": ";
    //     cout << svec2[i] << endl;
    // }
    // cout << "there are ";
    // cout << svec2.size();
    // cout << " tokens, ";
    // cout << svec1.size();
    // if (svec1.size() == 1)
    // {
    //     cout << " command" << endl;
    // }
    // else
    // {
    //     cout << " commands" << endl;
    // }
    // for (int i = 0; i < svec1.size(); i++)
    // {
    //     cout << '"';
    //     cout << svec1[i];
    //     cout << '"' << endl;
    // }

    return startCommand(svec1, svec2);
}

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

int startCommand(vector<string> commands, vector<string> tokens) 
{
    

    //convert vectors of strings into arrays of characters.
    //got this from somewhere on stackoverflow
    char ** tokarr = new char*[tokens.size()];
    for(size_t i = 0; i < tokens.size(); i++) {
        tokarr[i] = new char[tokens[i].size() + 1];
        strcpy(tokarr[i], tokens[i].c_str());
    }


    char ** comarr = new char*[commands.size()];
    for(size_t i = 0; i < commands.size(); i++) {
        comarr[i] = new char[commands[i].size() + 1];
        strcpy(comarr[i], commands[i].c_str());
    }

    

    if(IsBuiltIn(tokarr)) {
        if(strcmp(tokarr[0], "exit") == 0) {
            return 0;
        }
    } else {
        pid_t pid, waitPid;
        int status;
        

        pid = fork();

        if (pid == 0) {

            

            if (execvp(tokarr[0], tokarr) == -1) {
                perror("techShell");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("Forking error");
        } else {
            do {
                waitPid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 1;
}

int cd(char **tokens) {
    if (tokens[1] == NULL) {
        fprintf(stderr, "techShell: cd needs arguments\n");
    } else {
        if(chdir(tokens[1]) != 0) {
            perror("techShell");
        } else {
            pwd();
        }
    }

    return 1;
}

int exit() {
    return 0;
}

void pwd() {
    char buff[500];
    char* cwd;

    cwd = getcwd(buff, 500);
    if (cwd != NULL) {
        printf("%s\n",cwd);
    }
}

bool IsBuiltIn(char **tokens) {
    if (strcmp(tokens[0], "cd") == 0) {
        cd(tokens);
        return true;
    } else if(strcmp(tokens[0], "exit") == 0) {
        exit();
        return true;
    } else if(strcmp(tokens[0], "pwd") == 0) {
        pwd();
        return true;
    } else {
        return false;
    }
}