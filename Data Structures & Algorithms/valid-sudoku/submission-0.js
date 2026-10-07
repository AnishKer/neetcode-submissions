class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    rowColValid(board,row,col,num){
        for(let i =0;i<9;i++){
            if(board[i][col] === num && i !== row){
                return false
            }
            if(board[row][i] === num && i !== col){
                return false
            }
        }
        return true
    }

    gridValid(board,row,col , num){
        let rowStart = Math.floor(row/3)*3
        let colStart = Math.floor(col/3)*3
        for(let i = rowStart ; i<rowStart+3 ; i++){
            for(let j=colStart ; j<colStart+3 ;j++){
                if(num===board[i][j] && (i !== row || col !==j)){
                    return false
                }
            }
        }
        return true
    }


    isValidSudoku(board) {
        for(let i =0;i<9;i++){
            for(let j=0;j<9;j++){
                if(board[i][j] === '.') continue
                if(!this.gridValid(board,i,j,board[i][j])) return false
                if(!this.rowColValid(board,i,j,board[i][j])) return false
            }
        }
        return true
    }
}
