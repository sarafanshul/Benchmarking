import sys

cnt = 0
board_size = int(13)
Attacked_H  = { i:0 for i in range(0, board_size) }
Attacked_DU = { i:0 for i in range(0, board_size*2) }
Attacked_DD = { i:0 for i in range(-board_size, board_size) }


def nqueen(B, N, row, col):
    global cnt
    if(row >= N):
        return 1
    if(col >= N):
        cnt += 1
        return 0
    B[col] = row
    if(0==(Attacked_H[row] + Attacked_DU[row+col] + Attacked_DD[row-col])):
        [Attacked_H[row], Attacked_DU[row+col], Attacked_DD[row-col]] = [ 1,1,1 ]
        nqueen(B, N, 0, col + 1)
        [Attacked_H[row], Attacked_DU[row+col], Attacked_DD[row-col]] = [ 0,0,0 ]
    nqueen(B, N, row + 1, col)


nqueen(list(range(0, board_size)), board_size, 0, 0)
print(cnt)