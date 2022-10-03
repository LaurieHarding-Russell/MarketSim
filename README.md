# Market Simulator.
This is just meant to be a fun project to help me understand the stockmarket better. It shouldn't be taken seriously. 
This is by no means an accurate representation of real life.

Its a fun challenge where bots try to predict my silly "world model" based off of limited and sometimes faulty data. 
They will also have to predict each others strategies affects on the world economy. 

Probably best not to have more then bot per player to keep things fair. Or not, have fun!

## Getting started
1. Start up the program by running `bazel run Market`.
2. To start/reset preform a get on `127.0.0.1:8080/market/start` (Yup, I was too lazy to make a UI)
3. Start up trading bots.
4. To simulate a year preform a get on `127.0.0.1:8080/market/simulate-year`


## Bots
To start the example bot run `bazel run //TradingBot:exampleBot`.
Go to the readme in TradingBot to get more detail


# OTHER
Add pip dependency:
Add it to requirements.in 
run `bazelisk run requirements.update`