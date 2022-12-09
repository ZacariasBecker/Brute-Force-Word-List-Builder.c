
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

long int listSize()
{
    ifstream in("list.txt", ifstream::ate | ifstream::binary);
    return in.tellg();
}

void showSize()
{
    cout << "File size: " << listSize() << " bytes.\n";
    cout << "File size: " << listSize() / 1024 << " kb.\n";
    cout << "File size: " << listSize() / 1048576 << " mb.\n";
    cout << "File size: " << listSize() / 1073741824 << " gb.\n";
}

int main()
{
    bool start = false;
    char startSelector;

    printf("\n--- WordList Generator [8 char] ---\n");
    printf("     Generate now? [y/N]: ");
    scanf("%c", &startSelector);
    start = (startSelector == 'y' || startSelector == 'Y');

    printf("\n");

    if (start)
    {
        //
        remove("list.txt");
        ofstream outfile;
        outfile.open("list.txt", ios_base::app);
        //

        int alfaSize = 36;
        char alfa[alfaSize] = {
            '0',
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
            '9',
            'a',
            'b',
            'c',
            'd',
            'e',
            'f',
            'g',
            'h',
            'i',
            'j',
            'k',
            'l',
            'm',
            'n',
            'o',
            'p',
            'q',
            'r',
            's',
            't',
            'u',
            'v',
            'w',
            'x',
            'y',
            'z'};

        long int cont = 0;
        long int currentPercent;
        long int sizeOfLib = pow(alfaSize, 8);

        for (int i1 = 0; i1 < alfaSize; i1++)
        {
            for (int i2 = 0; i2 < alfaSize; i2++)
            {
                for (int i3 = 0; i3 < alfaSize; i3++)
                {
                    for (int i4 = 0; i4 < alfaSize; i4++)
                    {
                        for (int i5 = 0; i5 < alfaSize; i5++)
                        {
                            for (int i6 = 0; i6 < alfaSize; i6++)
                            {
                                for (int i7 = 0; i7 < alfaSize; i7++)
                                {
                                    for (int i8 = 0; i8 < alfaSize; i8++)
                                    {
                                        // GB 1073741824
                                        // 20 GB 21474836480
                                        if (listSize() >= 21474836480)
                                            goto endWordListMaker;

                                        system("clear");

                                        ++cont;
                                        showSize();
                                        currentPercent = (100 * cont) / sizeOfLib;
                                        printf("[%ld/%ld] | %ld%%\n", cont, sizeOfLib, currentPercent);

                                        outfile << alfa[i1] << alfa[i2] << alfa[i3] << alfa[i4] << alfa[i5] << alfa[i6] << alfa[i7] << alfa[i8] << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    endWordListMaker:
        printf("\n*** Done! ***\n");
        showSize();
    }
    else
    {
        printf("Exiting...\n\n");
    }

    return 0;
}