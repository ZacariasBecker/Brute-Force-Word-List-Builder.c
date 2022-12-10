
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

long int totalListSize(long int cont, int alfaSize);
long int currentListSize();
long int remainingListSize(long int cont, int alfaSize);
double totalTime(long int cont, int alfaSize, clock_t timer);
double currentTime(clock_t timer);
double remainingTime(long int cont, int alfaSize, clock_t timer);
int currentProgress(long int cont, int alfaSize);
long int totalListWords(int alfaSize);
void showStatus(int alfaSize, long int cont, clock_t timer);

long int totalListSize(long int cont, int alfaSize)
{
    long int totalListSize = (100 * currentListSize()) / currentProgress(cont, alfaSize);
    return totalListSize;
}

long int currentListSize()
{
    ifstream in("list.txt", ifstream::ate | ifstream::binary);
    return in.tellg();
}

long int remainingListSize(long int cont, int alfaSize)
{
    long int remainingListSize = totalListSize(cont, alfaSize) - currentListSize();
    return remainingListSize;
}

double totalTime(long int cont, int alfaSize, clock_t timer)
{
    double totalTime = (100 * currentTime(timer)) / currentProgress(cont, alfaSize);
    return totalTime;
}

double currentTime(clock_t timer)
{
    double currentTime = (clock() - timer) / (double)CLOCKS_PER_SEC;
    return currentTime;
}

double remainingTime(long int cont, int alfaSize, clock_t timer)
{
    long int remainingTime = totalTime(cont, alfaSize, timer) - currentTime(timer);
    return remainingTime;
}

int currentProgress(long int cont, int alfaSize)
{
    int currentPercent = (100 * cont) / totalListWords(alfaSize);
    return currentPercent;
}

long int totalListWords(int alfaSize)
{
    long int totalListWords = pow(alfaSize, 8);
    return totalListWords;
}

void showStatus(int alfaSize, long int cont, clock_t timer)
{
    long int varCurrentListSize = currentListSize();
    long int varTotalListWords = totalListWords(alfaSize);
    int varCurrentProgress = currentProgress(cont, alfaSize);

    cout << "File size: " << varCurrentListSize << " bytes.\n";
    cout << "File size: " << varCurrentListSize / 1024 << " kb.\n";
    cout << "File size: " << varCurrentListSize / 1048576 << " mb.\n";
    cout << "File size: " << varCurrentListSize / 1073741824 << " gb.\n";

    printf("Progress: [%ld/%ld] | %d%%\n", cont, varTotalListWords, varCurrentProgress);

    printf("Total time: %.2lfs\n", totalTime(cont, alfaSize, timer));
    printf("Current time: %.2lfs\n", currentTime(timer));
    printf("Remaining time: %.2lfs\n", remainingTime(cont, alfaSize, timer));
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
        remove("list.txt");
        ofstream outfile;
        outfile.open("list.txt", ios_base::app);

        long int cont = 0;
        int alfaSize = 3;
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

        clock_t timer = clock();

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
                                        if (currentListSize() >= 21474836480)
                                            goto endWordListMaker;

                                        system("cls");
                                        // system("clear");

                                        ++cont;

                                        showStatus(alfaSize, cont, timer);

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
    }
    else
    {
        printf("Exiting...\n\n");
    }

    return 0;
}