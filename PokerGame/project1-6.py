from tkinter import *
from random import *
from tkinter import simpledialog
from PIL import Image, ImageTk


class minBet:
   def __init__(self, smallBlind, stakes):
       self._stakes = stakes
       self._smallBlind = smallBlind
       self._bigBlind = smallBlind * (1 / stakes)

   def getBigBlindVal(self):
       """
       Obtains the big blind value
       :return: the big blind value
       """
       return self._bigBlind

   def getSmallBlindVal(self):
       """
       Obtains the small blind value
       :return: the small blind value
       """
       return self._smallBlind

   def getStakes(self):
       """
       Obtains the stake value
       :return: the stake value
       """
       return self._stakes

#
# Organizes the rounds of the poker game
#
class Round:
   def __init__(self):
       self._roundNo = 1
       self._round = ""
       self.setRound()

   def setRoundNo(self, number):
       """
       Sets the round number
       @param number: round number to set to
       @return: no return value; sets round number to number
       """
       self._roundNo = number

   def setRound(self):
       """
       Sets the current round
       @return: no return value; changes the current round
       """
       # Set pre flop
       if self._roundNo == 1:
           self.setPreFlop()
       # Set post flop
       elif self._roundNo == 2:
           self.setPostFlop()
       # Set post turn
       elif self._roundNo == 3:
           self.setPostTurn()
       # Set showdown
       elif self._roundNo == 4:
           self.setShowdown()
       # Default to pre flop
       else:
           self._roundNo = 1
           self.setPreFlop()

   def setPreFlop(self):
       """
       Sets the round to pre flop
       @return: no return value; sets turn to pre flop
       """
       self._round = "PRE-FLOP"

   def setPostFlop(self):
       """
       Sets round to post flop
       @return: no return value; sets turn to post flop
       """
       self._round = "POST-FLOP"

   def setPostTurn(self):
       """
       Sets round to post turn
       @return: no return value; sets turn to post turn
       """
       self._round = "POST-TURN"

   def setShowdown(self):
       """
       Sets round to showdown
       @return: no return value' sets turn to showdown
       """
       self._round = "SHOWDOWN"

   def getRound(self):
       """
       Gets the current round
       @return: returns the current round
       """
       return self._round

   def addRound(self):
       """
       Increments the round number
       @return: no return value; increases the round number by 1
       """
       self._roundNo += 1


class Player:
   """
   Rotates the positions of big/small blinds every round
   :param player: the name of player to be added
   :return: Nothing
   """

   def __init__(self, name):
       self._name = name
       self._hand = []
       self._balance = 300
       self._type = ""
       self._bet = 0

   """
   Return the name of the player
   :return: the name of player
   """

   def getName(self):
       return self._name

   """
   Change the name of the player
   :param name: the new name of player
   :return: Nothing
   """

   def setName(self, name):
       self._name = name

   """
   Return the player balance
   :return: the current balance of player
   """

   def getBalance(self):
       return self._balance

   """
   Change the balance of player
   :param amount: the amount of player to be deducted
   :return: Nothing
   """

   def setBalance(self, amount):
       self._balance = int(amount)

   """
   Return the type of player
   :return: the player type
   """

   def getType(self):
       return self._type

   """
   Set up the player bet
   :param amount: the bet amount of player
   :return: Nothing
   """

   def setBet(self, myBet):
       self._bet = myBet

   """
   Change the balance of player
   :return: the current bet of player
   """

   def getBet(self):
       return self._bet

   """
   Return the bet of the previous player to see if one can check
   and set up the minimum amount to bet
   :return: Nothing
   """

   def callBet(self, prevPlayerBet):
       self._bet = prevPlayerBet

   """
   If the player bets decides to raise the bet, increase the bet
   :param newBet: new increased bet amount
   :param prevPlayerBet: the bet of previous player
   :return: Nothing
   """

   def raiseBet(self, newBet, prevPlayerBet):
       # set the player bet to minimum bet
       self.callBet(prevPlayerBet)
       # if newBet is less than the minimum bet
       if newBet < self._bet:
           # set it to minimum amount
           self.callBet(prevPlayerBet)
       # if newBet is more than the entire balance
       elif newBet > self._balance:
           # use all the money have
           self.allin()
       # if newBet is more than the minimum
       else:
           # set bet to that amount
           self._bet = newBet

   """
   If no one bet previously, player can skip as well
   :param prevPlayerBet: the bet of previous player
   :return: True if checkable, false if not
   """

   def check(self, prevPlayerBet):
       # if player can check
       if prevPlayerBet == -1 or prevPlayerBet == 0:
           self._bet = 0
           return True
       # player can't check since there was a bet
       else:
           return False

   """
   set player type to a folded person
   :param prevPlayerBet: the bet of previous player
   :return: True if checkable, false if not
   """

   def fold(self):
       self._type = "skip"
       self.skip()

   """
   Player bet all the money curretly have
   :param prevPlayerBet: the bet of previous player
   :return: True if checkable, false if not
   """

   def allin(self, prevPlayerBet):
       # set up a minimum bet first
       self.callBet(prevPlayerBet)
       # if bet amount is more than what you have return
       if self._bet > self._balance:
           return
       # bet all the player balance
       else:
           self._bet = self._balance

   """
   Player with zero balance can buy their place
   :return: Nothing
   """

   def buy(self):
       return

   """
   skip this player's turn when fold
   :return: Nothing
   """

   def skip(self):
       return

   def leave(self):
       self._type = "skip"

   def compete(self):
       return

   def normal(self):
       self._type = "normal"

   def underTheGun(self):
       self._type = "under"

   def bigBlind(self):
       self._type = "big"

   def smallBlind(self):
       self._type = "small"

   """
   When player's turn ends, bet amount is deducted from balance
   :return: return the amount to bet
   """

   def giveMoney(self):
       # if bet is more than what you have, all in
       if self._balance < self._bet:
           giveMoney = self._balance
           # deduct the bet from balance
           self._balance -= giveMoney

           return giveMoney
       # betting less than the balance
       else:
           # deduct the bet from balance
           self._balance -= self._bet
           return self._bet

   def resetMin(self):
       return


