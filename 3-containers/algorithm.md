# Answer

The program recursively calls the function for transferring water into another container unless and until one of the three conditions are satisfied:\n
• Till it reaches a state that was reached before after $x$ steps\n
• If it reaches the target\n
• If a certain state is reached where there is no water to transfer or the container we are transferring to is already full\n

It records the steps for every iteration (using a lot of memory I am assuming) and when the target is reached, it compares it to an array which contains the minimum amount of steps required (the sequence of steps containing the minimum which were found till that function call). If it has lesser moves, it changes the minimum steps array and at the end it prints it out for the user to see.
