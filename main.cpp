/*
 * Assignment-1 OOP
 * Sara Tamer Bihery - 20210155 - Group-B
 *Presented to: Dr. Mohamed El-Ramly
 * Task-2 , Sheet-1 , Problem-9
 *
*/
#include <bits/stdc++.h>

using namespace std;

void fileComparison(string n1, string n2, char ch);

int main() {
    string name1 , name2;
    char choice;
    cout << "Please enter the first file's name : \n";
    cin >> name1 ;
    cout << "Please enter the second file's name: \n";
    cin >> name2;
    cout << "If you want word by word comparison enter 'w'\n"
            "If you want character by character comparison enter 'c'\n";
    cin >> choice;
    fileComparison(name1, name2, choice);
    return 0;
}
void fileComparison(string n1,string n2 , char ch) {
    fstream myFile1, myFile2;
    string temp;
    int s = 0;
    vector<string> lines1, lines2 , words1, words2;
    char text1[100], text2[100];
    bool b = true;

    myFile1.open(n1, fstream::in);
    myFile2.open(n2, fstream::in);

    while (!myFile1.eof()) {
        myFile1.getline(text1, 100, '\n');
        lines1.push_back(string(text1));
    }
    while (!myFile2.eof()) {
        myFile2.getline(text2, 100, '\n');
        lines2.push_back(string(text2));
    }

    if (ch == 'c') {
        for (int i = 0; i < lines1.size(); i++)
        {
            for (int j = 0; j < lines1[i].size(); j++)
            {
                if (lines2[i][j] != lines1[i][j])
                {
                    cout << "The files are different at line: " << i << "\nwhich is: \"";
                    for (int k = 0; k < lines1[i].size(); k++)
                    {
                        cout << lines1[i][k];
                    }
                    cout << "\"\n";
                    b = false;
                    break;
                }
            }
            if (!b) {
                break;
            }
        }
        if(b){
            cout << "The two files are identical.\n";
        }
    }
    else
    {
        myFile2.close();
        myFile1.close();
        myFile1.open(n1, fstream::in);
        myFile2.open(n2, fstream::in);
        while (myFile1 >> temp)
        {
            words1.push_back(temp);
            s++;
        }
        s = 0;
        while (myFile2 >> temp)
        {
            words2.push_back(temp);
            s++;
        }
        for (int i = 0; i < words1.size(); i++)
        {
                if(words1[i] != words2[i])
                {
                    cout << "The files are different at the line \"";
                    for (int k = 0; k < lines1.size(); k++)
                    {
                        if (lines1[k].find(words1[i]) != string::npos)
                        {
                            cout << lines1[k] ;
                        }
                    }
                    cout << "\"\n";
                    b = false;
                    break;
                }
            }
        }
        if(b)
        {
            cout << "The two files are identical.\n";
        }
}