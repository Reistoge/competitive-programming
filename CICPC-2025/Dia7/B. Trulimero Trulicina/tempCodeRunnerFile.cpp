for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                if (freq >= ((n * m) / k))
                {
                    if (count >= k)
                    {
                        count = 0;
                    }
                    count++;
                    freq = 0;
                }
                int index = j;
                if (i % 2 == 0 && index % 2 == 1)
                {
                    index = m - j + 1;
                    mat[i][index] = count;
                    mn[count]++;
                    freq++;
                }
                else if (i % 2 == 1 && index % 2 == 0)
                {
                    mat[i][index] = count;
                    mn[count]++;
                    freq++;
                }
            }
        }
