##Q1
x<-c(0,1,2,3,4)
p<-c(0.41,0.37,0.16,0.05,0.01)
sum(x*p) ##prefered
  ##OR
x<-c(0,1,2,3,4)
p<-c(0.41,0.37,0.16,0.05,0.01)
weighted.mean(x,p)
  ##OR
x<-c(0,1,2,3,4)
p<-c(0.41,0.37,0.16,0.05,0.01)
c(x%*%p)


##Q2
F<-function(t) {
  t*0.1*exp(-0.1*t)
}
I<-integrate(F,lower=0,upper=Inf) ##this gives result with absolute error so we use $ to remove error
I$value
  ##OR
F<-function(t) {
  0.1*exp(-0.1*t)
}
I<-integrate((t*F(t)),lower=0,upper=Inf) ##parameter F(t) mentioning is necessary
I$value


##Q3
y<-12*x+2*(3-x)-18
x<-c(0,1,2,3)
p<-c(0.1,0.2,0.2,0.5)
sum(y,p)


##Q4
fm<-function(x) {
  x*0.5*exp(-abs(x))
}
I1<-integrate(fm,lower=1,upper=10)
first_moment<-I1$value
print(paste("First Moment =",first_moment))
sm<-function(x) {
  x^2*0.5*exp(-abs(x))
}
I2<-integrate(sm,lower=1,upper=10)
second_moment<-I2$value
print(paste("Second Moment =",second_moment))
mean=first_moment
var=second_moment-first_moment^2
print(paste("Mean =",mean))
print(paste("Variance =",var))


##Q5
f<-function(y) {
  (3/4)*(1/4)^(sqrt(y)-1)
}