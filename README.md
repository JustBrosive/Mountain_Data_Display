Stock tracking program

Suppose you buy 100 shares of a stock at $12 per share on a given date , then another 100 at $10 per share on a given date, 
and then sell 150 shares at $15 on a given date.  You have to pay taxes on the gain, but exactly what is the gain? 
In the United States, the FIFO(queue) rule holds: You first sell all 
shares of the first batch for a profit of $300, then 50 of the shares from the second batch, for a profit of $250, yielding a total profit of $550. 

Included in this project is incomplete source that can make these calculations for arbitrary purchases and sales of shares in multiple companies. 
There is also a data file which contains all of the buy and sell orders for the simulation, you may use the following
data:

----------- Begin simulation.dat File ------------

buy aapl 100 126 05/01/2021
buy aapl 200 124 05/03/2021
buy prvb 200 10 05/01/2021
buy  amd  4  250   05/10/2021
sell prvb 150 12 05/10/2021
sell appl 50 120  05/08/2021
sell  amd  4 225   05/15/2021
quit

----------- End simulation.dat File ------------


There is a queue of objects of a class StockBlock that will contain the quantity and price of a block of shares and
a Map of the Queues which contain the StockBlock objects.

You will also need to declare and implement a Date class for the buy and sell dates that are in the StockBlock

The tasks include modifying and the given source code to add additional functionality:

1.  Choose and use another data structure that is appropriate to keep track of the gains (plus or minus) from the sell orders.
2.  Develop a report writer class that will accept the data structure that has the gains data structure and
    print the gains and the date associated with when the gain occured.


    The report should then print the total gain (plus or minus) so there is a total of what will need to
    be reported for taxes.

An example of the report would look like:


Company: AAPL
Date            Gain
05/10/2021      100
05/12/2021      -50
05/14/2021      50
Total for AAPL: 100

Company: AMD
Date            Gain
05/10/2021      200
05/12/2021      -50
05/14/2021      150
Total for AMD:  300

Total Gain: 400 dollars


NOTE -- The ReportWriter class source is not included in this project.  You will need to declare and implement that class.

The class name should be ReportWriter, the header file needs to have the appropriate conditional compilation directives for the header guard.

The Date class should be implemented with a constructor that will take the 
month, day and year as integers.  There will be an overloaded operator to
print out the date formatted as MM/DD/YYYY.

