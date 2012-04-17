travelling salesman problem
---------------------------
pseudocode

class Eage
{
public:
	int start;
	int end;
};

class Path
{
public:
	vector<Eage> ve;
	int cost;
}
void travelling_saleman(int G[][], int n)
{
	int low_cost = 0;
	int up_cost = MAX_INT;
	int num = n;
	int del_row[n]={0}, int del_cols[n]={0};
	stack<Path> tree;
	low_cost += update_matrix(G, del_row, del_cols);
	Path p;
	p.cost = low_cost;
	tree.push(p);
	while(tree.size != 0)
	{
		low_cost += update_matrix(G, del_row, del_cols);
		temp =  choose(G, del_row, del_cols); 
		delete_matrix(G, del_row, del_cols);
		tree_push(without(temp));
		tree_push(with(temp))
	}
}

int init_matrix(int G[][], int del_row[], int del_cols[], int n)
{
	int res = 0, temp;
	for(int i = 0; i < n && del_row[i]==0; i++)
	{
		temp = G[i][0]
		for(int j = 1; j < n && del_cols[j]==0; j++)
		{
			if(G[i][j] < temp)
			{
				temp = G[i][j];
			}
		}
		if(temp != 0)
		{
			res+= temp;
			for(int j = 0; j < n && del_cols[j]==0; j++)
			{
				G[i][j] -= temp;
			}
		}
	}
	for(int i = 0; i < n && del_cols[i]==0; i++)
	{
		temp = G[0][i]
		for(int j = 1; j < n && del_rows[j]==0; j++)
		{
			if(G[j][i] < temp)
			{
				temp = G[j][i];
			}
		}
		if(temp != 0)
		{
			res+= temp;
			for(int j = 0; j < n && del_rows[j]==0; j++)
			{
				G[j][i] -= temp;
			}
		}
	}
}
