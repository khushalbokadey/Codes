t=int(input())
while t:
 n=input()
 a=0
 i=.0
 while i<n:
  a+=pow(-1,i)/(2*i+1)
  i+=1
 print'%.15f'%a
 t-=1
