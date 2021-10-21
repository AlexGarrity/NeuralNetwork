# Neural Network
The name of this thing is a bit of a misnomer really.  As much as this project is based on the notion of a perceptron-eqsue kind of neuron, to call it a fully fledged neural network would be a little bit incorrect at this point in time.  I suppose by definition, given this is modelled on a network of neurons, this has to be counted as a neural network but when it comes to the implementation itself it's lacking.  I'm not 100% sure that you can even have connections longer than A->B.

## Why this exists
Regardless, this is one of the first "large" projects that I decided to undertake in C++ and also the first I ever used any form of version control with.  I'll give 16-17 year old me some credit:
 - At least it's modern-ish C++
 - There are no ridiculous hacks anywhere
 - It's memory safe (but I think that's more likely because at this point I was terrified of pointers)
 - It taught me a lot about project management and version control

## Should this exist?
By all metrics upon which I would currently rate my quality of code, this is awful.  The design is inefficient, memory alignment is all over the place, the entire thing is implemented on the stack.  I think now I'd at least link the nodes together with pointers (essentialy turning them into linked lists) or indices rather than just creating `n*n` nodes.

Really, this could be so much more memory (and probably even cache) efficient.  
Store all the words in a massive numbered dictionary, replace the nodes with 16 or 32-bit indices, connect them together with either pointers or some sort of graph representation.

I mean, even the data is awful.  There are 10000 words in the provided dictionary, which is realistically *far* too many.  There are 34 sentences worth of training data, which is realistically *far, far* too few.  Could have done with just downloading some books in txt format from Gutenberg or something.

Either way, this probably shouldn't remain in my portfolio and truth be told, I don't count it anymore.  But there's that tiny bit of nostalgia that stops me from deleting it.

## But if you don't want to delete it, why not rewrite it?
If I did, it would be in Python using TensorFlow.  Far better results in fewer than 100 lines of code.  
I'm not saying that I don't enjoy large projects in barebones systems languages but there's a time and a place which, given the 120k commits on the TensorFlow source tree by developers much more practiced than me, is certainly not here.

It's not out of the question that I might *actually* make this work one day, but that day is not today.


<hr>

# NeuralNetwork
I'm pretty sure this qualifies as a Neural Network, but if it doesn't, call it a 'thing for generating english-like sentences'

The IDE used is Code::Blocks, compiles with GCC 4.9.2 TDM
No other dependencies aside from the C++ standard library
(Although you do need the assets folder to be placed in the same directory as the executable)
