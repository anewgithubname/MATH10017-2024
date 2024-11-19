update <- function(x,v){
  # TODO: Check the boundary collision, and update v. 
  if(x[1] > 5 || x[1] < -5){
    v[1] <- - v[1]
  }
  if(x[2] > 5 || x[2] < -5){
    v[2] <- - v[2]
  }
  
  x <- x + v #update x
  return(list(x,v))
}

x <- c(0,0) #the initial position of x
v <- c(0.23456,0.12345) #the initial velocity of x

while(T){
  #TODO: create a new plot and draw x's current location 
  plot(c(-5, 5), c(-5, 5), type = "n", xlab = "x", ylab = "y")
  points(x[1],x[2])
  
  xv <- update(x,v) # update x and v
  # getting new x and v from the returned list. 
  # list indexing uses double brackets [[]]
  x<- xv[[1]]
  v<- xv[[2]]
  
  # wait a bit to allow RStudio plot the picture. 
  Sys.sleep(0.1)
}


######### Version that also changes colour
update <- function(x,v){
  flip <- FALSE
  # TODO: Check the boundary collision, and update v. 
  if(x[1] > 5 || x[1] < -5){
    v[1] <- - v[1]
    flip <- TRUE
  }
  if(x[2] > 5 || x[2] < -5){
    v[2] <- - v[2]
    flip <- TRUE
  }
  
  x <- x + v #update x
  return(list(x,v,flip))
}

flip <- FALSE
cl <- FALSE
while(T){
  if(flip){ cl <- !cl }
  #TODO: create a new plot and draw x's current location 
  plot(c(-5, 5), c(-5, 5), type = "n", xlab = "x", ylab = "y")
  points(x[1], x[2], col = cl + 1)

  xv <- update(x,v) # update x and v
  # getting new x and v from the returned list. 
  # list indexing uses double brackets [[]]
  x <- xv[[1]]
  v <- xv[[2]]
  flip <- xv[[3]]
  
  # wait a bit to allow RStudio plot the picture. 
  Sys.sleep(0.1)
}