#
# Table at which players sit, and rotate small and big blind.
#
class Table:
   ## Initializes a table at which players sit, and rotate small and big blind
   #
   def __init__(self):
       self._startingPos = 2
       self._currentPos = self._startingPos
       self._minimum = minBet(10, 1 / 2)
       self._communityCards = [None] * 3
       self._seats = []
       self._betPos = [self._minimum.getSmallBlindVal(), self._minimum.getBigBlindVal(), 0, 0, 0, 0]
       self._pot = 0
       self._round = Round()
       self._done = False
       self._minimumBet = self._minimum.getBigBlindVal()

   """
   Assign players to each seat
   :param player: the name of player to be added
   :return: Nothing
   """

   def occupySeat(self, player):
       self._seats.append(player)
       # if there are more than maximum occupancy, block the next player
       if len(self._seats) == 6:
           self._seats = self._seats[:len(self._seats)]

   """
   Rotates the positions of big/small blinds every round
   :param player: the name of player to be added
   :return: Nothing
   """

   def rotateBet(self):
       # send the first element to the back
       self._betPos = [self._betPos[-1]] + self._betPos[:-1]

   """
   Adds money player bet to the pot
   :param betAmount: amount of money player bet
   :return: Nothing
   """

   def addMoney(self, betAmount):
       # add to pot the money current palyer bet
       self._pot += betAmount

   """
   returns the current pot value
   :return: Nothing
   """

   def getPot(self):
       return self._pot

   """
   Split the pot in half in case there are two winners
   :return: half amount of the current pot
   """

   def split(self, numberOfPlayers):
       return self._pot/numberOfPlayers

   """
   remove the player with given name from the table
   :param player: player name to be removed
   :return: Nothing
   """

   def emptySeat(self, player):
       self._seats.remove(player)

   """
   Increments the current player position by one, when it
   the end of the list, return to the beginning
   :return: Nothing
   """

   def nextTurn(self):
       self._currentPos += 1
       if self._currentPos == 6:
           self._currentPos = 0

   """
   Return the current player position from the list
   :return: current position value
   """

   def getCurrentPlayer(self):
       return self._currentPos

   ## change outcome of game
   #
   def changeOutcome(self):
       return

   """

   :param player:
   :return:
   """

   def checkTable(self):
       listOfBets = []
       i = 0 
       while self._seats[i].getBet() == None :
           i += 1
       minBet = self._seats[i].getBet()
       print("THIS IS MINBET", minBet)
       for player in self._seats:
           listOfBets.append(player.getBet())
       if all(elem == minBet or elem == None or elem == 0 for elem in listOfBets) :
           return True
       else :
           return False

   """
   determine the minimum bet that current player has to bet
   :return: Nothing
   """

   def defineTableMinBet(self):
       # take the minimum bet that is assigned to each player
       # and set it assign them to player objects
       for i in range(len(self._betPos)):
           self._seats[i].setBet(self._betPos[i])

   """
   check if round has to advance to the next level
   :return: Nothing
   """

   def checkToChangeRound(self):
       # Add bet from each player to pot
       if self.checkTable():
           for player in self._seats:
               self.addMoney(player.giveMoney())
           # add round to go to next level
           self._round.addRound()
           # check the round variable and move on
           self._round.setRound()
           # if round is pre-flop
           if self._round.getRound() == "PRE-FLOP":
               # rotate bet list
               self.rotateBet()
               print("THIS IS BETPOS:", self._betPos)
               # redefine the minimum bet according to
               # the current bet
               self.defineTableMinBet()
               self._pot = 0
               # reset the stating position so it loops
               self._startingPos += 1
               print("THIS IS START POS:", self._startingPos)
               if self._startingPos > 5:
                   self._startingPos = 0
               self._currentPos = self._startingPos
           # if round is not pre flop, reset
           else:
               print("NOT PRE-FLOP")
               self._done = False
               self._currentPos = 0
       else:
           self.nextTurn()

   """
   Check if it is not pre-flop round
   :return: true if it is not pre-flop round, false if it is
   """

   def checkIfNotPreFlop(self):
#       imaginaryBetPos = [0, 0, 0, 0, 0, -1]
       last = len(self._seats) - 1
       if not self._round.getRound() == "PRE-FLOP":
           if not self._done:
               for i in range(len(self._seats)) :
                   if self._seats[i].getBet() != None :
                       self._seats[i].setBet(0)                
               while self._seats[last].getBet() == None :
                   last -= 1
                   if last == 0 :
                       break
               self._seats[last].setBet(-1)
               self._done = True
           return True
       else:
           return False
