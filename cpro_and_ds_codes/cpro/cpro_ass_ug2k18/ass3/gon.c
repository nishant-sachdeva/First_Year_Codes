#include<stdio.h>

#define ll long long int
#define get(n) ll n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int main()
{
	get(test);
	while(test--)
	{
		ll arrx[200], arry[200];
		get(n);
		get(m);
		ll input[110][110];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%lld", &input[i][j]);
			}
		}
		get(sx); get(sy);
		get(dx); get(dy);
		ll visited[110][110] = {0};

		ll direcx[] = {-1 , 1 ,  0 , 0 };
		ll direcy[] = { 0 , 0 , -1 , 1 };

		ll startx = 0, endx = 0;
		ll starty = 0, endy = 0;

		ll moves = 0, reached = 0;
		ll nodes = 1, next_nodes = 0;
		arrx[endx++] = sx;
		arry[endy++] = sy;

		while(endx - startx >0)
		{
			ll r = arrx[startx++];
			ll c = arry[starty++];
			if( r == dx && c == dy)
			{
				reached = 1; break;
			}
			// now , since we didn't break, 
			for(int i = 0; i<4 ; i++)
			{
				ll newx = r + direcx[i];
				ll newy = c + direcy[i];

				if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
				if(visited[newx][newy] == 1 || input[newx][newy] == 0) continue;

				// now since they are valid points;

				visited[newx][newy] = 1;
				arrx[endx++] = newx;
				arry[endy++] = newy;
				next_nodes++;
			}

			// now we have added the new nodes to the search  arrays;
			nodes--;

			if(nodes == 0)
			{
				nodes = next_nodes;
				next_nodes  = 0;
				moves++;
			}
		}

		if(reached == 1) printf("%lld\n", moves);
		else
			printf("-1\n");
	}
	return 0;
}