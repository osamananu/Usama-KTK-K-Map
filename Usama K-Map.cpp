#include <iostream>
#include <string>
using namespace std;

void addExpression3(int row, int col, string* exprArray)
{
    string terms[2][4] = {{"A'B'C'", "A'B'C", "A'BC", "A'BC'"}, {"AB'C'", "AB'C", "ABC", "ABC'"}};
    for (int i = 0; i < 8; i++)
    {
        if (*(exprArray + i) == "")
        {
            *(exprArray + i) = terms[row][col];
            break;
        }
    }
}

void display3VarBit(int termCount, int* minterms, int* bitCounter, int row, int col, string* exprArray)
{
    int found = 0;
    for (int k = 0; k < termCount; k++)
    {
        if (*(minterms + k) == *bitCounter)
        {
            cout << 1;
            found = 1;
            addExpression3(row, col, exprArray);
            break;
        }
    }
    if (!found)
    {
        cout << 0;
    }
    *bitCounter += 1;
}

void addExpression4(int row, int col, string* exprArray)
{
    string terms[4][4] = {{"A'B'C'D'", "A'B'C'D", "A'B'CD", "A'B'CD'"},
                          {"A'BC'D'", "A'BC'D", "A'BCD", "A'BCD'"},
                          {"ABC'D'", "ABC'D", "ABCD", "ABCD'"},
                          {"AB'C'D'", "AB'C'D", "AB'CD", "AB'CD'"}};
    for (int i = 0; i < 16; i++)
    {
        if (*(exprArray + i) == "")
        {
            *(exprArray + i) = terms[row][col];
            break;
        }
    }
}

void display4VarBit(int termCount, int* minterms, int* bitCounter, int row, int col, string* exprArray)
{
    int found = 0;
    for (int k = 0; k < termCount; k++)
    {
        if (*(minterms + k) == *bitCounter)
        {
            cout << 1;
            found = 1;
            addExpression4(row, col, exprArray);
            break;
        }
    }
    if (!found)
    {
        cout << 0;
    }
    *bitCounter += 1;
}

void addExpression5(int row, int col, string* exprArray)
{
    string terms[4][8] = {{"A'B'C'D'E'", "A'B'C'D'E", "A'B'C'DE", "A'B'C'DE'", "A'B'CD'E'", "A'B'CD'E", "A'B'CDE", "A'B'CDE'"},
                          {"A'BC'D'E'", "A'BC'D'E", "A'BC'DE", "A'BC'DE'", "A'BCD'E'", "A'BCD'E", "A'BCDE", "A'BCDE'"},
                          {"ABC'D'E'", "ABC'D'E", "ABC'DE", "ABC'DE'", "ABCD'E'", "ABCD'E", "ABCDE", "ABCDE'"},
                          {"AB'C'D'E'", "AB'C'D'E", "AB'C'DE", "AB'C'DE'", "AB'CD'E'", "AB'CD'E", "AB'CDE", "AB'CDE'"}};
    for (int i = 0; i < 32; i++)
    {
        if (*(exprArray + i) == "")
        {
            *(exprArray + i) = terms[row][col];
            break;
        }
    }
}

void display5VarBit(int termCount, int* minterms, int* bitCounter, int row, int col, string* exprArray)
{
    int found = 0;
    for (int k = 0; k < termCount; k++)
    {
        if (*(minterms + k) == *bitCounter)
        {
            cout << 1;
            found = 1;
            addExpression5(row, col, exprArray);
            break;
        }
    }
    if (!found)
    {
        cout << 0;
    }
    *bitCounter += 1;
}

void printFinalExpression(string* exprArray, int exprSize)
{
    bool isFirst = true;
    for (int i = 0; i < exprSize; i++)
    {
        if (*(exprArray + i) != "")
        {
            if (!isFirst)
            {
                cout << " + ";
            }
            cout << *(exprArray + i);
            isFirst = false;
        }
    }
    cout << endl;
}

void processRow(int* bitCounter, int termCount, int mapChoice, int row, string* exprArray, int* minterms)
{
    int colCount = (mapChoice == 3) ? 8 : 4;
    for (int col = 0; col < colCount; col++)
    {
        if (col == 2 || col == 6)
        {
            *bitCounter += 1;
        }
        else if (col == 3 || col == 7)
        {
            *bitCounter -= 1;
        }

        if (mapChoice == 1)
        {
            display3VarBit(termCount, minterms, bitCounter, row, col, exprArray);
        }
        else if (mapChoice == 2)
        {
            display4VarBit(termCount, minterms, bitCounter, row, col, exprArray);
        }
        else if (mapChoice == 3)
        {
            display5VarBit(termCount, minterms, bitCounter, row, col, exprArray);
        }

        if (col == 2 || col == 6)
        {
            *bitCounter -= 1;
        }
        else if (col == 3 || col == 7)
        {
            *bitCounter += 1;
        }

        cout << "   ";
        if (mapChoice == 3)
        {
            cout << " ";
        }
    }
}

int main()
{
    int mapChoice;
    cout << "Enter 1 for 3 variables K-map, 2 for 4 variables K-map, 3 for 5 variables K-map: ";
    cin >> mapChoice;

    int termCount;
    cout << "Enter the number of minterms you want to enter: ";
    cin >> termCount;

    int minterms[termCount];
    for (int i = 0; i < termCount; i++)
    {
        cout << "Enter the value of " << i + 1 << " minterm: ";
        cin >> minterms[i];
    }

    int exprSize = 32;
    string exprArray[exprSize];
    for (int i = 0; i < exprSize; i++)
    {
        exprArray[i] = "";
    }

    int bitCounter = 0;

    if (mapChoice == 1)
    {
        cout << "\n BC  00  01  11  10\nA\n\n";
        for (int row = 0; row < 2; row++)
        {
            cout << row << "     ";
            processRow(&bitCounter, termCount, mapChoice, row, exprArray, minterms);
            cout << endl;
        }
    }
    else if (mapChoice == 2)
    {
        cout << "\n  CD  00  01  11  10\nAB\n\n";
        for (int row = 0; row < 4; row++)
        {
            if (row == 0)
                cout << "00     ";
            else if (row == 1)
                cout << "01     ";
            else if (row == 2)
                cout << "11     ";
            else if (row == 3)
                cout << "10     ";

            if (row == 3)
                bitCounter -= 4;
            else if (row == 2)
                bitCounter += 4;

            processRow(&bitCounter, termCount, mapChoice, row, exprArray, minterms);

            if (row == 3)
                bitCounter += 4;
            else if (row == 2)
                bitCounter -= 4;

            cout << endl;
        }
    }
    else if (mapChoice == 3)
    {
        cout << "\n  CDE  000  001  011  010  100  101  111  110\nAB\n\n";
        for (int row = 0; row < 4; row++)
        {
            if (row == 0)
                cout << "00      ";
            else if (row == 1)
                cout << "01      ";
            else if (row == 2)
                cout << "11      ";
            else if (row == 3)
                cout << "10      ";

            if (row == 3)
                bitCounter -= 4;
            else if (row == 2)
                bitCounter += 4;

            processRow(&bitCounter, termCount, mapChoice, row, exprArray, minterms);

            if (row == 3)
                bitCounter += 4;
            else if (row == 2)
                bitCounter -= 4;

            cout << endl;
        }
    }

    printFinalExpression(exprArray, exprSize);

    return 0;
}

