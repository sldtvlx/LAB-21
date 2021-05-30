#include <iostream>
#include <vector>
#include <windows.h>
#include <queue>
#include <algorithm>
using namespace std;
int x;
int len = 6;
int result[6] = { 1000,1000,1000,1000,1000,1000 };
bool flag[6] = { false,false,false,false,false,false };
vector <vector<int>> matrix = { {0 ,4 ,0 ,0 ,8 ,0 },
                                 {0 ,0 ,15,9 ,0 ,0 },
                                 {0 ,15,0 ,0 ,12,0 },
                                  {0 ,0 ,0 ,0 ,0 ,11},
                                  {0 ,23,12,0 ,0 ,0 },
                                  {0 ,0 ,6 ,0 ,0 ,0 } };
bool comp(int a, int b)
{
    return matrix[x][a] < matrix[x][b];
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    queue <int> QUEUE;
    cout << "������� ��������� ������� (1<=x<=" << len << ")\n";
    cin >> x;
    x--;
    result[x] = 0;
    QUEUE.push(x);
    while (true)
    {
        x = QUEUE.front();
        vector <int> vec;
        for (int i = 0; i < len; i++) if (matrix[x][i] != 0 && !flag[i]) vec.push_back(i);
        if (vec.size() == 0)
        {
            flag[x] = true;
            QUEUE.pop();
            if (QUEUE.size() == 0) break;
            continue;
        }
        sort(vec.begin(), vec.end(), comp);
        for (int i = 0; i < vec.size(); i++)
        {
            result[vec[i]] = min(result[vec[i]], matrix[x][vec[i]] + result[x]);
            QUEUE.push(vec[i]);
        }
        flag[x] = true;
        QUEUE.pop();
        if (QUEUE.size() == 0) break;
    }
    cout << "���������� ����:\n";
    for (int i = 0; i < len; i++)
    {
        if (result[i] == 1000) cout << i + 1 << " - ����������\n";
        else cout << i + 1 << " - " << result[i] << endl;
    }
    system("pause");
}
