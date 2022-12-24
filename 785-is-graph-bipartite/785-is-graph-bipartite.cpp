class Solution {
public:
    bool isBipartite(vector<vector<int>>& a) {
        // Initialize the number of vertices in the graph
        int n = a.size(); 
        // Initialize the color array with all elements set to -1
        vector<int> color(n, -1);
        // Initialize a queue for breadth-first search
        queue<int> q;

        // Loop through all vertices in the graph
        for(int i = 0; i < n; i++) {
            // If the current vertex has already been colored, skip it
            if(color[i] != -1) continue;

            // Set the color of the current vertex to 0
            color[i] = 0;
            // Push the current vertex to the queue
            q.push(i);

            // While the queue is not empty
            while(!q.empty()) {
                // Get the front element of the queue
                int temp = q.front();
                // Pop the front element from the queue
                q.pop();

                // Loop through all the neighbors of the current vertex
                for(auto neighbor : a[temp]) {
                    // If the neighbor has not been colored
                    if(color[neighbor] == -1) {
                        // Set the color of the neighbor to the opposite of the current vertex
                        color[neighbor] = 1 - color[temp];
                        // Push the neighbor to the queue
                        q.push(neighbor);
                    }
                    // If the neighbor has the same color as the current vertex
                    else if(color[neighbor] == color[temp]) {
                        // The graph is not bipartite, return false
                        return false;
                    }
                }
            }
        }
        // All vertices have been colored, and no same-colored neighbors were found
        // The graph is bipartite, return true
        return true;
    }
};
