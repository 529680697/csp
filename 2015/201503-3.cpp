#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c, y_1, y_2;
int mouth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_runnian(int y) //�����ж�
{
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

int mou(int y, int m) //����y��m�µ�����
{
    if (m == 2 && check_runnian(y))
        return 29;
    else
        return mouth[m];
}

int count_day(int y, int m) //����y��m��1�����ܼ�
{
    int count = 0;
    for (int i = 1850; i < y; i++)
    {
        if (check_runnian(i))
            count += 366;
        else
            count += 365;
    }
    for (int i = 1; i < m; i++)
    {
        count += mouth[i];
    }
    if (m > 2 && check_runnian(y))
        count++;
    return (count + 1) % 7 + 1;
}

int main()
{
    cin >> a >> b >> c >> y_1 >> y_2;
    int tmp_day = 0;
    for (int y = y_1; y <= y_2; y++)
    {
        // cout << count_day(y, a) << endl;
        int day_1 = count_day(y, a); //ÿһ���a�������ܼ�
        if (day_1 <= c)              //��һ�ܰ�������c
        {
            tmp_day = c - day_1 + 1;
            tmp_day += (b - 1) * 7;
        }
        else //��һ�ܲ���������c
        {
            tmp_day = c + 8 - day_1;
            tmp_day += (b - 1) * 7;
        }
        if (tmp_day > mou(y, a))
            printf("none\n");
        else
            printf("%d/%02d/%02d\n", y, a, tmp_day);
    }
    return 0;
}