#
# Main gui class to display and run the poker game
#
class PokerDemo(Tk):
   def __init__(self):
       super().__init__()

       # Set up the table with 6 players
       self.t = Table()

       # Initialize player objects
       player = Player("Player")
       c1 = Player("Computer1")
       c2 = Player("Computer2")
       c3 = Player("Computer3")
       c4 = Player("Computer4")
       c5 = Player("Computer5")
       # Initialize list of player objects
       self._players = [player, c1, c2, c3, c4, c5]
       # Initialize player hands
       self._playerhands = [None] * 6

       # Occupy seats of table with players
       for i in range(0, len(self._players)):
           self.t.occupySeat(self._players[i])

       # Create a minimum bet
       self.t.defineTableMinBet()

       # Set turn to 0
       self._turn = 0
       # Set player name to empty string
       self.playerName = ""
       # Set default bet amount to 20
       self.betAmount = 20
       # Create canvas object
       self.canvas = Canvas(self, width=1000, height=800)
       # Draw green table
       self.canvas.create_rectangle(100, 200, 900, 500,
                                    outline="black", fill="green", width=2)
       # Draw rectangle for community cards
       dealerPos = self.canvas.create_rectangle(350, 200, 650, 300,
                                                outline="black", fill="white", width=2)

       # Initialize list of positions of players
       self.blindPos = [(690, 270, 704, 284), (800, 400, 814, 414), (600, 400, 614, 414),
                        (400, 400, 414, 414), (200, 400, 214, 414), (290, 270, 304, 284)]

       # Create the hands
       self.cardVal, self.usedCards = self.createHands(len(self._players))
       self.communityCards = self.getCommunityCards(self.usedCards)

       # Print hands and community cards
       print(self.cardVal)
       print(self.communityCards)

       # Initialize balances
       self.playerBalance = [170, 200, 120, 50, 200, 500]

       # Draw card outlines on table
       self.placeCards()
       # Create the pot
       self.createPot(self.blindPos)
       # Draw the hands
       self.drawHand()

       # Reset Button
       resetButton = Button(text="Reset", command=self.reset)
       self.canvas.create_window(40, 650, window=resetButton)

       # Show hands button
       showHands = Button(text="Show", command=self.showAllHands)
       self.canvas.create_window(40, 750, window=showHands)

       # Rotate
       rotateButton = Button(text='Rotate', command=self.rotate)
       self.canvas.create_window(40, 700, window=rotateButton)

       # Pot
       self.potValue = 0
       self.potLabel = Label(self, text="Pot: " + str(self.potValue), font=("helvetica", 10))
       self.potLabel.place(x=475, y=50)

       # Current Bet
       self.betValue = self.betAmount
       self.betLabel = Label(self, text="Current Bet: " + str(self.betValue), font=("helvetica", 10))
       self.betLabel.place(x=460, y=70)

       # Round
       self.round = self.t._round.getRound()
       self.roundLabel = Label(self, text="Current Round: " + self.round, font=("helvetica", 10))
       self.roundLabel.place(x=450, y=90)

       # Players
       self.currentPlayerLabel = Label(self, text="Current Player: ", font=("helvetica", 10))
       self.currentPlayerLabel.place(x=720, y=30)

       self.playerName = Label(self, text="Enter your name: ", font=("helvetica", 10))
       self.playerName.place(x=720, y=50)

       playerNameButton = Button(text='Input Name', command=self.updateName)
       self.canvas.create_window(790, 100, window=playerNameButton)

       # Balances
       self.balanceInput = Entry(self)
       self.canvas.create_window(200, 200, window=self.balanceInput)
       self.balanceInput.place(x=160, y=30)

       self.balanceLabel = Label(self, text="Balance: ", font=("helvetica", 10))
       self.balanceLabel.place(x=100, y=30)

       self.currentBalanceLabel = Label(self, text="Current Balance: ", font=("helvetica", 10))
       self.currentBalanceLabel.place(x=100, y=100)

       balanceButton = Button(text='Input Balance', command=self.updateBalance)
       self.canvas.create_window(210, 70, window=balanceButton)

       # Draw current player circle
       self.currentPlayerCirc = self.canvas.create_oval(self.blindPos[self.t.getCurrentPlayer()], fill="black")

       # Various action buttons
       fold = Button(text="Fold", command=self.fold)
       self.canvas.create_window(460, 20, window=fold)

       check = Button(text="Check", command=self.check)
       self.canvas.create_window(595, 20, window=check)

       call = Button(text="Call", command=self.bet)
       self.canvas.create_window(500, 20, window=call)

       raiseBet = Button(text="Raise", command=self.Raise)
       self.canvas.create_window(545, 20, window=raiseBet)

       allIn = Button(text="All-In", command=self.allin)
       self.canvas.create_window(415, 20, window=allIn)

       # Display game
       self.canvas.pack()

   def checkGameEnd(self):
       """
       Checks if the game is over
       @return: no return value; resets the game and shows hands if the game is over
       """
       # Check if the game is over
       if self.round == "SHOWDOWN" and self.t.checkTable():
           return True
       else :
           return False
   
   # function to open a new window  
   # on a button click 
   def openNewWindow(self, dialog): 
          
        # Toplevel object which will  
        # be treated as a new window 
        newWindow = Toplevel() 
      
        # sets the title of the 
        # Toplevel widget 
        newWindow.title("Winner!") 
      
        # sets the geometry of toplevel 
        newWindow.geometry("250x200") 
      
        # A Label widget to show in toplevel 
        Label(newWindow,  
              text =dialog).pack() 
             
        return newWindow

   def checkFold(self):
       """
       Check if the player has folded
       @return: no return value; checks if the player folded and skips them
       """
       # Check if the player folded or has no more money
       if (self._players[self.t.getCurrentPlayer()].getBet() == None or
               self._players[self.t.getCurrentPlayer()].getBalance() == 0):
           if self._players[self.t.getCurrentPlayer()].getBalance() == 0 :
               self._players[self.t.getCurrentPlayer()].fold()
           # Skip player
           print("None")
           self.t.nextTurn()
       else:
           print("NOTNONE")

   def fold(self):
       """
       Option to fold by the player
       @return: No return value; changes attributes of player to fold
       """
       self._players[self.t.getCurrentPlayer()].fold()

       # Alternate player
       self.canvas.delete(self.currentPlayerCirc)
       # Update text labels and round
       self.currentPlayerLabel.config(text="Current Player: " + self._players[self.t.getCurrentPlayer()].getName())
       self.currentBalanceLabel.config(
           text="Current Balance: " + str(self._players[self.t.getCurrentPlayer()].getBalance()))
       # Draw the current hand
       self.drawHand()
       # Update the round and round label
       self.round = self.t._round.getRound()
       self.roundLabel.config(text="Current Round: " + self.t._round.getRound())
       # See if the game has ended
       if self.checkGameEnd() :
           winnerString = ""
           winnerHand = ""
           winnerHands = self.compete()
           for i in range(0,len(winnerHands)):
               self._players[winnerHands[i]].setBalance(self._players[winnerHands[i]].getBalance() + self.t.split(len(winnerHands)))
           for i in winnerHands:
               winnerString = winnerString + self._players[i].getName() + " "
               if i == len(winnerHands) - 2 :
                   winnerString += "and "
           winnerHand = self._playerhands[winnerHands[0]].printHandRank()
           self.showAllHands()
           self.wait_window(self.openNewWindow(winnerString + "\nhas won the game with\n " + winnerHand))
           self.deleteAllHands()
           self.t.checkToChangeRound()
           self.reset()
       else :
           # Check to change round
           self.t.checkToChangeRound()

       # Draw new position of current player
       self.currentPlayerCirc = self.canvas.create_oval((self.blindPos[self.t.getCurrentPlayer()]), fill="black")
       # Update pot label
       self.potLabel.config(text="Pot: " + str(self.t.getPot()))
       self.makeHands()

       print(self.round)
       print(self.communityCards)
       print("Fold")
       # Display the community cards
       self.displayCommunityCards(self.communityCards, self.round)
       

   def bet(self):
       """
       Option to bet by the player
       @return: no return value; changes attributes for the player to bet
       """
       print("#########")
       print("Current Player: ", self.t.getCurrentPlayer())
       print("Prev Player bet: ", self._players[self.t.getCurrentPlayer() - 1].getBet())

       for i in range(len(self._players)):
           print(i, self._players[i].getBet())
       # Delete current player indicator
       self.canvas.delete(self.currentPlayerCirc)
       # Check if the current round is not pre flop
       if not self.t.checkIfNotPreFlop():
           self._players[self.t.getCurrentPlayer()].callBet(self._players[self.t.getCurrentPlayer() - 1].getBet())
       else:
           self._players[self.t.getCurrentPlayer()].callBet(self.t._minimumBet)
       # Draw the hands of the player
       self.drawHand()
       #Display the current Bet
       self.betLabel.config(text="Current Bet: " + str(self._players[self.t.getCurrentPlayer()].getBet()))
       # See if the game has ended
       if self.checkGameEnd() :
           winnerString = ""
           winnerHand = ""
           winnerHands = self.compete()
           for i in range(0,len(winnerHands)):
               self._players[winnerHands[i]].setBalance(self._players[winnerHands[i]].getBalance() + self.t.split(len(winnerHands)))
           for i in winnerHands:
               winnerString = winnerString + self._players[i].getName() + " "
               if i == len(winnerHands) - 2 :
                   winnerString += "and "
           winnerHand = self._playerhands[winnerHands[0]].printHandRank()
           self.showAllHands()
           self.wait_window(self.openNewWindow(winnerString + "\nhas won the game with\n " + winnerHand))
           self.deleteAllHands()
           self.t.checkToChangeRound()
           self.reset()
       else :
           # Check to change round
           self.t.checkToChangeRound()

       print(self.round)
       print(self.communityCards)
       # Update round label
       self.roundLabel.config(text="Current Round: " + self.t._round.getRound())
       # Update the round
       self.round = self.t._round.getRound()
       # Check if the player folded
       self.checkFold()
       # Update text labels
       self.currentPlayerLabel.config(text="Current Player: " + self._players[self.t.getCurrentPlayer()].getName())
       self.currentBalanceLabel.config(text="Current Balance: " + str(self._players[self.t.getCurrentPlayer()].getBalance()))
       # Draw new current player position
       self.currentPlayerCirc = self.canvas.create_oval((self.blindPos[self.t.getCurrentPlayer()]), fill="black")
       # Update pot label
       self.potLabel.config(text="Pot: " + str(self.t.getPot()))
       # Calculate value of hand
       self.makeHands()
       # Display community cards
       self.displayCommunityCards(self.communityCards, self.round)
       
 
   def allin(self):
       """
       Option for the player to all in
       @return: no return value; changes attributes to have the player all in
       """
       # Delete current player indicator
       self.canvas.delete(self.currentPlayerCirc)

       # Check if the current round is pre flop
       if not self.t.checkIfNotPreFlop():
           self._players[self.t.getCurrentPlayer()].allin(self._players[self.t.getCurrentPlayer() - 1].getBet())
       else:
           self._players[self.t.getCurrentPlayer()].allin(self.t._minimumBet)
       # Draw the hands of the player
       self.drawHand()
       #Display the current Bet
       self.betLabel.config(text="Current Bet: " + str(self._players[self.t.getCurrentPlayer()].getBet()))
       # See if the game has ended
       if self.checkGameEnd() :
           winnerString = ""
           winnerHand = ""
           winnerHands = self.compete()
           for i in range(0,len(winnerHands)):
               self._players[winnerHands[i]].setBalance(self._players[winnerHands[i]].getBalance() + self.t.split(len(winnerHands)))
           for i in winnerHands:
               winnerString = winnerString + self._players[i].getName() + " "
               if i == len(winnerHands) - 2 :
                   winnerString += "and "
           winnerHand = self._playerhands[winnerHands[0]].printHandRank()
           self.showAllHands()
           self.wait_window(self.openNewWindow(winnerString + "\nhas won the game with\n " + winnerHand))
           self.deleteAllHands()
           self.t.checkToChangeRound()
           self.reset()
       else :
           # Check to change round
           self.t.checkToChangeRound()

       print(self.round)
       print(self.communityCards)
       # Update round label
       self.roundLabel.config(text="Current Round: " + self.t._round.getRound())
       # Update the round
       self.round = self.t._round.getRound()
       # Check if the player folded
       self.checkFold()
       # Update text labels
       self.currentPlayerLabel.config(text="Current Player: " + self._players[self.t.getCurrentPlayer()].getName())
       self.currentBalanceLabel.config(text="Current Balance: " + str(self._players[self.t.getCurrentPlayer()].getBalance()))
       # Draw new current player position
       self.currentPlayerCirc = self.canvas.create_oval((self.blindPos[self.t.getCurrentPlayer()]), fill="black")
       # Update pot label
       self.potLabel.config(text="Pot: " + str(self.t.getPot()))
       # Calculate value of hand
       self.makeHands()
       # Display community cards
       self.displayCommunityCards(self.communityCards, self.round)

   def Raise(self):
       """
       Option for the player to raise the bet
       @return: no return value; changes attributes to raise the bet
       """
       # Displays pop out window for input for the raise
       name = simpledialog.askstring("Raise", "Enter amount to raise")
       # Delete current player indicator
       self.canvas.delete(self.currentPlayerCirc)
       # Check if the current round is the pre flop
       if not self.t.checkIfNotPreFlop():
           self._players[self.t.getCurrentPlayer()].raiseBet(float(name),
                                                             self._players[self.t.getCurrentPlayer() - 1].getBet())
       else:
           self._players[self.t.getCurrentPlayer()].raiseBet(float(name), self.t._minimumBet)

       #       print(self._players[self.t.getCurrentPlayer()].getBet())

       # Draw the hands of the player
       self.drawHand()
       #Display the current Bet
       self.betLabel.config(text="Current Bet: " + str(self._players[self.t.getCurrentPlayer()].getBet()))
       # See if the game has ended
       if self.checkGameEnd() :
           winnerString = ""
           winnerHand = ""
           winnerHands = self.compete()
           for i in range(0,len(winnerHands)):
               self._players[winnerHands[i]].setBalance(self._players[winnerHands[i]].getBalance() + self.t.split(len(winnerHands)))
           for i in winnerHands:
               winnerString = winnerString + self._players[i].getName() + " "
               if i == len(winnerHands) - 2 :
                   winnerString += "and "
           winnerHand = self._playerhands[winnerHands[0]].printHandRank()
           self.showAllHands()
           self.wait_window(self.openNewWindow(winnerString + "\nhas won the game with\n " + winnerHand))
           self.deleteAllHands()
           self.t.checkToChangeRound()
           self.reset()
       else :
           # Check to change round
           self.t.checkToChangeRound()

       print(self.round)
       print(self.communityCards)
       # Update round label
       self.roundLabel.config(text="Current Round: " + self.t._round.getRound())
       # Update the round
       self.round = self.t._round.getRound()
       # Check if the player folded
       self.checkFold()
       # Update text labels
       self.currentPlayerLabel.config(text="Current Player: " + self._players[self.t.getCurrentPlayer()].getName())
       self.currentBalanceLabel.config(text="Current Balance: " + str(self._players[self.t.getCurrentPlayer()].getBalance()))
       # Draw new current player position
       self.currentPlayerCirc = self.canvas.create_oval((self.blindPos[self.t.getCurrentPlayer()]), fill="black")
       # Update pot label
       self.potLabel.config(text="Pot: " + str(self.t.getPot()))
       # Calculate value of hand
       self.makeHands()
       # Display community cards
       self.displayCommunityCards(self.communityCards, self.round)

   def check(self):
       """
       Option for the player to check
       @return: no return value; changes attributes for the player to check
       """
       print("#########")
       print("Current Player: ", self.t.getCurrentPlayer())
       print("Prev Player bet: ", self._players[self.t.getCurrentPlayer() - 1].getBet())
       for i in range(len(self._players)):
           print(i, self._players[i].getBet())

       # Check if the current round is the pre flop
       if self.t.checkIfNotPreFlop():
           if self._players[self.t.getCurrentPlayer()].check(self._players[self.t.getCurrentPlayer() - 1].getBet()):
               # Delete the current player position
               self.canvas.delete(self.currentPlayerCirc)
               # Update labels
               self.currentPlayerLabel.config(
                   text="Current Player: " + self._players[self.t.getCurrentPlayer()].getName())
               self.currentBalanceLabel.config(
                   text="Current Balance: " + str(self._players[self.t.getCurrentPlayer()].getBalance()))
               # Draw the current hand
               self.drawHand()
               # See if the game has ended
               if self.checkGameEnd() :
                   winnerString = ""
                   winnerHand = ""
                   winnerHands = self.compete()
                   for i in range(0,len(winnerHands)):
                       self._players[winnerHands[i]].setBalance(self._players[winnerHands[i]].getBalance() + self.t.split(len(winnerHands)))
                   for i in winnerHands:
                       winnerString = winnerString + self._players[i].getName() + " "
                       if i == len(winnerHands) - 2 :
                           winnerString += "and "
                   winnerHand = self._playerhands[winnerHands[0]].printHandRank()
                   self.showAllHands()
                   self.wait_window(self.openNewWindow(winnerString + "\nhas won the game with\n " + winnerHand))
                   self.deleteAllHands()
                   self.t.checkToChangeRound()
                   self.reset()
               else :
                   # Check to change round
                   self.t.checkToChangeRound()
               # Update round label and round
               self.roundLabel.config(text="Current Round: " + self.t._round.getRound())
               self.round = self.t._round.getRound()
               # Check if the player folded
               self.checkFold()               
               # Draw new position of player
               self.currentPlayerCirc = self.canvas.create_oval((self.blindPos[self.t.getCurrentPlayer()]),
                                                                fill="black")
               # Update pot label
               self.potLabel.config(text="Pot: " + str(self.t.getPot()))
               # Calculate value of hand
               self.makeHands()
               print("Current Player: ", self.t.getCurrentPlayer())
               print("Prev Player bet: ", self._players[self.t.getCurrentPlayer() - 1].getBet())

               print(self.round)
               print(self.communityCards)
               # Display community cards
               self.displayCommunityCards(self.communityCards, self.round)


   def reset(self):
       """
       Resets the poker game
       @return:
       """
       # Reset hands and community cards
       print("FIRST")
       newCardVal = []
       usedCards = []
       print("SECOND")
       newCardVal, usedCards = self.createHands(len(self._players), newCardVal, usedCards)
       print("THIRD")
       print(usedCards)
       self.communityCards = self.getCommunityCards(usedCards)
       print("PASSED")
