## Description

Since Ayşe likes chocolate very much, she wants to buy and stock up as many chocolates as possible. However, her mother does not allow her to buy more than *M* chocolates per day. As a little girl, she does not have a big budget, so she wants to buy chocolates as cheap as possible. Unfortunately, chocolate is not something easily reachable where she lives. Because of the famine and black market of chocolates, prices are increasing significantly each day. Ayşe wants to know the minimum possible price she needs to pay to buy K chocolates without breaking her mother’s rule.

There are *N* chocolates available on the black market of chocolate. Each chocolate has a different price and the prices are increasing every day with the formula Pn,i = i * Cn, where Pn,i is the price of chocolate n at day i, and Cn is the price of chocolate n at day 1. For instance, if the price a chocolate is 5 on the first day, it will be 10, 15, 20, … and so on, on the second, third and the other days. She wants to buy the chocolates quickly, but her mother’s rule of buying maximum M chocolates per day limits her. Ayşe needs to find the minimum cost of buying K chocolates, for each K from 1 to N.

## Input

In the first row of the input, there are 2 numbers. ```(N, M)``` 
- First number specifies the number of chocolates available.
- Second number M specifies the maximum number of chocolates Ayşe can buy in one day because of her mother’s rule.

In the second row of the input, there are *N* numbers, prices of the chocolates.

## Output

N numbers, the minimum amounts that Ayşe needs to pay in order to buy K chocolates, for K=1, K=2, ... K=N respectively.


## Constraints

N (number of chocolates available) <= 200000

M (maximum number of chocolates Ayşe can buy each day) <= 200000

M<=N

P_i <= 200000 (Price for each chocolate)

