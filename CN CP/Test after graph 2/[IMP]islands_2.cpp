/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575412/offering/8882723/problem/10820

hard DSU problem
*/


// latest code in which I used 2d matrix in DSU
#include<bits/stdc++.h>
using namespace std;

int rows[] = {-1, 0, 1, 0};
int cols[] = {0, 1, 0, -1};

class DSU{
    vector<vector<pair<int,int>>> parent;
    vector<vector<int>> setSize;
	int islands;  // representing the number of islands currently present in the matrix
    int n, m;

	public:
    DSU(int n, int m){
        // since no land is present initially, hence nodes doesnt exist , so pushing -1 in parent and 0 in setSize
        // hence if some node's parent is -1, then that means that this node doesn't exist
        for(int i=0; i<n; i++) {
            parent.push_back(vector<pair<int,int>>(m, {-1,-1})); 
            setSize.push_back(vector<int>(m, 0));
        }
               
        islands = 0;
        this->n = n;
        this->m = m;
    }

    bool checkCoord(int x, int y, int n, int m){
        return (x >= 0 && x<n && y >= 0 && y<m) && (parent[x][y].first != -1);
    }

	void makeIsland(int x, int y){ // making a new land/island at a given coordinate
		parent[x][y] = {x,y};
		setSize[x][y] = 1;
		islands++;

        for(int i=0; i<4; i++){
            int nx = x + rows[i];
            int ny = y + cols[i];

            if(checkCoord(nx, ny, n, m)){
                // combine
                combine(x, y, nx, ny);
            }
        }
	}

    pair<int,int> findRoot(int x, int y){
        int tx = x, ty = y;
        while(!(parent[tx][ty].first == tx && parent[tx][ty].second == ty)){
            pair<int,int> temp = parent[tx][ty];
            parent[tx][ty] = parent[temp.first][temp.second];
            temp = parent[tx][ty];
            tx = temp.first;
            ty = temp.second;
        }

        return parent[x][y] = {tx, ty};
    }

    void combine(int x1, int y1, int x2, int y2){
        pair<int,int> ru = findRoot(x1, y1);
        pair<int,int> rv = findRoot(x2, y2);

        if(ru == rv) return;

        if(setSize[ru.first][ru.second] > setSize[rv.first][rv.second]){
            parent[rv.first][rv.second] = ru;
            setSize[ru.first][ru.second] += setSize[rv.first][rv.second];
        }
        else{
            parent[ru.first][ru.second] = rv;
            setSize[rv.first][rv.second] += setSize[ru.first][ru.second];
        }

		islands--;  // if combination happened between 2 different islands, then we need to reduce the islands by 1
    }

    int getIslands() {return islands;}
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	DSU dsu = DSU(n, m);

	vector<int> ans;
	int x, y;
	for(auto qe : q){
		x = qe[0];
		y = qe[1];

		dsu.makeIsland(x, y);

		ans.push_back(dsu.getIslands());
	}

	return ans;
}




// earlier code in which I used 1d matrix in DSU
#include<bits/stdc++.h>
using namespace std;

class DSU{
	public:
    vector<int> parent;
    vector<int> setSize;
	int islands;  // representing the number of islands currently present in the matrix

    DSU(int n){
        // since no land is present initially, hence nodes doesnt exist , so pushing -1 in parent and 0 in setSize
        // hence if some node's parent is -1, then that means that this node doesn't exist
        for(int i=0; i<n; i++) parent.push_back(-1), setSize.push_back(0);
		islands = 0;
    }

	void makeIsland(int u){ // making a new land/island at a given coordinate
		parent[u] = u;
		setSize[u] = 1;
		islands++;
	}

    int findRoot(int u){
        int temp = u;
        while(parent[temp] != temp){
            parent[temp] = parent[parent[temp]];
            temp = parent[temp];
        }

        parent[u] = temp;
        return temp;
    }

    void combine(int u, int v){
        int ru = findRoot(u);
        int rv = findRoot(v);

        if(ru == rv) return;

        if(setSize[ru] > setSize[rv]){
            parent[rv] = ru;
            setSize[ru] += setSize[rv];
        }
        else{
            parent[ru] = rv;
            setSize[rv] += setSize[ru];
        }

		islands--;  // if combination happened between 2 different islands, then we need to reduce the islands by 1
    }
};

bool checkCoord(int x, int y, int n, int m){
	return (x >= 0 && x<n && y >= 0 && y<m);
}

int rows[] = {-1, 0, 1, 0};
int cols[] = {0, 1, 0, -1};

void makeIsland(int x, int y, int n, int m, DSU &dsu){
	int id1, id2;
	id1 = (x*m) + y;  // calculating the 1D index of a cell present in the n*m 2D array

	dsu.makeIsland(id1);  // first make a new land/island consisting of only 1 node at the (x,y) coordinate

	for(int i=0; i<4; i++){
		int nx = x + rows[i];
		int ny = y + cols[i];
		id2 = (nx*m) + ny;

        // check 2 things :
        // 1. validity of nx,ny
        // 2. whether there is a land at this point (dsu.parent[id2] != -1)
        // then call dsu.combine() , which will take care of all the cases => whether to combine or not combine based on whether nodes are part of same island or not
		if(checkCoord(nx, ny, n, m) && dsu.parent[id2] != -1) dsu.combine(id1, id2);
	}
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	DSU dsu = DSU(n*m);

	vector<int> ans;
	int x, y;
	for(auto qe : q){
		x = qe[0];
		y = qe[1];

		makeIsland(x , y , n, m, dsu);

		ans.push_back(dsu.islands);
	}

	return ans;
}