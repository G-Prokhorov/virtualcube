void mx_printchar(char c);

void printSpace(int end)
{
    for (int s = 0; s < end; s++)
    {
        mx_printchar(' ');
    }
}

void printEdge_1(int bool1, int bool2)
{
    if (bool1)
    {
        mx_printchar('+');
    }
    else if (bool2)
    {
        mx_printchar('/');
    }
    else
    {
        mx_printchar('|');
    }
}

void printEdge_2(int i, int n, int height)
{
    for (int j = 0; j < n * 2; j++)
    {
        if (i == 0 || i == n / 2 + 1 || i == height - 1)
        {
            mx_printchar('-');
        }
        else
        {
            mx_printchar(' ');
        }
    }
}

void mx_cube(int n)
{
    int spaceStart = n / 2 + 1;
    int height = n + n / 2 + 3;
    for (int i = 0; i < height; i++)
    {
        int spaceBefore = spaceStart - i;
        int tmp = spaceBefore < 0 ? 0 : spaceBefore;
        int spaceAfter = (i <= height - n / 2 - 2) ? spaceStart - tmp - 1 : height - i - 2;

        printSpace(spaceBefore);
        printEdge_1((i == 0 || i == n / 2 + 1 || i == height - 1), (i > 0 && i < n / 2 + 1));
        printEdge_2(i, n, height);
        printEdge_1((i == 0 || i == n / 2 + 1 || i == height - 1), (i > 0 && i < n / 2 + 1));
        printSpace(spaceAfter);
        if (i != 0 && i != height - 1)
            printEdge_1((i == height - n / 2 - 2), (i > height - n / 2 - 2));
        mx_printchar('\n');
    }
}
