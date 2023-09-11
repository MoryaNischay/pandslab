##Q1
x<-c(5,10,15,20,25,30)
print(paste("Maximum value of given vector is",max(x)))
print(paste("Minimum value of given vector is",min(x)))

print("Original vector")
print(x)
max(x)
print("Maximum value of given vector is 30")


##Q2
NUM=as.integer(readline(prompt="Enter a number: "))
fact=1
if(NUM<0){
  print("Error! The number entered is invalid.")
} else if(NUM==0){
  print("The factorial of 0 is 1")
} else{
  for(i in 1:NUM){
    fact=fact*i
  }
  print(paste("The factorial of",NUM,"is",fact))
}

##Q3
n=as.integer(readline(prompt="Enter number of terms:"))
a=0
b=1
count=2
if(n<=0){
  print("Error! The number entered is invalid.")
} else{
  if(n==1){
    print("Fibonacci sequence:")
    print(a)
  } else if(n==2){
    print("Fibonacci sequence:")
    print(a)
    print(b)
  } else{
    print("Fibonacci sequence:")
    print(a)
    print(b)
    while(count<n){
      c=a+b
      print(c)
      a=b
      b=c
      count=count+1
    }
  }
}


##Q4
print("1. Addition")
print("2. Subtraction")
print("3. Multiplication")
print("4. Division")
ch=as.integer(readline(prompt="Enter your choice:"))
n1=as.integer(readline(prompt="Enter 1st number:"))
n2=as.integer(readline(prompt="Enter 2nd number:"))
add<-function(a,b){
  return(a+b)
}
sub<-function(a,b){
  return(a-b)
}
mul<-function(a,b){
  return(a*b)
}
div<-function(a,b){
  if(b==0)
    print("Denominator can't be zero!")
  else
    return(a/b)
}
res<-switch(ch,add(n1,n2),sub(n1,n2),mul(n1,n2),div(n1,n2))
print(res)

  
##Q5
plot(1,5)
plot(c(1,3),c(2,7))
plot(1:5)
x<-c(1,2,3,4,5)
y<-c(3,5,7,9,11)
plot(x,y,main="Graph",xlab="x-axis",ylab="y-axis",type="l",col="red")

x1<-c(1,2,3,4,5)
y1<-c(3,5,7,9,11)

x2<-x1+3
y2<-y1-3
plot(x1,y1,type="l",col="red")
points(x2,y2,type="l",col="blue")