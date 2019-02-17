# FlightGearSimulatorW
Flight Simulator. Visualize a real plane with it's system, controlled by a multi-threaded code that represents both the server and the client,
that give and send requests to the simulator. supporting the flight gear simualator (available for linux &amp; windows).

This is the first part of the flight gear project written in c++.

The first part focuses on building an interpreter for a new programming language.

The interpreter will go over code lines written in a script (file/command line) , written in the new language, and will interpret them,
similiar to the JVM process.

Each command is departed to it's own class, when each command has to implement the "excecute" method of the "command" interface,
to activate the command.

For example, the line "x= y * 3" will be intepreted to "assign command", and it's "excecute" implementation will be to put
the value of y * 3 into the variable x. All variables sit in HashMap. (for O(1) time).

There is also the "Shunting Yard" class to recursievly calculate expressions like "x= (y+3) * 5/2 +3".

In order to calculate such expressions, there is an "Expression" interface, from whom the "Binary expression" , "UnaryExpression" 
and the "Variable" class inherit.

Each expression is recursievly calculated to it's value, using the Shunitng-Yard Algorithm (which is also a kind of expression).
Of course, each command can also be an expression. so in order to connect both without changing existing code, I used the
Object Adapter - Design pattern. There is a class of "Expression command" that implements the "Expression" interface and contains 
a refference to a command object.


#The process of the intepretation includes:

Lexer - to split the lines of the code into a vector of known commands.
Parser - to go over the commands, and by using Factory - to create for each word it's own command and activate it's "execute" implemntation.

Connecting the FlightGear Simulator using sockets and multi-threading:
There are two special commands: (Both activated on different threads)

* OpenDataServerCommand - activated when the LexerParser interpret the words "OpenDataServer NUMBER". The excecution of the class is to 
open a server socket on the given NUMBER to whom the simulator will connect, and after recognizing a connection- to start reading
the data that the simulator sends (current height, rudder angle..).
In order to avoid forever-blocking mode, the class opens the server on a differenet thread and background runs it.

* Connect command -  activated when the LexerParser interpret the words "Connect NUMBER". The excecution of the class is to open
a socket and connect the server that the simulator runs, in order to send the simulator instructions, such as to move the rudder,
to press the throtle to 1 - means the engine can warm and the plane can start moving.





