
######### Solution
n_max = 1e4

p_target <- function(x){
  return( pmax(1 - abs(x-1), 0) )
}

acc <- c() # create an empty vector
n <- 0 # how many samples have we already obtained?
M <- 2 # This is M_star, the optimal M
n_iter <- 0 # Counting number of iteration
while(n < n_max){
  y <- runif(1, 0, 2)
  u <- runif(1)
  if(u <= p_target(y) / (M * dunif(y, 0, 2)) ){
    acc <- c(acc, y)
    n <- n + 1
    if(n == n_max) break
  }
  n_iter <- n_iter + 1
}

hist(acc, prob = TRUE) #plot the histogram of accepted samples
xseq <- seq(0, 2, length.out = 1e3)
lines(xseq, p_target(xseq), col = "blue")
# Looks right

######### TO try different values of M, it's better to wrap into a function

rj_sampler <- function(M){
  
  acc <- c() # create an empty vector
  n <- 0 # how many samples have we already obtained?
  n_iter <- 0 # Counting number of iteration
  while(n < n_max){
    y <- runif(1, 0, 2)
    u <- runif(1)
    if(u <= p_target(y) / (M * dunif(y, 0, 2)) ){
      acc <- c(acc, y)
      n <- n + 1
      if(n == n_max) break
    }
    n_iter <- n_iter + 1
  }
  
  cat("Number of iterations: ")
  print(n_iter[1])
  return( acc )
  
}

trial_1 <- rj_sampler(M = 2)

trial_big_M <- rj_sampler(M = 20)
hist(trial_big_M) 
# Looks right but took forever!

trial_small_M <- rj_sampler(M = 0.5)
hist(trial_small_M) 
# Fast but looks wrong!!!


######### Challenge, try Gaussian proposal

rj_sampler_gau <- function(M){
  
  acc <- c() # create an empty vector
  n <- 0 # how many samples have we already obtained?
  n_iter <- 0 # Counting number of iteration
  while(n < n_max){
    y <- rnorm(1, 1, 0.5)
    u <- runif(1)
    if(u <= p_target(y) / (M * dnorm(y, 1, 0.5)) ){
      acc <- c(acc, y)
      n <- n + 1
      if(n == n_max) break
    }
    n_iter <- n_iter + 1
  }
  
  cat("Number of iterations: ")
  print(n_iter[1])
  return( acc )
  
}

# Empirically find sufficiently large M, M = 1.3 seems fine
xseq <- seq(-0.5, 2.5, length.out = n)
yseq <- pmax(1 - abs(xseq - 1), 0)
plot(xseq, yseq, col = "blue", type = "l", xlab = "x", ylab = "p(x)", xlim = c(-0.5, 2.5))
lines(xseq, dnorm(xseq, 1, 0.5) * 1.3, col = "1")

trial_gau <- rj_sampler_gau(M = 1.3)
hist(trial_gau) # Looks right and almost twice more efficient that the uniform