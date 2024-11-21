#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

const int MXN = 100;

boolean isValid(int x, int y, int N, char arr[MXN][MXN], boolean visited[MXN][MXN])
{
    return (x >= 0 && x < N && y >= 0 && y < N && arr[x][y] != '#' && !visited[x][y]);
}

int main()
{
    int N;
    char arr[MXN][MXN];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &arr[i][j]);
        }
    }

    int startX, startY, endX, endY;
    boolean visited[MXN][MXN];
    int dist[MXN][MXN];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
            dist[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
            else if (arr[i][j] == 'B')
            {
                endX = i;
                endY = j;
            }
        }
    }

    Queue q;
    CreateQueue(&q);

    ElType startNode;
    startNode.row = startX;
    startNode.col = startY;
    enqueue(&q, startNode);
    visited[startX][startY] = true;

    boolean found = false;

    while (!isEmpty(q))
    {
        ElType current;
        dequeue(&q, &current);

        if (current.row == endX && current.col == endY)
        {
            printf("Ya\n%d\n", dist[current.row][current.col]);
            found = true;
            break;
        }

        // Cek gerak ke bawah
        if (isValid(current.row, current.col + 1, N, arr, visited))
        {
            visited[current.row][current.col + 1] = true;
            ElType newNode;
            newNode.row = current.row;
            newNode.col = current.col + 1;
            dist[newNode.row][newNode.col] = dist[current.row][current.col] + 1;
            enqueue(&q, newNode);
        }

        // Cek gerak ke atas
        if (isValid(current.row, current.col - 1, N, arr, visited))
        {
            visited[current.row][current.col - 1] = true;
            ElType newNode;
            newNode.row = current.row;
            newNode.col = current.col - 1;
            dist[newNode.row][newNode.col] = dist[current.row][current.col] + 1;
            enqueue(&q, newNode);
        }

        // Cek gerak ke kenan
        if (isValid(current.row + 1, current.col, N, arr, visited))
        {
            visited[current.row + 1][current.col] = true;
            ElType newNode;
            newNode.row = current.row + 1;
            newNode.col = current.col;
            dist[newNode.row][newNode.col] = dist[current.row][current.col] + 1;
            enqueue(&q, newNode);
        }

        // Cek gerak ke kiri
        if (isValid(current.row - 1, current.col, N, arr, visited))
        {
            visited[current.row - 1][current.col] = true;
            ElType newNode;
            newNode.row = current.row - 1;
            newNode.col = current.col;
            dist[newNode.row][newNode.col] = dist[current.row][current.col] + 1;
            enqueue(&q, newNode);
        }
    }

    if (!found)
    {
        printf("Tidak\n");
    }

    return 0;
}