#       # Resets turn, pot, pot label
#       self._turn = 0
#       self.t._pot = 0
#       self.potLabel.config(text="Pot: " + str(self.t.getPot()))
#
#       # Sets the round to pre flop and updates label
#       self.round = "PRE-FLOP"
#       self.t._round = Round()
#       self.roundLabel.config(text="Current Round: " + self.round)
#
#       # Resets the current position
#       self.t._currentPos = self.t._startingPos
#
#       # Resets the player position circle
#       self.canvas.delete(self.currentPlayerCirc)
#       self.currentPlayerCirc = self.canvas.create_oval((600, 400, 614, 414), fill='black')

       print(self.cardVal)
       print(self.communityCards)
       print(self.round)

   def rotate(self):
       """
       Rotates the big and small blind
       @return: no return value; rotates big and small blinds
       """
       # Check if the positions need to be reset
       if self._turn == 4:
           self._turn = -2
       # Draw circles
       self.canvas.create_oval(self.blindPos[self._turn - 1], fill='white')
       self.canvas.create_oval(self.blindPos[self._turn], fill='red')
       self.canvas.create_oval(self.blindPos[self._turn + 1], fill='blue')
       # Increment turn
       self._turn += 1
       # Rotate the bet
       self.t.rotateBet()

   def createPot(self, blindPos):
       """
       Create the pot circles
       @param blindPos: the position of the blinds
       @return: no return value; creates the pot
       """
       # Draws the positions of the pots
       for i in range(len(blindPos)):
           self.canvas.create_oval(blindPos[i], fill='white')

   def drawHand(self):
       """
       Draws the hands of the players
       @return: no return value; draws the cards in the hands
       """
       # Card 1
       # Opens the image for the first card in hand
       card1 = Image.open(self.cardVal[self.t.getCurrentPlayer()][0] + ".jpg")
       # Resize the card
       card1 = card1.resize((100, 160), Image.ANTIALIAS)
       # Convert image to a label
       photo = ImageTk.PhotoImage(card1)
       cardLabel1 = Label(self, image=photo)
       cardLabel1.image = photo
       # Place image
       cardLabel1.place(x=390, y=550)

       # Card 2
       # Opens the image for the second card in hand
       card2 = Image.open(self.cardVal[self.t.getCurrentPlayer()][1] + ".jpg")
       # Resize the card
       card2 = card2.resize((100, 160), Image.ANTIALIAS)
       # Convert image to label
       photo = ImageTk.PhotoImage(card2)
       cardLabel2 = Label(self, image=photo)
       cardLabel2.image = photo
       # Place image
       cardLabel2.place(x=510, y=550)

    
   def getCommunityCards(self, usedCards):
       """
       Creates list of community cards
       @param usedCards: the cards already used
       @return: a list of community cards
       """
       # Initialize list
       comCardList = []
       # Repeat 5 times
       for i in range(5):
           # Repeat indefinitely
           while True:
               # Get a random card
               card = self.randomizeValue() + self.randomizeSuit()
               # Check if it is used; if not add to community card list and break
               if card not in usedCards and card not in comCardList:
                   comCardList.append(card)
                   break

       # Return community card list
       return comCardList

   def displayCommunityCards(self, comCardList, round):
       """
       Displays the community cards
       @param comCardList: list of community cards
       @param round: current round of the game
       @return: no return value; displays the cards on the screen
       """

       # Open the first card
       card1 = Image.open(comCardList[0] + ".jpg")
       # Resize the card
       card1 = card1.resize((50, 80), Image.ANTIALIAS)
       # Convert image to label
       photo = ImageTk.PhotoImage(card1)
       cardLabel1 = Label(self, image=photo)
       cardLabel1.image = photo

       # Open the second card
       card2 = Image.open(comCardList[1] + ".jpg")
       # Resize the card
       card2 = card2.resize((50, 80), Image.ANTIALIAS)
       # Convert image to label
       photo = ImageTk.PhotoImage(card2)
       cardLabel2 = Label(self, image=photo)
       cardLabel2.image = photo

       # Open the third card
       card3 = Image.open(comCardList[2] + ".jpg")
       # Resize the card
       card3 = card3.resize((50, 80), Image.ANTIALIAS)
       # Convert image to label
       photo = ImageTk.PhotoImage(card3)
       cardLabel3 = Label(self, image=photo)
       cardLabel3.image = photo

       # Open the fourth card
       card4 = Image.open(comCardList[3] + ".jpg")
       # Resize the card
       card4 = card4.resize((50, 80), Image.ANTIALIAS)
       # Convert image to label
       photo = ImageTk.PhotoImage(card4)
       cardLabel4 = Label(self, image=photo)
       cardLabel4.image = photo

       # Open the fifth card
       card5 = Image.open(comCardList[4] + ".jpg")
       # Resize the card
       card5 = card5.resize((50, 80), Image.ANTIALIAS)
       # Convert image to label
       photo = ImageTk.PhotoImage(card5)
       cardLabel5 = Label(self, image=photo)
       cardLabel5.image = photo

       # Open image for back of a card
       backOfCard = Image.open("Gray_back.jpg")
       # Resize card
       backOfCard = backOfCard.resize((50, 80), Image.ANTIALIAS)
       # Convert image to label
       photo1 = ImageTk.PhotoImage(backOfCard)

       # Check of current round is pre flop
       if round == "PRE-FLOP":
           # Duplicate the backs of the cards 5 times
           back1 = Label(self, image=photo1)
           back2 = Label(self, image=photo1)
           back3 = Label(self, image=photo1)
           back4 = Label(self, image=photo1)
           back5 = Label(self, image=photo1)

           # Convert them to images
           back1.image = photo1
           back2.image = photo1
           back3.image = photo1
           back4.image = photo1
           back5.image = photo1

           # Place images
           back1.place(x=475, y=205)
           back2.place(x=425, y=205)
           back3.place(x=375, y=205)
           back4.place(x=525, y=205)
           back5.place(x=575, y=205)

       # Check if the round is post flop
       elif round == "POST-FLOP":
           # Place the first three community cards
           cardLabel1.place(x=475, y=205)
           cardLabel2.place(x=425, y=205)
           cardLabel3.place(x=375, y=205)

       # Check if the round is post turn
       elif round == "POST-TURN":
           # Place the fourth community card
           cardLabel4.place(x=525, y=205)

       # Check if the round is showdown
       elif round == "SHOWDOWN":
           # Place the fifth community card
           cardLabel5.place(x=575, y=205)

   def placeCards(self):
       """
       Places the outlines of cards on the table
       @return: no return value; displays outlines of cards
       """
       # Displays outlines of cards for players
       # 0
       self.canvas.create_rectangle(660, 210, 695, 260,
                                    outline="black", fill="white", width=2)
       self.canvas.create_rectangle(700, 210, 735, 260,
                                    outline="black", fill="white", width=2)

       # 1
       self.canvas.create_rectangle(760, 440, 795, 490,
                                    outline="black", fill="white", width=2)
       self.canvas.create_rectangle(800, 440, 835, 490,
                                    outline="black", fill="white", width=2)

       # 2
       self.canvas.create_rectangle(560, 440, 595, 490,
                                    outline="black", fill="white", width=2)
       self.canvas.create_rectangle(600, 440, 635, 490,
                                    outline="black", fill="white", width=2)

       # 3
       self.canvas.create_rectangle(360, 440, 395, 490,
                                    outline="black", fill="white", width=2)
       self.canvas.create_rectangle(400, 440, 435, 490,
                                    outline="black", fill="white", width=2)

       # 4
       self.canvas.create_rectangle(160, 440, 195, 490,
                                    outline="black", fill="white", width=2)
       self.canvas.create_rectangle(200, 440, 235, 490,
                                    outline="black", fill="white", width=2)

       # 5
       self.canvas.create_rectangle(300, 210, 335, 260,
                                    outline="black", fill="white", width=2)
       self.canvas.create_rectangle(260, 210, 295, 260,
                                    outline="black", fill="white", width=2)

   def showAllHands(self):
       """
       Shows all hands of the players in the card outlines on the table
       @return: no return value; displays all the cards on the table
       """
       # Hand 1 Card 1
       # Open the first card
       card1 = Image.open(self.cardVal[2][0] + ".jpg")
       # Resize the card
       card1 = card1.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card1)
       self.cardLabel1 = Label(self, image=photo)
       self.cardLabel1.image = photo
       # Place card
       self.cardLabel1.place(x=560, y=440)

       # Hand 1 Card 2
       # Open the second card
       card2 = Image.open(self.cardVal[2][1] + ".jpg")
       # Resize the card
       card2 = card2.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card2)
       self.cardLabel2 = Label(self, image=photo)
       self.cardLabel2.image = photo
       # Place card
       self.cardLabel2.place(x=600, y=440)

       # Hand 2 Card 1
       # Open the first card
       card1 = Image.open(self.cardVal[3][0] + ".jpg")
       # Resize the card
       card1 = card1.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card1)
       self.cardLabel3 = Label(self, image=photo)
       self.cardLabel3.image = photo
       # Place card
       self.cardLabel3.place(x=360, y=440)

       # Hand 2 Card 2
       # Open the second card
       card2 = Image.open(self.cardVal[3][1] + ".jpg")
       # Resize the card
       card2 = card2.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card2)
       self.cardLabel4 = Label(self, image=photo)
       self.cardLabel4.image = photo
       # Place card
       self.cardLabel4.place(x=400, y=440)

       # Hand 3 Card 1
       # Open the first card
       card1 = Image.open(self.cardVal[4][0] + ".jpg")
       # Resize the card
       card1 = card1.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card1)
       self.cardLabel5 = Label(self, image=photo)
       self.cardLabel5.image = photo
       # Place card
       self.cardLabel5.place(x=160, y=440)

       # Hand 3 Card 2
       # Open the second card
       card2 = Image.open(self.cardVal[4][1] + ".jpg")
       # Resize the card
       card2 = card2.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card2)
       self.cardLabel6 = Label(self, image=photo)
       self.cardLabel6.image = photo
       # Place card
       self.cardLabel6.place(x=200, y=440)

       # Hand 4 Card 1
       # Open the first card
       card1 = Image.open(self.cardVal[5][0] + ".jpg")
       # Resize the card
       card1 = card1.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card1)
       self.cardLabel7 = Label(self, image=photo)
       self.cardLabel7.image = photo
       # Place card
       self.cardLabel7.place(x=260, y=210)

       # Hand 4 Card 2
       # Open the second card
       card2 = Image.open(self.cardVal[5][1] + ".jpg")
       # Resize the card
       card2 = card2.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card2)
       self.cardLabel8 = Label(self, image=photo)
       self.cardLabel8.image = photo
       # Place card
       self.cardLabel8.place(x=300, y=210)

       # Hand 5 Card 1
       # Open the first card
       card1 = Image.open(self.cardVal[0][0] + ".jpg")
       # Resize the card
       card1 = card1.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card1)
       self.cardLabel9 = Label(self, image=photo)
       self.cardLabel9.image = photo
       # Place card
       self.cardLabel9.place(x=660, y=210)

       # Hand 5 Card 2
       # Open the second card
       card2 = Image.open(self.cardVal[0][1] + ".jpg")
       # Resize the card
       card2 = card2.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card2)
       self.cardLabel10 = Label(self, image=photo)
       self.cardLabel10.image = photo
       # Place card
       self.cardLabel10.place(x=700, y=210)

       # Hand 5 Card 1
       # Open the first card
       card1 = Image.open(self.cardVal[1][0] + ".jpg")
       # Resize the card
       card1 = card1.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card1)
       self.cardLabel11 = Label(self, image=photo)
       self.cardLabel11.image = photo
       # Place card
       self.cardLabel11.place(x=760, y=440)

       # Hand 6 Card 2
       # Open the second card
       card2 = Image.open(self.cardVal[1][1] + ".jpg")
       # Resize the card
       card2 = card2.resize((35, 50), Image.ANTIALIAS)
       # Convert the card to label
       photo = ImageTk.PhotoImage(card2)
       self.cardLabel12 = Label(self, image=photo)
       self.cardLabel12.image = photo
       # Place card
       self.cardLabel12.place(x=800, y=440)

   def deleteAllHands(self) :
       self.cardLabel1.destroy()
       self.cardLabel2.destroy()
       self.cardLabel3.destroy()
       self.cardLabel4.destroy()
       self.cardLabel5.destroy()
       self.cardLabel6.destroy()
       self.cardLabel7.destroy()
       self.cardLabel8.destroy()
       self.cardLabel9.destroy()
       self.cardLabel10.destroy()
       self.cardLabel11.destroy()
       self.cardLabel12.destroy()
    
   def updateBalance(self):
       """
       Updates the balance from the input given by the user
       @return: No return value; updates the balance label
       """
       # Obtain input for new balance
       newBalance = self.balanceInput.get()
       # Set new balance
       self._players[self.t.getCurrentPlayer()].setBalance(newBalance)
       # Display new balance
       self.currentBalanceLabel.config(text="Current Balance: " + newBalance)

   def updateName(self):
       """
       Updates the name from the input given by the user
       @return: no return value; updates the name label
       """
       # Obtain input for new name
       name = simpledialog.askstring("Player name", "Enter your name")
       # Set new name
       self._players[self.t.getCurrentPlayer()].setName(name)
       # Display new name
       self.currentPlayerLabel.config(text="Current Player: " + name)

   def createHands(self, numOfPlayers, cardList=[], usedCards=[]):
       """
       Creates the hands of the players in the Poker game
       :param numOfPlayers: the number of players in the game
       :param cardList: a list of tuples representing the individual hands of the players
       :param usedCards: list of cards to prevent duplicate cards being dealt
       :return: returns a list of tuples containing the hands of the players
       """
       # Create the cards
       card1 = self.randomizeValue() + self.randomizeSuit()
       card2 = self.randomizeValue() + self.randomizeSuit()
       # Check if the cards have been used yet
       if card1 not in usedCards and card2 not in usedCards and card1 != card2:
           # Subtract the amount of hands that need to be created
           numOfPlayers -= 1
           # Add used cards to usedCards lists
           usedCards.append(card1)
           usedCards.append(card2)
           # Add hand to cardList
           cardList.append((card1, card2))
           # Break recursion if the number of players reaches 0
           if numOfPlayers == 0:
               return
           # Enter next layer of recursion
           self.createHands(numOfPlayers, cardList, usedCards)
       # If the cards have been used then enter next layer of recursion
       else:
           self.createHands(numOfPlayers, cardList, usedCards)

       # Return the cardList
       return cardList, usedCards

   def randomizeValue(self):
       """
       Randomizes the value of the card
       @return: a random value of the card
       """
       # Identify a random number
       value = randint(1, 13)
       # Determine what to return based on the random number obtained
       if value == 1:
           return "A"
       elif value == 11:
           return "J"
       elif value == 12:
           return "Q"
       elif value == 13:
           return "K"
       else:
           return str(value)

   def randomizeSuit(self):
       """
       Randomizes the suit of the card
       @return: a random suit of the card
       """
       # Identify a random suit
       suit = randint(1, 4)
       # Determine what to return based on the random number obtained
       if suit == 1:
           return "C"
       elif suit == 2:
           return "D"
       elif suit == 3:
           return "H"
       else:
           return "S"

   def makeHands(self):
       """
       Calculates the value of the hand
       @return: no return value; changes indicies in list based on new values
       """
       # Initialize list
       hand = []
       # Append hand cards to list
       for i in range(2):
           hand.append(self.cardVal[self.t.getCurrentPlayer()][i])
       # Add community cards to list
       hand += self.communityCards
       # Calculate value
       h = Handrank(hand)
       # Record value
       self._playerhands[self.t.getCurrentPlayer()] = h

   def compete(self):
       """
       Compares values of hands and declares a winner
       @return: index of winner
       """
       scoreList = []
       
       for i in range(len(self._playerhands)) :
           print("HERE IS THE HAND:",i, self._playerhands[i].getHand(), self._playerhands[i].score())
           scoreList.append(self._playerhands[i].score())
       
       firstWinner = scoreList.index(max(scoreList))
       index = firstWinner
       winnerList = []
       tempList = []
       tempList.append(index)
       for i in range(firstWinner + 1, len(self._playerhands)) :
           if self._playerhands[index].score() == self._playerhands[i].score() :
               if self._playerhands[index] < self._playerhands[i] :
                   index = i
                   tempList.clear()
                   tempList.append(i)
               elif self._playerhands[index] == self._playerhands[i] :
                   tempList.append(i)
       
       winnersList = tempList         
               
       return winnersList
