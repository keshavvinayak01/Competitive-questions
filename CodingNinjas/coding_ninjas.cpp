bool search2D( char Graph[][MAXN], int row, int col, string word, int nrow,int ncol, int level)
{
    int length = word.length();
    
    if( level == length)
        return true;
    
    if( row < 0 || col < 0 || row >= nrow || col >= ncol)
        return false;
    
    if( Graph[row][col] == word[level])
    {
        
        char temp = Graph[row][col];
        Graph[row][col] = '#';
        
        bool res =  search2D(Graph, row-1, col, word, nrow, ncol, level+1) |
                    search2D(Graph, row+1, col, word, nrow, ncol, level+1) |
                    search2D(Graph, row, col-1, word, nrow, ncol, level+1) |
                    search2D(Graph, row, col+1, word, nrow, ncol, level+1) |
                    search2D(Graph, row-1, col-1, word, nrow, ncol, level+1) |
                    search2D(Graph, row-1, col+1, word, nrow, ncol, level+1) |
                    search2D(Graph, row+1, col-1, word, nrow, ncol, level+1) |
                    search2D(Graph, row+1, col+1, word, nrow, ncol, level+1);
                    
        Graph[row][col] = temp;
        return res;
    }
    else
        return false;
}

int solve(char Graph[][MAXN],int N, int M)
{
    string  word = "CODINGNINJA";
	// Write your code here.
    for( int row = 0 ; row < N; row++ )
    {
        for( int col = 0 ; col < M; col++ )
        {
            if( Graph[row][col] == word[0] )
            {
               if(search2D(Graph, row, col, word, N, M, 0) )
                  return 1; 
            }
            
        }
    }
        return 0;
    
}