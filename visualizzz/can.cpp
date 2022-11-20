/*void minmax(node* ary)
{
	if (stop(ary) != true)
	{
		int maxi = 0;
		int savemax = 0;
		int savemaxi = 0;
		int mini = 10000;
		int savemin = 0;
		int savemini = 0;
		for (int i = 0; i < arysize; i++)
		{
			if (maxi < ary[i].y && maxmax > ary[i].y)
			{
				maxi = ary[i].y;
				savemax = i;
			}
			if (mini > ary[i].y && minmin < ary[i].y)
			{
				mini = ary[i].y;
				savemin = i;
			}
		}

			savemaxi = ary[maxcounter].y;
			savemini = ary[mincounter].y;
			if (savemaxi == savemin)
			{
				ary[savemin].y = savemaxi;
				ary[savemax].y = savemaxi;
			}
			else
			{
				ary[maxcounter--].y = maxi;
				ary[savemax].y = savemaxi;
				maxmax = maxi;
				ary[mincounter++].y = mini;
				ary[savemin].y = savemini;
				minmin = mini;
			}
	}
}



node* buff = new node[arysize];

void merge(node* ary, int l, int r, int m, RenderWindow& window)
{
	int i, j, k;

	i = l;
	k = l;
	j = m + 1;
	while (i <= m && j <= r)
		buff[k] = (ary[i].y < ary[j].y ? (++i, ary[i]) : (++j, ary[j]));
	while (i <= m)
		buff[k++] = ary[i++];
	while (j <= r)
		buff[k++] = ary[j++];
	for (i = l; i < k; i++)
		ary[i] = buff[i];

}

void mergesort(node* ary, int l, int r, RenderWindow& window)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2;
		mergesort(ary, l, m, window);
		mergesort(ary, m + 1, r, window);
		merge(ary, l, r, m, window);
	}
}













*/