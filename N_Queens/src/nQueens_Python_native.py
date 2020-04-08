import numpy as np
import numba
from   numba import njit,prange
from time import time

@njit(nogil=True) #Numba decorator
def allQueensNmb(n,i=0,col=None,dg1=None,dg2=None):
    # The array types must be numba compatible
    col = np.ones(n,dtype=numba.boolean)
    dg1 = np.ones(2*n,dtype=numba.boolean)
    dg2 = np.ones(2*n,dtype=numba.boolean)
    
    return allQueensNumba(n,0,col,dg1,dg2)
    
@njit(nogil=True) #Numba decorator
def allQueensNumba(n,i,col,dg1,dg2):
    # All rows are filled. Stop the recursion
    if n == i :
        return 1
    # Try putting a queen in each cell of row i
    nsol=0
    for j in range(n):
        if (col[j] and dg1[i+j] and dg2[i-j+n]): 

            col[j]     = False  # Mark column j as occupied
            dg1[i+j]   = False  # Mark diagonal i+j as occupied
            dg2[i-j+n] = False  # Mark diagonal i-j as occupied

            nsol+=allQueensNumba(n,i+1,col,dg1,dg2)
            
            col[j]     = True   # Unmark column j
            dg1[i+j]   = True   # Unmark diagonal i+j
            dg2[i-j+n] = True   # Unmark diagonal i-j
            
    return nsol
if __name__ == "__main__":
    n = 13
    mean = 0
    print("N -> 13,")
    for i in range(30):
        a = time()
        ns = allQueensNmb(n)
        t = time()-a
        print('     ',t,",")
        mean += t
    print("m ->",mean/30)