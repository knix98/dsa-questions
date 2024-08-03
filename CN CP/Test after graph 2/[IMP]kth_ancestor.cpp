/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575412/offering/8882723/problem/16310
*/



void dfs(vector<vector<int>> &tree, int node, int parent, vector<int> &dfs_path_till_now, vector<int> &ans, int k){

    /*
    vector.size() has to be handeled carefully because =>
    If your vector has fewer than 10 elements, vector.size() - 10 will result in an unsigned integer underflow, and you might get a 
    large positive value instead of a negative value. In C++, the size of a container is of type size_t, which is an unsigned integer type. 
    If the vector has, for example, 5 elements, then vector.size() - 10 would be interpreted as an underflow of an unsigned integer.
    To handle this situation more robustly, you can check if the vector size is greater than or equal to 10 before attempting the subtraction
    
    size_t is an unsigned integer type in C++ that is commonly used to represent the size of objects, such as the number of elements in an array or the size of a container like a std::vector or std::string.
    */
    if (dfs_path_till_now.size() >= k) {
        ans[node] = dfs_path_till_now[dfs_path_till_now.size() - k];
    } else {
        ans[node] = -1;
    }

    dfs_path_till_now.push_back(node);

    for(int i : tree[node]){
        if(i != parent){
            dfs(tree, i, node, dfs_path_till_now, ans, k);
        }
    }

    dfs_path_till_now.pop_back();
}

vector<int> kthAncestor(int n, int k, vector<vector<int>> &edges)
{
    vector<vector<int>> tree(n);
    for(auto edge : edges){
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    vector<int> ans(n);
    vector<int> dfs_path_till_now;

    dfs(tree, 0, -1, dfs_path_till_now, ans, k);

    return ans;
}