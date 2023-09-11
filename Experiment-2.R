##Q1(a)
x<-c(rep("Gold",20),rep("Silver",30),rep("Bronze",50))
sample(x,10)
   ##OR
sample(c("Gold","Silver","Bronze"),10,replace=T,c(20,30,50))
##Q1(b)
sample(c("Success","Failure"),10,replace=T,prob=c(0.9,0.1))


##Q2
n=as.integer(readline(prompt = "Enter number : ")) 
p=1
for(i in 1:n){ 
  p=p*(1-(i-1)/365)
}
prob=1-p 
print(paste("probability is:",prob))
##(a)
N=5000
sum=0
for(i in 1:N){
  A<-as.integer(any(duplicated(sample(365,50,replace=T))))
  sum=sum+A
}
prob=sum/N
print(paste("Probability = ",prob))
##(b)
n=2
while(1){ 
  p=1
  for(i in 1:n){
    p=p*(1-(i-1)/365) 
  }
  prob=1-p
  if(prob>0.5){ 
    break
  } 
  n=n+1
} 
print(n)


##Q3
BayesThm<-function(a,b,c){
  res=a*b/c
  print(res)
}
x=0.2
y=0.85
z=0.4
BayesThm(x,y,z)


##Q4
dat<-iris
##(a)
head(dat,10)
##(b)
str(dat)
##(c)
range(dat$Sepal.Length)
##(d)
mean(dat$Sepal.Length)
##(e)
median(dat$Sepal.Length)
##(f)
quantile(dat$Sepal.Length,0.25) 
quantile(dat$Sepal.Length,0.75) 
IQR(dat$Sepal.Length)
##(g)
sd(dat$Sepal.Length) 
var(dat$Sepal.Length)
##(h)
lapply(dat[2:4],range) 
lapply(dat[2:4],mean) 
lapply(dat[2:4],median) 
lapply(dat[2:4],IQR)
lapply(dat[2:4],sd) 
lapply(dat[2:4],var)
##(i)
summary(iris)


##Q5
mode<-function(v){
  uniq<-unique(v) 
  uniq[which.max(tabulate(match(v,uniq)))]
} 
v<-c(2,1,2,3,4,2,3,1,2) 
modeval<-mode(v) 
print(modeval)