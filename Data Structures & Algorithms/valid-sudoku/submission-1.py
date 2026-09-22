class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        for i in range(len(board)):
            row = []
            for j in range(len(board[i])):
                if board[j][i] != '.':
                    if board[j][i] in row:
                        return False
                    row.append(board[j][i])
                
        
        for i in range(9):
            col = []
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in col:
                        return False
                    col.append(board[i][j])
                

        square = [[[] for _ in range(3)] for _ in range(3)]
        for i in range(9):
            for j in range(9):
                if board[j][i] != '.':
                    if board[j][i] in square[j//3][i//3]:
                        return False
                    square[j//3][i//3].append(board[j][i])
        
        return True