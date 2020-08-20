#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int x, y, num;
} no;

int n, m, k, d;
int f[1010][1010];
long long ans;
vector<node> end1; //����ŵ�Ϳͻ�λ��
queue<node> q;

inline bool canUp(int x, int y) //���Ը�������һ��λ��
{
    if (x > 1 && f[x - 1][y] > f[x][y] + 1)
        return 1;
    else
        return 0;
}

inline bool canDown(int x, int y) //���Ը�������һ��λ��
{
    if (x < n && f[x + 1][y] > f[x][y] + 1)
        return 1;
    else
        return 0;
}
inline bool canLeft(int x, int y) //���Ը������һ��λ��
{
    if (y > 1 && f[x][y - 1] > f[x][y] + 1)
        return 1;
    else
        return 0;
}
inline bool canRight(int x, int y) //���Ը����ұ�һ��λ��
{
    if (y < n && f[x][y + 1] > f[x][y] + 1)
        return 1;
    else
        return 0;
}

void refush() //���¾�����Ϣ
{
    node st, now, next_node;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (canUp(now.x, now.y))
        {
            next_node.x = now.x - 1;
            next_node.y = now.y;
            f[next_node.x][next_node.y] = f[now.x][now.y] + 1; //���¾���
            q.push(next_node);
        }
        if (canDown(now.x, now.y))
        {
            next_node.x = now.x + 1;
            next_node.y = now.y;
            f[next_node.x][next_node.y] = f[now.x][now.y] + 1; //���¾���
            q.push(next_node);
        }
        if (canLeft(now.x, now.y))
        {
            next_node.x = now.x;
            next_node.y = now.y - 1;
            f[next_node.x][next_node.y] = f[now.x][now.y] + 1; //���¾���
            q.push(next_node);
        }
        if (canRight(now.x, now.y))
        {
            next_node.x = now.x;
            next_node.y = now.y + 1;
            f[next_node.x][next_node.y] = f[now.x][now.y] + 1; //���¾���
            q.push(next_node);
        }
    }
}

int main()
{
    cin >> n >> m >> k >> d;
    int x, y, num;
    // fill(f, f + (1010 * 1010), INF);
    for (int i = 0; i < 1010; i++)
    {
        fill(f[i], f[i] + 1010, INF);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &no.x, &no.y);
        // start.push_back(no);
        q.push(no);
        f[no.x][no.y] = 0; //����λ��
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &no.x, &no.y, &no.num);
        end1.push_back(no);
    }
    for (int i = 0; i < d; i++)
    {
        scanf("%d%d", &x, &y);
        f[x][y] = -1; //���ɾ���
    }
    refush();
    for (vector<node>::iterator it = end1.begin(); it != end1.end(); it++)
    {
        ans += (long long)(f[it->x][it->y] * it->num);
    }
    cout << ans << endl;
    return 0;
}