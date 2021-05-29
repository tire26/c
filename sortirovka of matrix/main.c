for (int i = temparraymax - 1; i >= 0; i--)
{
    noswap = 1;
    for (int j = 0; j < i; j++)
    {
        sortcheck++;
        if (temparray[j] > temparray[j + 1])
        {
            checkchange - change(&temparray[j], &temparray[j + 1]);
            sortchange++;

            for (int k = 0; k < temparraymax; k++)
                noswap = 0;
        }
    }
    if (noswap == 1)
        break;
}
temparrayelement = 0;