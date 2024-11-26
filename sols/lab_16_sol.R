
na <- 500 
nb <- 800 
m <- 784 

A <- matrix(rnorm(m*na), na, m)
B <- matrix(rnorm(m*nb), m, nb)

dist <- function(a, b){
  sqrt(sum((a-b)^2))
}

# scalar compute
pdist1 <- function(A, B){
  nA <- nrow(A)
  nB <- ncol(B)
  d <- ncol(A)
  D <- matrix(0, nA, nB)
  for (i in 1:nA){ 
    for (j in 1:nB){ 
      s <- 0
      for (k in 1:ncol(A)){ 
        s <- s + (A[i, k] - B[k, j])^2
      }
      D[i, j] <- sqrt(s)
    }
  }
  return(D)
}

start <- Sys.time() #timing

D1 <- pdist1(A, B)

end <- Sys.time()
print(end - start)

# vectorising the computation of D_ij
pdist2 <- function(A,B){
  nA <- nrow(A)
  nB <- ncol(B)
  D <- matrix(0, nA, nB)
  for (i in 1:nA){ 
    for (j in 1:nB){ 
      D[i, j] <- dist(A[i,], B[,j])
    }
  }
  return(D)
}

start <- Sys.time() #timing

D2 <- pdist2(A, B)

end <- Sys.time()
print(end - start)

# Are the two functions giving the same result?
plot(D1, D2)
abline(0, 1, col = 2)

range(D1 - D2)
# It seems so!

# vectorising the computation of D_i, the i-th row of D
pdist3 <- function(A,B){
  nA <- nrow(A)
  nB <- ncol(B)
  D <- matrix(0, nA, nB)
  for (i in 1:nA){ 
    D[i,] <- sqrt( sum(A[i, ]^2) - 2*t(B)%*%A[i,] + colSums(B^2) )
  }
  return(D)
}

start <- Sys.time() #timing

D3 <- pdist3(A, B)

end <- Sys.time()
print(end - start)

# Is the result still correct?
plot(D2, D3)
abline(0, 1, col = 2)

range(D2 - D3)
# It seems so!

# fully vectorised versions
pdist4 <- function(A,B){
  nA <- nrow(A)
  nB <- ncol(B)
  o1 <- matrix(1, 1, nB)
  o2 <- matrix(1, nA, 1)
  
  D <- sqrt( rowSums(A^2) %*% o1 - 2 * A%*%B + o2%*%t(colSums(B^2)) )
  return(D)
}

start <- Sys.time() #timing

D4 <- pdist4(A, B)

end <- Sys.time()
print(end - start)

# Is the result still correct?
plot(D3, D4)
abline(0, 1, col = 2)

range(D3 - D4)
# It seems so!


