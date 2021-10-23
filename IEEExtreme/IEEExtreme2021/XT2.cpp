int main() {
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		full = (1 << m) - 1;
		s1 = s2 = s3 = 0;
		memset(cnt, 0 , sizeof(cnt)); 
		for (int i = 0; i < n; i++)
		{
			cin >> line; 
			int t = 0;
			for (int j = 0; j < m; j++)
				if (line[j] == 'y')
					can[i] |= 1 << j;
			cnt[can[i]]++;
			A[full-can[i]]++; 
		}

		// SOS sum https://codeforces.com/blog/entry/45223 
		for(int i = 0; i<(1<<m); ++i)
			F[full-i] = A[full-i] = cnt[i];
		for(int i = 0;i < m; ++i) 
			for(int mask = 0; mask < (1<<m); ++mask)
				if(mask & (1<<i))
					F[mask] += F[mask^(1<<i)];

		for (int i = 0; i< (1<<m); i++)
			cnt[i] = F[full-i];


		// for (int i = full; i ; i--)             cout << i << ' '<<cnt[i] << endl;
		for (int i = 0; i < n; i++)
			//if (can[i] != full) 
			for (int j = 0; j < n; j++)
				//if (can[j] != full)
			{
				int cur = can[i] | can[j];
				if (cur == full) {
					s2 += 1;
				}
				s3 += cnt[full-cur]; 
			}
		s3 /= 6; 
		ans = s3;
		cout << ans << endl; 
	}
	return 0;
}
