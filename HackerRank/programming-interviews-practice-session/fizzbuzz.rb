#!/usr/bin/ruby
1.upto(100){|i|if(i%15==0)then puts"FizzBuzz" elsif(i%3==0)then puts"Fizz" elsif(i%5==0)then puts"Buzz" else puts i end}