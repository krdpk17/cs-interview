'''
 * This code is working but having time-out issue
 * So, it means that code is not optimal
 * https://leetcode.com/problems/number-of-islands/description/
'''
class Solution(object):
    
    def check_if_neighbour_color(self, grid, row, col, color):
        rows = len(grid)
        cols = len(grid[0])

        #print("neighbours", grid[row - 1][col], grid[row + 1][col], grid[row][col - 1], grid[row][col + 1])
        if(row - 1 >= 0):
            if(grid[row - 1][col] == color):
                return True

        if(row + 1 < rows):
            if(grid[row + 1][col] == color):
                return True

        if(col - 1 >= 0):
            if(grid[row][col - 1] == color):
                return True

        if(col + 1 < cols):
            if(grid[row][col + 1] == color):
                return True

        #print("check_if_neighbour_color", row, col, grid[row][col], color)
        return False

    def color_if_neighbour(self, grid, row, col, color_val):
        rows = len(grid)
        
        cols = len(grid[0])
        if(row < 0 or row >= rows or col < 0 or col >= cols):
            return
        if(grid[row][col] == "1" and self.check_if_neighbour_color(grid, row, col, color_val)):
            #print("color_if_neighbour")
            grid[row][col] = color_val
            self.color_if_neighbour(grid, row-1, col, color_val)
            self.color_if_neighbour(grid, row+1, col, color_val)
            self.color_if_neighbour(grid, row, col-1, color_val)
            self.color_if_neighbour(grid, row, col+1, color_val)
            return


    def dfs_recursive(self, grid, node, visited):
        print(node)
        visited[node] = True
        for neighbor, is_connected in enumerate(matrix[node]):
            if is_connected and not visited[neighbor]:
                dfs_recursive(matrix, neighbor, visited)

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        rows = len(grid)
        
        cols = len(grid[0])

        color_val = 2

        found = True
        island_count = 0
        print(grid[0][0], type(grid[0][0]), rows, cols)
        print("grid:", grid)
        while found == True:
            found = False
            for row in range(rows):
                for col in range(cols):
                    #print(grid[row][col], type(grid[row][col]))
                    if(grid[row][col] == '1'):
                        print("Found", row, col)
                        self.found_island(grid, row, col, color_val)
                        self.found_island(grid, row, col, color_val)
                        print("grid:", grid)
                        found = True
                        island_count += 1
                        color_val += 1
        return island_count