#       # Initialize lists
#       points = []
#       temp = []
#       # Append values to points list
#       for i in range(0, len(self._playerhands)):
#           points.append(self._playerhands[i].score())
#       print(points)
#       # Sort points
#       temp = sorted(points)
#       # Initialize index
#       index = 0
#       # Find largest points
#       for i in range(0, len(points)):
#           if temp[0] == points[i]:
#               index = i
#
#       print(self._players[index].getName())
#       # Return the index of the winner
#       return self._players[index].getName()


class Handrank:
   def __init__(self, hand):
       self._hand = hand
       self._temp = {}
       self._temp2 = {}
       self.checkHand()
       
   def getHand(self) :
       return self._hand

   def onePair(self):  # done
       """
       Checks if the hand contains one pair
       @return: returns whether or not one pair is present in the hand
       """
       # Check if 2 is in the values and return true
       if 2 in self._temp.values():
           return True
       return False

   def twoPairs(self):  # done
       """
       Checks if the hand contains two pairs
       @return: returns whether or not two pairs are present in the hand
       """
       # Initialize counter for pairs
       pairCounter = 0
       # Count pairs
       for value in self._temp.values():
           if value >= 2:
               pairCounter += 1

       # Check if there are 2 or more pairs and return true
       if pairCounter >= 2:
           return True
       return False

   def threeOfAKind(self):  # done
       """
       Checks if the hand contains three of a kind
       @return: returns whether or not the hand contains three of a kind
       """
       # Check if there are three of a kind and return true
       if 3 in self._temp.values():
           return True
       return False

   def straight(self):  # done
       """
       Checks if the hand contains a straight
       @return: returns whether or not the hand has a straight
       """
       # Create a list of numbers present in hand
       num = sorted([int(i) for i in self._temp.keys()])
       # Check if the hand length is greater or equal than 5
       if len(num) >= 5:
           # Iterate through items 5 at a time
           for i in range(0, (len(num) % 5) + 1):
               # Calculate if the difference is 4 and return true
               minn = int(num[i])
               maxn = int(num[i + 4])
               if maxn - minn == 4:
                   return True
       return False

   def flush(self):  # done
       """
       Checks if the hand contains a flush
       @return: returns whether or not the hand has a flush
       """
       # Iterate through 5 - 7
       for x in range(5, 7):
           # Check if 5 - 7 are in the values and return true
           if x in self._temp2.values():
               return True
       return False

   def fullHouse(self):  # done
       """
       Checks if the hand contains a full house
       @return: returns whether or not the hand contains a full house
       """
       # Check if both 2 and 3 are present in values and returns true
       if 2 in self._temp.values() and 3 in self._temp.values():
           return True
       return False

   def fourOfAKind(self):  # done
       """
       Checks if the hand has four of a kind
       @return: returns if the hand has four of a kind
       """
       # Check if the 4 is present in the values and return true
       if 4 in self._temp.values():
           return True
       return False

   def straightFlush(self):  # done
       """
       Checks if the hand has a straight flush
       @return: returns whether or not the hand contains a straight flush
       """
       # Check if the hand has both a straight and a flush and return true
       if self.straight() and self.flush():
           return True
       return False

   def royalFlush(self):  # done
       """
       Checks if the hand has a royal flush
       @return: returns whether or not the hand contains a royal flush
       """
       # Checks if the hand has a straight, royal, flush at the same time and return true
       if self.straight() and self.royal() and self.flush():
           return True
       return False

   def royal(self):  # done
       """
       Checks if the hand contains all the royals
       @return: returns whether or not the hand contains all the royals
       """
       # Creates sorted list for card values
       num = sorted([int(i) for i in self._temp.keys()])
       # Check if 10 - ace are present in the hand and return true
       if 10 and 11 and 12 and 13 and 14 in num:
           return True
       else:
           return False

   def royalToNum(self, num):
       """
       Converts the royals to numerical value
       @param num: the character to convert to value
       @return: returns the number that the letter is valued at
       """
       # If joker return 11
       if num == "J":
           return 11
       # If queen return 12
       elif num == "Q":
           return 12
       # If king return 13
       elif num == "K":
           return 13
       # If ace return 14
       elif num == "A":
           return 14

       return

   def getNumericValue(self):
       """
       Gets the highest value of a hand
       @return: the highest value of a hand
       """
       # Sort the list in reverse
       sortDict = sorted(self._temp.items(), key=lambda x: (x[1], x[0]), reverse=True)
       # Returns the highest valued card
       return int(sortDict[0][0])

   def checkHand(self):
       """
       Converts the list of cards into two dictionaries containing the values and suits
       @return: no return value; converts the list into two dictionaries
       """
       # Iterate through the items in the hand
       for i in self._hand:
           # Gets the first character of the card
           num = i[:len(i) - 1]
           # Check if it is a letter and convert to numerical value
           if not num.isdigit():
               num = self.royalToNum(num)
           # If it is a number do nothing
           else:
               num = int(num)
           # If the number is already present then increment
           if num in self._temp.keys():
               self._temp[num] += 1
           # If the number is not present then add to dictionary
           else:
               self._temp[num] = 1

       # Iterate through the items in the hand
       for i in self._hand:
           # Get the first character of the card
           num = i[len(i) - 1]
           # Check if it is present in the dictionary; increment if present and add if not
           if num in self._temp2.keys():
               self._temp2[num] += 1
           else:
               self._temp2[num] = 1

   def score(self):
       """
       Calculates the score of the hand
       @return: the score of the hand
       """
       print(self._temp)
       print(self._temp2)

       # Default point value to 0
       self.point = 0
       # If one pair present then change point to 1
       if self.onePair():
           self.point = 1
       # If two pairs present then change point to 2
       if self.twoPairs():
           self.point = 2
       # If three of a kind present then change point to 3
       if self.threeOfAKind():
           self.point = 3
       # If straight is present then change point to 4
       if self.straight():
           self.point = 4
       # If flush is present then change point to 5
       if self.flush():
           self.point = 5
       # If full house is present then change point to 6
       if self.fullHouse():
           self.point = 6
       # If four of a kind is present then change point to 7
       if self.fourOfAKind():
           self.point = 7
       # If straight flush is present then change point to 8
       if self.straightFlush():
           self.point = 8
       # If royal flush is present then change point to 9
       if self.royalFlush():
           self.point = 9
      
       # Return point value
       return self.point
   
   def printHandRank(self) :
       if self.point == 0 :
           return "HIGH CARD"
       elif self.point == 1 :
           return "ONE PAIR"
       elif self.point == 2 :
           return "TWO PAIR"
       elif self.point == 3 :
           return "THREE OF A KIND"
       elif self.point == 4 :
           return "STRAIGHT"
       elif self.point == 5 :
           return "FLUSH"
       elif self.point == 6 :
           return "FULL HOUSE"
       elif self.point == 7 :
           return "FOUR OF A KIND"
       elif self.point == 8 :
           return "STRAIGHT FLUSH"
       elif self.point == 9 :
           return "ROYAL FLUSH"

   def compareDicts(self, d1, d2, greaterThan=True):
       """
       Compares two dictionaries to see which is greater
       @param d1: first dictionary to be compared
       @param d2: second dictionary to be compared
       @param greaterThan: whether or not the first is greater
       @return: whether or not the first dictionary is greater than the second
       """
       # Initialize dictionaries to be compared
       d1 = sorted(d1.items(), key=lambda x: x[1], reverse=True)
       d2 = sorted(d2.items(), key=lambda x: x[1], reverse=True)
       # Initialize lists
       list1 = []
       list2 = []
       # Obtain the first value in the tuple for each item
       for tup1 in d1:
           list1.append(tup1[0])
       # Obtain the second value in the tuple for each item
       for tup2 in d2:
           list2.append(tup2[0])

       print(list1)
       print(list2)
      
       lenOfList = 0 
       fiveCards = 0
       
       if len(list1) > len(list2) :
           lenOfList = len(list2)
       else :
           lenOfList = len(list1)
        
       for i in range(lenOfList) :
           fiveCards += list1[i]
           if greaterThan :
               if list1[i] > list2[i] :
                   return True
           else :
               if list1[i] < list2[i] :
                   return True
           if fiveCards >= 5 :
               break
       return False

   def __lt__(self, rhs):
       return (self.score() < rhs.score() or
               self.compareDicts(self._temp, rhs._temp, False))

   def __gt__(self, rhs):
       return (self.score() > rhs.score() or
               self.compareDicts(self._temp, rhs._temp))

   def __eq__(self, rhs):
       return not (self < rhs or self > rhs)

   def __ne__(self, rhs):
       return not self == rhs


