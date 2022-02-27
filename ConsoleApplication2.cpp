//----------------------- PROJECT 7.3 -----------------------// 

#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;


const int MAX_CHARS = 1000;

const int MAX_LINES = 100;

char buffer[MAX_CHARS] = { 0 };
char* lines[MAX_LINES];

ifstream words("textfile.txt");


int main()
{
    int nchars = 0;
    int nlines = 0;

    // read the file
    bool newLine = true;
    for (nchars = 0; nchars < MAX_CHARS; nchars++)
    {
        words.get(buffer[nchars]);

        if (buffer[nchars] == 0)
        {
            // breaks if it reaches file end
            break;
        }

        if (newLine == true)
        {
            if (nlines == MAX_LINES)
            {
                // No more lines can be added, so it breaks

                break;
            }

            if (buffer[nchars] != '\n')
            {
                // set the new line-pointer

                lines[nlines] = &buffer[nchars];
                nlines++;

                newLine = false;
            }
        }

        if (buffer[nchars] == '\n')
        {

            // replace newline with null-terminator

            buffer[nchars] = '\0';

            // next character set on newline

            newLine = true;
        }
    }

    // print lines in basic order
    for (int i = 0; i < nlines; i++)
    {
        if (strlen(lines[i]) == 0)
        {
            // do not print empty lines.
        }
        else
        {
            cout << lines[i] << endl;
        }

    }

    cout << endl;

    // print the lines in reverse
    for (int i = nlines; i >= 1; i--)
    {
        if (strlen(lines[i - 1]) == 0)
        {
            // do not print empty lines.
        }
        else
        {
            cout << lines[i - 1] << endl;
        }

    }
    

    return 0;
}