a <- c(1,0)
b <- c(1,1)

dist <- function(v1, v2){
  return(sqrt(sum((v1 - v2)^2)))
}

angle <- function(v1, v2){
  return(acos(v1%*%v2/dist(v1,0)/dist(v2,0))/2/pi*360)
}

dist(a,b)
angle(a,b)

######  Path-finding function

pathfinder <- function(X){
  n <- nrow(X)
  step_length <- numeric(n-1)
  step_dir <- numeric(n-1)
  for(ii in 1:(n-1)){
    step_length[ii] <- dist(X[ii, ], X[ii+1, ])
    step_dir[ii] <- angle(X[ii+1, ] - X[ii, ], c(1, 0))
  }
  total_length <- sum(step_length)
  return( list(step_length, step_dir, total_length) )
}

### Try on basic example
locs <- matrix(c(0, 2, 3, 2, 1, 1, 0, 1, 1, 3, 4, 5), 6, 2)

pth <- pathfinder(locs)

# Is this correct?
plot(locs)

for(ii in 1:(nrow(locs)-1)){
  ang_rad <- pth[[2]][ii] / 360 * 2 * pi
  seg_start <- locs[ii, ]
  seg_end <- locs[ii, ] + pth[[1]][ii] * c(cos(ang_rad), sin(ang_rad))
  arrows(seg_start[1], seg_start[2], seg_end[1], seg_end[2], col="blue")
}

# YES!


