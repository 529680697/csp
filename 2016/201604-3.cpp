#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int p;
string cur_path; //��ǰ·��
string tmp;      //��Ҫ���滯��·��

void erase1() //ɾ������� /
{
    for (int i = 0; i < tmp.size(); i++)
        if (tmp[i] == '/')
            while (i + 1 < tmp.size() && tmp[i + 1] == '/')
                tmp.erase(i + 1, 1);
    if (tmp.empty()) //��·������Ϊ��ǰ·��
        tmp = cur_path;
    if (tmp[tmp.size() - 1] != '/') //ȷ����б�ܽ�β
        tmp.append("/");
    if (tmp[0] != '/') //���·�����ڵ�ǰ·����
        tmp.insert(0, cur_path + "/");
    // cout << tmp << endl;
}

void del_point() //ȥ�� .. �� .
{
    int pos1 = 0;
    while ((pos1 = tmp.find("/./")) != string::npos) //ȥ�� .
    {
        tmp.replace(pos1, 3, "/");
    }
    while ((pos1 = tmp.find("/../")) != string::npos) //ȥ�� ..
    {
        if (pos1 == 0) //��һ��Ϊ���ڵ�
        {
            tmp.replace(pos1, 4, "/");
        }
        else
        {
            int i;
            for (i = pos1 - 1; tmp[i] != '/'; i--)
                ;
            // cout << pos1 << "  " << i << endl;
            tmp.erase(i, pos1 + 3 - i);
        }
    }
    if (tmp.size() != 1)
        tmp.erase(tmp.size() - 1, 1);
}

int main()
{
    cin >> p >> cur_path;
    getchar();
    for (int i = 0; i < p; i++)
    {
        getline(cin, tmp);
        erase1();
        del_point();
        cout << tmp << endl;
    }

    return 0;
}