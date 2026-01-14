#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the no of rows and columns : ";
    int nRows, mCols;
    cin >> nRows >> mCols;
    int arr[nRows][mCols];
    cout << "Enter the elements of matrix : \n";
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            cin>> arr[i][j];
        }
        
    }
    cout<<"Printing... \n";
    for (int j = 0; j < mCols; j++)
    {
        if (j % 2 == 0)
        {
            int i = 0;
            while (i < nRows)
            {
                cout << arr[i][j] << " ";
                i++;
            }
        }
        else
        {
            int i = nRows - 1;
            while (i >= 0)
            {
                cout << arr[i][j] << " ";
                i--;
            }
        }
    }
    return 0;
}