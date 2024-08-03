/*
    https://www.codingninjas.com/studio/problems/selling-stock_630282

    Problem statement
    You have been given stock values/prices for N number of days. Every i-th day signifies the price of a stock on that day. 
    Your task is to find the maximum profit which you can make by buying and selling the stocks.

    Note :
    You may make as many transactions as you want but can not have more than one transaction at a time i.e, if you have the stock, 
    you need to sell it first, and then only you can buy it again.
*/



// for solution explanation can look at striver video = https://www.youtube.com/watch?v=nGJmxkUJQGs
// basically at every index, there is two states possible : 1.you can buy this stock (further 2 cases buy/dont buy), 2.you can only sell the curr stock(sell/ not sell at this index)
long getMaximumProfit(long *values, int n)
{
    long prevCanBuyProfit = 0, prevCanSellProfit = 0;
    long currCanBuyProfit = 0, currCanSellProfit = 0;

    for(int i=n-1; i>=0; i--){
        // first calculating canBuyProfit at current index
        // case 1 : buy at current index
        currCanBuyProfit = prevCanSellProfit - values[i];

        // case 2 : not buy at curr index
        currCanBuyProfit = max(currCanBuyProfit, prevCanBuyProfit);

        // now calculating canSellProfit at current index
        // case 1 : sell at current index
        currCanSellProfit = prevCanBuyProfit + values[i];

        // case 2 : not sell at curr index
        currCanSellProfit = max(currCanSellProfit, prevCanSellProfit);

        prevCanBuyProfit = currCanBuyProfit;
        prevCanSellProfit = currCanSellProfit;
    }

    return currCanBuyProfit;  // ans would be = can buy profit at 0th index
}