def main():
   poker = PokerDemo()
   poker.bet()


if __name__ == "__main__":
   main()

"""
AI Code

#!/usr/bin/env python3
# -*- coding: utf-8 -*-

Created on Sat May 30 15:40:50 2020

@author: zxgnj


from numpy import exp, dot, random, amax, array

def sigmoid(x) :
   return 1/(1 + exp(-x))

def sigmoid_d(x) :
   return x * (1 - x)

class Computer(Player) :
   def __init__(self) :
       super().__init__()
       self.t = Table()
       c1 = Player("Computer1")
       c2 = Player("Computer2")
       c3 = Player("Computer3")
       c4 = Player("Computer4")
       c5 = Player("Computer5")
       self._players = [self, c1, c2, c3, c4, c5]
       self._playerhands = [None] * 6
      

       for i in range(0, len(self._players)):
           self.t.occupySeat(self._players[i])
          
       self.t.defineTableMinBet()

       self.cardVal, self.usedCards = self.createHands(len(self._players))
       self.communityCards = self.getCommunityCards(self.usedCards)

      

       self._bet = 50.0
       self._money = 500.0
       self._betted = 0.0
       self.PRE_ROUND = array([[1,0,0], #LowCard
                               [0,1,0], #HighCard
                               [0,0,1]]) #1Pair
#        self.ROUND = array([[1/2,0,0,0,0,0,0,0,0,0], #HIGHCARD
#                            [0,1/2.37,0,0,0,0,0,0,0,0], #1Pair
#                            [0,0,1/21,0,0,0,0,0,0,0], #2Pair
#                            [0,0,0,1/47.3,0,0,0,0,0,0], #3ofaKind
#                            [0,0,0,0,1/254.8,0,0,0,0,0], #Straight
#                            [0,0,0,0,0,1/508.8,0,0,0,0], #Flush
#                            [0,0,0,0,0,0,1/694.17,0,0,0], #FullHouse
#                            [0,0,0,0,0,0,0,1/4165,0,0], #4ofaKind
#                            [0,0,0,0,0,0,0,0,1/72193.33,0], #StraightFlush
#                            [0,0,0,0,0,0,0,0,0,1/649740]]) #RoyalFlush
  
       self.ROUND = array([[1,0,0,0,0,0,0,0,0,0], #HIGHCARD
                           [0,1,0,0,0,0,0,0,0,0], #1Pair
                           [0,0,1,0,0,0,0,0,0,0], #2Pair
                           [0,0,0,1,0,0,0,0,0,0], #3ofaKind
                           [0,0,0,0,1,0,0,0,0,0], #Straight
                           [0,0,0,0,0,1,0,0,0,0], #Flush
                           [0,0,0,0,0,0,1,0,0,0], #FullHouse
                           [0,0,0,0,0,0,0,1,0,0], #4ofaKind
                           [0,0,0,0,0,0,0,0,1,0], #StraightFlush
                           [0,0,0,0,0,0,0,0,0,1]]) #RoyalFlush
  
      
       self._winning_samplePR = array([[0,0.5,1]]).T

       self._winning_sampleR = array([[1,1,1,1,1,1,1,1,1,1]]).T

       self.DECISION = array([[1.0, 0.0, 0.0, 0.0, 0.0],
                              [0.0, 1.0, 0.0, 0.0, 0.0],
                              [0.0, 0.0, 1.0, 0.0, 0.0],
                              [0.0, 0.0, 0.0, 1.0, 0.0],
                              [0.0, 0.0, 0.0, 0.0, 1.0]])

       self.syn_weightsP1 = 2 * random.random((3, 5)) - 1
       self.syn_weightsR = 2 * random.random((10, 5)) - 1
       self.syn_weightsAFR = 2 * random.random((5, 1)) - 1
       self.syn_weightsAFP = array([[-self._bet/self._money, 0, self._bet/self._money, (self._bet * 2)/self._money, 1]]).T #Fold #Check #Call #Raise #ALL-IN
       self.syn_weightsAFP1 = 2 * random.random((5, 1)) - 1

       self.HAND_RANKS = array([[1]])
      
   def trainPRE_ROUND(self) :
       syn_weightsP = array([[1.0,1.0,0.0,0.0,0.0],
                             [0.0,0.0,1.0,0.0,0.0],
                             [0.0,0.0,0.0,1.0,1.0]])
  
       print("RANDOM SYNAPTIC WEIGHTS FOR PRE-ROUND:")
       print(self.syn_weightsP1)
       print(self.syn_weightsAFP)
       for itera in range(10000) :
#            opponent = 2 * random.random() - 1
#       
#            for i in range(len(self.ROUND)) :
#                if opponent > max(self.ROUND[i]):
#                    opponent = i
#                    break

           input_PRE_ROUND = self.PRE_ROUND
          
           outputs1, outputs_after_sig = self.thinkPRE_ROUND(input_PRE_ROUND)
#            outputs1 = sigmoid(dot(input_PRE_ROUND, syn_weightsP1))
#                       
#            outputs_after_sig = sigmoid(dot(outputs1, syn_weightsAFP1))
          
           error = self._winning_samplePR - outputs_after_sig
          
          
           adjustments1 = error * sigmoid_d(outputs_after_sig)                      
          
           self.syn_weightsAFP1 += dot(outputs1.T, adjustments1)
          
           syn_weightsP_error = dot(self.syn_weightsAFP1, adjustments1.T).T
          
           adjustments2 = syn_weightsP_error * sigmoid_d(outputs1)
          
           self.syn_weightsP1 += dot(input_PRE_ROUND.T, adjustments2)
          
          
          
       print("RANDOM SYNAPTIC WEIGHTS AFTER PRE-ROUND:")
       print(self.syn_weightsP1)
       print(self.syn_weightsAFP)
      
       print("OUTPUTS FROM ROUND TO DECISIONS AFTER TRAINING:")
       print(outputs1)
      
#        print("OFFICIAL OUTPUTS: ")
#        print(official_decision)
          
      
       print("OUTPUT AFTER SIG: ")
       print(outputs_after_sig)
      
   def trainROUND(self) :
       syn_weightsP = array([[1.0,1.0,0.0,0.0,0.0],
                             [0.0,0.0,1.0,0.0,0.0],
                             [0.0,0.0,0.0,1.0,1.0]])
  
       print("RANDOM SYNAPTIC WEIGHTS FOR PRE-ROUND:")
       print(self.syn_weightsR)
       print(self.syn_weightsAFR)
       for itera in range(1) :
           opponent = 2 * random.random() - 1
      
           for i in range(len(self.ROUND)) :
               if opponent > max(self.ROUND[i]):
                   opponent = i
                   break

           input_ROUND = self.ROUND
          
           outputs1, outputs_after_sig = self.thinkROUND(input_ROUND)
#            outputs1 = sigmoid(dot(input_PRE_ROUND, syn_weightsP1))
#                       
#            outputs_after_sig = sigmoid(dot(outputs1, syn_weightsAFP1))
          
           error = self._winning_sampleR - outputs_after_sig
          
          
           adjustments1 = error * sigmoid_d(outputs_after_sig)                      
          
           self.syn_weightsAFR += dot(outputs1.T, adjustments1)
          
           syn_weightsP_error = dot(self.syn_weightsAFR, adjustments1.T).T
          
           adjustments2 = syn_weightsP_error * sigmoid_d(outputs1)
          
           self.syn_weightsR += dot(input_ROUND.T, adjustments2)
          
          
          
       print("RANDOM SYNAPTIC WEIGHTS AFTER PRE-ROUND:")
       print(self.syn_weightsP1)
       print(self.syn_weightsAFP)
      
       print("OUTPUTS FROM ROUND TO DECISIONS AFTER TRAINING:")
       print(outputs1)
      
#        print("OFFICIAL OUTPUTS: ")
#        print(official_decision)
          
      
       print("OUTPUT AFTER SIG: ")
       print(outputs_after_sig)
      
   def thinkPRE_ROUND(self, myInput) :
      
       outputs1 = sigmoid(dot(myInput, self.syn_weightsP1))
                      
       outputs_after_sig = sigmoid(dot(outputs1, self.syn_weightsAFP1))
      
       return outputs1, outputs_after_sig
  
   def thinkROUND(self, myInput) :
      
       outputs1 = sigmoid(dot(myInput, self.syn_weightsR))
                      
       outputs_after_sig = sigmoid(dot(outputs1, self.syn_weightsAFR))
      
       return outputs1, outputs_after_sig

"""

