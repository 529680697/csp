#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

struct option
{
    char p;         //����ѡ��
    bool have_prim; //���޲������
} op[30];
typedef struct result
{
    char p;         //����ѡ��
    bool have_prim; //���޲������
    char prim[256]; //����
} result;

int op_num = 0; //����ѡ�����

int inOption(char *s) //�ж�s�Ƿ�Ϊ�Ϸ�����ѡ�� 0:�Ƿ�  1:�޲�  2:�в�
{
    if (strlen(s) == 2 && s[0] == '-')
    {
        for (int i = 0; i < op_num; i++)
        {
            if (op[i].p == s[1])
            {
                if (op[i].have_prim)
                    return 2;
                else
                    return 1;
            }
        }
        return 0;
    }
    else
    {
        return 0;
    }
}

bool cmp(result x, result y)
{
    return x.p < y.p;
}

int main()
{
    char c;
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        if (c == ':')
        {
            op[--i].have_prim = 1; //��ʾ�ϸ��ַ������в����ַ�
        }
        else
        {
            op[i].p = c;
            op_num++;
        }
    }
    // for (int i = 0; i < prim_num; i++)
    // {
    //     cout << op[i].p << " " << op[i].have_prim << endl;
    // }
    int n;
    char s[300], t_p[256];
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++)
    {

        gets(s);
        // puts(s);
        if (sscanf(s, "%s %[^\n]", t_p, s) == 1)
        {
            cout << "Case " << i << ": " << endl;
            // cout << t_p << " --- " << s << endl;
            continue;
        }
        map<char, string> mp;
        bool rec_flag = 0; //��ǰ��Ҫ���յ��������ͣ�����ѡ�0��������1
        char temp_p;
        while (sscanf(s, "%s %[^\n]", t_p, s) != 1)
        {
            // cout << t_p << " --- " << s << endl;
            if (!rec_flag) //��ǰ��Ҫ���ղ���ѡ��
            {
                int ret = inOption(t_p);
                if (ret == 1) //Ϊ�Ϸ��޲β���ѡ��
                {
                    mp[t_p[1]] = "";
                }
                else if (ret == 2) //Ϊ�Ϸ��вβ���ѡ��
                {
                    temp_p = t_p[1];
                    // mp[t_p[1]] = "";
                    rec_flag = 1;
                }
                else //����ѡ��Ϸ�
                {
                    break;
                }
            }
            else //��ǰ��Ҫ���ղ���
            {
                mp[temp_p] = t_p;
                rec_flag = 0;
            }
        }
        // cout << t_p << " --- " << s << endl;
        if (!rec_flag) //��ǰ��Ҫ���ղ���ѡ��
        {
            int ret = inOption(t_p);
            if (ret == 1) //Ϊ�Ϸ��޲β���ѡ��
            {
                mp[t_p[1]] = "";
            }
            else if (ret == 2) //Ϊ�Ϸ��вβ���ѡ��
            {
                temp_p = t_p[1];
                // mp[t_p[1]] = "";
                rec_flag = 1;
            }
        }
        else //��ǰ��Ҫ���ղ���
        {
            mp[temp_p] = t_p;
            rec_flag = 0;
        }
        cout << "Case " << i << ":";
        map<char, string>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == "")
                cout << " -" << it->first;
            else
                cout << " -" << it->first << " " << it->second;
        }
        cout << endl;
    }
    return 0;
}